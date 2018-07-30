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
    char key;
    bool can_use_key = false;
    bool running = true;
    
    init();

    while (running)
    {
        key = 'u';
        // clears screen using ansi escape sequences
        // credit to cs50's fifteen.c for this
        clear();
        
        draw();
        
        while (!legal_move(key) || !can_use_key)
        {
            key = keyPress();

            // End if 'ESC' or 'q' is pressed
            if (key == 27 || key == 'q')
            {
                running = false;
                break;
            }
            can_use_key = update(key);
        } 
    }
    return 0;
}
