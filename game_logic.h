/** @file graphics.h
    @authors Soren Subritzky (73976523) and Harry Collard (71662706)
    @date 14 Oct 2019
    @brief Support module for the game_logic library.
*/

#ifndef GAME_LOGIC_H
#define GAME_LOGIC_H

// Macros for each game state.
#define WIN 1
#define LOOSE 0
#define DRAW 2
#define ERROR 3


// Allows the player to select their move
// and display it on the LCD display.
// Returns the selected move.
char select_move(void);

// Checks if the match is either a win, loss 
// or a draw based on the players and opponents
// move. 
// Returns the result of the game. If the match
// is undecided an error message is returned.
int check_winner(char player, char opponent);

#endif
