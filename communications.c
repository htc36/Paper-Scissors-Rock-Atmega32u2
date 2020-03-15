/** @file graphics.c
    @authors Soren Subritzky (73976523) and Harry Collard (71662706)
    @date 14 Oct 2019
    @brief Module for transmitting and receiving player moves.
*/

#include "../../drivers/avr/ir_uart.h"
#include "../../drivers/avr/system.h"
#include "../../drivers/navswitch.h"
#include "../../utils/pacer.h"
#include "graphics.h"
#include "communications.h"


void initialise_comms(void) {
    // Initialise the ir_uart module.
    ir_uart_init();
}


char transmit_and_receieve(char move)
{
    // Sends the players selected move and receives the opponents
    // move. 
    // Takes the current players move as a parameter and returns 
    // a character representing the opponents move.
    
    char character = TERMINATOR;
    bool is_sent = false;
    bool is_received = false;
    
    while (is_sent == false || is_received == false) {
        navswitch_update();
        update_display();
        pacer_wait();
        
        if (ir_uart_read_ready_p()) {
            character = ir_uart_getc();
            if (character != TERMINATOR) {
                is_received = true;
            }
        }
        
        if ((navswitch_push_event_p(NAVSWITCH_PUSH)) && is_sent == false) {
            if (ir_uart_write_ready_p()) {
                ir_uart_putc(move);
                display_text(WAIT_MESSAGE);
                update_display();
                is_sent = true;
            }
        }
    }
    
    ir_uart_putc(move);
    
    return character;
}
