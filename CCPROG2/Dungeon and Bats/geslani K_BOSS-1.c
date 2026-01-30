/*  
    Description: boss battle
    Programmed by: Keila Franchoise Leigh Geslani 
    Last modified: July 30, 2025  
    Version: 12.0  
    [Acknowledgements: https://cplusplus.com, cppreference.com, dlsu.instructure.ph, old MPs, old Exams,
					worldcounter.net(counting chars)]  
*/
#include "geslani K_struct.h"
/* Initializes the boss battle state, positions of Yohane, Lailaps, Siren, and the switches  
Precondition: dungeon is a valid 2D array of dimensions HEIGHT x WIDTH, player and items are properly initialized  

@param dungeon 2D character array representing the dungeon map  
@param boss pointer to BossBattleState struct holding battle state variables  
@param player pointer to PlayerData struct representing player state  
@param achieve array of Achievement structs (not modified here)  
@param items array of ItemShop structs used to check for item ownership  
@return none */
void initializeBossBattle(char dungeon[][WIDTH], BossBattleState *boss, PlayerData *player, Achievement achieve[], ItemShop items[])
{
    boss->yohaneX = 24;
    boss->yohaneY = 10;
    boss->lailapsX = 25;
    boss->lailapsY = 10;
    boss->sirenX = 24;
    boss->sirenY = 1;
    boss->switchTriggersCompleted = 0;
    boss->moveCount = 0;
    boss->sirenReleased = 0;
    boss->battleWon = 0;
    boss->gameOver = 0;
    boss->iceCreamUsed = 0;
    
    if (items[8].itemOwned > 0)
    {
        boss->hasIceCream = 1;
    }
    else
    {
        boss->hasIceCream = 0;
    }
    
    generateSwitches(dungeon, boss);
}

/* Generates the boss dungeon layout including walls and switch placements  
Precondition: dungeon is a valid 2D array of dimensions HEIGHT x WIDTH, boss is initialized  

@param dungeon 2D character array representing the boss battle map  
@param boss pointer to BossBattleState struct to store switch positions  
@return none */
void BossMap(char dungeon[][WIDTH], BossBattleState *boss, BossBat bats[], int maxBats)
{
    int i, j, k;
    
    for (i = 0; i < HEIGHT; i++) 
    {
        for (j = 0; j < WIDTH; j++) 
        {
            if (i == 0 || i == HEIGHT - 1 || j == 0 || j == WIDTH - 1) 
            {
                dungeon[i][j] = '*';
            } 
            else 
            {
                dungeon[i][j] = '.'; 
            }
        }
    }
    

    if (boss->switchTriggersCompleted < 3)
    {

        for (j = 16; j <= 31; j++)
        {
            dungeon[3][j] = '*';
        }

        for (i = 1; i <= 3; i++)
        {
            dungeon[i][16] = '*';
            dungeon[i][31] = '*';
        }
    }
    

    if (boss->sirenReleased)
    {
        dungeon[boss->sirenY][boss->sirenX] = 'S';
    }
    else
    {
        dungeon[1][24] = 'S'; 
    }
    

    if (!boss->battleWon && boss->switchTriggersCompleted < 3)
    {
        dungeon[boss->switch1Y][boss->switch1X] = '0';
        dungeon[boss->switch2Y][boss->switch2X] = '0';
        // Removed switch3 reference since you only have 2 switches
    }
    

    if (boss->battleWon)
    {
        dungeon[1][24] = 'E'; 
    }
    

    for (k = 0; k < maxBats; k++)
    {
        if (bats[k].active)
        {
            dungeon[bats[k].y][bats[k].x] = 'B';
        }
    }
    
    dungeon[boss->yohaneY][boss->yohaneX] = 'Y';
    dungeon[boss->lailapsY][boss->lailapsX] = 'L';
}
/* Generates two unique switch positions in valid floor tiles within the dungeon  
Precondition: dungeon is a valid HEIGHT x WIDTH character array, boss pointer is valid  

@param dungeon 2D character array representing the boss map  
@param boss pointer to BossBattleState to store switch coordinates  
@return none */
void generateSwitches(char dungeon[][WIDTH], BossBattleState *boss)
{
    int attempts = 0;
    
    while (attempts < 100)
    {
        boss->switch1X = 1 + rand() % (WIDTH - 2);
        boss->switch1Y = 1 + rand() % (HEIGHT - 2);
        
        if (dungeon[boss->switch1Y][boss->switch1X] == '.')
        {
            attempts = 0;
            break;
        }
        attempts++;
    }
    
    while (attempts < 100)
    {
        boss->switch2X = 1 + rand() % (WIDTH - 2);
        boss->switch2Y = 1 + rand() % (HEIGHT - 2);
        
        if (dungeon[boss->switch2Y][boss->switch2X] == '.' && 
            !(boss->switch2X == boss->switch1X && boss->switch2Y == boss->switch1Y))
        {
            break;
        }
        attempts++;
    }
}
/* Spawns a new bat enemy in a valid random floor tile, avoiding switches and main characters  
Precondition: dungeon is a valid HEIGHT x WIDTH character array, bats is an initialized array  

@param dungeon 2D character array representing the boss map  
@param bats array of BossBat structures  
@param maxBats maximum number of bats allowed  
@param boss pointer to BossBattleState used to avoid placing bats on key positions  
@return none */
void spawnBat(char dungeon[][WIDTH], BossBat bats[], int maxBats, BossBattleState *boss)
{
    int i;
    int batIndex = -1;
    int attempts = 0;
    
    for (i = 0; i < maxBats; i++)
    {
        if (!bats[i].active)
        {
            batIndex = i;
            break;
        }
    }
    
    if (batIndex == -1) 
    {
        return;
    }
    
    while (attempts < 100)
    {
        bats[batIndex].x = 1 + rand() % (WIDTH - 2);
        bats[batIndex].y = 1 + rand() % (HEIGHT - 2);
        
        if (dungeon[bats[batIndex].y][bats[batIndex].x] == '.' &&
            !(bats[batIndex].x == boss->switch1X && bats[batIndex].y == boss->switch1Y) &&
            !(bats[batIndex].x == boss->switch2X && bats[batIndex].y == boss->switch2Y) &&
            !(bats[batIndex].x == boss->yohaneX && bats[batIndex].y == boss->yohaneY) &&
            !(bats[batIndex].x == boss->lailapsX && bats[batIndex].y == boss->lailapsY))
        {
            bats[batIndex].active = 1;
            bats[batIndex].dungeonLevel = boss->switchTriggersCompleted + 1;
            break;
        }
        attempts++;
    }
}
/* Checks if both Yohane and Lailaps are standing on different switches at the same time  
Precondition: boss contains valid coordinates for both characters and both switches  

@param boss pointer to BossBattleState containing switch and character positions  
@return 1 if both switches are triggered correctly, 0 otherwise */
int checkSwitchActivation(BossBattleState *boss)
{
    int yohaneOnSwitch = 0;
    int lailapsOnSwitch = 0;
    
    if ((boss->yohaneX == boss->switch1X && boss->yohaneY == boss->switch1Y) ||
        (boss->yohaneX == boss->switch2X && boss->yohaneY == boss->switch2Y))
    {
        yohaneOnSwitch = 1;
    }
    
    if ((boss->lailapsX == boss->switch1X && boss->lailapsY == boss->switch1Y) ||
        (boss->lailapsX == boss->switch2X && boss->lailapsY == boss->switch2Y))
    {
        lailapsOnSwitch = 1;
    }
    
    if (yohaneOnSwitch && lailapsOnSwitch &&
        !((boss->yohaneX == boss->switch1X && boss->yohaneY == boss->switch1Y) &&
          (boss->lailapsX == boss->switch1X && boss->lailapsY == boss->switch1Y)) &&
        !((boss->yohaneX == boss->switch2X && boss->yohaneY == boss->switch2Y) &&
          (boss->lailapsX == boss->switch2X && boss->lailapsY == boss->switch2Y)))
    {
        return 1;
    }
    
    return 0;
}
/* Moves the Siren one tile closer to Yohane using basic pathing (diagonal or orthogonal)  
Precondition: boss contains valid positions, dungeon is a valid map  

@param dungeon 2D character array representing the boss map  
@param boss pointer to BossBattleState containing Siren and Yohane coordinates  
@return none */
void moveSiren(char dungeon[][WIDTH], BossBattleState *boss)
{
    int deltaX = 0;
    int deltaY = 0;
    
    if (boss->yohaneX > boss->sirenX)
        deltaX = 1;
    else if (boss->yohaneX < boss->sirenX)
        deltaX = -1;
        
    if (boss->yohaneY > boss->sirenY)
        deltaY = 1;
    else if (boss->yohaneY < boss->sirenY)
        deltaY = -1;
    
    int newX = boss->sirenX + deltaX;
    int newY = boss->sirenY + deltaY;
    
    if (newX >= 1 && newX < WIDTH - 1 && newY >= 1 && newY < HEIGHT - 1 &&
        dungeon[newY][newX] != '*')
    {
        boss->sirenX = newX;
        boss->sirenY = newY;
    }
}
/* Checks if the Siren has collided with Yohane or Lailaps  
If Yohane is hit and the player has an Ice Cream item, it is consumed to prevent death  
Precondition: all pointers are valid and initialized  

@param dungeon 2D character array representing the boss map  
@param boss pointer to BossBattleState holding Siren and character positions  
@param player pointer to PlayerData representing the player  
@param items array of ItemShop structs to check for ice cream item  
@param achieve array of Achievement structs  
@param queue pointer to AchievementNotif queue to log achievement unlocks  
@return 1 if collision causes defeat, 0 if saved or no collision */
int checkSirenCollision(char dungeon[][WIDTH], BossBattleState *boss, PlayerData *player, ItemShop items[], Achievement achieve[], AchievementNotif *queue)
{
    if (boss->sirenX == boss->yohaneX && boss->sirenY == boss->yohaneY)
    {
        if (boss->hasIceCream && !boss->iceCreamUsed)
        {
            boss->iceCreamUsed = 1;
            items[8].itemOwned--; 
            player->hp = 0.5; 
            printf("Ruby's ice cream saved you from a fatal blow!\n");
            
            markAchievementEarned(&achieve[26], queue); 
            
            return 0; 
        }
        else
        {
            return 1; 
        }
    }
    
    if (boss->sirenX == boss->lailapsX && boss->sirenY == boss->lailapsY)
    {
        return 1; 
    }
    
    return 0;
}

/* Controls the final boss battle encounter, including movement, interactions, and win/loss logic  
Precondition: player, items, dungeons, achieve, and queue pointers are properly initialized  

@param player pointer to PlayerData representing the player's stats and position  
@param items array of ItemShop structs used to manage items (e.g., ice cream)  
@param dungeons array of Dungeon structs (not used directly in this function)  
@param achieve array of Achievement structs for tracking progress  
@param queue pointer to AchievementNotif used to push unlocked achievement notifications  
@return 1 if the player defeats the boss and completes the game, 0 if the player loses or quits */
int bossBattle(PlayerData *player, ItemShop items[], Dungeon dungeons[], Achievement achieve[], AchievementNotif *queue)
{
    BossBattleState boss;
    BossBat bats[10]; 
    char dungeon[HEIGHT][WIDTH]; 
    int i;
    char input;
    int validMove;
    
    for (i = 0; i < 10; i++)
    {
        bats[i].active = 0;
    }
    
    initializeBossBattle(dungeon, &boss, player, achieve, items);
    
    while (!boss.battleWon && !boss.gameOver)
    {
        system("cls");
        
        printf("Final Battle: Siren of the Mirror World!\n");
        printf("Switches Triggered: %d/3\n", boss.switchTriggersCompleted);
        printf("HP: %.1f / %.1f  \tLailaps HP: 4 / 4  \tTotal Gold: %d GP\n", 
               player->hp, player->maxHP, player->gold);
        
        BossMap(dungeon, &boss, bats, 10);
        
        for (i = 0; i < HEIGHT; i++)
        {
            int j;
            for (j = 0; j < WIDTH; j++)
            {
                printf("%c", dungeon[i][j]);
            }
            printf("\n");
        }
        
        printf("\nMove: [W]Up [S]Down [A]Left [D]Right [Q]uit\n");
        printf("Choice: ");
        scanf(" %c", &input);
        
        validMove = 0;
        
        if (input == 'w' || input == 'W')
        {
            if (boss.yohaneY > 1 && dungeon[boss.yohaneY - 1][boss.yohaneX] != '*')
            {
                boss.yohaneY--;
                validMove = 1;
            }
        }
        else if (input == 's' || input == 'S')
        {
            if (boss.yohaneY < HEIGHT - 2 && dungeon[boss.yohaneY + 1][boss.yohaneX] != '*')
            {
                boss.yohaneY++;
                validMove = 1;
            }
        }
        else if (input == 'a' || input == 'A')
        {
            if (boss.yohaneX > 1 && dungeon[boss.yohaneY][boss.yohaneX - 1] != '*')
            {
                boss.yohaneX--;
                validMove = 1;
            }
        }
        else if (input == 'd' || input == 'D')
        {
            if (boss.yohaneX < WIDTH - 2 && dungeon[boss.yohaneY][boss.yohaneX + 1] != '*')
            {
                boss.yohaneX++;
                validMove = 1;
            }
        }
        else if (input == 'q' || input == 'Q')
        {
            boss.gameOver = 1;
        }
        
        if (validMove)
        {
            boss.moveCount++;
            
            if (checkSwitchActivation(&boss))
            {
                boss.switchTriggersCompleted++;
                printf("Switches activated! (%d/3)\n", boss.switchTriggersCompleted);
                
                if (boss.switchTriggersCompleted >= 3)
                {
                    printf("The walls around the Siren have broken! The Siren is now free!\n");
                    boss.sirenReleased = 1;
                    boss.sirenX = 24;
                    boss.sirenY = 1;
                }
                else
                {
                    generateSwitches(dungeon, &boss);
                }
                
                _getch();
            }
            
            if (boss.moveCount % 8 == 0)
            {
                spawnBat(dungeon, bats, 10, &boss);
                printf("A bat has appeared!\n");
                _getch();
            }
            
            if (boss.sirenReleased)
            {
                moveSiren(dungeon, &boss);
                
                if (checkSirenCollision(dungeon, &boss, player, items, achieve, queue))
                {
                    printf("Game Over! The Siren defeated you!\n");
                    boss.gameOver = 1;
                    _getch();
                }
            }
            
            if (boss.sirenReleased && 
                abs(boss.yohaneX - boss.sirenX) <= 1 && 
                abs(boss.yohaneY - boss.sirenY) <= 1)
            {
                printf("Press [SPACE] to attack the Siren!\n");
                char attack;
                scanf(" %c", &attack);
                if (attack == ' ')
                {
                    printf("Yohane defeats the Siren! 750 GP earned!\n");
                    player->gold += 750;
                    boss.battleWon = 1;
                    _getch();
                }
            }
            
            if (boss.battleWon && boss.yohaneX == 24 && boss.yohaneY == 1)
            {
                printf("Congratulations! You've completed the game!\n");
                return 1; // Victory!
            }
        }
    }
    
    if (boss.gameOver)
    {
        return 0;
    }
    
    return boss.battleWon;
}
