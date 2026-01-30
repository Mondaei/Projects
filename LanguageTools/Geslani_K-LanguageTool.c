/*********************************************************************************************************
This is to certify that this project is my own work, based on my personal efforts in studying and applying the concepts 
learned. I have constructed the functions and their respective algorithms and corresponding code by myself. The 
program was run, tested, and debugged by my own efforts. I further certify that I have not copied in part or whole or 
otherwise plagiarized the work of other students and/or persons.
Geslani, Keila Franchoise Leigh, DLSU ID# 12206997
*********************************************************************************************************/

#include "Geslani_K-ManageData.c"
int tokenize (identifyLang identify, sentence s);
void identifyMainLanguage(entry entries[], int *entryCount);
void simpleTranslation(entry entries[], int *entryCount);
void languageTools(entry entries[], int *entryCount);

/* tokenize takes a sentence and breaks it down into individual words 
@param identify - struct containing the words and their corresponding language 
@param s - the sentence to be tokenized 
@return the number of words in the sentence 
*/
int
tokenize (identifyLang identify, 
			sentence s)
{
	int i = 0;
	int j = 0;
	int k = 0;
    
	while (s[j] != '\0') 
	{
        if (s[j] != ' ' && s[j] != ',' && s[j] != '!' && s[j] != '?') 
		{
            identify[k][i] = s[j];
            i++;
        } 
		else 
		{
            identify[k][i] = '\0';
            k++;
            i = 0;
        }
        j++;
    }
    
    identify[k][i] = '\0';
    k++;
    
    return k;
}

/* identifyMainLanguage identifies the main language of the entries 
@param entries - array of entries 
@param entryCount - the number of entries in the array 
*/
void
identifyMainLanguage(entry entries[], 
						int *entryCount)
{
    char input[LEN];
    char words[LEN][MAX_TRANSLENGTH];
    int wordCount;
	int i = 0;
	int j, k, l;
	char ch;
	int languageCounts[MAX_ENTRIES] = {0};
	int maxCount = 0;
	int languagesCount = 0;
    char languages[MAX_ENTRIES][MAX_TRANSLENGTH];
    int currentCount, langIndex;
    
    
	printf("Enter a sentence or a phrase: "); 
	
	while (i < LEN - 1 && (ch = getchar()) != '\n' && ch != EOF) 
	{
        input[i++] = ch;
    }
    
    input[i] = '\0';
	
	wordCount = tokenize(words, input);
	
    
	for (i = 0; i < *entryCount; i++) 
	{
        for (j = 0; j < entries[i].count; j++) 
		{
            currentCount = 0;
            for (k = 0; k < wordCount; k++) 
			{
                if (strcmp(words[k], entries[i].pairs[j].translation) == 0) 
				{
                    currentCount++;
                }
            }

            if (currentCount > 0) 
			{
                langIndex = -1;
                for (l = 0; l < languagesCount; l++) 
				{
                    if (strcmp(entries[i].pairs[j].language, languages[l]) == 0) 
					{
                        langIndex = l;
                    }
                }
                if (langIndex == -1) 
				{
                    strcpy(languages[languagesCount], entries[i].pairs[j].language);
                    languageCounts[languagesCount] = currentCount;
                    languagesCount++;
                } 
				else 
				{
                    if (languageCounts[langIndex] < currentCount) 
					{
                        languageCounts[langIndex] = currentCount;
                    }
                }
            }
        }
    }

    for (i = 0; i < languagesCount; i++) 
	{
        if (languageCounts[i] > maxCount) 
		{
            maxCount = languageCounts[i];
        }
    }

    if (maxCount == 0) 
	{
        printf("Cannot determine the language.\n");
        printf("Returning to the Language Tools Menu.\n");
    } 
	else 
	{
        printf("Languages found:\n");
        
		for (i = 0; i < languagesCount; i++) 
		{
            if (languageCounts[i] > 0) 
			{
                printf("%s: %d\n", languages[i], languageCounts[i]);
            }
        }

        printf("Main language(s): ");
        
		for (i = 0; i < languagesCount; i++) 
		{
            if (languageCounts[i] == maxCount) 
			{
                printf("%s ", languages[i]);
            }
        }
        printf("\n");
    }
}
/*simpleTranslation performs a simple translation of a given sentence. It does not consider punctuations or
	special characters in the translation.
@param entries - array of entries 
@param entryCount - the number of entries in the array 
*/
void 
simpleTranslation(entry entries[],
					int *entryCount)
{
	char input[LEN];
    char words[LEN][MAX_TRANSLENGTH];
    int wordCount;
	int i = 0;
	char ch;
	char sourceLanguage[MAX_LANGUAGE_LENGTH];
	char targetLanguage[MAX_LANGUAGE_LENGTH];
	int found = 0;
	int j, k, 
		l, w;
	int wordFound, entryIndex, translationFound, 
			pairIndex, targetPairIndex; 
	int stopper = 0;
	char translateText, chevy;
	
	printf("Enter the source language: ");
	scanf(" %20s", sourceLanguage);
	getchar();
		
	printf("Enter the Language to be translated to: ");
	scanf(" %20s", targetLanguage);
	getchar();
		
	do
	{
		memset(input, 0, sizeof(input));
        for (i = 0; i < LEN; i++) 
		{
            memset(words[i], 0, sizeof(words[i]));
        }

        i = 0;
		
		printf("Enter the text to be translated: "); 
		while (i < LEN - 1 && (ch = getchar()) != '\n' && ch != EOF) 
		{
		    input[i++] = ch;
		}
		    
		input[i] = '\0';
			
		wordCount = tokenize(words, input);
			
		for (w = 0; w < wordCount; w++)
		{
			wordFound = 0; 
	        entryIndex = 0;
	        	
	        while (entryIndex < *entryCount && !wordFound)
	        {
	            pairIndex = 0;
	            	
	            while (pairIndex < entries[entryIndex].count && !wordFound)
	            {
	            	if (strcmp(entries[entryIndex].pairs[pairIndex].language, sourceLanguage) == 0 &&
	                    	strcmp(words[w], entries[entryIndex].pairs[pairIndex].translation) == 0)
	                {
	                    targetPairIndex = 0;
	                    	
	                    while (targetPairIndex < entries[entryIndex].count)
	                    {
	                    	if (strcmp(entries[entryIndex].pairs[targetPairIndex].language, targetLanguage) == 0)
	                    	{
								printf("%s ", entries[entryIndex].pairs[targetPairIndex].translation);
								wordFound = 1;
							}
								
							targetPairIndex++;
						}
					}
						
					pairIndex++;
				}
							
				if (!wordFound) 
				{
		            entryIndex++;
		        }
			}
				
			if (!wordFound) 
			{
                printf("%s ", words[w]);
            }
		}
			
		printf("\n");
			
		printf("Translate again? Y/N \n");
		scanf(" %c", &chevy);
		getchar();
			
		stopper = (chevy == 'Y' || chevy == 'y') ? 0 : 1;
					
	}while (!stopper);
}

/*languageTools displays the Language Tools Menu
@param entries - array of entries 
@param entryCount - the number of entries in the array 
*/
void
languageTools(entry entries[], 
				int *entryCount)
{
	int choice;
	int stopper = 0;
	
	importData(entries, &*entryCount);
	
	while (stopper == 0)
	{
		printf("\n===========================\n");
		printf("\nIf you want to change the\nimported entries\npress 3 for Exit and\nPick Language Tools Again\n");
		printf("\n===========================\n");
		printf("\n\nNumber of Entries %d\n", *entryCount);
		printf("==Language Tools==\n");
		printf("1. Identify Main Language\n");
		printf("2. Simple Translation\n");
		printf("3. Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);
		getchar();
		
		switch (choice)
		{
			case 1:
				identifyMainLanguage(entries, &*entryCount);
				break;
			case 2:
				simpleTranslation(entries, &*entryCount);
				break;
			case 3:
				stopper = 1;
				clearData(entries, &*entryCount);
				return;
				break;
			default:
                printf("Invalid choice. Please try again.\n");
		}	
	}
}
