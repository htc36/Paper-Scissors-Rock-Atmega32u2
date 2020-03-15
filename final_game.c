/** @file final_game.c
    @authors Soren Subritzky (73976523) and Harry Collard (71662706)
    @date 14 Oct 2019
    @brief Paper scissors rock game for the UCFK4.
*/

#include "../../drivers/avr/system.h"
#include "../../utils/pacer.h"
#include "../../utils/pacer.h"
#include "../../utils/tinygl.h"
#include "../../drivers/navswitch.h"
#include "graphics.h"
#include "communications.h"
#include "game_logic.h"

#define PACER_RATE 1000


int main(void)
{
    // Initialise the communications, graphics, pacer, navswitch 
    // and system modules.
    
    system_init();
    initialise_graphics();
    initialise_comms();
    navswitch_init();
    pacer_init(PACER_RATE);
    
    char opponents_move = TERMINATOR;
    char player_move = TERMINATOR;
    int result = 0;
    
    // Continuously select and check the players move against the 
    // opponents move. When both players have sent their moves
    // the result of the match is displayed on the LED matrix.
    
    while (true) {
        player_move = select_move();
        opponents_move = transmit_and_receieve(player_move);
        result = check_winner(player_move, opponents_move);
        display_results(result);
        update_display();    
    }
}
