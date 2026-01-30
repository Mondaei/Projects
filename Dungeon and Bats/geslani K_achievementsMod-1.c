/*  
    Description: for getting an achievement
    Programmed by: Keila Franchoise Leigh Geslani 
    Last modified: July 30, 2025  
    Version: 8.0  
    [Acknowledgements: https://cplusplus.com, cppreference.com, dlsu.instructure.ph, old MPs, old Exams,
					worldcounter.net(counting chars)]  
*/
#include "geslani K_BOSS.c"

/* 
Gets the current system date and time, and stores it in the provided dateTag struct.
Precondition: @param date must be a valid pointer to a dateTag struct.
@return none
*/
void getTheDateNow(dateTag *date) 
{
    time_t rawtime;
    struct tm *timeinfo;
    
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    
    date->year = timeinfo->tm_year + 1900;
    date->month = timeinfo->tm_mon + 1;
    date->day = timeinfo->tm_mday;
    date->hour = timeinfo->tm_hour;
    date->minute = timeinfo->tm_min;
}

/* 
Marks an achievement as earned if not already earned and adds to notification queue.
Precondition: @param achieve must be a valid pointer to an Achievement.
Precondition: @param queue must be a valid pointer to AchievementNotificationQueue.
@return none
*/
void markAchievementEarned(Achievement *achieve, AchievementNotif queue[])
{
    if (achieve->earned == 0) // it checks if the achievement hasnt been earned
    {
        achieve->earned = 1;
        getTheDateNow(&achieve->date);
        
        if (queue->count < TOTAL_ACHIEVEMENTS)
        {
            queue->achievements[queue->count] = achieve;
            queue->count++;
        }
    }
}

/* 
Initialize the achievement notification queue.
Precondition: @param queue must be a valid pointer to AchievementNotificationQueue.
@return none
*/
void initAchievementQueue(AchievementNotif *queue)
{
    queue->count = 0; // makes the queue count empty
}

/*
Display all newly earned achievements at the top of the screen.
Clears the notification queue after displaying.
Precondition: @param queue must be a valid pointer to AchievementNotificationQueue.
@return none
*/
void displayAchievementNotifications(AchievementNotif queue[])
{
    int i; // for loop
    
    if (queue->count > 0) // this is for checking notification to display
    {
        for (i = 0; i < queue->count; i++) // loop through each notification in the queue
        {
            printf("Achievement unlocked: %s\n", queue->achievements[i]->name);
        }
        
        queue->count = 0; // this resets the count of the queue
    }
}
/*
Check if there are any pending achievement notifications.
Precondition: @param queue must be a valid pointer to AchievementNotificationQueue.
@return 1 if there are notifications, 0 otherwise
*/
int hasAchievementNotifications(AchievementNotif *queue)
{
    if (queue->count > 0) // this is used for checking notifications
    {
        return 1; // yes notification
    }
    else
    {
        return 0; // no notification
    }
}

