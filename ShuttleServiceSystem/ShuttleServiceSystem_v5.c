/*********************************************************************************************************
This is to certify that this project is my own work, based on my personal efforts in studying and applying the concepts 
learned. I have constructed the functions and their respective algorithms and corresponding code by myself. The 
program was run, tested, and debugged by my own efforts. I further certify that I have not copied in part or whole or 
otherwise plagiarized the work of other students and/or persons.
Geslani, Keila Franchoise Leigh, DLSU ID# 12206997
*********************************************************************************************************/
#include "structv2.h"  // include header file that contains structs


void MNLtoLGN(appointment app[], int userCounter){
	int choice;
    
	printf("=== Manila to Laguna ===\n");
    printf("Please Select a Schedule.\n");
    printf("     Trip Number    ETD\n");
    printf("1.    AE101 	 6:00 am\n");
    printf("2.    AE102      7:30 am\n");
    printf("3.    AE103      9:30 am\n");
    printf("4.    AE104      11:00 am\n");
    printf("5.    AE105      1:00 pm\n");
    printf("6.    AE106      2:30 pm\n");
    printf("7.    AE107      3:30 pm\n");
    printf("8.    AE108      5:00 pm\n");
    printf("9.    AE109      6:15 pm\n");
	printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice){
		case 1:
			app[userCounter].tripNum = 101;
			break;
        case 2:
            app[userCounter].tripNum = 102;
            break;
        case 3:
            app[userCounter].tripNum = 103;
            break;
        case 4:
            app[userCounter].tripNum = 104;
            break;
        case 5:
            app[userCounter].tripNum = 105;
            break;
        case 6:
            app[userCounter].tripNum = 106;
            break;
        case 7:
            app[userCounter].tripNum = 107;
            break;
        case 8:
            app[userCounter].tripNum = 108;
            break;
        case 9:
            app[userCounter].tripNum = 109;
            break;
        default:
        	printf("Invalid choice. Please try again.\n");
    }while(choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 6 && choice != 7 && choice != 8 && choice != 9);
	// Repeat until a valid choice between (1-9) is entered
}
void LGNtoMNL(appointment app[], int userCounter){
    int choice;
    
    printf("===Laguna to Manila =====\n\n");
    printf("Please Select a Schedule.\n");
    printf("     Trip Number    ETD\n");
    printf("1.     AE150      5:30 am\n");
    printf("2.     AE151      5:45 am\n");
    printf("3.     AE152      7:00 am\n");
    printf("4.     AE153      7:30 am\n");
    printf("5.     AE154      9:00 am\n");
    printf("6.     AE155      11:00 am\n");
    printf("7.     AE156      1:00 pm\n");
    printf("8.     AE157      2:30 pm\n");
    printf("9.     AE158      3:30 pm\n");
    printf("10.    AE159      5:00 pm\n");
    printf("11.    AE160      6:15 pm\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice){
        case 1:
            app[userCounter].tripNum = 150;
            break;
        case 2:
            app[userCounter].tripNum = 151;
            break;
        case 3:
            app[userCounter].tripNum = 152;
            break;
        case 4:
            app[userCounter].tripNum = 153;
            break;
        case 5:
            app[userCounter].tripNum = 154;
            break;
        case 6:
            app[userCounter].tripNum = 155;
            break;
        case 7:
            app[userCounter].tripNum = 156;
            break;
        case 8:
            app[userCounter].tripNum = 157;
            break;
        case 9:
            app[userCounter].tripNum = 158;
            break;
        case 10:
            app[userCounter].tripNum = 159;
            break;
        case 11:
            app[userCounter].tripNum = 160;
            break;
        default:
        	printf("Invalid choice. Please try again.\n");
    }while(choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 6 && choice != 7 && choice != 8 && choice != 9 && choice != 10 && choice != 11); 
	// Repeat until a valid choice between (1-11) is entered
}

/* This function is for viewing the recent trip
    @param appointment app[]
    @param userCounter
    @param embarkation pts[]

*/
void ViewRecentTrip(appointment app[], int *userCounter, embarkation pts[]){
    int i;
	char fileName[9]; // This is the filename, the user want to view
	FILE *fp_in;

    printf ("Enter the date you want to view with this format Trip-DD-MM-YYYY: "); // Allows the user to specify the filename of the text file the user want to view
	scanf ("%s", fileName);
    fp_in = fopen (fileName, "r"); // opens the file to read and scan into the array of structs
					
	if (fp_in == NULL){
        perror("Cannot Find File, Please Try Again.\n");
    }
    char buffer[256]; // Assuming each line in the file is no longer than 255 characters
    while (fgets(buffer, sizeof(buffer), fp_in) != NULL) {
        printf("%s", buffer); // Print each line
    }
	fclose (fp_in);	
}
/*This function will save into text file all current data on set of users 
	and set of schedules then terminates the program 
	@param appointment app[]
    @param userCounter
    @param embarkation pts[]
*/
void ExitMenu(appointment app[], int userCounter, embarkation pts[], char *currentDate){
    int i;
	FILE *fp_out1;
	
	strcat(currentDate, ".txt");
    fp_out1 = fopen (currentDate, "w"); // Exports all current data into the current date
    for (i = 0; i < userCounter + 1; i++){
      if (i == 0 || app[i].tripNum != app[i - 1].tripNum || strcmp(pts[i].place, pts[i - 1].place) != 0) {
            fprintf(fp_out1, "\nAE%d\n", app[i].tripNum);// Print trip number to text file
            fprintf(fp_out1, "%s\n", pts[i].place); // Print embarkation place to text file
        }
            
        fprintf(fp_out1, "%s, %s\n", app[i].lname, app[i].fname);// Prints passenger information
        fprintf(fp_out1, "%d\n", app[i].idNum); // Prints passenger information
        fprintf(fp_out1, "%d\n", app[i].priority);// Prints priority number
        fprintf(fp_out1, "%s\n\n", app[i].DropPoint); // Prints drop off point
    }
    fclose (fp_out1);
}

void SearchPassenger(appointment app[], embarkation pts[], int *userCounter){
	int found = 0;
	string20 temp;
	int i;
	
	printf("Passenger's Lastname: ");
	scanf("%s", temp);
    for (i = 0; i < *userCounter; ++i) {
        if (strcmp(app[i].lname, temp) == 0) {
        	printf("========== Search =============\n");
            printf("Passenger found:\n");
            printf("Trip Number: AE%d\n", app[i].tripNum);
            printf("Place: %s\n", pts[i].place);
            printf("Name: %s, %s\n", app[i].lname, app[i].fname);
            printf("ID Number: %d\n", app[i].idNum);
            printf("Priority: %d\n", app[i].priority);
            printf("Drop Point: %s\n", app[i].DropPoint);
            printf("================================\n");
            found = 1;
        }
    }
    if (!found) {
        printf("Passenger with last name '%s' not found.\n", app[*userCounter].lname);
    }
}
/* This function is for loading passenger information it will be an alternative way to input passenger information
	it will read the passenger info and the trip number from a text file.
	@param	app[] - 
    @param   pts[] - 
	@param userCounter -  
*/
void loadPassengerInfo(appointment app[], embarkation pts[], int *userCounter) {
	int i;
	char fileName[21];
	
	FILE *fp_in;
	printf ("Enter File Name of Data to Import: "); // Allows the user to specify the filename of the text file to import
	scanf ("%s", fileName);
					
	fp_in = fopen (fileName, "r"); // opens the file to read and scan into the array of structs
					
	if (fp_in == NULL){
		perror("Cannot Find File, Please Try Again.\n");
	}	
    // Loop to read each line of the file
    while (fscanf(fp_in, "AE%d", &app[i].tripNum) == 1) {
        fscanf(fp_in, " EP: %13[^,],", pts[i].place); // Read embarkation point
        fscanf(fp_in, " LN: %20[^,],", app[i].lname); // Read last name
        fscanf(fp_in, " FN: %20[^,],", app[i].fname); // Read first name
        fscanf(fp_in, " ID: %d,", &app[i].idNum); // Read ID number
        fscanf(fp_in, " PN: %d,", &app[i].priority); // Read priority
        fscanf(fp_in, " DP: %s", app[i].DropPoint); // Read drop point
	}
    printf("Data successfully imported\n");
	fclose (fp_in);	
}

