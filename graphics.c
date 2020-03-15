/** @file graphics.c
    @authors Soren Subritzky (73976523) and Harry Collard (71662706)
    @date 14 Oct 2019
    @brief Module for displaying the in game graphics.
*/

#include "../../utils/tinygl.h"
#include "../../fonts/font5x7_1.h"
#include "../../drivers/navswitch.h"
#include "../../utils/pacer.h"
#include "game_logic.h"
#include "graphics.h"


void update_display(void)
{
    // Updates the LED matrix display.
    tinygl_update ();    
}


void initialise_graphics(void)
{
    // Initialise the tinygl graphics driver.
    tinygl_init (DISP_FREQ);
    tinygl_font_set (&font5x7_1);
    tinygl_text_speed_set (MESSAGE_RATE);    
    tinygl_text_mode_set (TINYGL_TEXT_MODE_SCROLL);
}


void display_character (char character)
{   
    // Displays an 8 bit ASCII character on the LED matrix.
    char buffer[2];
    buffer[0] = character;
    buffer[1] = TERMINATOR;
    tinygl_text (buffer);
}


void display_text (char* str)
{
    // Displays a string on the LED matrix.
    tinygl_text (str);
}


void display_results (int result)
{
    // Displays the result of the rock paper scissors game
    // on the LED matrix.
    // The message is displayed until the the player presses
    // down on the navigation switch.
    
    if (result == WIN) {
        display_text(WINNING_MESSAGE);
    } else if (result == LOOSE) {
        display_text(LOOSING_MESSAGE);
    } else if (result == DRAW) {
        display_text(DRAW_MESSAGE);
    } else {
        display_text(ERROR_MESSAGE);
    }
    
    navswitch_update();
    
    while (navswitch_push_event_p(NAVSWITCH_PUSH) == 0) {
        pacer_wait();
        update_display();
        navswitch_update();
    }
}
