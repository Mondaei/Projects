#include "geslani K_achievementsMod.c"
/*  
    Description: dungeons contain the battle, gamplay, gameover, continue, shop
    Programmed by: Keila Franchoise Leigh Geslani 
    Last modified: July 30, 2025 
    Version: 12.0  
    [Acknowledgements: https://cplusplus.com, cppreference.com, dlsu.instructure.ph, old MPs, old Exams,
					worldcounter.net(counting chars)]  
*/
/* 
Displays a hidden debug menu showing dungeon completion status, character rescue progress,
shop availability, and item unlock conditions based on rescued characters.
Precondition: dungeons[] must be fully initialized with characterToSave data populated.
@param dungeons array of Dungeon structs containing dungeon and character data
@return none
*/
void debugDungeonStatus(Dungeon dungeons[])
{
    int i, j;
    
    system("cls");
    printf("=== DEBUG: DUNGEON & CHARACTER STATUS ===\n\n");
    
    printf("DUNGEON COMPLETION STATUS:\n");
    printf("%-30s %-10s\n", "Dungeon Name", "Status");
    printf("%-30s %-10s\n", "------------", "------");
    
    for (i = 0; i < TOTAL_CHARACTERS2SAVE; i++) // Assuming this is your total dungeon count
    {
        printf("%-30s %-10s\n", 
               dungeons[i].dungeonName, 
               dungeons[i].complete ? "COMPLETE" : "INCOMPLETE");
    }
    
    printf("\n");
    printf("CHARACTER RESCUE STATUS:\n");
    printf("%-15s %-30s %-10s\n", "Dungeon", "Character Name", "Rescued");
    printf("%-15s %-30s %-10s\n", "-------", "--------------", "-------");
    
    for (i = 0; i < TOTAL_CHARACTERS2SAVE; i++)
    {
        // Assuming each dungeon has at least one character to save
        // Adjust this loop if some dungeons have multiple characters
        for (j = 0; j < 1; j++) // Change this if you have multiple characters per dungeon
        {
            printf("%-15s %-30s %-10s\n",
                   dungeons[i].dungeonName,
                   dungeons[i].characterToSave[j].name,
                   dungeons[i].characterToSave[j].rescued ? "YES" : "NO");
        }
    }
    
    printf("\n");
    printf("SHOP AVAILABILITY STATUS:\n");
    if (dungeons[3].characterToSave[0].rescued) // Assuming Hanamaru is at index 3
    {
        printf("Hanamaru's Shop: AVAILABLE\n");
    }
    else
    {
        printf("Hanamaru's Shop: NOT AVAILABLE (Rescue Hanamaru first)\n");
    }
    
    printf("\n");
    printf("ITEM UNLOCK STATUS:\n");
    printf("Tears of Fallen Angel: ALWAYS AVAILABLE\n");
    printf("Noppo Bread: ALWAYS AVAILABLE\n");
    
    if (dungeons[3].characterToSave[0].rescued)
        printf("Shovel Upgrade: UNLOCKED\n");
    else
        printf("Shovel Upgrade: LOCKED (Rescue character at index 3)\n");
        
    if (dungeons[2].characterToSave[0].rescued)
        printf("Bat Tamer: UNLOCKED\n");
    else
        printf("Bat Tamer: LOCKED (Rescue character at index 2)\n");
        
    if (dungeons[1].characterToSave[0].rescued)
        printf("Air Shoes: UNLOCKED\n");
    else
        printf("Air Shoes: LOCKED (Rescue character at index 1)\n");
        
    if (dungeons[0].characterToSave[0].rescued)
        printf("Stewshine: UNLOCKED\n");
    else
        printf("Stewshine: LOCKED (Rescue character at index 0)\n");
        
    if (dungeons[4].characterToSave[0].rescued)
        printf("Mikan Mochi: UNLOCKED\n");
    else
        printf("Mikan Mochi: LOCKED (Rescue character at index 4)\n");
        
    if (dungeons[5].characterToSave[0].rescued)
        printf("Kurosawa Macha: UNLOCKED\n");
    else
        printf("Kurosawa Macha: LOCKED (Rescue character at index 5)\n");
        
    if (dungeons[6].characterToSave[0].rescued)
        printf("Choco-Mint Ice Cream: UNLOCKED\n");
    else
        printf("Choco-Mint Ice Cream: LOCKED (Rescue character at index 6)\n");
    
    printf("\n");
    printf("Press any key to return to main menu...\n");
    _getch();
}

/* 
Checks if the player owns and can use the "Choco-Mint Ice Cream" revival item. 
If owned, revives the player to full HP and decreases the item count by 1.  
Precondition: player, items, and nItems must be properly initialized; itemIDX must be within bounds  
@param player pointer to the PlayerData struct containing player stats  
@param items array of ItemShop structs containing all items in the game  
@param nItems array of indices for items currently owned by the player  
@param itemIDX the index in nItems[] of the selected item  
@param nItemsAvailable the number of items currently owned by the player  
@return 1 if player was revived, 0 otherwise 
*/
int checkRevivalItem(PlayerData *player, ItemShop items[], int nItems[], int itemIDX, int nItemsAvailable)
{
    if (nItemsAvailable > 0 && itemIDX >= 0 && itemIDX < nItemsAvailable) 
	{
        int IDX = nItems[itemIDX]; //item index check on hand item if choco mint revive else die
        if (strcmp(items[IDX].itemName, "Choco-Mint Ice Cream") == 0 && items[IDX].itemOwned > 0) {
            printf("Choco-Mint Ice Cream activated! You've been revived!\n");
            player->hp = player->maxHP;
            items[IDX].itemOwned--;
            return 1; // Player revived
        }
    }
    return 0; // No revival
}

/*
Handles the game over scenario by presenting the player with options.
Precondition: player must be a valid pointer and the game must be in a state where it ended.
@param player a pointer to the player's data
@param items the item shop inventory
@param dungeons the array of dungeon data
@param dungeonNum the number of the current dungeon
@param DUNGselection the current dungeon selection state
@return the character representing the user's choice:
'C' for continue, 'N' for new game, 'V' for view achievements,
'Q' for quit, or -1 for invalid input
*/
char itsGameOver(PlayerData *player, ItemShop items[], 
		Dungeon dungeons[], Achievement achieve[], DungeonSelection *DUNGselection, AchievementNotif *queue)
{
	char choice;
	system("cls");
	printf("************************************************\n");
	printf("*\t       Yohane The Parhelion!\t       *\n");
	printf("*\t   The Siren in the Mirror World!      *\n");
	printf("************************************************\n");
	printf("\t\t======GAME OVER!======\n\n\n");
	printf("\t\t[C]ontinue\n");
	printf("\t\t[N]ew Game\n");
	printf("\t\t[V]iew Achievements\n");
	printf("\t\t[Q]uit\n");
	printf("Your choice:");
	choice = _getch();
    printf("%c\n", choice);
	if (choice == 'C' || choice == 'c')
	{
		player->maxHP = 3; // if the player decided to continue again the game
		if (player->hp <= 0) 
		{
            player->hp += player->maxHP;
            printf("Your HP has been restored to full!\n");
            printf("Press any key to continue...\n");
            _getch();
        }
		gameplay(player, items, dungeons,achieve, DUNGselection, queue);
		return 'C';
	}
	else if (choice == 'N' || choice == 'n')
	{
		 newGame(player, items, dungeons,achieve, DUNGselection, queue);
		 return 'N';
	}
	else if (choice == 'V' || choice == 'v')
	{
		return 'V';
	}
	else if (choice == 'Q' || choice == 'q')
	{
		return 'Q';
	}
	else
	{
		while (getchar() != '\n'); // Flush input buffer
		return -1; // Invalid input
	}
}
/* 
Displays the post-event menu allowing the player to continue, view achievements, or quit.
Precondition: player, items, dungeons, and DUNGselection must be initialized and valid

@param player pointer to PlayerData struct representing current player state
@param items array of ItemShop structs available in the game
@param dungeons array of Dungeon structs representing dungeon states
@param dungeonNum the current dungeon index
@param DUNGselection pointer to DungeonSelection struct containing selected dungeons
@return 'C' if player chooses to continue, 'V' if viewing achievements, 'Q' if quitting, -1 if input is invalid
*/
char continueGame(PlayerData *player, ItemShop items[], 
	Dungeon dungeons[],Achievement achieve[], DungeonSelection *DUNGselection, AchievementNotif *queue)
{
	char choice;
	system("cls");
	if (player->hp <= 0)
	{
		printf("************************************************\n");
		printf("*\t       Yohane The Parhelion!\t       *\n");
		printf("*\t   The Siren in the Mirror World!      *\n");
		printf("************************************************\n");
		printf("\t\t======GAME OVER!======\n\n\n");
		return 'Q';
	}
	printf("************************************************\n");
	printf("*\t       Yohane The Parhelion!\t       *\n");
	printf("*\t   The Siren in the Mirror World!      *\n");
	printf("************************************************\n");
	if (player->toMainMenu)
	{
		player->toMainMenu = 0; 
		return 'Q';	
	}
	
	printf("\t\t[C]ontinue\n");
	printf("\t\t[V]iew Achievementsano\n");
	printf("\t\t[Q]uit\n");
	printf("Your choice:");
	
	choice = _getch();
    printf("%c\n", choice);
	if (choice == 'C' || choice == 'c')
	{
		gameplay(player, items, dungeons, achieve, DUNGselection, queue);
		return 'C';
	}
	else if (choice == 'V' || choice == 'v')
	{
		return 'V';
	}
	else if (choice == 'Q' || choice == 'q')
	{
		return 'Q';
	}
	else
	{
		while (getchar() != '\n'); // Flush input buffer
		return -1; // Invalid input
	}
}

/* 
    Attempts to dig a wall tile in the specified direction
    @param dungeon the dungeon layout
    @param x, y the target coordinates to dig
    @return 1 if wall was successfully dug, 0 otherwise
*/
int digWall(char dungeon[][WIDTH], int x, int y)
{
    if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
    {
    	return 0;
	}
        
    if (dungeon[y][x] == 'v')
    {
        dungeon[y][x] = '.'; 
        return 1; 
    }
    
    return 0; 
}

/* 
    Attempts to attack a bat in the specified direction
    @param dungeon the dungeon layout
    @param x, y the target coordinates to attack
    @param bats the array of bats to modify
    @return 1 if the bat is successfully killed, 0 otherwise
*/
int attackBat(char dungeon[][WIDTH], int x, int y, Bat bats[])
{
    int i;
    int batFound = 0;
    
    if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
    {
        return 0;
    }
        
    if (dungeon[y][x] == 'b' || dungeon[y][x] == 'B')
    {
        for (i = 0; i < MAX_BATS && !batFound; i++)
        {
            if (bats[i].pos.x == x && bats[i].pos.y == y && bats[i].active)
            {
                bats[i].active = 0;      
                bats[i].Attacked = 1;  
                batFound = 1;
            }
        }
        
        dungeon[y][x] = 'g';
        return 1; 
    }
    
    return 0; 
}

/* 
    Attempts to destroy a spike tile in the specified direction
    @param dungeon the dungeon layout
    @param x, y the target coordinates to destroy
    @return 1 if spike was successfully destroyed, 0 otherwise
*/
int destroySpike(char dungeon[][WIDTH], int x, int y)
{
	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
    {
    	return 0;
	}
        
    if (dungeon[y][x] == 'x')
    {
        dungeon[y][x] = '.';
        return 1; 
    }
    
    return 0; 
}

/* 
Initializes all bat enemies with their properties and random positions.
Precondition: dungeon is a valid 2D array; bats array is sized to MAX_BATS; player is initialized with ChebiMiloBibo set to 1–3

@param dungeon a 2D character array representing the dungeon layout
@param player a pointer to the PlayerData struct indicating the current floor (via ChebiMiloBibo)
@param bats an array of Bat structs to be initialized
@return none
*/
void initBats(char dungeon[][WIDTH], PlayerData *player, Bat bats[])
{
	int i;
	
	for (i = 0; i < MAX_BATS; i++)
	{
		bats[i].active = 1;
        bats[i].pos.x = rand() % WIDTH;
        bats[i].pos.y = rand() % HEIGHT;
        bats[i].lastMoveTurn = 0;
        bats[i].Attacked = 0;
        bats[i].onWater = 0;
        
        if (player->ChebiMiloBibo == 1)
        {
        	bats[i].damage = 0.5;
            bats[i].moveCooldown = 2;
            bats[i].diagonalMovement = 0;
		}
		else if(player->ChebiMiloBibo == 2)
		{
			bats[i].damage = 1.0;
            bats[i].moveCooldown = 1;
            bats[i].diagonalMovement = 0;
		}
		else if (player->ChebiMiloBibo == 3)
		{
			bats[i].damage = 1.5;
            bats[i].moveCooldown = 1;
            bats[i].diagonalMovement = 1;
		}
	}
}

/* 
Checks if a given tile position is already occupied by another object (e.g., wall, water, enemy, etc.)
Precondition: All arrays must be initialized and contain valid positions; x and y must be within dungeon bounds
@param x the horizontal coordinate to check
@param y the vertical coordinate to check
@param bats array of Bat structs currently in the dungeon
@param treasure array of Treasure structs (only first index used)
@param walls array of Wall structs
@param water array of Water structs
@param spikes array of Spike structs
@param heats array of Heat structs
@param exit array of Exit structs (only first index used)
@return 1 if the position is occupied by any object, otherwise 0
*/
int isOccupied(int x, int y, Treasure treasure[], Wall walls[],
				Water water[], Spike spikes[], Heat heats[], Exit exit[])
{
	int i;
	
	for (i = 0; i < 1; i++)
	{
		if (exit[i].pos.x == x && exit[i].pos.y == y)
			return 1;
	}
	
	for (i = 0; i < 1; i++)
	{
		if (treasure[i].pos.x == x && treasure[i].pos.y == y)
			return 1;
	}
	
	for (i = 0; i < MAX_SPIKES; i++)
	{
		if (spikes[i].pos.x == x && spikes[i].pos.y == y)
			return 1;
	}
	
	for (i = 0; i < MAX_HEAT; i++)
	{
		if (heats[i].pos.x == x && heats[i].pos.y == y)
			return 1;
	}
	
	for (i = 0; i < MAX_WATER; i++)
	{
		if (water[i].pos.x == x && water[i].pos.y == y)
			return 1;
	}
	
	for (i = 0; i < MAX_WALL; i++)
	{
		if (walls[i].pos.x == x && walls[i].pos.y == y)
			return 1;
	}
	
	return 0;
}

/* 
Initializes the dungeon layout with borders and passable tiles  
Precondition: dungeon is a 2D array with defined HEIGHT and WIDTH  
	
	@param dungeon a 2D character array representing the dungeon layout  
	@return none 
*/
void createDungeon(char dungeon[][WIDTH], Treasure treasure[], Wall walls[],
				Water water[], Spike spikes[], Heat heats[], Exit exit[]) 
{
	int i, j;
	int x, y;
	int spikeCount = 0, wallCount = 0;
	int waterCount = 0, heatCount = 0, treasureCount = 0, exitCount = 0;
	    
	for (i = 0; i < HEIGHT; i++) 
	{
	    for (j = 0; j < WIDTH; j++) 
		{
	        if (i == 0 || i == HEIGHT - 1 || j == 0 || j == WIDTH - 1) 
			{
	            dungeon[i][j] = '*'; // Border
	        } 
			else 
			{
				dungeon[i][j] = '.'; // Walkable floor
	        }
		}
	}
	
	while (exitCount < 1)
	{
		x = 1 + rand() % (WIDTH - 2);
		y = 1 + rand() % (HEIGHT - 2);
		
		if (dungeon[y][x] == '.' && !(x == WIDTH / 2 && y == HEIGHT / 2) &&
	        !isOccupied(x, y, treasure, walls, water, spikes, heats, exit))
		{
			dungeon[y][x] = 'E'; // Solid wall
			exit[exitCount].pos.x = x;
			exit[exitCount].pos.y = y;
			exit[exitCount].active = 1;
			exitCount++;
		}
	}
	
	while (treasureCount < 1)
	{
		x = 1 + rand() % (WIDTH - 2);
		y = 1 + rand() % (HEIGHT - 2);
		
		if (dungeon[y][x] == '.' && !(x == WIDTH / 2 && y == HEIGHT / 2) &&
	        !isOccupied(x, y, treasure, walls, water, spikes, heats, exit))
		{
			dungeon[y][x] = 'T';
			treasure[treasureCount].pos.x = x;
			treasure[treasureCount].pos.y = y;
			treasure[treasureCount].active = 1;
			treasureCount++;
		}
	}
	
	while (waterCount < MAX_WATER)
	{
		x = 1 + rand() % (WIDTH - 2);
		y = 1 + rand() % (HEIGHT - 2);
		
		if (dungeon[y][x] == '.' && !(x == WIDTH / 2 && y == HEIGHT / 2) &&
	        !isOccupied(x, y, treasure, walls, water, spikes, heats, exit))
		{
			dungeon[y][x] = 'w';
			water[waterCount].pos.x = x;
			water[waterCount].pos.y = y;
			water[waterCount].active = 1;
			waterCount++;
		}
	}
	
	while (heatCount < MAX_HEAT)
	{
		x = 1 + rand() % (WIDTH - 2);
		y = 1 + rand() % (HEIGHT - 2);
		
		if (dungeon[y][x] == '.' && !(x == WIDTH / 2 && y == HEIGHT / 2) &&
	        !isOccupied(x, y, treasure, walls, water, spikes, heats, exit))
		{
			dungeon[y][x] = 'h';
			heats[heatCount].pos.x = x;
			heats[heatCount].pos.y = y;
			heats[heatCount].active = 1;
			heatCount++;
		}
	}
	
	while (spikeCount < MAX_SPIKES)
	{
		x = 1 + rand() % (WIDTH - 2);
		y = 1 + rand() % (HEIGHT - 2);
		
		if (dungeon[y][x] == '.' && !(x == WIDTH / 2 && y == HEIGHT / 2) &&
	        !isOccupied(x, y, treasure, walls, water, spikes, heats, exit))
		{
			dungeon[y][x] = 'x';
			spikes[spikeCount].pos.x = x;
			spikes[spikeCount].pos.y = y;
			spikes[spikeCount].active = 1;
			spikeCount++;
		}
	}
	
	while (wallCount < MAX_WALL)
	{
		x = 1 + rand() % (WIDTH - 2);
		y = 1 + rand() % (HEIGHT - 2);
		
		if (dungeon[y][x] == '.' && !(x == WIDTH / 2 && y == HEIGHT / 2) &&
	        !isOccupied(x, y, treasure, walls, water, spikes, heats, exit))
		{
			dungeon[y][x] = 'v';
			walls[wallCount].pos.x = x;
			walls[wallCount].pos.y = y;
			walls[wallCount].active = 1;
			wallCount++;
		}
	}
	
}

/* 
    Displays the current dungeon layout to the console  
    Precondition: dungeon is a fully initialized 2D array  
    @param dungeon a 2D character array representing the dungeon layout  
    @return none 
*/
void printDungeon(char dungeon[][WIDTH], PlayerData *player) 
{
    int i, j;

    for (i = 0; i < HEIGHT; i++) 
    {
        for (j = 0; j < WIDTH; j++) 
        {
            if (i == player->pos.y && j == player->pos.x) 
            {
                printf("Y");
            }
            else 
            {
                printf("%c", dungeon[i][j]);
            }
        }
        printf("\n");
    }  
}


/* 
Handles the battle phase inside a dungeon floor. Manages player movement, item usage, enemy interactions, and tile effects.
Precondition: player, items, dungeons, and DUNGselection must be properly initialized. Dungeon layout and bat behavior depend on floor and selection.

@param player a pointer to the PlayerData struct representing the current player state
@param items an array of ItemShop structs representing items the player owns
@param dungeons an array of Dungeon structs with current dungeon information
@param currentFloor the current floor number in the selected dungeon
@param totalFloors the total number of floors for this dungeon
@param dungeonNum the index of the currently selected dungeon from the dungeon array
@param DUNGselection a pointer to the DungeonSelection struct tracking selected dungeons in the playthrough
@return 0 if the player dies, 1 if the player successfully completes the final floor, 2 if moving to the next floor
*/
int battle(PlayerData *player, ItemShop items[], Dungeon dungeons[], 
				int currentFloor, int totalFloors, int dungeonNum, 
										DungeonSelection *DUNGselection)
{
	char dungeon[HEIGHT][WIDTH]; 
	Bat bats[MAX_BATS];
	Wall walls[MAX_WALL];
	Spike spikes[MAX_SPIKES];
	Treasure treasure[1];
	Exit exit[1];
	Water water[MAX_WATER];
	Heat heats[MAX_HEAT];
	
	int gameOver = 0, turnCount = 0;
	int i;
	char input;
	int newX, newY, playerMoved;
	int dig, destroy, atacc;
	char currentTile;
	int ataccWall, ataccSpike, ataccBat, goldDrop;
	char targetTile;
	int nItemsAvailable = 0;
	int nItems[ITEM_COUNT];
	int itemIDX = -1;
	int equipItemIDX;
	int IDX;
	int goldAmount;
	int roll;
	
	player->pos.x = WIDTH / 2;
	player->pos.y = HEIGHT / 2;
	
	for (i = 0; i < MAX_BATS; i++)
    {
    	for (i = 0; i < MAX_BATS; i++) 
		{
		    bats[i].active = 1;
		    bats[i].pos.x = rand() % WIDTH;
		    bats[i].pos.y = rand() % HEIGHT;
		}
		    if (bats[i].active) 
        {
            if (bats[i].Attacked == 1) 
            {
                dungeon[bats[i].pos.y][bats[i].pos.x] = 'B';
            }
            else 
            {
                dungeon[bats[i].pos.y][bats[i].pos.x] = 'b';
            }
        }
    }
	
	createDungeon(dungeon, treasure, walls, water, spikes, heats, exit);
	
	for (i = 0; i < MAX_BATS; i++)
    {
        int attempts = 0;
        do {
            bats[i].pos.x = rand() % WIDTH;
            bats[i].pos.y = rand() % HEIGHT;
            attempts++;
        } while (dungeon[bats[i].pos.y][bats[i].pos.x] != '.' && attempts < 100);
        
        if (attempts < 100) {  // Successfully found empty spot
            bats[i].active = 1;
            
            if (player->ChebiMiloBibo == 1)
		    {
		    	bats[i].damage = 0.5;
			}
			else if (player->ChebiMiloBibo == 2)
			{
				bats[i].damage = 1;
			}
			else if (player->ChebiMiloBibo == 3)
			{
				bats[i].damage = 1.5;
			}
            bats[i].Attacked = 0;
            dungeon[bats[i].pos.y][bats[i].pos.x] = 'b';
        } else {
            bats[i].active = 0; 
        }
    }
	
	nItemsAvailable = 0;
	
	for (i = 0; i < ITEM_COUNT; i++)
	{
		if (items[i].itemOwned > 0)
		{
			nItems[nItemsAvailable] = i;
			nItemsAvailable++;
		}
	}
	
	if (nItemsAvailable == 0)
	{
		itemIDX = -1;
	}
	else
	{
		itemIDX = 0;
	}
	
	while(!gameOver)
	{
		system("cls");
	    printf("turncount: %d\n", turnCount);
	    printf("=== Floor %d of %d ===\n", currentFloor, totalFloors);
		printf("HP:%.1f / %.1f  \t\tTotal Gold: %d\n", player->hp, player->maxHP, player->gold);
		printf("Item on Hand:");
		
		if (nItemsAvailable == 0)
		{
			printf(" N/A\n");
		}
		else
		{
			equipItemIDX = nItems[itemIDX];
			printf(" %s (%d)\n", items[equipItemIDX].itemName, items[equipItemIDX].itemOwned);
		}	
		
		
		printf("[ Previous Item OR ] Next Item OR [Space] Use Item\n");
		
		printDungeon(dungeon, player);
		
		input = _getch();
			
			newX = player->pos.x;
	    	newY = player->pos.y;
	    	playerMoved = 0;
	    	
	    	if (input == 'w' || input == 'W')
	    	{
	    		newY = (player->pos.y > 0) ? player->pos.y - 1 : player->pos.y;
	    		turnCount++;
	    		playerMoved = 1;
			}
	        else if (input == 's' || input == 'S')
	        {
	        	newY = (player->pos.y < HEIGHT - 1) ? player->pos.y + 1 : player->pos.y;
	        	turnCount++;
	        	playerMoved = 1;
			}
	        else if (input == 'a' || input == 'A')
	        {
	        	newX = (player->pos.x > 0) ? player->pos.x - 1 : player->pos.x;
	        	turnCount++;
	        	playerMoved = 1;
			}
	        else if (input == 'd' || input == 'D')
	        {
	        	newX = (player->pos.x < WIDTH - 1) ? player->pos.x + 1 : player->pos.x;
	        	turnCount++;
	        	playerMoved = 1;
			}
			else if (input == 'x' || input == 'X')
			{
				turnCount++;
				playerMoved = 1;
			}
			else if (input == '[')
			{
				turnCount++;
				playerMoved = 1;
				
				if (nItemsAvailable > 0)
				{
					itemIDX = (itemIDX - 1 + nItemsAvailable) % nItemsAvailable;
					printf("%s\n", items[nItems[itemIDX]].itemName);
				}
				else
				{
					printf("N/A\n");
				}
			}
			else if (input == ']')
			{
				turnCount++;
				playerMoved = 1;
				
				if (nItemsAvailable > 0)
				{
					itemIDX = (itemIDX + 1 + nItemsAvailable) % nItemsAvailable;
					printf("%s\n", items[nItems[itemIDX]].itemName);
				}
				else
				{
					printf("N/A\n");
				}
			}
			else if (input == ' ')
			{
				turnCount++;
    			playerMoved = 1;
    			
    			if (nItemsAvailable > 0)
    			{
    				IDX = nItems[itemIDX];
    				
    				if (strcmp(items[IDX].itemName, "Noppo Bread") == 0)
    				{
    					if (player->hp >= player->maxHP)
    					{
    						printf("ERROR! You already have a full hp.\n");
						}
						else
						{
							printf("You successfully used an item!\n");
							player->hp += 0.5;
							items[IDX].itemOwned -= 1;
							
							nItemsAvailable = 0;
			                for (i = 0; i < ITEM_COUNT; i++)
			                {
			                    if (items[i].itemOwned > 0)
			                    {
			                        nItems[nItemsAvailable] = i;
			                        nItemsAvailable++;
			                    }
			                }
			                
			                if (nItemsAvailable == 0)
			                {
			                    itemIDX = -1;
			                }
			                else if (itemIDX >= nItemsAvailable)
			                {
			                    itemIDX = 0;
			                }
						}
					}
					else if (strcmp(items[IDX].itemName, "Tears of a fallen angel")== 0)
					{
						if (player->hp == player->maxHP)
    					{
    						printf("ERROR! You already have a full hp.\n");
						}
						else
						{
							printf("You successfully used an item!\n");
							player->hp += 0.5;
							items[IDX].itemOwned -= 1;
							
							nItemsAvailable = 0;
			                for (i = 0; i < ITEM_COUNT; i++)
			                {
			                    if (items[i].itemOwned > 0)
			                    {
			                        nItems[nItemsAvailable] = i;
			                        nItemsAvailable++;
			                    }
			                }
			                
			                if (nItemsAvailable == 0)
			                {
			                    itemIDX = -1;
			                }
			                else if (itemIDX >= nItemsAvailable)
			                {
			                    itemIDX = 0;
			                }
						}
					}
					else if (strcmp(items[IDX].itemName, "Choco-Mint Ice Cream")== 0)
					{
						printf("This item automatically activates.\n");
						printf("You've wasted your turn.\n");
						printf("Sorry! :P\n");
					}
				}
				else
				{
					printf("You dont have an item.\n");
					printf("You've wasted your turn.\n");
				}
				_getch();
			}
			else if (input == '`')
			{
				roll = rand() % 100;
				if (roll < 40) 
				{
					printf("Bibo: How did you find me?\n");
					player->gold += 200;
					printf("You have received money from Bibo!\n");
					_getch();
				}
				else if (roll < 50)
				{
					printf("Chebi: How did you find me?\n");
					player->gold += 150;
					printf("You have received money from Chebi!\n");
					_getch();
				}
				else
				{
					printf("Milo: How did you find me?\n");
					player->gold += 150;
					printf("You have received money from Milo!\n");
					_getch();
				}
			}
			else
			{
				turnCount++;
	    		playerMoved = 1;
			}
			
			if (playerMoved && (input == 'w' || input == 'W' || input == 's' || input == 'S' || 
		                   input == 'a' || input == 'A' || input == 'd' || input == 'D'))
			{
				ataccWall = 0;
				ataccSpike = 0;
				ataccBat = 0;
				targetTile = dungeon[newY][newX];
				
				if (targetTile == 'v')
	    		{
	    			dig = digWall(dungeon, newX, newY);
	    			if (dig)
	    			{
	    				printf("You dug through a wall!\n");
	    				ataccWall = 1;
	    				walls[(unsigned char)targetTile].active = 0;
	    				_getch();
	    			}
	    		}
				else if (targetTile == 'x')
	    		{
	    			destroy = destroySpike(dungeon, newX, newY);
	    			
					if (destroy)
	    			{
	    				printf("You destroyed a spike!\n");
	    				player->hp -= 0.5;
	    				printf("Oh No! You got hurt! -0.5 hp\n");
	    				ataccSpike = 1;
	    				spikes[(unsigned char)targetTile].active = 0;
	    				
	    				if (player->hp <= 0)
				        {
				            if (!checkRevivalItem(player, items, nItems, itemIDX, nItemsAvailable)) {
				                printf("You have died!\n");
				                printf("Press any key to return to main menu...\n");
				                _getch();
				                gameOver = 1;
				            }
				        }
	    				_getch();
	    			}
	    		}
	    		else if (targetTile == 'b' || targetTile == 'B')
	    		{
	    			atacc = attackBat(dungeon, newX, newY, bats);
	    			
	    			if (atacc)
	    			{
	    				printf("You attacked a Bat!\n");
		    			ataccBat = 1;
		    			bats[(unsigned char)targetTile].active = 0;
		    			
						if (player->ChebiMiloBibo == 1)
		    			{
		    				goldDrop = 5;
						}
						else if (player->ChebiMiloBibo == 2)
						{
							goldDrop = 10;
						}
						else if (player->ChebiMiloBibo == 3)
						{
							goldDrop = 15;
						}
						
		    			printf("\nYou attacked and killed the bat! It turned into a gold tile worth %d gold!\n", goldDrop);
			            printf("Press any key to continue...\n");
			            _getch();
					}
				}
	    		else if (targetTile == 'w')
	    		{
	    			printf("Sorry, You can't go here.\n");
	    			_getch();
				}
				
				if (!ataccBat && !ataccWall && !ataccSpike && dungeon[newY][newX] != '*' && 
					dungeon[newY][newX] != 'w') // Can't move into walls
				{
					player->pos.x = newX;
					player->pos.y = newY;
				}
			}
			
			if(playerMoved)
			{
				
				currentTile = dungeon[player->pos.y][player->pos.x];
			
				if (currentTile == 'E')
				{
					if (currentFloor < totalFloors)
					{
						printf("Moving to the next floor\n");
						_getch();
						return 2;
					}
					else
					{
						printf("You found the exit!\n");
						_getch();
						return 1;
					}
				}
				else if (currentTile == 'T')
				{
					if (rand() % 2 == 0)
					{
						goldAmount = 10 + rand() % 91;
						player->gold += goldAmount;
						printf("You found %d gold!\n", goldAmount);
					}
					else
					{
						for (i = 0; i < ITEM_COUNT; i++)
						{
							if (strcmp(items[i].itemName, "Noppo Bread") == 0)
							{
								items[i].itemOwned++;
								printf("You found Noppo Bread!\n");
							}
						}
					}
					dungeon[player->pos.y][player->pos.x] = '.'; // Remove treasure
					_getch();
				}
				else if (currentTile == 'h')
				{
					printf("You stepped on heat tile!\n");
					printf("You got hurt! -1 hp.\n");
					player->hp -= 1;
					
					if (player->hp <= 0)
					{
					    if (!checkRevivalItem(player, items, nItems, itemIDX, nItemsAvailable)) 
						{
					        printf("You have died!\n");
					        printf("Press any key to return to main menu...\n");
					        _getch();
					        gameOver = 1;
					    }
					}
					
					_getch();
				}
				else if (currentTile == 'g')
				{
					printf("You picked %d\n", goldDrop);
					
					if (player->ChebiMiloBibo == 1)
		    		{
		    			goldDrop = 5;
					}
					else if (player->ChebiMiloBibo == 2)
					{
						goldDrop = 10;
					}
					else if (player->ChebiMiloBibo == 3)
					{
						goldDrop = 15;
					}
						
					player->gold += goldDrop;
					printf("Press any key to continue...\n");
					dungeon[player->pos.y][player->pos.x] = '.';
			        _getch();
				}
				
					if (player->hp <= 0)
					{
					    if (!checkRevivalItem(player, items, nItems, itemIDX, nItemsAvailable)) 
						{
					        printf("You have died!\n");
					        printf("Press any key to return to main menu...\n");
					        _getch();
					        gameOver = 1;
					    }
					}
			}
			
			for (i = 0; i < MAX_BATS; i++)
	        {
	            if (bats[i].active) 
	            {
	                int batX = bats[i].pos.x;
	                int batY = bats[i].pos.y;
	                
	                
	                int dx = abs(batX - player->pos.x);
	                int dy = abs(batY - player->pos.y);
	                
	                if ((dx == 1 && dy == 0) || (dx == 0 && dy == 1)) 
	                {
	                    player->hp -= bats[i].damage;
	                    bats[i].Attacked = 1; 
	                    
	                    printf("\nA bat attacked you from (%d,%d)! Lost %.1f HP!\n", batX, batY, bats[i].damage);
	                    printf("The attacking bat is now showing as uppercase 'B'!\n");
	                    printf("Press any key to continue...\n");
	                    _getch();
	                    
	                    if (player->hp <= 0)
						{
						    if (!checkRevivalItem(player, items, nItems, itemIDX, nItemsAvailable)) 
							{
						        printf("You have died!\n");
						        printf("Press any key to return to main menu...\n");
						        _getch();
						        gameOver = 1;
						    }
						}
	                    
	                    i = MAX_BATS; 
	                }
	            }
	        }
			
			// Reset attacked bats at the very end of the turn
			for (i = 0; i < MAX_BATS; i++)
			{
			    if (bats[i].Attacked == 1) {
			        bats[i].Attacked = 0;  // Reset for next turn
			    }
			}
	        
	}
	return 0;
}

/* Saves game data to a binary file
Precondition: All structs must be initialized

@param player Pointer to the PlayerData struct
@param dungeons Array of Dungeon structs
@return void */
void saveGame(PlayerData *player, Dungeon dungeons[], ItemShop items[])
{
	FILE *file = fopen("savegame.dat", "wb");
    
	if (file == NULL) 
	{
        printf("Failed to open save file.\n");
    }

    fwrite(player, sizeof(PlayerData), 1, file);
    fwrite(dungeons, sizeof(Dungeon), TOTAL_CHARACTERS2SAVE, file);
    fwrite(items, sizeof(ItemShop), ITEM_COUNT, file);

    fclose(file);
    printf("Game saved successfully.\n");
}

/* Loads game data from a binary file
Precondition: All pointers must point to valid memory

@param player Pointer to the PlayerData struct
@param dungeons Array of Dungeon structs
@return void */
void loadGame(PlayerData *player, Dungeon dungeons[], ItemShop items[])
{
    FILE *file = fopen("savegame.dat", "rb");
    
	if (file == NULL) 
	{
        printf("No save file found. Starting new game.\n");
    }

    fread(player, sizeof(PlayerData), 1, file);
    fread(dungeons, sizeof(Dungeon), TOTAL_CHARACTERS2SAVE, file);
    fread(items, sizeof(ItemShop), ITEM_COUNT, file);

    fclose(file);
    printf("Game loaded successfully (binary).\n");
}

/* Displays the shop and handles item purchase logic
Precondition: Player and item data must be initialized. Dungeons must reflect rescued characters.

@param player Pointer to player data
@param items Array of items available in the game
@param dungeons Array of dungeon data for character rescue tracking
@return void */
void hanamaruShop(PlayerData *player, ItemShop items[], Dungeon dungeons[])
{
    int i;
    char choice[10];
    int selectedItem = -1;;
    int canBuy;
    int shopOpen = 1;

    while (shopOpen) 
    {
    	system("cls");
        printf("\t\n=== Hanamaru's Shop ===\n\n");
        printf("Hanamaru: Yohane-chan, zura! What can I do for you today?\n\n");
        printf("Gold: %d GP\n", player->gold);
        for (i = 0; i < ITEM_COUNT; i++) 
        {
            canBuy = 0;

            // Unlock condition
            if (strcmp(items[i].itemName, "Tears of a Fallen Angel") == 0 || 
                strcmp(items[i].itemName, "Noppo Bread") == 0) 
            {
                canBuy = 1;
            } 
            else if (strcmp(items[i].itemName, "Shovel Upgrade") == 0 && dungeons[3].characterToSave[0].rescued) 
            {
                canBuy = 1;
            } 
            else if (strcmp(items[i].itemName, "Bat Tamer") == 0 && dungeons[2].characterToSave[0].rescued) 
            {
                canBuy = 1;
            } 
            else if (strcmp(items[i].itemName, "Air Shoes") == 0 && dungeons[1].characterToSave[0].rescued) 
            {
                canBuy = 1;
            } 
            else if (strcmp(items[i].itemName, "Stewshine") == 0 && dungeons[0].characterToSave[0].rescued) 
            {
                canBuy = 1;
            } 
            else if (strcmp(items[i].itemName, "Mikan Mochi") == 0 && dungeons[4].characterToSave[0].rescued) 
            {
                canBuy = 1;
            } 
            else if (strcmp(items[i].itemName, "Kurosawa Macha") == 0 && dungeons[5].characterToSave[0].rescued) 
            {
                canBuy = 1;
            } 
            else if (strcmp(items[i].itemName, "Choco-Mint Ice Cream") == 0 && dungeons[6].characterToSave[0].rescued) 
            {
                canBuy = 1;
            }

            if (canBuy) 
            {
                printf("[%d] %s - %d GP", i + 1, items[i].itemName, items[i].itemPrice);
                if (items[i].itemOwned > 0) 
                {
                    printf(" [SOLD]");
                }
                printf("\n");
            }
        }

        printf("[R]eturn\n");
        printf("Choose item number to buy: ");
        scanf("%s", choice);
        
        if (strcmp(choice, "R") == 0 || strcmp(choice, "r") == 0)
        {
            shopOpen = 0;
        }
        else
        {
            int selected = atoi(choice) - 1;

            if (selected >= 0 && selected < ITEM_COUNT)
            {
                if (items[selected].itemOwned > 0)
                {
                    printf("You already purchased %s.\n", items[selected].itemName);
                    printf("You can't purchase anymore of this item this playthrough!\n One is enough\n");
                }
                else if (player->gold >= items[selectedItem].itemPrice) 
                {
                    player->gold -= items[selectedItem].itemPrice;
                    items[selectedItem].itemOwned = 1;
                	printf("You bought %s!\n", items[selectedItem].itemName);
	            } 
	            else 
	            {
	                printf("Not enough gold to buy %s!\n", items[selectedItem].itemName);
	            }
                printf("Press any key to continue...\n");
                _getch();
            }
        } 
    }
}


/* 
Main gameplay loop where the player selects and enters dungeons, uses items, visits shops, and saves progress.
Precondition: player, items, dungeons, and DUNGselection are all properly initialized.

@param player a pointer to PlayerData struct holding the current player's status
@param items an array of ItemShop structs representing all available items
@param dungeons an array of Dungeon structs containing all dungeon data
@param dungeonNum the total number of dungeons in the game
@param DUNGselection a pointer to DungeonSelection struct tracking selected dungeons for the current run
@return none
*/
void gameplay(PlayerData *player, ItemShop items[], Dungeon dungeons[], 
		Achievement achieve[], DungeonSelection *DUNGselection, AchievementNotif *queue)
{
    int i;
    char choice[10];
    int usedRAN[8] = {0};
    int num, index;
    int isDone = 0;
    int selected;
    int floors;
    int allDUNGCompleted;
    int gameRunning = 1;
    int DUNGresult;
    int currentFloor;
    int nItemsAvailable = 0;
	int nItems[ITEM_COUNT];
	int itemIDX = -1;
	int equipItemIDX;
	int dungeonSuccess;
	int chika, riko,you, hana,ruby, dia, kanan, mari;
	int clearedCount;
	
    
    
    while (gameRunning)
    {
        system("cls");
        printf("Lailaps: Yohane! Where should we go to now?\n\n");
        printf("HP:%.1f / %.1f  \t\tTotal Gold: %d\n", player->hp, player->maxHP, player->gold);
        printf("Item on Hand:");
        
        nItemsAvailable = 0;
	
		for (i = 0; i < ITEM_COUNT; i++)
		{
			if (items[i].itemOwned > 0)
			{
				nItems[nItemsAvailable] = i;
				nItemsAvailable++;
			}
		}
		
		if (nItemsAvailable == 0)
		{
			itemIDX = -1;
		}
		else
		{
			itemIDX = 0;
		}
		
		if (nItemsAvailable == 0)
		{
			printf(" N/A\n");
		}
		else
		{
			equipItemIDX = nItems[itemIDX];
			printf(" %s (%d)\n", items[equipItemIDX].itemName, items[equipItemIDX].itemOwned);
		}
        
        // Initialize dungeon selection only once
        while (!DUNGselection->isInitialized)
        {
            srand(time(NULL));
            
            for (i = 0; i < 3;) 
            {
                num = rand() % 8;
                
                if (!usedRAN[num]) 
                {
                    DUNGselection->selectedDungeons[i] = num;
                    usedRAN[num] = 1;
                    i++;
                }
            }
            
            DUNGselection->isInitialized = 1;
        }
        
        printf("\nChoose a dungeon to visit:\n");
    
        for (i = 0; i < 3; i++) 
        {
            index = DUNGselection->selectedDungeons[i];
            
            if (dungeons[index].complete) 
            {
                printf("[X] Visit %s (COMPLETED)\n", dungeons[index].dungeonName);
            } else 
            {
                printf("[%d] Visit %s\n", i + 1, dungeons[index].dungeonName);
            }
        }
        
        allDUNGCompleted = 1;
        for (i = 0; i < 3; i++)
        {
            if (!dungeons[DUNGselection->selectedDungeons[i]].complete)
            {
                allDUNGCompleted = 0;
            }
        }
        
        if(allDUNGCompleted)
        {
            printf("\n*** ALL DUNGEONS COMPLETED! FINAL BOSS AWAITS! ***\n");
            printf("[F]ace the Siren of Numazu \n");
        }
        
        printf("\n\n[I] Inventory\n[S] Save and Quit\n");
        
		if (strcmp(dungeons[3].characterToSave[0].name, "Hanamaru") == 0 &&
		    dungeons[3].characterToSave[0].rescued == 1)
		{
		    printf("\n\n[H]anamaru's Shop\n");
		}
        
        isDone = 0;
        
        while (isDone == 0) 
        {
            printf("\nChoice: ");
            scanf("%9s", choice);
            
            if (strcmp(choice, "I") == 0 || strcmp(choice, "i") == 0) 
            {
				system("cls");
				printf("Lailaps: These are the items you have, Yohane!\nHP: %.0f / %.0f Total Gold: %d GP\n\n",
                		player->hp, player->maxHP, player->gold);
                printf("Items available\n");
                
				int trackableItems[3] = {0, 1, 8}; // Indices for: Tears of fallen angel, Noppo bread, Choco-mint ice cream
    
			    for (i = 0; i < 3; i++) 
			    {
			        int itemIndex = trackableItems[i];
			        printf("%d. %s x %d\n", i + 1, items[itemIndex].itemName, items[itemIndex].itemOwned);
			    }
			    
			    printf("\n[R]eturn\n");
			    
			    char inventoryChoice;
			    int inventoryDone = 0;
			    
			    while (!inventoryDone) {
			        printf("Choice: ");
			        scanf(" %c", &inventoryChoice); // Note: using %c for single character, space before % to consume whitespace
			        
			        switch(inventoryChoice)
			        {
			            case '1': 
			                if (items[trackableItems[0]].itemOwned > 0) 
							{   
								if (player->hp >= player->maxHP)
								{
									printf("ERROR! FULL HP.\n");
								}
								else
								{
									printf("You used %s!\n", items[trackableItems[0]].itemName);
									player->hp += .5;
			                    	items[trackableItems[0]].itemOwned--;
								}
			                } else {
			                    printf("You don't have any %s!\n", items[trackableItems[0]].itemName);
			                }
			                printf("Press any key to continue...\n");
			                _getch();
			                break;
			                
			            case '2':
			                if (items[trackableItems[1]].itemOwned > 0) 
							{
			                    if (player->hp >= player->maxHP)
								{
									printf("ERROR! FULL HP.\n");
								}
								else
								{
									printf("You used %s!\n", items[trackableItems[1]].itemName);
									player->hp += .5;
			                    	items[trackableItems[0]].itemOwned--;
								}
			                } 
							else
							{
			                    printf("You don't have any %s!\n", items[trackableItems[1]].itemName);
			                }
			                printf("Press any key to continue...\n");
			                _getch();
			                break;
			                
			            case '3':
			                if (items[trackableItems[2]].itemOwned > 0) 
							{
			                    printf("You can't use the item: %s\n", items[trackableItems[2]].itemName);
			                } 
							else 
							{
			                    printf("You don't have any %s!\n", items[trackableItems[2]].itemName);
			                }
			                printf("Press any key to continue...\n");
			                _getch();
			                break;
			                
			            case 'R':
			            case 'r':
			                inventoryDone = 1;
			                system("cls");
					        printf("Lailaps: Yohane! Where should we go to now?\n\n");
					        printf("HP:%.1f / %.1f  \t\tTotal Gold: %d\n", player->hp, player->maxHP, player->gold);
					        printf("Item on Hand:");
					        nItemsAvailable = 0;
	
							for (i = 0; i < ITEM_COUNT; i++)
							{
								if (items[i].itemOwned > 0)
								{
									nItems[nItemsAvailable] = i;
									nItemsAvailable++;
								}
							}
							
							if (nItemsAvailable == 0)
							{
								itemIDX = -1;
							}
							else
							{
								itemIDX = 0;
							}
							
							if (nItemsAvailable == 0)
							{
								printf(" N/A\n");
							}
							else
							{
								equipItemIDX = nItems[itemIDX];
								printf(" %s (%d)\n", items[equipItemIDX].itemName, items[equipItemIDX].itemOwned);
							}
							
							printf("\nChoose a dungeon to visit:\n");
    
					        for (i = 0; i < 3; i++) 
					        {
					            index = DUNGselection->selectedDungeons[i];
					            
					            if (dungeons[index].complete) 
					            {
					                printf("[X] Visit %s (COMPLETED)\n", dungeons[index].dungeonName);
					            } else 
					            {
					                printf("[%d] Visit %s\n", i + 1, dungeons[index].dungeonName);
					            }
					        }
							
							printf("\n\n[I] Inventory\n[S] Save and Quit\n");
							
			                break;
			                
			            default:
			                printf("Invalid choice. Please try again.\n");
			                break;
			        }
			    }
            }
            else if ((strcmp(choice, "F") == 0 || strcmp(choice, "f") == 0) && allDUNGCompleted) 
            {
                printf("Entering the Mirror World for the final battle...\n");
                printf("Press any key to begin...\n");
                _getch();
                
                int bossResult = bossBattle(player, items, dungeons, achieve, queue);
                
                if (bossResult == 1) 
                {
                    printf("*** CONGRATULATIONS! ***\n");
                    printf("You have successfully completed the game!\n");
                    printf("Yohane and all the Aqours members are safe!\n");
                    
                    markAchievementEarned(&achieve[9], queue); 
                    

                    if (hasAchievementNotifications(queue))
                    {
                        displayAchievementNotifications(queue);
                    }
                    
                    printf("Press any key to return to main menu...\n");
                    _getch();
                    
                    isDone = 1;
                    gameRunning = 0;
                    player->toMainMenu = 1;
                }
                else 
                {
                    
                    printf("The final battle was lost...\n");
                    printf("But don't give up! Try again when you're ready.\n");
                    printf("Press any key to continue...\n");
                    _getch();
                    
                    // Return to gameplay menu (don't end the game)
                    isDone = 1;
                }
            }
            else if (strcmp(choice, "S") == 0 || strcmp(choice, "s") == 0) 
            {
                printf("Game saved! Goodbye.\n");
                saveGame(player,dungeons, items);
                isDone = 1;
                gameRunning = 0;
                player->toMainMenu = 1;
            }
            else if ((strcmp(choice, "H") == 0 || strcmp(choice, "h") == 0)) 
			{
			    if (strcmp(dungeons[3].characterToSave[0].name, "Hanamaru") == 0 &&
			        dungeons[3].characterToSave[0].rescued == 1) 
			    {
			        hanamaruShop(player, items, dungeons);
			    }
			    else 
			    {
			        printf("Hanamaru's shop is not available yet.\n");
			        _getch();
			    }
			}
			else if (strcmp(choice, "P") == 0)
			{
				debugDungeonStatus(dungeons);
                isDone = 1;
			}
			
            else if (strcmp(choice, "1") == 0 || strcmp(choice, "2") == 0 || strcmp(choice, "3") == 0) 
            {
                selected = atoi(choice) - 1;
                
                if (selected >= 0 && selected < 3) 
                {
                    index = DUNGselection->selectedDungeons[selected];
                    
                    if (dungeons[index].complete) 
                    {
                        printf("That dungeon is already completed. Pick another.\n");
                        printf("Press any key to continue...\n");
                        _getch();
                    } else 
                    {   
                        
                        if (selected == 0)
                        {
                            floors = 1;
                            player->ChebiMiloBibo = 1;
                        }
                        else if (selected == 1)
                        {
                            floors = 2 + rand() % 2;
							player->ChebiMiloBibo = 2; 
                        }
                        else if (selected == 2)
                        {
                             floors = 3 + rand() % 2;
                             player->ChebiMiloBibo = 3;
                        }
                        
                        printf("Entering %s...\n", dungeons[index].dungeonName);
                        printf("This dungeon has %d floor(s) to complete!\n\n", floors);
                        printf("Press any key to start...\n");
                        _getch();
                        
                        dungeonSuccess = 1;
                        
                        for (currentFloor = 1; currentFloor <= floors; currentFloor++)
                        {
                            printf("\n--- Floor %d of %d ---\n", currentFloor, floors);
                            DUNGresult = battle(player, items, dungeons, 
                                        currentFloor, floors, index, DUNGselection);
                            
                            if (DUNGresult == 0) 
                            {
                                printf("You died in the dungeon!\n");
                                dungeonSuccess = 0;
                                
                            }
                        }
                        
                        if (dungeonSuccess && DUNGresult == 1) 
                        {
                            dungeons[index].complete = 1;
                            dungeons[index].characterToSave[0].rescued = 1;
                            
                            if (index == 0) // Chika
				            {
				                markAchievementEarned(&achieve[1], queue);
				            }
				            else if (index == 1) // Riko
				            {
				                markAchievementEarned(&achieve[2], queue); 
				            }
				            else if (index == 2) // You
				            {
				                markAchievementEarned(&achieve[3], queue);
				            }
				            else if (index == 3) // Hanamaru
				            {
				                markAchievementEarned(&achieve[4], queue);
				            }
				            else if (index == 4) // Ruby
				            {
				                markAchievementEarned(&achieve[5], queue);
				            }
				            else if (index == 5) // Dia
				            {
				                markAchievementEarned(&achieve[6], queue); 
				            }
				            else if (index == 6) // Kanan
				            {
				                markAchievementEarned(&achieve[7], queue); 
				            }
				            else if (index == 7) // Mari
				            {
				                markAchievementEarned(&achieve[8], queue);
				            }
						
						    clearedCount = 0;
						    for ( i = 0; i < TOTAL_CHARACTERS2SAVE; i++) 
						    {
						        if (dungeons[i].complete)
						            clearedCount++;
						    }
						
						    if (clearedCount == 1)
						        markAchievementEarned(&achieve[0], queue); 
						
						    chika = dungeons[0].characterToSave[0].rescued;
						    riko  = dungeons[1].characterToSave[0].rescued;
						    you   = dungeons[2].characterToSave[0].rescued;
						    hana  = dungeons[3].characterToSave[0].rescued;
						    ruby  = dungeons[4].characterToSave[0].rescued;
						    dia   = dungeons[5].characterToSave[0].rescued;
						    kanan = dungeons[6].characterToSave[0].rescued;
						    mari  = dungeons[7].characterToSave[0].rescued;
						
						    // Group achievements
						    if (chika && you && ruby)
						        markAchievementEarned(&achieve[20], queue); // "CYaRon!"
						    if (hana && dia && kanan)
						        markAchievementEarned(&achieve[21], queue); // "AZALEA!"
						    if (riko && mari)
						        markAchievementEarned(&achieve[22], queue); // "Guilty Kiss!"
						
						    // All characters rescued
						    if (chika && riko && you && hana && ruby && dia && kanan && mari)
						        markAchievementEarned(&achieve[23], queue); // "Eikyuu Hours!"
						        
						    // Display achievement notifications FIRST
				            if (hasAchievementNotifications(queue))
				            {
				                displayAchievementNotifications(queue);
				            }
				            printf("************************************************************\n");
                            printf("\n*** DUNGEON CLEARED! ***\n");
                            printf("You successfully cleared %s!\n", dungeons[index].dungeonName);
                            printf("%s rescued!\n", dungeons[index].characterToSave[0].name);
                            printf("************************************************************\n");
                            
                            if (index == 3) // Hanamaru example
				            {
				                printf("Hanamaru: Yohane-chan, zura! You're here!\n");
				                printf("Yohane: Hanamaru! We have to get out of here quickly!\n");
				                printf("Hanamaru: Oh? I was wondering what this place was and why there are bats everywhere, zura!\n");
				                printf("Yohane: Seems like there's a Siren that wants to take your voices and is holding you in this dimension so that your counterparts in the real world can't sing!\n");
				                printf("Hanamaru: Really? That sounds terrifying, zura. What have we got to do?\n");
				                printf("Yohane: First, we have to get out of here, Zuramaru! I know the way out.\n");
				                printf("Hanamaru: Lead the way, zura!\n");
				            }
				            
				            printf("[R]eturn\n");
                            printf("Press any key to return to dungeon selection...\n");
							_getch();
                            gameRunning = 0;
                            
                        }
                        else if (!dungeonSuccess)
                        {
                            printf("Returning to main menu after defeat...\n");
                            gameRunning = 0;
                        }
                        
                        isDone = 1;
                    }
                } else
                {
                    printf("Invalid choice. Try again.\n");
                }
            }
            else 
            {
                printf("Invalid input. Try again.\n");
            }
        }
    }
}

