/*
 * @param transaction - The transaction containing purchase details for the receipt
 * 
 * @author Adriane Joaquin Marcelino
 * version 4
 * 
 */
package fromMCO1;
import java.io.IOException;
import java.io.PrintStream;

public class ReceiptModel {
    private TransactionModel transaction;
    
    public ReceiptModel(TransactionModel transaction) {
        this.transaction = transaction;
    }
    
    public void displayReceipt() {
        transaction.displaySummary();
        transaction.displayPaymentBreakdown();
    }
    public void saveReceiptToFile() {
        try {
            PrintStream console = System.out;
            PrintStream fileOut = new PrintStream("receipt.txt");
            System.setOut(fileOut);

            transaction.displaySummary();
            transaction.displayPaymentBreakdown();

            fileOut.close();
            System.setOut(console);

            System.out.println("Text successfully saved to file!");

        } catch (IOException e) {
            System.out.println("An error occurred while saving the file.");
            e.printStackTrace();
        }
    }
}
