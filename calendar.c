#include <stdio.h>
#include <time.h>
#include <ctype.h>
#include <stdbool.h>


#include "calendar.h"

int current_row;
int current_column;

void init(void)
{
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    
    int daysInMon = days_in_month(tm);
    

    int i = 0, j = 0;
    int day_count = 1;

    for (i = 0; i < MAX_ROW; i++)
    {
        for (j = 0; j < MAX_COLUMN; j++)
        {
            calendar[i][j] = day_count++;
        }
    }

    FILE *fp = fopen("log_init.txt", "w");
    fprintf(fp, "daysInMon = %i\n", daysInMon);
    fprintf(fp, "day_count = %i\n", day_count);
    fprintf(fp, "current_position = %i\n", current_position);
    fclose(fp);
}

void clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

void draw(void)
{
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    
    int daysInMon = days_in_month(tm);
    int i = 0, j = 0;
    int day_count = 1;

    printf("\n\n");
    for (i = 0; i < MAX_ROW; i++)
    {
        for (j = 0; j < MAX_COLUMN; j++)
        {   
            if (day_count == current_position)
            {
                printf("| [%i] ", calendar[i][j]);
                current_row = i;
                current_column = j;
            }
            else
            {
                printf("|%4i  ", calendar[i][j]);
            }
            
            day_count++;
            
            if ((day_count - 1) == daysInMon)
            {
                i = MAX_ROW;
                break;
            }
        }
        printf("|\n");
    }
    FILE *fp = fopen("log_draw.txt", "w");
    fprintf(fp, "daysInMon = %i\n", daysInMon);
    fprintf(fp, "day_count = %i\n", day_count);
    fclose(fp);
}

char keyPress(void)
{
    
    int c;
    
    c = getchar();
    c = tolower(c);
    
    return c;
}

bool update(char key)
{

    //current_position = ;
}

int days_in_month(struct tm *tm)
{
    switch (tm->tm_mon)
    {
        case 0:
            return 31;
        case 1:
            if ((tm->tm_year % 4 == 0 && tm->tm_year % 100) || tm->tm_year % 400 == 0)
                return 29;
            else
                return 28;
        case 2:
            return 31;
        case 3:
            return 30;
        case 4:
            return 31;
        case 5:
            return 30;
        case 6:
            return 31;
        case 7:
            return 31;
        case 8:
            return 30;
        case 9:
            return 31;
        case 10:
            return 30;
        case 11:
            return 31;
        default:
            return 31;
    }
}

bool legal_move(key)
{
    switch (key)
    {
        case 'w':
            return true;
        case 'a':
            return true;
        case 's':
            return true;
        case 'd':
            return true;
        case 'q':
            return true;
        case 27:
            return true;
        default:
            return false;
    }
}