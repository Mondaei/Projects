/*********************************************************************************************************
This is to certify that this project is my own work, based on my personal efforts in studying and applying the concepts 
learned. I have constructed the functions and their respective algorithms and corresponding code by myself. The 
program was run, tested, and debugged by my own efforts. I further certify that I have not copied in part or whole or 
otherwise plagiarized the work of other students and/or persons.
Geslani, Keila Franchoise Leigh, DLSU ID# 12206997
*********************************************************************************************************/
/*  
    Description: the main
    Programmed by: Keila Franchoise Leigh Geslani 
    Last modified: July 30, 2025  
    Version: 12.0  
    [Acknowledgements: https://cplusplus.com, cppreference.com, dlsu.instructure.ph, old MPs, old Exams,
					worldcounter.net(counting chars)]  
*/
#include "geslani K_menu.c"

int main()
{
	Achievement achievements[TOTAL_ACHIEVEMENTS] =
	{
		{"Yohane Descends!", "Cleared first dungeon", 0, {0}}, // achievement, description, if unlocked or not, date
		{"Mikan Power!", "Rescued Chika for the first time", 0, {0}},// achievement, description, if unlocked or not, date
		{"Riko-chan BEAM!", "Rescued Riko for the first time", 0, {0}},// achievement, description, if unlocked or not, date
		{"Yousoro!", "Rescued You for the first time", 0, {0}},// achievement, description, if unlocked or not, date
		{"It's the future, zura!", "Rescued Hanamaru for the first time", 0, {0}},// achievement, description, if unlocked or not, date
		{"Ganbaruby!", "Rescued Ruby for the first time", 0, {0}},// achievement, description, if unlocked or not, date
		{"Buu-buu desu wa!", "Rescued Dia for the first time", 0, {0}},// achievement, description, if unlocked or not, date
		{"Hug!!!", "Rescued Kanan for the first time", 0, {0}},// achievement, description, if unlocked or not, date
		{"Shiny!", "Rescued Mari for the first time", 0, {0}},// achievement, description, if unlocked or not, date
		{"In This Unstable World!", "Beat the Final boss for the first time", 0, {0}},// achievement, description, if unlocked or not, date
		{"One more sunshine story!", "Rescued Chika twice", 0, {0}},// achievement, description, if unlocked or not, date
		{"Pianoforte Monologue!", "Rescued Riko twice", 0, {0}},// achievement, description, if unlocked or not, date
		{"Beginner’s Sailing!", "Rescued You twice", 0, {0}},// achievement, description, if unlocked or not, date
		{"Oyasuminasan!", "Rescued Hanamaru twice", 0, {0}},// achievement, description, if unlocked or not, date
		{"Red Gem Wink!", "Rescued Ruby twice", 0, {0}},// achievement, description, if unlocked or not, date
		{"White First Love!", "Rescued Dia twice", 0, {0}},// achievement, description, if unlocked or not, date
		{"Sakana ka Nandaka!", "Rescued Kanan twice", 0, {0}},// achievement, description, if unlocked or not, date
		{"New Winding Road!", "Rescued Mari twice", 0, {0}},// achievement, description, if unlocked or not, date
		{"Deep Resonance!", "Beat the Final boss twice", 0, {0}},// achievement, description, if unlocked or not, date
		{"No. 10!", "Clear 10 dungeons", 0, {0}},// achievement, description, if unlocked or not, date
		{"CYaRon!", "Rescued Chika, You, and Ruby (Not necessarily in one playthrough)", 0, {0}},// achievement, description, if unlocked or not, date
		{"AZALEA!", "Rescued Hanamaru, Dia, and Kanan (Not necessarily in one playthrough)", 0, {0}},// achievement, description, if unlocked or not, date
		{"Guilty Kiss!", "Rescued Riko and Mari (Not necessarily in one playthrough)", 0, {0}},// achievement, description, if unlocked or not, date
		{"Eikyuu Hours!", "Have Yohane rescue all Aqours members for the first time", 0, {0}},// achievement, description, if unlocked or not, date
		{"Aozora Jumping Heart!", "Clear a dungeon without incurring any damage", 0, {0}},// achievement, description, if unlocked or not, date
		{"Mitaiken Horizon!", "Accumulate a total of 5000G spent on Hanamaru's stores across multiple playthroughs", 0, {0}},// achievement, description, if unlocked or not, date
		{"Ruby-chan! Hai? Nani ga suki?", "Get saved by a fatal blow from Ruby's choco-mint ice cream item.", 0, {0}},// achievement, description, if unlocked or not, date
		{"Step! ZERO to ONE!", "Complete a playthrough with 0G on-hand at the end", 0, {0}}// achievement, description, if unlocked or not, date
	};
	
	Dungeon dungeons[TOTAL_CHARACTERS2SAVE] = {
        {"Yasudaya Ryokan", 0, {{"Chika", 0}}}, // dungeon, if dungeon complete, whos the character that will be saved, rescued flag
        {"Numazu Deep Sea Aquarium", 0, {{"Riku", 0}}},// dungeon, if dungeon complete, whos the character that will be saved, rescued flag
        {"Izu-Mito Sea Paradise", 0, {{"You", 0}}},// dungeon, if dungeon complete, whos the character that will be saved, rescued flag
        {"Shougetsu Confectionary", 0, {{"Hanamaru", 0}}},// dungeon, if dungeon complete, whos the character that will be saved, rescued flag
        {"Nagahama Castle Ruins", 0, {{"Ruby", 0}}},// dungeon, if dungeon complete, whos the character that will be saved, rescued flag
        {"Numazugoyotei", 0, {{"Dia", 0}}},// dungeon, if dungeon complete, whos the character that will be saved, rescued flag
        {"Uchiura Bay Pier", 0, {{"Kanan", 0}}},// dungeon, if dungeon complete, whos the character that will be saved, rescued flag
        {"Awashima Marine Park", 0, {{"Mari", 0}}}// dungeon, if dungeon complete, whos the character that will be saved, rescued flag
    };
	
	ItemShop items[ITEM_COUNT] =
	{
		{"Tears of a fallen angel", 30, 0, 0}, // item name, price, how many in inventory, unlocked or no
		{"Noppo Bread", 100, 0, 0}, // item name, price, how many in inventory, unlocked or no
		{"Shovel Upgrade", 300, 0, 0}, // item name, price, how many in inventory, unlocked or no
		{"Bat Tamer", 400, 0, 0}, // item name, price, how many in inventory, unlocked or no
		{"Air Shoes", 500, 0, 0}, // item name, price, how many in inventory, unlocked or no
		{"Stewshine", 1000, 0, 0}, // item name, price, how many in inventory, unlocked or no
		{"Mikan Mochi", 1000, 0, 0}, // item name, price, how many in inventory, unlocked or no
		{"Kurosawa Macha", 1000, 0, 0}, // item name, price, how many in inventory, unlocked or no
		{"Choco-Mint Ice Cream", 2000, 0, 0} // item name, price, how many in inventory, unlocked or no
	};
	
	Achievement achieve; // type of structure belongs to Achievement
	PlayerData player; // structure 
	char choice; // variable for checking user input
	int flag = 1; // flag
	player.gameOver= 0; // to know if its gameOver
	DungeonSelection DUNGselection; // dungeon selection
	DUNGselection.isInitialized = 0; 
	player.toMainMenu = 0; // for returning to main menu
	player.ChebiMiloBibo = 0; // placeholder for the dungeons, dungeon 1, dungeon 2, dungeon 3
	AchievementNotif queue[TOTAL_ACHIEVEMENTS];
	
	srand(time(NULL));
	
	while (flag == 1)
	{
		choice = MainMenuModule();
		
		if (choice == 'N' || choice == 'n')
		{
			newGame(&player, items, dungeons, &achieve, &DUNGselection, queue); // calls the new game menu
			
			do // newgame -> continuegame -> gameplay -> battle -> continuegame
			{
	            choice = continueGame(&player, items, dungeons, &achieve, &DUNGselection,queue);
	
	            if (choice == 'V' || choice == 'v')
	            {
	                displayAchievements(achievements, dungeons);// for viewing achievements
	            }
	            else if (choice == 'Q' || choice == 'q')
	            {
	                flag = 0;
	                printf("\nThank you for playing the game. Enjoy your day!\n\n");
	            }

        	} while (choice != 'Q' && choice != 'q');
        	
        	if (player.hp <= 0)
        	{
        		do
        		{
        			// the itsGameOver function has the option to continue the game or newgame
        			choice = itsGameOver(&player, items, dungeons, &achieve,&DUNGselection, queue);
        			if (choice == 'V' || choice == 'v')
		            {
		                displayAchievements(achievements, dungeons);
		            }
		            else if (choice == 'Q' || choice == 'q')
		            {
		                flag = 0;
		                printf("\nThank you for playing the game. Enjoy your day!\n\n");
		            }
				}while (choice != 'Q' && choice != 'q');
			}
		}
		else if (choice == 'L' || choice == 'l')
		{
			loadGame(&player, dungeons, items); // for loading save file
			printf("Welcome back, Yohane!\n");
			
			do 
			{	// loadgame -> continuegame -> gameplay -> battle -> continue
	            choice = continueGame(&player, items, dungeons, &achieve, &DUNGselection, queue);
				
	            if (choice == 'V' || choice == 'v')
	            {
	                displayAchievements(achievements, dungeons);// for viewing achievements
	            }
	            else if (choice == 'Q' || choice == 'q')
	            {
	                flag = 0;
	                printf("\nThank you for playing the game. Enjoy your day!\n\n");
	            }
	
	        } while (choice != 'Q' && choice != 'q');
	        
	        if (player.hp <= 0)
        	{
        		do
        		{
        			choice = itsGameOver(&player, items, dungeons, &achieve,&DUNGselection, queue);
        			if (choice == 'V' || choice == 'v')
		            {
		                displayAchievements(achievements, dungeons);// for viewing achievements
		            }
		            else if (choice == 'Q' || choice == 'q')
		            {
		                flag = 0;
		                printf("\nThank you for playing the game. Enjoy your day!\n\n");
		            }
				}while (choice != 'Q' && choice != 'q');
			}
		}
		else if (choice == 'V' || choice == 'v')
		{
			displayAchievements(achievements, dungeons); // for viewing achievements
		}
		else if (choice == 'Q' || choice == 'q') 
		{
			flag = 0;
			printf("\nThank you for playing the game. Enjoy your day!\n\n");
		}
		else 
		{
        	printf("Invalid input. Please try again.\n");
    	}
	}
	
	return 0;
}
