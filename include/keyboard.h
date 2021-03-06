/*
 * Contains keyboard input functions.
 */
#ifndef _KEYBOARD_H
#define _KEYBOARD_H

#include "sys.h"
#include "memory.h"

/* key codes */ 
enum KeyCode {
    UNKNOWN,
    ARROW_UP,
    ARROW_DOWN,
    ARROW_LEFT,
    ARROW_RIGHT,
    ENTER,
    ESCAPE,
};

void key_buffer_clear();
void key_init();
void key_poll();
void key_decode(int *key, char *pressed);
int get_char();

#endif
