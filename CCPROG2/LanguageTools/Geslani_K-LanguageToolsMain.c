/*********************************************************************************************************
This is to certify that this project is my own work, based on my personal efforts in studying and applying the concepts 
learned. I have constructed the functions and their respective algorithms and corresponding code by myself. The 
program was run, tested, and debugged by my own efforts. I further certify that I have not copied in part or whole or 
otherwise plagiarized the work of other students and/or persons.
Geslani, Keila Franchoise Leigh, DLSU ID# 12206997
*********************************************************************************************************/
#include "Geslani_K-LanguageTool.c"


int 
main()
{
	entry entries[MAX_ENTRIES];
	int entryCount = 0;
	int choice;
	int stopper = 0;
	
	while (stopper == 0)
	{
		printf("==Main Menu==\n");
		printf("1. Manage Data\n");
		printf("2. Language Tools\n");
		printf("3. Exit\n");
		printf("Enter your choice: ");
		scanf(" %d", &choice);
		getchar();
			
		switch (choice)
		{
			case 1:
				manageData(entries, &entryCount);
				break;
			case 2:
				languageTools(entries, &entryCount);
				break;
			case 3:
                stopper = 1;
				break;
			default:
                printf("Invalid choice. Please try again.\n");
		}	
	}
	return 0;
}


