/*********************************************************************************************************
This is to certify that this project is my own work, based on my personal efforts in studying and applying the concepts 
learned. I have constructed the functions and their respective algorithms and corresponding code by myself. The 
program was run, tested, and debugged by my own efforts. I further certify that I have not copied in part or whole or 
otherwise plagiarized the work of other students and/or persons.
Geslani, Keila Franchoise Leigh, DLSU ID# 12206997
*********************************************************************************************************/

#include "DataManagementMenu_v7_fixed.c"

int main(){
    int choice;
    char currentDate[20];  // FIXED: Increased size for safety
    appointment app[MAX_USERS];
    int user = 0;
    char day[3];
    char month[3];
    char year[5];
    
    printf("Enter day (DD): ");
    scanf("%2s", day); // Read up to 2 characters to accommodate DD format
    printf("Enter month (MM): ");
    scanf("%2s", month); // Read up to 2 characters to accommodate MM format
    printf("Enter year (YYYY): ");
    scanf("%4s", year); // Read up to 4 characters to accommodate YYYY format
    strcpy(currentDate, "Trip-");
    strcat(currentDate, day);
    strcat(currentDate, "-");
    strcat(currentDate, month);
    strcat(currentDate, "-");
    strcat(currentDate, year);
    
    printf("%s\n", currentDate);

	PassengerOrPersonnel(app, &user, currentDate);
    ExitMenu(app, user, currentDate);
    
	return 0;
}