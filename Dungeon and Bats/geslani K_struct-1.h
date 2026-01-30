/*********************************************************************************************************
This is to certify that this project is my own work, based on my personal efforts in studying and applying the concepts 
learned. I have constructed the functions and their respective algorithms and corresponding code by myself. The 
program was run, tested, and debugged by my own efforts. I further certify that I have not copied in part or whole or 
otherwise plagiarized the work of other students and/or persons.
Geslani, Keila Franchoise Leigh, DLSU ID# 12206997
*********************************************************************************************************/
/*  
    Description: structures
    Programmed by: Keila Franchoise Leigh Geslani 
    Last modified: July 29, 2025  
    Version: 5.0  
    [Acknowledgements: https://cplusplus.com, cppreference.com, dlsu.instructure.ph, old MPs, old Exams,
					worldcounter.net(counting chars)]  
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <ctype.h>

#define TOTAL_ACHIEVEMENTS 28
#define TOTAL_CHARACTERS2SAVE 8
#define PAGE_SIZE 8
#define ITEM_COUNT 9
#define WIDTH 55
#define HEIGHT 12
#define MAX_BATS 15
#define MAX_SPIKES 25
#define MAX_WALL 25
#define MAX_WATER 25
#define MAX_HEAT 25

typedef struct
{
	int x;
	int y;
} Position;

typedef struct 
{
    int month; // month
    int day; // day
    int year; // year
    int hour; // hour
    int minute; //minute
} dateTag; // all use for the date in achievements

typedef struct 
{
    char name[50]; // name of the achievement
    char description[100]; // description for the achievements
    int earned;  // 1 or 0 || earned or not earned
    dateTag date; // date in achievements
} Achievement; // struct for the achievement module

typedef struct
{
	Achievement* achievements[TOTAL_ACHIEVEMENTS];
    int count;
} AchievementNotif;

typedef struct {
    char name[20];
    int rescued;
} Character;

typedef struct 
{
    char dungeonName[30];
    int complete;
    Character characterToSave[8];
} Dungeon;

typedef struct
{
	int rescuedMembers[8];
	int gold;
	Achievement playerAchievements[28];
	float hp;
	float maxHP;
	int isNewGame;
	Position pos;
	int gameOver;
	int toMainMenu;
	int pendingAch[TOTAL_ACHIEVEMENTS];
	int pendingCTR;
	int ChebiMiloBibo;
	char dungeonNameHolder[30];
	int totalSpent;
} PlayerData;

typedef struct
{
	char itemName[25];
	int itemPrice;
	int itemOwned;
	int isUnlocked;
} ItemShop;

typedef struct 
{
    Position pos;
    int active;
    float damage;
    int moveCooldown;
    int lastMoveTurn;
    int Attacked;
    int diagonalMovement;
    int onWater;
} Bat;

typedef struct 
{
    Position pos;
    int active;
} Spike;

typedef struct
{
	Position pos;
    int active;
} Water;

typedef struct
{
	Position pos;
    int active;
} Wall;

typedef struct
{
	Position pos;
    int active;
} Heat;


typedef struct {
    Position pos;
    int active;
} Exit;

typedef struct {
    Position pos;
    int active;
    int collected;
} Treasure;

typedef struct {
    int selectedDungeons[3];
    int isInitialized;
} DungeonSelection;

typedef struct 
{
    int yohaneX, yohaneY;
    int lailapsX, lailapsY;
    int sirenX, sirenY;
    int switch1X, switch1Y;
    int switch2X, switch2Y;
    int switchTriggersCompleted;
    int moveCount;
    int sirenReleased;
    int battleWon;
    int gameOver;
    int hasIceCream;
    int iceCreamUsed;
} BossBattleState;

typedef struct {
    int x, y;
    int active;
    int dungeonLevel; // 1, 2, or 3 based on switch triggers
} BossBat;

/*  
    Description: core dungeon ang game loop
    Programmed by: Keila Franchoise Leigh Geslani 
    Last modified: July 29, 2025  
    Version: 5.0  
    [Acknowledgements: https://cplusplus.com, cppreference.com, dlsu.instructure.ph, old MPs, old Exams,
					worldcounter.net(counting chars)]  
*/
void debugDungeonStatus(Dungeon dungeons[]);
int checkRevivalItem(PlayerData *player, ItemShop items[], int nItems[], int itemIDX, int nItemsAvailable);
char itsGameOver(PlayerData *player, ItemShop items[], Dungeon dungeons[], Achievement achieve[], DungeonSelection *DUNGselection, AchievementNotif *queue);
char continueGame(PlayerData *player, ItemShop items[], Dungeon dungeons[], Achievement achieve[], DungeonSelection *DUNGselection, AchievementNotif *queue);
void gameplay(PlayerData *player, ItemShop items[], Dungeon dungeons[], Achievement achieve[], DungeonSelection *DUNGselection, AchievementNotif *queue);
void newGame(PlayerData *player, ItemShop items[], Dungeon dungeons[], Achievement achieve[], DungeonSelection *DUNGselection, AchievementNotif *queue);

/*  
    Description: player action and combat
    Programmed by: Keila Franchoise Leigh Geslani 
    Last modified: July 29, 2025  
    Version: 5.0  
    [Acknowledgements: https://cplusplus.com, cppreference.com, dlsu.instructure.ph, old MPs, old Exams,
					worldcounter.net(counting chars)]  
*/
int digWall(char dungeon[][WIDTH], int x, int y);
int attackBat(char dungeon[][WIDTH], int x, int y, Bat bats[]);
int isOccupied(int x, int y, Treasure treasure[], Wall walls[], Water water[], Spike spikes[], Heat heats[], Exit exit[]);
int battle(PlayerData *player, ItemShop items[], Dungeon dungeons[], int currentFloor, int totalFloors, int dungeonNum, DungeonSelection *DUNGselection);

/*  
    Description: bats and movement
    Programmed by: Keila Franchoise Leigh Geslani 
    Last modified: July 29, 2025  
    Version: 5.0  
    [Acknowledgements: https://cplusplus.com, cppreference.com, dlsu.instructure.ph, old MPs, old Exams,
					worldcounter.net(counting chars)]  
*/
void initBats(char dungeon[][WIDTH], PlayerData *player, Bat bats[]);
void moveBats(PlayerData *player, Bat bats[], int turnCount, char dungeon[][WIDTH]);

/*  
    Description: dungeon setup
    Programmed by: Keila Franchoise Leigh Geslani 
    Last modified: July 29, 2025  
    Version: 5.0  
    [Acknowledgements: https://cplusplus.com, cppreference.com, dlsu.instructure.ph, old MPs, old Exams,
					worldcounter.net(counting chars), activities]  
*/
void createDungeon(char dungeon[][WIDTH], Treasure treasure[], Wall walls[], Water water[], Spike spikes[], Heat heats[], Exit exit[]);
void printDungeon(char dungeon[][WIDTH], PlayerData *player);

/*  
    Description: save load shop
    Programmed by: Keila Franchoise Leigh Geslani 
    Last modified: July 29, 2025  
    Version: 5.0  
    [Acknowledgements: https://cplusplus.com, cppreference.com, dlsu.instructure.ph, old MPs, old Exams,
					worldcounter.net(counting chars)]  
*/
void saveGame(PlayerData *player, Dungeon dungeons[], ItemShop items[]);
void loadGame(PlayerData *player, Dungeon dungeons[], ItemShop items[]);
void hanamaruShop(PlayerData *player, ItemShop items[], Dungeon dungeons[]);

/*  
    Description: achievements
    Programmed by: Keila Franchoise Leigh Geslani 
    Last modified: July 29, 2025  
    Version: 5.0  
    [Acknowledgements: https://cplusplus.com, cppreference.com, dlsu.instructure.ph, old MPs, old Exams,
					worldcounter.net(counting chars)]  
*/
void unlockAchievement(PlayerData *player, int achievementIndex);
void markAchievementEarned(Achievement *achieve, AchievementNotif *queue);
void getTheDateNow(dateTag *date);
void showAchievementDetails(Achievement achieve);
void displayAchievements(Achievement achieve[], Dungeon dungeons[]);

/*  
    Description: menu
    Programmed by: Keila Franchoise Leigh Geslani 
    Last modified: July 29, 2025  
    Version: 5.0  
    [Acknowledgements: exams]  
*/
char MainMenuModule();

/*  
    Description: boss battle system
    Programmed by: Keila Franchoise Leigh Geslani 
    Last modified: July 29, 2025  
    Version: 5.0  
    [Acknowledgements: https://cplusplus.com, cppreference.com, dlsu.instructure.ph, old MPs, old Exams,
					worldcounter.net(counting chars)]  
*/
void initializeBossBattle(char dungeon[][WIDTH], BossBattleState *boss, PlayerData *player, Achievement achieve[], ItemShop items[]);
void BossMap(char dungeon[][WIDTH], BossBattleState *boss, BossBat bats[], int maxBats);
void generateSwitches(char dungeon[][WIDTH], BossBattleState *boss);
void spawnBat(char dungeon[][WIDTH], BossBat bats[], int maxBats, BossBattleState *boss);
void moveSiren(char dungeon[][WIDTH], BossBattleState *boss);
int checkSirenCollision(char dungeon[][WIDTH], BossBattleState *boss, PlayerData *player, ItemShop items[], Achievement achieve[], AchievementNotif *queue);

