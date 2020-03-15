/** @file graphics.h
    @authors Soren Subritzky (73976523) and Harry Collard (71662706)
    @date 14 Oct 2019
    @brief Support module for the communications library.
*/

#ifndef COMMUNICATIONS_H
#define COMMUNICATIONS_H

// Macros for the null terminator and graphics.
#define TERMINATOR '\0'
#define WAIT_MESSAGE "Waiting..."


// Initialise the ir_uart module.
void initialise_comms(void);

// Sends the players selected move and receives the opponents
// move over the infrared module. 
// Takes the current players move as a parameter and returns 
// a character representing the opponents move.
char transmit_and_receieve(char move);

#endif
