/*********************************************************************************************************
This is to certify that this project is my own work, based on my personal efforts in studying and applying the concepts 
learned. I have constructed the functions and their respective algorithms and corresponding code by myself. The 
program was run, tested, and debugged by my own efforts. I further certify that I have not copied in part or whole or 
otherwise plagiarized the work of other students and/or persons.
Geslani, Keila Franchoise Leigh, DLSU ID# 12206997
*********************************************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ENTRIES 151 // MAX ENTRIES
#define LEN 151 // MAX WORDS INPUT
#define MAX_PAIRS 11 // MAX LANGUAGE PAIR
#define MAX_LANGUAGE_LENGTH 21 // MAX LANGUAGE LENGTH
#define MAX_TRANSLENGTH 21 // MAX TRANSLATION LENGTH

typedef char String20[21];
typedef char String30[31];
typedef char sentence[LEN];
typedef char identifyLang[LEN][MAX_TRANSLENGTH];

typedef struct
{
	char language[MAX_LANGUAGE_LENGTH];
	char translation[MAX_TRANSLENGTH];
} pair;


typedef struct
{
	pair pairs[MAX_PAIRS];
	int count;
} entry;