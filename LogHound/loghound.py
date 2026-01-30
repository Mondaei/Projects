#python3
# -*- coding: utf-8 -*-

"""
Group 4 - Windows Event Log Forensics Tool

This script analyzes Windows event logs (EVTX) to identify suspicious activities including:
- Failed login attempts
- Privilege escalation events
- Account modifications
- Persistence techniques // Currently not working
- Other suspicious activities // Currently not working

"""

import Evtx.Evtx as evtx
import Evtx.Views as e_views
import pandas as pd
import argparse
import datetime
import re
import os
import xml.etree.ElementTree as ET
from pathlib import Path
from collections import defaultdict
import json
import sys

# For PDF export
try:
    from reportlab.lib import colors
    from reportlab.lib.pagesizes import letter
    from reportlab.platypus import SimpleDocTemplate, Table, TableStyle, Paragraph, Spacer
    from reportlab.lib.styles import getSampleStyleSheet
    PDF_SUPPORT = True
except ImportError:
    PDF_SUPPORT = False


class WindowsLogForensics:
    def __init__(self, logpath=None, outputformat="csv", outputpath=None, days=7):
        self.logpath = logpath or Path("C:/Windows/System32/winevt/Logs")
        self.outputformat = outputformat.lower()
        self.outputpath = Path(outputpath or Path.home() / "Documents" / "LogForensics")
        self.days = days
        
        # Create output directory if it doesn't exist
        if not self.outputpath.exists():
            self.outputpath.mkdir(parents=True)
            print(f"Created output directory: {self.outputpath}")
        
        # Calculate date range
        self.end_date = datetime.datetime.now()
        self.start_date = self.end_date - datetime.timedelta(days=self.days)
        
        # Initialize findings dictionary
        self.findings = {
            "FailedLogins": [],
            "PrivilegeEscalation": [],
            "AccountModifications": [],
            "PersistenceTechniques": [],
            "SuspiciousExecutables": [],
            "ServiceCreation": [],
            "PowerShellActivity": []
        }
        
        # Define paths to common event logs
        self.security_log = self.logpath / "Security.evtx"
        self.system_log = self.logpath / "System.evtx"
        self.powershell_log = self.logpath / "Microsoft-Windows-PowerShell%4Operational.evtx"

    def _get_formatted_timestamp(self):
        """Get a formatted timestamp for filenames"""
        return datetime.datetime.now().strftime("%Y%m%d_%H%M%S")
    
    def _parse_event_data(self, record):
        """Parse XML event data into a dictionary"""
        xml_string = record.xml()
        root = ET.fromstring(xml_string)
        
        # Get namespace
        ns = {"ns": re.match(r'{(.*)}', root.tag).group(1)}
        
        # Extract basic event information
        system_elem = root.find(".//ns:System", ns)
        event_id = system_elem.find("ns:EventID", ns).text
        time_created = system_elem.find("ns:TimeCreated", ns).attrib["SystemTime"]
        
        # Try multiple datetime formats to handle different log formats
        for fmt in ["%Y-%m-%dT%H:%M:%S", "%Y-%m-%d %H:%M:%S"]:
            try:
                time_created = datetime.datetime.strptime(time_created[:19], fmt)
                break
            except ValueError:
                continue
        
        # Extract event data
        event_data = {}
        event_data_elem = root.find(".//ns:EventData", ns)
        
        if event_data_elem is not None:
            for data in event_data_elem.findall("ns:Data", ns):
                name = data.attrib.get("Name", "Data")
                value = data.text or ""
                event_data[name] = value
        
        return {
            "EventID": event_id,
            "TimeCreated": time_created,
            "EventData": event_data,
            "RawXML": xml_string
        }
    
    def _is_in_date_range(self, timestamp):
        """Check if timestamp is within the specified date range"""
        return self.start_date <= timestamp <= self.end_date
    
    def analyze_security_log(self):
        """Analyze Security event log for suspicious activities"""
        print("Analyzing Security Event Logs for suspicious activities...")
        
        if not self.security_log.exists():
            print(f"Security log not found at {self.security_log}")
            return
        
        try:
            with evtx.Evtx(str(self.security_log)) as log:
                for record in log.records():
                    event = self._parse_event_data(record)
                    
                    # Skip events outside our date range
                    if not self._is_in_date_range(event["TimeCreated"]):
                        continue
                    
                    # Process based on event ID
                    event_id = int(event["EventID"])
                    
                    # Failed login attempts (Event ID 4625)
                    if event_id == 4625:
                        data = event["EventData"]
                        self.findings["FailedLogins"].append({
                            "TimeCreated": event["TimeCreated"],
                            "ID": event_id,
                            "UserName": data.get("TargetUserName", ""),
                            "Domain": data.get("TargetDomainName", ""),
                            "SourceIP": data.get("IpAddress", "Local"),
                            "FailureReason": data.get("Status", "")
                        })
                    
                    # Privilege escalation events (4672 - Special privileges assigned to new logon)
                    elif event_id == 4672:
                        data = event["EventData"]
                        username = data.get("SubjectUserName", "")
                        # Skip system accounts
                        if not any(x in username.upper() for x in ["SYSTEM", "LOCAL SERVICE", "NETWORK SERVICE"]):
                            self.findings["PrivilegeEscalation"].append({
                                "TimeCreated": event["TimeCreated"],
                                "ID": event_id,
                                "UserName": username,
                                "Domain": data.get("SubjectDomainName", ""),
                                "PrivilegesAssigned": data.get("PrivilegeList", "")
                            })
                    
                    # Account modifications
                    elif event_id in [4720, 4738, 4732]:
                        data = event["EventData"]
                        event_type = {
                            4720: "Account Created",
                            4738: "Account Modified",
                            4732: "Account Added to Group"
                        }.get(event_id)
                        
                        self.findings["AccountModifications"].append({
                            "TimeCreated": event["TimeCreated"],
                            "ID": event_id,
                            "EventType": event_type,
                            "TargetUser": data.get("TargetUserName", ""),
                            "PerformedBy": data.get("SubjectUserName", "")
                        })
        
        except Exception as e:
            print(f"Error processing Security log: {e}")
        
        # Print summary of findings
        print(f"  Found {len(self.findings['FailedLogins'])} failed login attempts")
        print(f"  Found {len(self.findings['PrivilegeEscalation'])} privilege escalation events")
        print(f"  Found {len(self.findings['AccountModifications'])} account modification events")
    
    def analyze_system_log(self):
        """Analyze System event log for suspicious activities"""
        print("Analyzing System Event Logs for suspicious activities...")
        
        if not self.system_log.exists():
            print(f"System log not found at {self.system_log}")
            return
        
        try:
            with evtx.Evtx(str(self.system_log)) as log:
                for record in log.records():
                    event = self._parse_event_data(record)
                    
                    # Skip events outside our date range
                    if not self._is_in_date_range(event["TimeCreated"]):
                        continue
                    
                    event_id = int(event["EventID"])
                    
                    # Service creation events (7045)
                    if event_id == 7045:
                        data = event["EventData"]
                        self.findings["ServiceCreation"].append({
                            "TimeCreated": event["TimeCreated"],
                            "ID": event_id,
                            "ServiceName": data.get("ServiceName", ""),
                            "ExecutablePath": data.get("ImagePath", ""),
                            "ServiceType": data.get("ServiceType", ""),
                            "StartType": data.get("StartType", ""),
                            "ServiceAccount": data.get("AccountName", "")
                        })
        
        except Exception as e:
            print(f"Error processing System log: {e}")
        
        print(f"  Found {len(self.findings['ServiceCreation'])} new service creation events")
    
    def analyze_powershell_log(self):
        """Analyze PowerShell event log for suspicious activities"""
        print("Checking for suspicious PowerShell activity...")
        
        if not self.powershell_log.exists():
            print(f"PowerShell operational log not found at {self.powershell_log}")
            return
        
        suspicious_patterns = [
            "Invoke-Mimikatz", "Invoke-Expression", "IEX", "Download", 
            "Net.WebClient", "Hidden", "Base64", "SecureString", 
            "EncodedCommand", "PasswordVault"
        ]
        
        try:
            with evtx.Evtx(str(self.powershell_log)) as log:
                for record in log.records():
                    event = self._parse_event_data(record)
                    
                    # Skip events outside our date range
                    if not self._is_in_date_range(event["TimeCreated"]):
                        continue
                    
                    event_id = int(event["EventID"])
                    
                    # Script block logging (4104)
                    if event_id == 4104:
                        data = event["EventData"]
                        script_block = data.get("ScriptBlockText", "")
                        
                        # Check if the script block contains suspicious patterns
                        if any(pattern.lower() in script_block.lower() for pattern in suspicious_patterns):
                            # Truncate script block if too long
                            if len(script_block) > 200:
                                script_block = script_block[:200] + "..."
                                
                            self.findings["PowerShellActivity"].append({
                                "TimeCreated": event["TimeCreated"],
                                "ID": event_id,
                                "ScriptBlock": script_block
                            })
        
        except Exception as e:
            print(f"Error processing PowerShell log: {e}")
        
        print(f"  Found {len(self.findings['PowerShellActivity'])} suspicious PowerShell events")
    
    def export_findings_to_csv(self):
        """Export findings to CSV files"""
        print("Exporting findings to CSV...")
        timestamp = self._get_formatted_timestamp()
        
        # Export each category to a separate CSV
        for category, data in self.findings.items():
            if data:
                # Convert data to DataFrame
                df = pd.DataFrame(data)
                
                # Save to CSV
                csv_path = self.outputpath / f"{category}_{timestamp}.csv"
                df.to_csv(csv_path, index=False)
                print(f"  Exported {category} to {csv_path}")
        
        # Create summary CSV
        summary_data = []
        for category, data in self.findings.items():
            summary_data.append({
                "Category": category,
                "Count": len(data),
                "Details": "See detailed CSV report" if data else "No findings"
            })
        
        summary_df = pd.DataFrame(summary_data)
        summary_path = self.outputpath / f"Summary_{timestamp}.csv"
        summary_df.to_csv(summary_path, index=False)
        print(f"  Exported summary to {summary_path}")
    
    def export_findings_to_pdf(self):
        """Export findings to a PDF report"""
        if not PDF_SUPPORT:
            print("ReportLab library not found. Please install it for PDF support.")
            print("Falling back to CSV export.")
            self.export_findings_to_csv()
            return
        
        print("Exporting findings to PDF...")
        timestamp = self._get_formatted_timestamp()
        pdf_path = self.outputpath / f"LogForensics_Report_{timestamp}.pdf"
        
        # Create PDF document
        doc = SimpleDocTemplate(str(pdf_path), pagesize=letter)
        elements = []
        
        # Add title and metadata
        styles = getSampleStyleSheet()
        elements.append(Paragraph("Windows Event Log Forensics Report", styles['Title']))
        elements.append(Paragraph(f"Generated: {datetime.datetime.now()}", styles['Normal']))
        elements.append(Paragraph(f"Analysis Period: {self.start_date} to {self.end_date}", styles['Normal']))
        elements.append(Spacer(1, 12))
        
        # Add findings for each category
        for category, data in self.findings.items():
            elements.append(Paragraph(category, styles['Heading2']))
            
            if data:
                # Convert data to a list of lists for table
                table_data = [[k for k in data[0].keys()]]  # Header row
                
                for item in data:
                    row = []
                    for key in data[0].keys():
                        value = item.get(key, "")
                        # Format datetime objects
                        if isinstance(value, datetime.datetime):
                            value = value.strftime("%Y-%m-%d %H:%M:%S")
                        row.append(str(value))
                    table_data.append(row)
                
                # Create table
                table = Table(table_data)
                table.setStyle(TableStyle([
                    ('BACKGROUND', (0, 0), (-1, 0), colors.grey),
                    ('TEXTCOLOR', (0, 0), (-1, 0), colors.whitesmoke),
                    ('ALIGN', (0, 0), (-1, -1), 'CENTER'),
                    ('FONTNAME', (0, 0), (-1, 0), 'Helvetica-Bold'),
                    ('BOTTOMPADDING', (0, 0), (-1, 0), 12),
                    ('BACKGROUND', (0, 1), (-1, -1), colors.beige),
                    ('GRID', (0, 0), (-1, -1), 1, colors.black)
                ]))
                elements.append(table)
            else:
                elements.append(Paragraph("No findings", styles['Normal']))
            
            elements.append(Spacer(1, 12))
        
        # Build and save PDF
        doc.build(elements)
        print(f"  PDF report saved to {pdf_path}")
    
    def export_findings(self):
        """Export findings based on the selected format"""
        if self.outputformat == "csv":
            self.export_findings_to_csv()
        elif self.outputformat == "pdf":
            self.export_findings_to_pdf()
        else:
            print(f"Unsupported output format: {self.outputformat}")
            print("Falling back to CSV export.")
            self.export_findings_to_csv()
    
    def show_summary(self):
        """Display a summary of findings"""
        print("\nWindows Event Log Forensics Summary:")
        print("=================================")
        print(f"Analysis Period: {self.start_date} to {self.end_date}")
        print(f"Output Directory: {self.outputpath}")
        print(f"Output Format: {self.outputformat}")
        print("\nFindings:")
        
        for category, data in self.findings.items():
            count = len(data)
            if count > 0:
                # Display in red if findings exist
                print(f"  {category}: {count} events")
            else:
                # Display in green if no findings
                print(f"  {category}: {count} events")
        
        print("\nCheck the output directory for detailed reports.")
    
    def run(self):
        """Run the full analysis"""
        print("Windows Event Log Forensics Tool (Python)")
        print("=======================================\n")
        
        # Check if running with sufficient privileges
        if os.name == 'nt' and not os.environ.get('ADMINISTRATOR'):
            print("Warning: This script may not access all logs without administrator privileges.")
            print("Consider running the script as Administrator for complete results.\n")
        
        # Analyze logs
        self.analyze_security_log()
        self.analyze_system_log()
        self.analyze_powershell_log()
        
        # Export findings
        self.export_findings()
        
        # Show summary
        self.show_summary()


def main():
    """Main entry point"""
    parser = argparse.ArgumentParser(description="Windows Event Log Forensics Tool")
    parser.add_argument("--logpath", help="Path to event log files (default: system logs)")
    parser.add_argument("--outputformat", choices=["csv", "pdf"], default="csv",
                        help="Format for the report output (CSV or PDF)")
    parser.add_argument("--outputpath", help="Path where the report should be saved")
    parser.add_argument("--days", type=int, default=7, help="Number of days in the past to analyze")
    
    args = parser.parse_args()
    
    # Create and run the forensics tool
    forensics = WindowsLogForensics(
        logpath=args.logpath,
        outputformat=args.outputformat,
        outputpath=args.outputpath,
        days=args.days
    )
    forensics.run()


if __name__ == "__main__":
    main()
