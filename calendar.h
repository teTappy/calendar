#include <stdio.h>
#include <time.h>
#include <stdbool.h>

#define MAX_ROW 5
#define MAX_COLUMN 7

int current_position;

// Initialise calendar
int calendar[MAX_ROW][MAX_COLUMN];



void init(void);

void clear(void);

void draw(void);

char keyPress(void);

bool update(char key);

int days_in_month(struct tm *tm);

bool legal_move(char key);

