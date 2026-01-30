/*********************************************************************************************************
This is to certify that this project is my own work, based on my personal efforts in studying and applying the concepts 
learned. I have constructed the functions and their respective algorithms and corresponding code by myself. The 
program was run, tested, and debugged by my own efforts. I further certify that I have not copied in part or whole or 
otherwise plagiarized the work of other students and/or persons.
Geslani, Keila Franchoise Leigh, DLSU ID# <number>
*********************************************************************************************************/
#include <stdio.h>
#include <string.h>
#define MAX_USERS 300
#define MAX_PRIORITY 7
#define MAX_TRIPCAPREG 14
#define MAX_TRIPCAPWORST 17

typedef char string12[13];
typedef char string20[21];
typedef char string50[51];

typedef struct{
	string20 fname;
	string20 lname;
	int priority;
	int idNum;
	int tripNum;
	string50 DropPoint;
	string12 place;
	int status;
}appointment;

