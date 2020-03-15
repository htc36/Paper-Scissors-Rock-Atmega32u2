/** @file graphics.c
    @authors Soren Subritzky (73976523) and Harry Collard (71662706)
    @date 14 Oct 2019
    @brief Module for selecting the players move and determining
    the outcome of the paper scissors rock game.
*/

#include "../../drivers/avr/system.h"
#include "../../drivers/navswitch.h"
#include "../../utils/pacer.h"
#include "../../utils/tinygl.h"
#include "graphics.h"
#include "game_logic.h"


char select_move(void)
{
    // Allows the player to select their move
    // and display it on the LCD display.
    // Returns the selected move.
    
    int index = 0;
    char possible_move[] = {'P', 'S', 'R'};
    
    while (true) {
        pacer_wait ();
        tinygl_update();
        navswitch_update();
        
        if (navswitch_push_event_p(NAVSWITCH_WEST)) {
            if (index == 0) {
                index = 2;
            } else {
                index--;
            }
        }

        if (navswitch_push_event_p(NAVSWITCH_EAST)) {
            if (index == 2) {
                index = 0;
            } else {
                index++;
            }
        }

        if (navswitch_push_event_p(NAVSWITCH_PUSH)) {
            return possible_move[index];
        }

        display_character(possible_move[index]);
    }
}


int check_winner(char player, char opponent) 
{
    // Checks if the match is either a win, loss 
    // or a draw based on the players and opponents
    // move. 
    // Returns the result of the game. If the match
    // is undecided an error message is returned.
    
    if (player == PAPER) {
        if (opponent == ROCK) {
            return WIN;
        }

        if (opponent == SCISSORS) {
            return LOOSE;
        }

        if (opponent == PAPER) {
            return DRAW;
        }
    }

    if (player == SCISSORS) {
        if (opponent == PAPER) {
            return WIN;
        }
        
        if (opponent == ROCK) {
            return LOOSE;
        }
        
        if (opponent == SCISSORS) {
            return DRAW;
        }
    }

    if (player == ROCK) {
        if (opponent == SCISSORS) {
            return WIN;
        }

        if (opponent == PAPER) {
            return LOOSE;
        }
        
        if (opponent == ROCK) {
            return DRAW;
        }
    }
    
    return ERROR;
}
