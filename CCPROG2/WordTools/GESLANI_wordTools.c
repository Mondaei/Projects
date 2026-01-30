/* Name:  Geslani, Keila Franchoise Leigh O.
*/

#include "wordTools.h"  //you cannot add other libraries

/* ToDo:  Implement this function.
   This function should copy each word in the sentence into the array of words and updates *pElem to the number of entries in the array of words.  
   
   Precondition: 
   1. There are no numeric characters stored in the sentence. 
   2. There can also be a (only 1) special character in between words in the sentence but should not be included in the word.  Special characters can be space, comma, semicolon, period, question mark, and exclamation point.  Note that it is possible there can be 1 or no special characters right after the last letter in sentence.
   
   @param sentence - a long string which may contain more than 
                     one word
   @param aWords - resulting array of words (excluding 
                   special characters)
   @param pElem - address where the number of elements in 
                  aWords should be stored in
*/
void
split(longString sentence, string aWords[], int *pElem)
{
	int i = 0; 
	int j = 0;
	int k = 0;
	int count = 0;
	
	while (i < strlen(sentence))
	{
		while (i < strlen(sentence) && (sentence[i] == ' ' || sentence[i] == ','
				|| sentence[i] == ';' || sentence[i] == '.' || sentence[i] == '!'
				|| sentence[i] == '?'))
		{
			i++;
		}
		
		
		while (i < strlen(sentence) && sentence[i] != ' ' && sentence[i] != ',' && 
				sentence[i] != ';' && sentence[i] != '.' && sentence[i] != '?' && 
				sentence[i] != '!')
		{
			aWords[count][k] = sentence[i];
			i++;
			k++;
		}
				
		count++;
		
	}
	
	*pElem = count;
}

/* ToDo: Implement this function.
   This function should return the number of letters in the entire sentence.  This count does not include the special characters.
   
   @param sentence - a long string which may contain more than 
                     one word
   @return the number of letters (both capital and small) that 
           are in the sentence
*/
int
countLetters(longString sentence)
{
	int i;
	int count = 0;
	
	for (i = 0; sentence[i] != '\0'; i++)
	{
		if ((sentence[i] >= 'A' && sentence[i] <= 'Z') || 
			(sentence[i] >= 'a' && sentence[i] <= 'z'))
			{
				count++;
			}
	}
	return count;
}

/* ToDo: Implement this function.
   This function should return the number of times the keyword appears in the array of words.  Only exact matches are counted.  For example, if keyword is “apple”, then “AppLe”, “appleStore”, “redapple” will not be included in the count.
   
   @param keyword - the word being searched
   @param aWords - array of words to search from
   @param nElem - number of elements in aWords
   
   @return number of times keyword appears in aWords; 
           if keyword is not in aWords, the function
		   returns 0
*/
int
countOccurrence(string keyword, string aWords[], int nElem)
{
	int i;
	int count = 0;
	
	for (i = 0; i < nElem; i++)
	{
		if (strcmp(keyword, aWords[i]) == 0)
		{
			count++;
		}
	}
	
	return count;
}

/* ToDo: Implement this function. 
   This function should store in the array of counts the number of words that start with each letter of the alphabet.  That is, index 0 of the array of counts indicate number of words starting with ‘A’ or ‘a’, index 1 indicates number of words starting with ‘B’ or ‘b’, and so on. Note that the array of counts may not be initialized yet.
   
   @param aWords - array of words
   @param nElem - number of elements in aWords
   @param aCounts - resulting array of counts
*/
void
tally(string aWords[], int nElem, int aCounts[])
{
	int i, j;
	char fLetter;
	
	for (i = 0; i < MAX; i++)
	{
		aCounts[i] = 0;
	}
	
	for (i = 0; i < nElem; i++)
	{
		fLetter = aWords[i][0];
		
		if (fLetter >= 'A' && fLetter <= 'Z')
		{
			aCounts[fLetter - 'A']++;
		} else if (fLetter >= 'a' && fLetter <= 'z')
		{
			 aCounts[fLetter - 'a']++;
		}
	}
	
}

/* ToDo: Implement this function.
   This function should sort the array of words in increasing order (depends on the ASCII value).  For example, if array of words initially contains {“banana”, “apple”, “Hello”, “ABCDEFG”}, the function should result to having the same array now contain {“ABCDEFG”, “Hello”, “apple”, “banana”}

   @param aWords - array of words to sort
   @param nElem - number of elements in aWords
*/
void
sort(string aWords[], int nElem)
{
	int i, j;
	string temp;
	
	for (i = 0; i < nElem - 1; i++)
	{
		for (j = i + 1; i < nElem ; j++)
		{
			if (strcmp(aWords[i], aWords[j]) > 0)
			{
				strcpy(temp, aWords[i]);
				strcpy(aWords[i], aWords[j]);
				strcpy(aWords[j], temp);
			}
		}
	}
} 
