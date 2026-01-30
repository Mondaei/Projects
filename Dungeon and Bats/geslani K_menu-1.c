/*********************************************************************************************************
This is to certify that this project is my own work, based on my personal efforts in studying and applying the concepts 
learned. I have constructed the functions and their respective algorithms and corresponding code by myself. The 
program was run, tested, and debugged by my own efforts. I further certify that I have not copied in part or whole or 
otherwise plagiarized the work of other students and/or persons.
Geslani, Keila Franchoise Leigh, DLSU ID# 12206997
*********************************************************************************************************/
/*  
    Description: the menu for the game
    Programmed by: Keila Franchoise Leigh Geslani 
    Last modified: July 27, 2025  
    Version: 3.0  
    [Acknowledgements: https://cplusplus.com, cppreference.com, dlsu.instructure.ph, old MPs, old Exams]  
*/
#include "geslani K_dungeonsVer2.c"  // include header file that contains structs

void unlockAchievement(PlayerData *player, int achievementIndex) 
{
    if (!player->playerAchievements[achievementIndex].earned) {
        player->playerAchievements[achievementIndex].earned = 1;
        getTheDateNow(&player->playerAchievements[achievementIndex].date);
        
        printf("\n*** ACHIEVEMENT UNLOCKED! ***\n");
        printf("?? %s\n", player->playerAchievements[achievementIndex].name);
        printf("%s\n", player->playerAchievements[achievementIndex].description);
        printf("Press any key to continue...\n");
        _getch();
    }
}

void newGame(PlayerData *player, ItemShop items[], Dungeon dungeons[],
	Achievement achieve[],  DungeonSelection *DUNGselection,AchievementNotif *queue)
{
	player->hp = 3;
	player->maxHP = 3;
	player->isNewGame = 1;
	player->gold = 0;
	
	int i;
	
	for (i = 0; i < 8; i++) 
	{
        player->rescuedMembers[i] = 0; 
    }
    
    for (i = 0; i < 28; i++)
    {
    	player->playerAchievements[i].earned = 0;
        player->playerAchievements[i].date.month = 0;
		player->playerAchievements[i].date.day = 0;
        player->playerAchievements[i].date.year = 0;
        player->playerAchievements[i].date.hour = 0;
        player->playerAchievements[i].date.minute = 0;
	}
	
	continueGame(player, items, dungeons,achieve, DUNGselection,queue);
}
/*
DONE
*/
void showAchievementDetails(Achievement achieve) 
{
	int i;
	int achievementsEarned = 0;
	
	for (i = 0; i < 28; i++) 
	{
        if (achieve.earned == 1) 
		{
            achievementsEarned++;
        }
    }
    
	system("cls");
	printf("************************************************\n");
	printf("*\t       Achievements module\t       *\n");
	printf("*\t   Obtained: %d / 28               *\n", achievementsEarned);
	printf("************************************************\n");
	
    printf("Achievement Name: %s\n", achieve.name);
    printf("\nStatus: %s\n", achieve.earned ? "EARNED!" : "NOT EARNED");
    
    if (achieve.earned) 
	{
        printf("Date Earned: %02d-%02d-%04d %02d:%02d\n",
            achieve.date.month, achieve.date.day, achieve.date.year, achieve.date.hour, achieve.date.minute);
    } 
	
	else 
	{
        printf("Date Earned: -\n");
    }
    
    printf("\nDescription:\n%s\n", achieve.description);
    printf("\n[R]eturn to Achievements Module\n");
}

/*
DONE
*/
void displayAchievements(Achievement achieve[], Dungeon dungeons[])
{
	int i;
	int achievementsEarned;
	int page = 0;
	int start, end;
	char choice[2];
	int totalPages = (TOTAL_ACHIEVEMENTS + PAGE_SIZE - 1) / PAGE_SIZE;
	int flag = 0;
	int input;
	int index;
	char returnTomenu;
	
    
    while (!flag)
    {
    	system("cls");
    	achievementsEarned = 0;
    
    	start = page * PAGE_SIZE;
    	end = start + PAGE_SIZE;
		
    	if (end > TOTAL_ACHIEVEMENTS)
	    {
	    	end = TOTAL_ACHIEVEMENTS;
		}
	
		for (i = 0; i < TOTAL_ACHIEVEMENTS; i++) 
		{
	        if (achieve[i].earned == 1) 
			{
	            achievementsEarned++;
	        }
	    }
	
		printf("************************************************\n");
		printf("*\t       Achievements module\t       *\n");
		printf("*\t   Obtained: %d / 28\t\t       *\n", achievementsEarned);
		printf("************************************************\n");
    
	    	
		for (i = start; i < end; i++) 
		{
	        printf("[%d] %-33s %s\n",
	                (i - start) + 1,
	                achieve[i].name,
	                achieve[i].earned ? "EARNED!" : "NOT EARNED");
	    }
    
	    printf("\nPage %d of %d\n", page + 1, totalPages);
	        printf("[N]ext Page\n[P]revious Page\n[R]eturn to Main Menu\n");
	        printf("Choice: ");
	        fgets(choice, sizeof(choice), stdin);
        
    	if (strlen(choice) == 2 && choice[1] == '\n') choice[1] = '\0';
    
		if (isdigit(choice[0]))
		{
			input = choice[0] - '0';
			index = start + (input - 1);
	    
		    if (input >= 1 && input <= (end - start)) 
			{
		        showAchievementDetails(achieve[index]);
		    	returnTomenu= ' ';
		    	
		    	while (returnTomenu != 'r' && returnTomenu != 'R') {
		                    printf("Choice: ");
		                    scanf(" %c", &returnTomenu);
		                    getchar();
		                }
			}
		}
	
		else if (choice[0] == 'n' || choice[0] == 'N')
		{
			if (page < totalPages - 1)
				page++;
		}
		
		else if (choice[0] == 'p' || choice[0] == 'P')
		{
			if (page > 0) 
				page--;
		}
		
		else if (choice[0] == 'r' || choice[0] == 'R')
		{
			flag = 1;
		}
	}
}
/*
DONE
*/
char MainMenuModule()
{
	char choice;
	
	system("cls");
	printf("************************************************\n");
	printf("*\t       Yohane The Parhelion!\t       *\n");
	printf("*\t   The Siren in the Mirror World!      *\n");
	printf("************************************************\n");
	printf("\t\t[N]ew Game\n");
	printf("\t\t[L]oad Game\n");
	printf("\t\t[V]iew Achievements\n");
	printf("\t\t[Q]uit\n");
	printf("Your choice:");
	scanf("%c", &choice);
	
	if (choice != 'N' && choice != 'n' && choice != 'L' && choice != 'l' &&
			 choice != 'V' && choice != 'v' && choice != 'Q' && choice != 'q')
	{
	    while (getchar() != '\n');
	    choice = -1;
	}
	
	return choice;
}
