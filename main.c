// An interactive terminal calendar.
// TODO: 
// initialise table of dates
// print current month table
// while 'esc' or 'q' is not pressed:
//      update time
//      if left or right key is pressed:
//          navigate columns
//      else if up or down:
//          navigate rows
//      if 'enter' is pressed on a given date: 
//          give exact amount of time that has passed since

#include <stdio.h>
#include <time.h>

#include "calendar.h"

int main(void)
{
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    current_position = tm->tm_mday;
    char key = 'u';
    
    init();

    while (key != 27)
    {
        // clears screen using ansi escape sequences
        // credit to cs50's fifteen.c for this
        clear();
        
        draw();
        
        while (!legal_move(key) || key != 'u');
            key = keyPress();
        
        if (key != 27 || key != 'q')
            
            update(key);
        
        

    }
    return 0;
}
