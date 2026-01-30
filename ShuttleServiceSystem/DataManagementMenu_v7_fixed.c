/*********************************************************************************************************
This is to certify that this project is my own work, based on my personal efforts in studying and applying the concepts 
learned. I have constructed the functions and their respective algorithms and corresponding code by myself. The 
program was run, tested, and debugged by my own efforts. I further certify that I have not copied in part or whole or 
otherwise plagiarized the work of other students and/or persons.
Geslani, Keila Franchoise Leigh, DLSU ID# 12206997
*********************************************************************************************************/
#include "struct_v7_fixed.h"  // include header file that contains structs

/* This function is for storing tripNum
	@param app[]
	@param userCounter
*/
void MNLtoLGN(appointment app[], int *userCounter){
	int choice;
    
	do{  // FIXED: Added missing 'do' statement
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
				app[*userCounter].tripNum = 101;
				break;
	        case 2:
	            app[*userCounter].tripNum = 102;
	            break;
	        case 3:
	            app[*userCounter].tripNum = 103;
	            break;
	        case 4:
	            app[*userCounter].tripNum = 104;
	            break;
	        case 5:
	            app[*userCounter].tripNum = 105;
	            break;
	        case 6:
	            app[*userCounter].tripNum = 106;
	            break;
	        case 7:
	            app[*userCounter].tripNum = 107;
	            break;
	        case 8:
	            app[*userCounter].tripNum = 108;
	            break;
	        case 9:
	            app[*userCounter].tripNum = 109;
	            break;
	        default:
	        	printf("Invalid choice. Please try again.\n");
	    }
	}while(choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 6 && choice != 7 && choice != 8 && choice != 9);
	// Repeat until a valid choice between (1-9) is entered
}
/* This function is for storing tripNum
	@param 
	@param 
*/
void LGNtoMNL(appointment app[], int *userCounter){
    int choice;
    
	do{
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
            app[*userCounter].tripNum = 150;
            break;
        case 2:
            app[*userCounter].tripNum = 151;
            break;
        case 3:
            app[*userCounter].tripNum = 152;
            break;
        case 4:
            app[*userCounter].tripNum = 153;
            break;
        case 5:
            app[*userCounter].tripNum = 154;
            break;
        case 6:
            app[*userCounter].tripNum = 155;
            break;
        case 7:
            app[*userCounter].tripNum = 156;
            break;
        case 8:
            app[*userCounter].tripNum = 157;
            break;
        case 9:
            app[*userCounter].tripNum = 158;
            break;
        case 10:
            app[*userCounter].tripNum = 159;
            break;
        case 11:
            app[*userCounter].tripNum = 160;
            break;
        default:
        	printf("Invalid choice. Please try again.\n");
    	}
	}while(choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 6 && choice != 7 && choice != 8 && choice != 9 && choice != 10 && choice != 11); 
	// Repeat until a valid choice between (1-11) is entered
}
/*This function is for Embarkation encoding
    @param app[]
    @param *userCounter
*/
void Passenger(appointment app[], int *userCounter){
  	int i;
  	int choice, choice2, choice3, choice4, choice5, choice6;
	char *exits;  
  
  	printf("=================== Passenger ==================");
  	printf("\nPlease fill out your embarkation card.\n");
  	printf("Name FN LN: ");
  	scanf("%19s %19s", app[*userCounter].fname, app[*userCounter].lname);  // FIXED: Added field width limit
	printf("ID Number: ");
  	scanf("%d", &app[*userCounter].idNum);
  	
	do{
  		printf("Enter your priority number.\n");
  		printf("1. Faculty and ASF with Inter-campus assignments \n");
  		printf("2. Students with Inter-campus enrolled subjects or enrolled in thesis using Inter-campus facilities\n");
  		printf("3. Researchers\n");
  		printf("4. School Administrators (Academic Coordinators level and up for Faculty and ASF, and \n");
		printf("   Director level and up for APSP\n");
		printf("5. University Fellows\n");
		printf("6. Employees and Students with official business\n");
		printf("Enter your choice: ");
		scanf("%d", &choice2);
	
	switch(choice2){
		case 1:
			app[*userCounter].priority = 1;
			break;
		case 2:
			app[*userCounter].priority = 2;
			break;
		case 3:
			app[*userCounter].priority = 3;
			break;
		case 4:
			app[*userCounter].priority = 4;
			break;
		case 5:
			app[*userCounter].priority = 5;
			break;
		case 6:
			app[*userCounter].priority = 6; 
			break;
		default:
		    printf("Invalid choice. Please try again.\n");
		}
  	}while(choice2 != 1 && choice2 != 2 && choice2 != 3 && choice2 != 4 && choice2 != 5 && choice2 != 6); // Repeat until a valid choice between (1-6) is entered
  	
	do{
		printf("What is your route? Please Pick One.\n");
  		printf("1. Manila to Laguna\n");
  		printf("2. Laguna to Manila\n");
  		printf("Enter your choice: ");
		scanf("%d", &choice); 
	  	switch (choice){
		    case 1:
		    	strcpy(app[*userCounter].place, "Manila Campus");
		    	MNLtoLGN(app, userCounter);
		      	break;
		    case 2:
		    	strcpy(app[*userCounter].place, "Laguna Campus");
		      	LGNtoMNL(app, userCounter);
		     	break;
			default:
		        printf("Invalid choice. Please try again.\n");
  		}
	}while(choice != 1 && choice != 2); // Repeat until a valid choice (1 or 2) is entered
	
	if (choice == 1){
		printf("Please Select a Drop off\n");
		if (app[*userCounter].tripNum == 101 || app[*userCounter].tripNum == 102 || app[*userCounter].tripNum == 104 || app[*userCounter].tripNum == 108 || 
				app[*userCounter].tripNum == 109) {
			do{
				exits = "Mamplasan";
		        printf("========== Mamplasan =============\n\n");
		        printf("1. drop-off point  Mamplasan Toll Exit\n");
		        printf("2. drop-off point  Phase 5, San Jose Village\n");
		        printf("3. drop-off point  Milagros Del Rosario (MRR) Building\n");
		        printf("Enter your choice: ");
		        scanf("%d", &choice3);
		        switch (choice3){
		        	case 1:
		        		strcpy(app[*userCounter].DropPoint, "Mamplasan Toll");
		        		break;
		        	case 2:
		        		strcpy(app[*userCounter].DropPoint, "Phase 5, San Jose Village");
	                    break;
	                case 3:
	                    strcpy(app[*userCounter].DropPoint, "Milagros Del Rosario (MRR) Building");
	                    break;
	                default:
	                    printf("Invalid choice. Please try again.\n");
	                    break;
				}
			}while(choice3 != 1 && choice3 != 2 && choice3 != 3); // Repeat until a valid choice (1 to 3) is entered
	        
	    } else {
	        do{
	        	exits = "ETON";
		        printf("========== ETON =============\n\n");
		        printf("1. drop-off point  Laguna Blvd. Guard House\n");
		        printf("2. drop-off point   Milagros Del Rosario (MRR) Building\n");
		        printf("Enter your choice: ");
		        scanf("%d", &choice4);
		        switch (choice4){
		        	case 1:
		        		strcpy(app[*userCounter].DropPoint, "Laguna Blvd");
		        		break;
		        	case 2:
		        		strcpy(app[*userCounter].DropPoint, "Milagros Del Rosario (MRR) Building");
		        		break;
		        	default:
		        		printf("Invalid choice. Please try again.\n");
	                    break;
				}
			}while(choice4 != 1 && choice4 != 2); // Repeat until a valid choice (1 or 2) is entered
			
	    }
	} else if (choice == 2){
		printf("Please Select a Drop off\n");
		if (app[*userCounter].tripNum == 152 || app[*userCounter].tripNum == 153 || app[*userCounter].tripNum == 155 || app[*userCounter].tripNum == 159 ||
			 	app[*userCounter].tripNum == 160) {
			do{
				exits = "Estrada";
		        printf("========== Estrada =============\n\n");
		        printf("1. drop-off point  Petron Gasoline Station along Gil Puyat Avenue\n");
		        printf("2. drop-off point  Gate 4: Gokongwei Gate\n");
		        printf("3. drop-off point  Gate 2: North Gate (HSSH)\n");
		        printf("4. drop-off point  Gate 1: South Gate (LS Building Entrance)\n");
		        printf("Enter your choice: ");
		        scanf("%d", &choice5);
		        switch (choice5){
		        	case 1:
		        		strcpy(app[*userCounter].DropPoint, "Petron Gasoline Station");
		        		break;
		        	case 2:
		        		strcpy(app[*userCounter].DropPoint, "Gate 4: Gokongwei Gate");
		        		break;
		        	case 3:
		        		strcpy(app[*userCounter].DropPoint, "Gate 2: North Gate");
		        		break;
		        	case 4:
		        		strcpy(app[*userCounter].DropPoint, "Gate 1: South Gate");
		        		break;
		        	default:
		        		printf("Invalid choice. Please try again.\n");
	                    break;
				}
			}while(choice5 != 1 && choice5 != 2 && choice5 != 3 && choice5 != 4); // Repeat until a valid choice (1 to 4) is entered
	        
	    } else {
	    	do{
	    		exits = "Buendia";
		        printf("========== Buendia =============\n\n");
		        printf("1. drop-off point  College of St. Benilde (CSB)\n");
		        printf("2. drop-off point  Gate 4: Gokongwei Gate\n");
		        printf("3. drop-off point  Gate 2: North Gate (HSSH)\n");
		        printf("4. drop-off point  Gate 1: South Gate (LS Building Entrance)\n");
		        printf("Enter your choice: ");
		        scanf("%d", &choice6);
		        switch (choice6){
		        	case 1:
		        		strcpy(app[*userCounter].DropPoint, "College of St. Benilde");
		        		break;
		        	case 2:
		        		strcpy(app[*userCounter].DropPoint, "Gate 4: Gokongwei Gate");
		        		break;
		        	case 3:
		        		strcpy(app[*userCounter].DropPoint, "Gate 2: North Gate");
		        		break;
		        	case 4:
		        		strcpy(app[*userCounter].DropPoint, "Gate 1: South Gate");
		        		break;
		        	default:
		        		printf("Invalid choice. Please try again.\n");
	                    break;
				}
			}while(choice6 != 1 && choice6 != 2 && choice6 != 3 && choice6 != 4); // Repeat until a valid choice (1 to 4) is entered       
    	}
	}
	(*userCounter)++;
}
/* This function is for viewing the recent trip
    @param appointment app[]
    @param userCounter

*/
void ViewRecentTrip(appointment app[]){
    int i;
	char fileName[50];  // FIXED: Increased buffer size for safety
	FILE *fp_in;

    printf ("Enter the date you want to view with this format Trip-DD-MM-YYYY: "); // Allows the user to specify the filename of the text file the user want to view
	scanf ("%49s", fileName);  // FIXED: Added field width limit
    fp_in = fopen (fileName, "r"); // opens the file to read and scan into the array of structs
					
	if (fp_in == NULL){
        perror("Cannot Find File, Please Try Again.\n");
        return;  // FIXED: Added return to prevent further processing
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
*/
void ExitMenu(appointment app[], int userCounter, char *currentDate){
    int i;
	FILE *fp_out1;
	char filename[50];  // FIXED: Create local copy to avoid modifying original
	
	strcpy(filename, currentDate);
	strcat(filename, ".txt");
    fp_out1 = fopen (filename, "w"); // Exports all current data into the current date
    
    if (fp_out1 == NULL) {  // FIXED: Added file open check
        perror("Error opening file for writing");
        return;
    }
    
    for (i = 0; i < userCounter; i++){
      if (i == 0 || app[i].tripNum != app[i - 1].tripNum || strcmp(app[i].place, app[i - 1].place) != 0) {
            fprintf(fp_out1, "\nAE%d\n", app[i].tripNum);// Prints trip number to text file
            fprintf(fp_out1, "%s\n", app[i].place); // Print embarkation place to text file
        }
            
        fprintf(fp_out1, "%s, %s\n", app[i].lname, app[i].fname);// Prints passenger information
        fprintf(fp_out1, "%d\n", app[i].idNum); // Prints passenger information
        fprintf(fp_out1, "%d\n", app[i].priority);// Prints priority number
        fprintf(fp_out1, "%s\n\n", app[i].DropPoint); // Prints drop off point
    }
    fclose (fp_out1);
}

void SearchPassenger(appointment app[], int *userCounter){
	int found = 0;
	string20 temp;
	int i;
	
	printf("Passenger's Lastname: ");
	scanf("%19s", temp);  // FIXED: Added field width limit
    for (i = 0; i < *userCounter; ++i) {  // FIXED: Changed <= to <
        if (strcmp(app[i].lname, temp) == 0) {
        	printf("========== Search =============\n");
            printf("Passenger found:\n");
            printf("Trip Number: AE%d\n", app[i].tripNum);
            printf("Place: %s\n", app[i].place);
            printf("Name: %s, %s\n", app[i].lname, app[i].fname);
            printf("ID Number: %d\n", app[i].idNum);
            printf("Priority: %d\n", app[i].priority);
            printf("Drop Point: %s\n", app[i].DropPoint);
            printf("================================\n");
            found = 1;
        }
    }
    if (!found) {
        printf("Passenger with last name '%s' not found.\n", temp);  // FIXED: Use temp instead of app[*userCounter].lname
    }
}
/* This function is for loading passenger information it will be an alternative way to input passenger information
	it will read the passenger info and the trip number from a text file.
	@param	app[] - 
	@param userCounter -  
*/
void loadPassengerInfo(appointment app[], int *userCounter) {
	int i;
	char fileName[50];  // FIXED: Increased buffer size
	int newUserCounter = 0; // Counter for the number of new passengers imported
	
	FILE *fp_in;
	printf ("Enter File Name of Data to Import: "); // Allows the user to specify the filename of the text file to import
	scanf ("%49s", fileName);  // FIXED: Added field width limit
					
	fp_in = fopen (fileName, "r"); // opens the file to read and scan into the array of structs
					
	if (fp_in == NULL){
		perror("Cannot Find File, Please Try Again.\n");
		return;  // FIXED: Added return
	}	
    // Read and store data from the file
    while (fscanf(fp_in, "AE%d\n", &app[*userCounter].tripNum) == 1) {
        fscanf(fp_in, "%[^\n]\n", app[*userCounter].place);
        fscanf(fp_in, "%[^,], %s%d%d\n", app[*userCounter].lname, app[*userCounter].fname,
                                        &app[*userCounter].priority, &app[*userCounter].idNum);
        fscanf(fp_in, "%[^\n]\n", app[*userCounter].DropPoint);

        // Increment userCounter for the next appointment
        (*userCounter)++;
        newUserCounter++;
    }
    printf("Data imported successfully. Number of passengers: %d\n", newUserCounter);
	fclose (fp_in);	
}
/* This function is for comparing the priority of the user
	@param app[] - the array of structs containing user information 
	@param userCounter - the number of appointments in the app array
*/
void sort_appointments(appointment app[], int size) {
    int i;
    appointment temp[MAX_USERS];
	int count[MAX_PRIORITY + 1] = {0};
    
    for (i = 0; i < size; ++i) {// For counting occurrences of each priority
        ++count[app[i].priority];
    }

    // Update the counting array to store the position of each priority
    for (i = 1; i <= MAX_PRIORITY; ++i) {
        count[i] += count[i - 1];
    }

    // Build the sorted array
    for (i = size - 1; i >= 0; --i) {
        temp[--count[app[i].priority]] = app[i];
    }

    // Copy the sorted array back to the original array
    for (i = 0; i < size; ++i) {
        app[i] = temp[i];
    }
}
/*This function is for viewing passenger information. It is for displaying the list of names, ID numbers
	and priority numbers 
	@param app[] - the array of structs containing user information
	@param userCounter - the index of the user to be added
	@param tripNumber - representing the trip number for which the passenger information needs to be displayed
*/
void ViewPassengerInfo(appointment app[], int *userCounter, int tripNumber){
	int i;
	
    for (i = 0; i < *userCounter; i++) {
        if (app[i].tripNum == tripNumber) {
        	printf("===========================\n");
            printf("%s, %s\n", app[i].lname, app[i].fname);
            printf("ID Number: %d\n", app[i].idNum);
            printf("Priority: %d\n", app[i].priority);
        }
    }
}
int CountPassengersForTrip(appointment app[], int userCounter, int tripNumber) {
    int count = 0;
    int i;
    
    for (i = 0; i < userCounter; i++) {  // FIXED: Changed <= to <
        if (app[i].tripNum == tripNumber) {
            count++;
        }
    }
    return count;
}

void displaySeatArrangement(int numPassengers) {
	int i;
	
    printf("-------------------\n");
    for (i = 1; i <= 14; i++) {
        if (i == 14) {
            printf("|  %s  |\n", numPassengers > 13 ? "X" : "DRIVER");
        } else {
            printf("|  %s  ", i <= numPassengers ? "X" : "O");
        }
        if (i % 3 == 0 && i != 14) {
            printf("|\n-------------------\n");
        }
    }
}

// FIXED: Added implementation for counting passengers by drop-off point
void CountPassengersByDropOff(appointment app[], int userCounter) {
    int i, j;
    string50 dropPoints[MAX_USERS];
    int counts[MAX_USERS];
    int numUniqueDrops = 0;
    int found;
    
    // Count occurrences of each drop-off point
    for (i = 0; i < userCounter; i++) {
        found = 0;
        // Check if this drop-off point has been counted
        for (j = 0; j < numUniqueDrops; j++) {
            if (strcmp(app[i].DropPoint, dropPoints[j]) == 0) {
                counts[j]++;
                found = 1;
                break;
            }
        }
        // If not found, add new drop-off point
        if (!found) {
            strcpy(dropPoints[numUniqueDrops], app[i].DropPoint);
            counts[numUniqueDrops] = 1;
            numUniqueDrops++;
        }
    }
    
    // Display the results
    printf("==============================================\n");
    printf("Passenger Count by Drop-off Point:\n");
    printf("==============================================\n");
    for (i = 0; i < numUniqueDrops; i++) {
        printf("%s: %d passenger(s)\n", dropPoints[i], counts[i]);
    }
    printf("==============================================\n");
}

/*This function is for Viewing the number of passengers on a certain trip, View the count of passengers of a specific drop-off point
  View passenger information, Load passenger information, Search passenger, and View any recent trip files via a file load feature.
	@param app[] - the array of structs containing user information
	@param userCounter - the index of the user to be added
	@param *currentDate - The current date inputted by the user
*/
void Personnel(appointment app[],int userCounter, char *currentDate){
	int choice;
	int tripNumber;
	int passengerCount;
	char choice2;
	
	
	do{
	printf("========== Arrow Express Personnel =============\n");
	printf("Number of Passengers: %d\n", userCounter);
	printf("1. View the number of passengers\n");
	printf("2. View the count of passengers by drop-off point\n");
	printf("3. View passenger information\n");
	printf("4. Load passenger information\n");
	printf("5. Search passenger\n");
	printf("6. View any recent trip files via a file load feature.\n");
	printf("7. Exit to Main Menu\n");  // FIXED: Added explicit exit option
	printf("Enter your choice: ");
	scanf("%d", &choice);
	switch(choice){
		case 1:
			printf("==============================================\n");
			printf("Enter the trip number: ");
            scanf("%d", &tripNumber);
            passengerCount = CountPassengersForTrip(app, userCounter, tripNumber);
            printf("Number of passengers for trip %d: %d\n", tripNumber, passengerCount);
            printf("Seat arrangement:\n");
            displaySeatArrangement(passengerCount);
			break;
		case 2:
			CountPassengersByDropOff(app, userCounter);  // FIXED: Added implementation
			break;
		case 3:
			printf("==============================================\n");
			printf("Enter the trip number: ");
            scanf("%d", &tripNumber);
            sort_appointments(app, userCounter);
			ViewPassengerInfo(app, &userCounter, tripNumber);
			break;
		case 4:
			loadPassengerInfo(app, &userCounter);
			break;
		case 5:
			SearchPassenger(app, &userCounter);
			break;
		case 6:
			do{
				ViewRecentTrip(app);
				printf("\n==============================================\n");
				printf("Do you want to view another file? Y/N or B to go Back \n");
				printf("Enter your choice: ");
				scanf(" %c", &choice2); // Read the character for user input
				    while(getchar() != '\n'); // Consume any remaining characters in the input buffer, including the newline
				if (choice2 == 'B' || choice2 == 'b'){
					break;  // Exit the file viewing loop
				}
			} while (choice2 == 'Y' || choice2 == 'y');
			break;
		case 7:
			break;  // Exit to main menu
		default:
			printf("Invalid choice. Please try again.\n");
	}
	}while(choice != 7); // FIXED: Changed exit condition to match the exit option
}
/* This function contains the menu for asking if the user is personnel or a passenger.
	@param app[] - the array of structs containing user information
	@param userCounter - the index of the user to be added
	@param currentDate - The current date inputted by the user.
*/
void PassengerOrPersonnel(appointment app[], int *userCounter, char *currentDate){
	int choice;
	char choice2, choice3;

	do{
		printf("=============== MENU ================\n");
		printf("Number of Passengers: %d\n", *userCounter);
		printf("Please pick which user are you.\n");
	    printf("1. Passenger\n");
	    printf("2. Arrows Express Personnel\n");
	    printf("3. Exit\n");
	    printf("Enter your choice: ");
	    scanf("%d", &choice);
	    switch(choice){
	        case 1:
	        	do{
	        		Passenger(app, userCounter);
	        		printf("==============================================\n");
					printf("Add more passengers? (Y/N Choosing N will go back to the Menu.)\n");
					printf("Enter your choice: ");
				    scanf(" %c", &choice2); // Read the character for user input
				    while(getchar() != '\n'); // Consume any remaining characters in the input buffer, including the newline
				} while (choice2 == 'Y' || choice2 == 'y');  // FIXED: Simplified loop condition
				break;
	        case 2:
	            do{
	        		Personnel(app, *userCounter, currentDate);
	        		printf("==============================================\n");
					printf("Do you still want to view the Personnel Menu? (Y/N Choosing N will go back to the Main Menu.) \n");
					printf("Enter your choice: ");
				    scanf(" %c", &choice3); // Read the character for user input
				    while(getchar() != '\n'); // Consume any remaining characters in the input buffer, including the newline
				} while (choice3 == 'Y' || choice3 == 'y');  // FIXED: Simplified loop condition
	            break;
	        case 3:
	        	ExitMenu(app, *userCounter, currentDate);
	        	break;
	        default:
                printf("Invalid choice. Please try again.\n");
	    }	
	}while(choice != 3); // FIXED: Changed to exit when choice is 3
}