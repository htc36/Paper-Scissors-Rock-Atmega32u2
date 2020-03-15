/** @file graphics.h
    @authors Soren Subritzky (73976523) and Harry Collard (71662706)
    @date 14 Oct 2019
    @brief Support module for the graphics library.
*/

#ifndef GRAPHICS_H
#define GRAPHICS_H

#define MESSAGE_RATE 25
#define DISP_FREQ 1000

// Macros for each possible move.
#define ROCK 'R'
#define PAPER 'P'
#define SCISSORS 'S'

// Macros for the in game graphics.
#define WINNING_MESSAGE "You Win!"
#define LOOSING_MESSAGE "You Loose!"
#define DRAW_MESSAGE "It's a Draw!"
#define ERROR_MESSAGE "Try again!"
#define WAIT_MESSAGE "Waiting..."
#define TERMINATOR '\0'


// Initialise the tinygl graphics driver.
void initialise_graphics(void);

// Displays the result of the rock paper scissors game.
void display_results(int results);

// Displays an 8 bit ASCII character on the LED matrix.
void display_character(char character);

// Displays a string the the LED matrix.
void display_text(char* str);

// Updates the LED matrix display.
void update_display(void);

#endif


