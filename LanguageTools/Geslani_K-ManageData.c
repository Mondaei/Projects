/*********************************************************************************************************
This is to certify that this project is my own work, based on my personal efforts in studying and applying the concepts 
learned. I have constructed the functions and their respective algorithms and corresponding code by myself. The 
program was run, tested, and debugged by my own efforts. I further certify that I have not copied in part or whole or 
otherwise plagiarized the work of other students and/or persons.
Geslani, Keila Franchoise Leigh, DLSU ID# 12206997
*********************************************************************************************************/
#include "Geslani_K-struct.h"

int checkAndDisplayExistingEntries(entry entries[], int *entryCount, const char *language, const char *translation);
void addEntry(entry entries[], int *entryCount);
void deleteEntry(entry entries[], int *entryCount);
void deleteTranslation(entry entries[], int *entryCount);
void displaytheEntries(entry *entries);
void displayAllEntries(entry entries[], int *entryCount);
void searchWord(entry entries[], int *entryCount);
void searchTranslation(entry entries[], int *entryCount);
void addTranslations(entry entries[], int *entryCount);
void exportData(entry entries[], int *entryCount);
void importData(entry entries[], int *entryCount);
void clearData(entry entries[], int *entryCount);
void displaysforModifyDelete(entry *entries);
void modifyEntry(entry entries[], int *entryCount);
void manageData(entry entries[], int *entryCount);

/*checkAndDisplayExistingEntries checks for duplicated pairs and prints first the matching translation-pair
	after showing the matching translation-pair, it will show other entries 
@param entries - structure that contains the language and translation pair and the number of pairs in the entry
@param entryCount - the number of entry
@param language - the language that needs checking 
@param translation - the translation that needs checking
return 1 if the user decided to add a new entry and returns 0 if the user decided its not a new entry
*/
int 
checkAndDisplayExistingEntries(entry entries[], 
									int *entryCount, 
									const char *language, 
									const char *translation) 
{
    
    int i, j, k;
	int index = -1;
	int found = 0;
	char isNewEntry;
	int matchFound;

    
    for (i = 0; i < *entryCount; i++) 
    {
        matchFound = 0;
        for (j = 0; j < entries[i].count; j++) 
        {
            if (strcmp(entries[i].pairs[j].language, language) == 0 &&
                strcmp(entries[i].pairs[j].translation, translation) == 0) 
            {
                matchFound = 1;
                found = 1;
            }
        }

        if (matchFound) 
        {
            printf("\n===========================\n"); 
			printf("Language    | Translation\n");
            printf("------------|----------------\n");
            
			for (j = 0; j < entries[i].count; j++) 
            {
                printf("%-12s | %-12s\n", entries[i].pairs[j].language, entries[i].pairs[j].translation);
            }
            
			printf("\n");
        }
    }

    if (found) 
    {
	    for (i = 0; i < *entryCount; i++) 
	    {
	        matchFound = 0;
	        
			for (j = 0; j < entries[i].count; j++) 
	        {
	            if (strcmp(entries[i].pairs[j].language, language) == 0 &&
	                strcmp(entries[i].pairs[j].translation, translation) == 0) 
	            {
	                matchFound = 1;
	            }
	        }
	
	        if (!matchFound && entries[i].count > 0) 
	        {
	            printf("\n===========================\n"); 
				printf("Language    | Translation\n");
	            printf("------------|----------------\n");
	            
				for (j = 0; j < entries[i].count; j++) 
	            {
	                printf("%-12s | %-12s\n", entries[i].pairs[j].language, entries[i].pairs[j].translation);
	            }
	            printf("\n");
	        }
	    }
        
		do 
        {
            printf("Is this a new entry? Y/N \n");
            scanf(" %c", &isNewEntry);
			getchar();

            if (isNewEntry == 'Y' || isNewEntry == 'y') 
            {
                return 1; 
            }
			else if (isNewEntry == 'N' || isNewEntry == 'n') 
            {
                return 0;  // FIXED: Return 0 instead of recursively calling manageData
            }
        } while (isNewEntry != 'Y' && isNewEntry != 'y' && isNewEntry != 'N' && isNewEntry != 'n');
    }

    return 0;
}
/*addEntry is for adding a new entry, it asks for a language-translation pair
@param entries - structure that contains the language and translation pair and the number of pairs in the entry
@param entryCount - the number of entry
returns to the Manage Data Menu if the user decided to not add any more pairs.
*/
void 
addEntry(entry entries[], 
			int *entryCount)
{
    int i, j;
    int found = 0;
    int delOrBack;
    char addMorePairs;
    int currentEntry = *entryCount;
	
	if (*entryCount >= MAX_ENTRIES)
	{
		do
		{
			printf("Maximum entries reached.\n");
			printf("You need to delete an entry first.\n");
			printf("Do you want to go delete an entry? or go back to the Manage Data Menu?\n");
			printf("Press 1 if you want to delete an entry.\n");
			printf("Press 2 if you want to go back to the Manage Data Menu.\n");
			scanf(" %d", &delOrBack);
			getchar();
			
			switch (delOrBack)
			{
				case 1:
					deleteEntry(entries, entryCount);  // FIXED: Removed &*
					break;
				case 2:
					return;  // FIXED: Just return instead of calling manageData
				default:
	                printf("Invalid choice. Please try again.\n");
	    	}
    	}while(delOrBack != 1 && delOrBack != 2);
	}
	
	printf("=== Add Entry ===\n");
	printf("Number of Entries %d\n", *entryCount);
        
	printf("Enter language: ");
	scanf(" %20s", entries[currentEntry].pairs[entries[currentEntry].count].language);
	printf("Enter translation: ");
	scanf(" %20s",  entries[currentEntry].pairs[entries[currentEntry].count].translation);
	getchar();
	
	found = checkAndDisplayExistingEntries(entries, entryCount,
                                        entries[currentEntry].pairs[entries[currentEntry].count].language,
                                        entries[currentEntry].pairs[entries[currentEntry].count].translation);
	
	if (!found)
	{
		entries[currentEntry].count++;
		(*entryCount)++;
		printf("Entry added successfully!\n");
		
		while (entries[currentEntry].count < MAX_PAIRS)
		{
			printf("\n===========================\n"); 
			printf("Do you want to add a pair? \n");
			printf("Y to add and press any letter to go back to the Manage Data Menu\n");
			printf("Choice: ");
			scanf(" %c", &addMorePairs);
			getchar();
			
			if (addMorePairs == 'Y' || addMorePairs == 'y')
			{
				printf("Enter language: ");
				scanf(" %20s", entries[currentEntry].pairs[entries[currentEntry].count].language);
				printf("Enter translation: ");
				scanf(" %20s", entries[currentEntry].pairs[entries[currentEntry].count].translation);
				getchar();
				entries[currentEntry].count++;
				
				printf("Added new pair:\n");
			}
			else
			{
				return;
			}
		}
	}	
}
/*deleteEntry is for deleting an entry, all language-translation pair are included in the deletion
@param entries - structure that contains the language and translation pair and the number of pairs in the entry
@param entryCount - the number of entry
returns if an invalid number of entry is given and if the user decided to exit the deleteEntry page.
*/
void 
deleteEntry(entry entries[],
				 int *entryCount) 
{
	int currentEntry = 0;
	int index, i, j;
	int stopper = 0;
	char command;
	
	if (*entryCount == 0)
	{
		printf("No entries to delete.\n");
		return;
	}
	
	while (stopper == 0)
	{
		displaysforModifyDelete(&entries[currentEntry]);
        
        printf("Enter command (D = Delete Entry, N = Next, P = Previous, X = Exit): ");
        scanf(" %c", &command);
		getchar();
        
        switch (command)
    	{
    		case 'D':
    		case 'd':
    			for (i = 0; i < *entryCount; i++) 
				{
			        printf("Entry %d:\n", i + 1);
			        printf("\n===========================\n"); 
					printf("Language    | Translation\n");
		            printf("------------|----------------\n");
			        
					for (j = 0; j < entries[i].count; j++) 
					{
			            printf("%s | %s\n", entries[i].pairs[j].language, entries[i].pairs[j].translation);
			        }
			        
					printf("\n");
			    }
			    
			    printf("Enter the number of the entry to delete: ");
			    scanf("%d", &index);
				getchar();
			
			    
			    if (index < 1 || index > *entryCount) 
				{
			        printf("Invalid entry number. Returning to menu.\n");
			        
					return;
			    }
			
			    
			    for (i = index - 1; i < *entryCount - 1; i++) 
				{
			        entries[i] = entries[i + 1];
			    }
			    
				(*entryCount)--;
			
			    printf("Entry deleted successfully.\n");
				
				if (currentEntry >= *entryCount && currentEntry > 0)
				{
					currentEntry--;
				}
			    break;
			case 'N':
			case 'n':
				if (currentEntry < *entryCount - 1) 
				{
                    currentEntry++;
                }
                else
				{
					printf("\n===========================\n");  
                	printf("No more entries to display.\n");
				}
				break;
			case 'P':
			case 'p':
				if (currentEntry > 0) 
				{
                    currentEntry--;
                }
                else
                {
                	printf("\n===========================\n"); 
                	printf("No more entries to display.\n");
				}
				break;
			case 'X':
			case 'x':
				stopper = 1;
				printf("\n===========================\n"); 
                return;  // FIXED: Just return
			default:
                printf("Invalid command.\n");
                break;
		}	        
    }
}

/* deleteTranslation is for deleting a language-translation pair
@param entries - structure that contains the language and translation pair and the number of pairs in the entry
@param entryCount - the number of entry
returns if there are no more language-translation pair available, if the entire entry has been deleted, and if the user
	decided to exit the deleteTranslation page.
*/
void
deleteTranslation(entry entries[], 
					int *entryCount)
{
	char command;
	int pairNum;
	int currentEntry = 0;
	int stopper = 0;
	int modify = 0;
	int i;
	char choice;
	
	if (*entryCount == 0)
	{
		printf("No entries available.\n");
		return;
	}
	
	while (stopper == 0)
	{
		displaysforModifyDelete(&entries[currentEntry]);
		
		printf("Enter command (D = Delete Translation, N = Next, P = Previous, X = Exit): ");
        scanf(" %c", &command);
		getchar();
        
        switch (command)
    	{
    		case 'D':
    		case 'd':
    			if (entries[currentEntry].count == 0)
			    {
			    	printf("There are no language-pair available to delete in this entry.\n");
			        return;
				}
				do
				{
					printf("\nEnter the pair number to delete (1 to %d): ", entries[currentEntry].count);
    				scanf("%d", &pairNum);
    				getchar();
					
    				if (pairNum < 1 || pairNum > entries[currentEntry].count) 
					{
			            printf("Invalid pair number.\n");
			            choice = 'N';
			        }
			        else
			        {
			        	pairNum--;
					
						for (i = pairNum; i < entries[currentEntry].count - 1; i++) 
						{
					    	entries[currentEntry].pairs[i] = entries[currentEntry].pairs[i + 1];
					    }
					        
					    entries[currentEntry].count--;
					        
					        
					    if (entries[currentEntry].count == 0) 
						{    
							for (i = currentEntry; i < *entryCount - 1; i++) 
							{
			                    entries[i] = entries[i + 1];
			                }
							(*entryCount)--;
							stopper = 1;
							printf("There are no pairs left. \n");
							printf("The entire entry has been deleted.\n");
							return;
					    }
					        
					    printf("Pair deleted successfully.\n");
					}
					
					if (entries[currentEntry].count > 0) 
					{
			            displaysforModifyDelete(&entries[currentEntry]);
			            
						printf("Do you want to delete another pair from this entry? Y/N: ");
			            scanf(" %c", &choice);
			            getchar();
			        }
			        
			        if (choice == 'N' || choice == 'n') 
					{
				        stopper = 1;
						printf("\n===========================\n"); 
				        printf("Returning to the Menu.\n");
				        printf("\n===========================\n"); 
						return;
				    }
				}while ((choice == 'Y' || choice == 'y') && entries[currentEntry].count > 0);
			    break;
			case 'N':
			case 'n':
				if (currentEntry < *entryCount - 1) 
				{
                    currentEntry++;
                }
                else
				{
					printf("\n===========================\n");  
                	printf("No more entries to display.\n");
				}
				break;
			case 'P':
			case 'p':
				if (currentEntry > 0) 
				{
                    currentEntry--;
                }
                else
                {
                	printf("\n===========================\n"); 
                	printf("No more entries to display.\n");
				}
				break;
			case 'X':
			case 'x':
				stopper = 1;
				printf("\n===========================\n"); 
                return;  // FIXED: Just return
			default:
                printf("Invalid command.\n");
                break;
		}	        
    }
}
	
/* displaytheEntries where the entries are sorted and display for the function displayAllEntries.
@param entries - structure that contains the language and translation pair and the number of pairs in the entry
*/
void
displaytheEntries(entry *entries)
{
	int j, k;
    
    for (j = 0; j < entries->count - 1; j++) 
    {
        for (k = j + 1; k < entries->count; k++) 
        {
            if (strcmp(entries->pairs[j].language, entries->pairs[k].language) > 0) 
            {
                pair temp = entries->pairs[j];
                entries->pairs[j] = entries->pairs[k];
                entries->pairs[k] = temp;
            }
        }
    }
    
    printf("\n===========================\n"); 
    printf("Language | Translation\n");
    printf("------------|----------------\n");
    
	for (j = 0; j < entries->count; j++) 
    {
        printf("%-12s | %-13s\n", entries->pairs[j].language, entries->pairs[j].translation);
    }
    
	printf("\n");
}

/* displayAllEntries is the menu for displaying all the sorted entries. 
@param entries - structure that contains the language and translation pair and the number of pairs in the entry
@param entryCount - the number of entry
returns if the user decided to exit the displayAllEntries page.
*/
void 
displayAllEntries(entry entries[], 
					int *entryCount) 
{
    char command;
    int currentEntry = 0;
    int stopper = 0;
    
    if (*entryCount == 0)
	{
		printf("No entries to display.\n");
		return;
	}
	
    while (stopper == 0) 
	{
        if (currentEntry >= *entryCount) 
		{
            printf("No more entries.\n");
            return;
        }
        
		
        displaytheEntries(&entries[currentEntry]);
        
        printf("Enter command (N = Next, P = Previous, X = Exit): ");
        scanf(" %c", &command);
		getchar();

        switch (command) 
		{
            case 'N':
            case 'n':
				if (currentEntry < *entryCount - 1) 
				{
                    currentEntry++;
                }
                else
				{
					printf("\n===========================\n");  
                	printf("No more entries to display.\n");
				}
                break;
            case 'P':
            case 'p':
                if (currentEntry > 0) 
				{
                    currentEntry--;
                }
                else
                {
                	printf("\n===========================\n"); 
                	printf("No more entries to display.\n");
				}
                break;
            case 'X':
            case 'x':
            	printf("\n===========================\n"); 
                stopper = 1;
				return;
            default:
                printf("Invalid command.\n");
                break;
        }
    }
}

/* searchWord is for asking for an input word, then the program proceeds to show a listing of all entries 
	where that input word appears as a translation. Display is similar to how the Display All Entries 
	work (with a way to view next, previous, and exit) but only those that matches the given word.
@param entries - structure that contains the language and translation pair and the number of pairs in the entry
@param entryCount - the number of entry
returns if the user decided to exit the searchWord page.
*/
void 
searchWord(entry entries[], 
			int *entryCount) 
{
    char search[MAX_TRANSLENGTH];
    int matchCount = 0;
    int found = 0;
    int currentIndex = 0;
    entry matchingEntries[MAX_ENTRIES];
    int i, j;
    int choice;
    
    printf("Enter the word to search for: ");
    scanf("%s", search);
	getchar();

    
    for ( i = 0; i < *entryCount; i++) 
	{
        for ( j = 0; j < entries[i].count; j++) 
		{
            if (strcmp(entries[i].pairs[j].translation, search) == 0) 
			{
                matchingEntries[matchCount++] = entries[i];
                break;  // FIXED: Added break to avoid duplicates
            }
        }
    }

    if (matchCount == 0) 
	{
		printf("\n===========================\n");
        printf("No entries match the word '%s'.\n", search);
        return;
    }

    while (1) 
	{
        if (currentIndex >= matchCount) 
		{
            currentIndex = matchCount - 1;
        } 
		else if (currentIndex < 0) 
		{
            currentIndex = 0;
        }
        
        printf("\n===========================\n");
		printf("\nDisplaying entry %d of %d:\n", currentIndex + 1, matchCount);
        displaytheEntries(&matchingEntries[currentIndex]);
        
        printf("\n===========================\n");
        printf("\nOptions:\n");
        printf("1. Next\n");
        printf("2. Previous\n");
        printf("3. Exit\n");
        
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1: 
                currentIndex++;
                break;
            case 2: 
                currentIndex--;
                break;
            case 3: 
                return;
            default:
                printf("Invalid choice. Please enter 1, 2, or 3.\n");
        }
    }
}

/* searchTranslation searches for a translation in the entries array 
@param entries - structure that contains the language and translation pair and the number of pairs in the entry
@param entryCount - the number of entry
returns if there's no match or the user decided to exit the searchTranslation page.
*/
void
searchTranslation(entry entries[], 
					int *entryCount)
{
	String20 language;
	String20 translation;
    int matchCount = 0;
    int found = 0;
    int currentIndex = 0;
    entry matchingEntries[MAX_ENTRIES];
    int i, j;
    int choice;
    
    printf("Enter the Language to search for: ");
    scanf("%s", language);
    printf("Enter the Translation to search for: ");
    scanf("%s", translation);
    getchar();
    
    for ( i = 0; i < *entryCount; i++) 
	{
        for ( j = 0; j < entries[i].count; j++) 
		{
            if (strcmp(entries[i].pairs[j].language, language) == 0 &&
				strcmp(entries[i].pairs[j].translation, translation) == 0) 
			{
                matchingEntries[matchCount++] = entries[i];
                break;  // FIXED: Added break to avoid duplicates
            }
        }
    }
    
    if (matchCount == 0) 
	{
		printf("\n===========================\n");
        printf("No entries match the pair '%s' '%s'.\n", language, translation);
        return;
    }
    
    while (1) 
	{
        if (currentIndex >= matchCount) 
		{
            currentIndex = matchCount - 1;
        } 
		else if (currentIndex < 0) 
		{
            currentIndex = 0;
        }
        
        printf("\n===========================\n");
		printf("\nDisplaying entry %d of %d:\n", currentIndex + 1, matchCount);
        displaytheEntries(&matchingEntries[currentIndex]);
        
        printf("\n===========================\n");
        printf("\nOptions:\n");
        printf("1. Next\n");
        printf("2. Previous\n");
        printf("3. Exit\n");
        
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) 
		{
            case 1: 
                currentIndex++;
                break;
            case 2: 
                currentIndex--;
                break;
            case 3: 
                return;
            default:
                printf("Invalid choice. Please enter 1, 2, or 3.\n");
        }
    }
}
/* addTranslations adds a new translation to the entries array 
@param entries - array of entries 
@param entryCount - the number of entries in the array
returns if No existing entry, entry is full, or the user decided to not add translation anymore
*/
void 
addTranslations(entry entries[], 
					int *entryCount)
{
	String20 language;
	String20 translation;
	int i, j;
    int choice;
    char response;
	int found = 0;
    int index = 0;
    int matchFound = 0;
    
    printf("Enter language: ");
	scanf(" %20s", language);
	printf("Enter translation: ");
	scanf(" %20s",  translation);
	getchar();
	
	for (i = 0; i < *entryCount; i++) 
    {
        for (j = 0; j < entries[i].count; j++) 
        {
            if (strcmp(entries[i].pairs[j].language, language) == 0 && 
                strcmp(entries[i].pairs[j].translation, translation) == 0) 
            {
                found = 1;
                index = i;
                break;  // FIXED: Added break
            }
        }
        if (found) break;  // FIXED: Added break
    }
    
    if (found == 0) 
    {
        printf("\n===========================\n\n"); 
		printf("No existing entry with the indicated language and translation pair.\n");
        printf("Please use the Add Entry option first.\n\n");
        
		return;
    }
    
    if (entries[index].count == 1) 
    {
        printf("\n===========================\n");  
		printf("Enter language: ");
		scanf(" %20s", entries[index].pairs[entries[index].count].language);
		printf("Enter translation: ");
		scanf(" %20s",  entries[index].pairs[entries[index].count].translation);
		getchar();
	
	    entries[index].count++;
    } 
    
    else
    {
	    for (i = 0; i < *entryCount; i++) 
	    {
	        matchFound = 0;
	        
	        for (j = 0; j < entries[i].count; j++) 
	        {
	            if (strcmp(entries[i].pairs[j].language, language) == 0 &&
	                strcmp(entries[i].pairs[j].translation, translation) == 0) 
	            {
	                matchFound = 1;
	                break;  // FIXED: Added break
	            }
	        }
	
	        if (matchFound) 
	        {
				printf("\n===========================\n"); 
	            printf("Language    | Translation\n");
	            printf("------------|----------------\n");
	            printf("Entry: %d\n", i + 1);
				for (j = 0; j < entries[i].count; j++) 
	            {
	                printf("%-12s | %-12s\n", entries[i].pairs[j].language, entries[i].pairs[j].translation);
	            }
	            
				printf("\n");
	        }
    	}
        
		printf("Multiple entries found. Enter the entry number to add the translation: ");
        scanf("%d", &choice);
		getchar();

        if (choice > 0 && choice <= *entryCount) 
        {
            index = choice - 1;
            
			printf("\n===========================\n");
			printf("Enter language: ");
			scanf(" %20s", entries[index].pairs[entries[index].count].language);
			printf("Enter translation: ");
			scanf(" %20s",  entries[index].pairs[entries[index].count].translation);
			getchar();
	
	        entries[index].count++;
    	}
    	
    	else 
        {
            printf("Invalid entry number.\n");
            
			return;
        }
    }
    
    if (entries[index].count < 10) 
    {
        
        printf("Add more translations to the same entry? (Y/N): ");
        scanf(" %c", &response);
		getchar();

        while (response == 'Y' || response == 'y') 
        {
            printf("\n===========================\n");
			printf("Enter language: ");
			scanf(" %20s", entries[index].pairs[entries[index].count].language);
			printf("Enter translation: ");
			scanf(" %20s",  entries[index].pairs[entries[index].count].translation);
			getchar();
	
	        entries[index].count++;

            if (entries[index].count < 10) 
            {
                printf("Add more translations to the same entry? (Y/N): ");
                scanf(" %c", &response);
                getchar();
            } 
            else 
            {
            	printf("\n===========================\n\n"); 
                printf("Maximum number of translations reached.\n");
                return;
            }
        }
    } 
    
	else 
    {
        printf("Maximum number of translations reached.\n");
        return;
    }

    printf("\n===========================\n\n"); 
    
	return;
}

/* exportData exports the entries data to a file 
@param entries - array of entries 
@param entryCount - the number of entries in the array 
*/
void 
exportData(entry entries[], 
			int *entryCount) 
{
    FILE *fp;
	String30 fileName;
	int i, j;
	
	printf("Enter File Name of Data to Export: ");  // FIXED: Changed "Import" to "Export"
	scanf("%30s", fileName);
	getchar();
	
	if ((fp = fopen (fileName, "w")) != NULL)
	{
		for (i = 0; i < *entryCount; i++) 
		{
	        for (j = 0; j < entries[i].count; j++) 
			{
	            fprintf(fp, "%s: %s\n", entries[i].pairs[j].language, entries[i].pairs[j].translation);
	        }
	        
	        fprintf(fp, "\n");
		}
		
		fclose(fp);
	    printf("Data exported to %s successfully.\n", fileName);
    }
	else
	{
		printf("Error opening file for export.\n");
	}
    
	return;
}

/* importData imports data from a file into the entries array 
@param entries - array of entries 
@param entryCount - the number of entries in the array 
*/
void 
importData(entry entries[],
			 int *entryCount) 
{
    FILE *fp;
	String30 fileName;
	int i, j;
	char line[1024];
    int pairIndex = 0;
    char response;
    char choice;
	
	printf("Enter File Name of Data to Import: "); 
	scanf("%30s", fileName);
	getchar();
	
	if ((fp = fopen (fileName, "r")) != NULL)
	{
		while (fgets(line, 1024, fp))
		{
			if (line[0] == '\n')
			{
				if (pairIndex > 0)
				{
					printf("\n===========================\n\n");
					printf("Load entry:\n");
					
					for (i = 0; i < pairIndex; i++) 
					{
                    	printf("%s: %s\n",  entries[*entryCount].pairs[i].language, entries[*entryCount].pairs[i].translation);
                	}
                	
					printf("Add to list? (Y/N): ");
                	scanf(" %c", &response);
                	getchar();
                	
                	if (response == 'Y' || response == 'y') 
					{
	                    if (*entryCount < MAX_ENTRIES) 
						{
	                        entries[*entryCount].count = pairIndex;
                        	(*entryCount)++;
                        	
	                    } 
						else
						{
	                        printf("Entry list is full.\n");
	                    }
                	}
                	
                	pairIndex = 0;
				}	
			}
			
			else
			{
				char language[MAX_LANGUAGE_LENGTH], translation[MAX_TRANSLENGTH];
	            sscanf(line, "%[^:]: %s\n", language, translation);
	            
				if (pairIndex < MAX_PAIRS) 
				{
	                strcpy(entries[*entryCount].pairs[pairIndex].language, language);
                    strcpy(entries[*entryCount].pairs[pairIndex].translation, translation);
                    
					pairIndex++;
				}
			}
		}
		
		// FIXED: Handle last entry if file doesn't end with blank line
		if (pairIndex > 0)
		{
			printf("\n===========================\n\n");
			printf("Load entry:\n");
			
			for (i = 0; i < pairIndex; i++) 
			{
            	printf("%s: %s\n",  entries[*entryCount].pairs[i].language, entries[*entryCount].pairs[i].translation);
        	}
        	
			printf("Add to list? (Y/N): ");
        	scanf(" %c", &response);
        	getchar();
        	
        	if (response == 'Y' || response == 'y') 
			{
                if (*entryCount < MAX_ENTRIES) 
				{
                    entries[*entryCount].count = pairIndex;
                	(*entryCount)++;
                } 
				else
				{
                    printf("Entry list is full.\n");
                }
        	}
		}
		
		fclose(fp);
	    printf("Data imported from %s successfully.\n", fileName);
	}
	else
	{
		printf("Error opening file for import.\n");
	}

}
/* clearData clears the entries data 
@param entries - array of entries 
@param entryCount - the number of entries in the array  
*/
void 
clearData(entry entries[], 
			int *entryCount) 
{
	int i, j;
	
    *entryCount = 0;
    for (i = 0; i < MAX_ENTRIES; i++) 
	{
        entries[i].count = 0;
        for (j = 0; j < MAX_PAIRS; j++) 
		{
            entries[i].pairs[j].language[0] = '\0';
            entries[i].pairs[j].translation[0] = '\0';
        }
    }
}

/* displaysForModifyDelete displays the entries for modifyEntry, deleteTranslation, and deleteEntry
@param entries - pointer to the array of entries 
*/
void
displaysforModifyDelete(entry *entries)
{
	int j, k;
    
    for (j = 0; j < entries->count - 1; j++) 
    {
        for (k = j + 1; k < entries->count; k++) 
        {
            if (strcmp(entries->pairs[j].language, entries->pairs[k].language) > 0) 
            {
                pair temp = entries->pairs[j];
                entries->pairs[j] = entries->pairs[k];
                entries->pairs[k] = temp;
            }
        }
    }
    
    printf("\n===========================\n"); 
    printf("Language | Translation\n");
    printf("------------|----------------\n");
    
	for (j = 0; j < entries->count; j++) 
    {
        printf("%d. %-12s | %-13s\n", j+1, entries->pairs[j].language, entries->pairs[j].translation);
    }
    
	printf("\n");
}
/* modifyEntry modifies an existing entry in the entries array 
@param entries - array of entries 
@param entryCount - the number of entries in the array 
*/
void
modifyEntry(entry entries[], 
				int *entryCount)
{
	int stopper = 0;
	int currentEntry = 0;
	char command;
	int pairNum;
	int modify = 0;
	
	if (*entryCount == 0)
	{
		printf("No entries to modify.\n");
		return;
	}
	
	while (stopper == 0)
	{
		displaysforModifyDelete(&entries[currentEntry]);
		
		printf("Enter command (M = Modify, N = Next, P = Previous, X = Exit): ");
        scanf(" %c", &command);
    	getchar();

    	switch (command)
    	{
    		case 'M':
    		case 'm':
    			if (entries[currentEntry].count == 0)
			    {
			    	printf("There are no pairs available to modify in this entry.\n");
			        return;
				}
				
				printf("\nEnter the pair number you want to modify (1 to %d): ", entries[currentEntry].count);
    			scanf("%d", &pairNum);
    			getchar();
				
    			if (pairNum < 1 || pairNum > entries[currentEntry].count) 
				{
		            printf("Invalid pair number.\n");
		            break;  // FIXED: Changed return to break to stay in loop
		        }
    			
    			pairNum--; 
			
				printf("Which field would you like to modify?\n");
	            printf("1. Language\n");
	            printf("2. Translation\n");
	            printf("Enter your choice: ");
	            scanf("%d", &modify);
	            getchar();
					
	            if (modify == 1)
	            {
	                printf("Enter language: ");
					scanf(" %20s", entries[currentEntry].pairs[pairNum].language);
					getchar();
				}
				else if (modify == 2)
				{
					printf("Enter translation: ");
					scanf(" %20s", entries[currentEntry].pairs[pairNum].translation);
					getchar();
				}
				else
				{
					 printf("\n===========================\n"); 
					 printf("Invalid choice.\n");
				}
				break;
			case 'N':
			case 'n':
				if (currentEntry < *entryCount - 1) 
				{
                    currentEntry++;
                }
                else
				{
					printf("\n===========================\n");  
                	printf("No more entries to display.\n");
				}
				break;
			case 'P':
			case 'p':
				if (currentEntry > 0) 
				{
                    currentEntry--;
                }
                else
                {
                	printf("\n===========================\n"); 
                	printf("No more entries to display.\n");
				}
				break;
			case 'X':
			case 'x':
				stopper = 1;
				printf("\n===========================\n"); 
                return;
            default:
                printf("Invalid command.\n");
                break;
		}
	}
}

/* manageData displays the manage data menu 
@param entries - array of entries 
@param entryCount - the number of entries in the array 
*/
void 
manageData(entry entries[], 
			int *entryCount)
{	
	int choice;
	int stopper = 0;
	
	while (stopper == 0)
	{
		printf("\n\nNumber of Entries %d\n", *entryCount);
		printf("==Manage Data==\n");
		printf("1. Add Entry\n");
		printf("2. Add Translations\n");
		printf("3. Modify Entry\n");
		printf("4. Delete Entry\n");
		printf("5. Delete Translation\n");
		printf("6. Display All Entries\n");
		printf("7. Search Word\n");
		printf("8. Search Translation \n");
		printf("9. Export\n");
		printf("10. Import \n");
		printf("11. Exit\n");
		printf("Enter your choice: ");
		scanf(" %d", &choice);
		getchar();
			
		switch (choice)
		{
			case 1:
				addEntry(entries, entryCount);  // FIXED: Removed all &*
				break;
			case 2:
				addTranslations(entries, entryCount);
				break;
			case 3:
				modifyEntry(entries, entryCount);
				break;
			case 4:
				deleteEntry(entries, entryCount);
				break;
			case 5:
				deleteTranslation(entries, entryCount);
				break;
			case 6:
				displayAllEntries(entries, entryCount); 
				break;
			case 7:
				searchWord(entries, entryCount);
				break;
			case 8:
				searchTranslation(entries, entryCount);
				break;
			case 9:
				exportData(entries, entryCount);
				break;
			case 10:
				importData(entries, entryCount);
				break;
			case 11:
				stopper = 1;
				clearData(entries, entryCount);
				return;
			
			default:
                printf("Invalid choice. Please try again.\n");
		}	
	}
}