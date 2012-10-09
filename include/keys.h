/*
 *  File: keys.h
 *  Last Updated: 18/08/2012
 *  Coded By: Erick Luis Moraes de Sousa
 */

#ifndef __KEYS_H__
#define __KEYS_H__

#include <SDL.h>
namespace Polymorphic {

    typedef enum {
        //ascii mapped keys
        KEY_BACKSPACE = SDLK_BACKSPACE, 
        KEY_TAB = SDLK_TAB, 
        KEY_CLEAR = SDLK_CLEAR, 
        KEY_RETURN = SDLK_RETURN, 
        KEY_PAUSE = SDLK_PAUSE,  
        KEY_ESCAPE = SDLK_ESCAPE,
        KEY_SPACE = SDLK_SPACE,
        KEY_EXCLAMATION = SDLK_EXCLAIM,
        KEY_DOUBLEQUOTE = SDLK_QUOTEDBL,
        KEY_HASH = SDLK_HASH,
        KEY_DOLLAR = SDLK_DOLLAR,
        KEY_AMPERSAND = SDLK_AMPERSAND,
        KEY_QUOTE = SDLK_QUOTE,
        KEY_LPARENT = SDLK_LEFTPAREN,
        KEY_RPARENT = SDLK_RIGHTPAREN,
        KEY_ASTERISK = SDLK_ASTERISK,
        KEY_PLUS = SDLK_PLUS,
        KEY_COMMA = SDLK_COMMA,
        KEY_PERIOD = SDLK_PERIOD,
        KEY_SLASH = SDLK_SLASH,
        KEY_0 = SDLK_0,
        KEY_1 = SDLK_1,
        KEY_2 = SDLK_2,
        KEY_3 = SDLK_3,
        KEY_4 = SDLK_4,
        KEY_5 = SDLK_5,
        KEY_6 = SDLK_6,
        KEY_7 = SDLK_7,
        KEY_8 = SDLK_8,
        KEY_9 = SDLK_9,
        KEY_COLON = SDLK_COLON,
        KEY_SEMICOLON = SDLK_SEMICOLON,
        KEY_LESS = SDLK_LESS,
        KEY_EQUAL = SDLK_EQUALS, 
        KEY_GREATER = SDLK_GREATER,
        KEY_QUESTION = SDLK_QUESTION,
        KEY_AT = SDLK_AT,
        KEY_LBRACKET = SDLK_LEFTBRACKET,
        KEY_BACKSLASH = SDLK_BACKSLASH,
        KEY_RBRACK = SDLK_RIGHTBRACKET,
        KEY_CARET = SDLK_CARET,
        KEY_UNDERSCORE = SDLK_UNDERSCORE,
        KEY_BACKQUOTE = SDLK_BACKQUOTE,
        KEY_A = SDLK_a,  //mapped as lower case ascii codes
        KEY_B = SDLK_b,
        KEY_C = SDLK_c,
        KEY_D = SDLK_d,
        KEY_E = SDLK_e,
        KEY_F = SDLK_f,
        KEY_G = SDLK_g,
        KEY_H = SDLK_h,
        KEY_I = SDLK_i,
        KEY_J = SDLK_j,
        KEY_K = SDLK_k,
        KEY_L = SDLK_l,
        KEY_M = SDLK_m,
        KEY_N = SDLK_n,
        KEY_O = SDLK_o,
        KEY_P = SDLK_p,
        KEY_Q = SDLK_q,
        KEY_R = SDLK_r,
        KEY_S = SDLK_s,
        KEY_T = SDLK_t,
        KEY_U = SDLK_u,
        KEY_V = SDLK_v,
        KEY_W = SDLK_w,
        KEY_X = SDLK_x,
        KEY_Y = SDLK_y,
        KEY_Z = SDLK_z,
        KEY_DELETE = SDLK_DELETE,
        //end of ascii mapped keys

        //Num pad keys
        KEY_NUM0 = SDLK_KP0,
        KEY_NUM1 = SDLK_KP1,
        KEY_NUM2 = SDLK_KP2,
        KEY_NUM3 = SDLK_KP3,
        KEY_NUM4 = SDLK_KP4,
        KEY_NUM5 = SDLK_KP5,
        KEY_NUM6 = SDLK_KP6,
        KEY_NUM7 = SDLK_KP7,
        KEY_NUM8 = SDLK_KP8,
        KEY_NUM9 = SDLK_KP9,
        KEY_NUM_PERIOD = SDLK_KP_PERIOD,
        KEY_NUM_DIVIDE = SDLK_KP_DIVIDE,
        KEY_NUM_MULTIPLY = SDLK_KP_MULTIPLY,
        KEY_NUM_MINUS = SDLK_KP_MINUS,
        KEY_NUM_PLUS = SDLK_KP_PLUS,
        KEY_NUM_ENTER = SDLK_KP_ENTER,
        KEY_NUM_EQUAL = SDLK_KP_EQUALS,

        //Arrows, Home pad and Function Keys
        KEY_UP = SDLK_UP,
        KEY_DOWN = SDLK_DOWN,
        KEY_RIGHT = SDLK_RIGHT,
        KEY_LEFT = SDLK_LEFT,
        KEY_INSERT = SDLK_INSERT,
        KEY_HOME = SDLK_HOME,
        KEY_END = SDLK_END,
        KEY_PAGEUP = SDLK_PAGEUP,
        KEY_PAGEDOWN = SDLK_PAGEDOWN,
        KEY_F1 = SDLK_F1,
        KEY_F2 = SDLK_F2,
        KEY_F3 = SDLK_F3,
        KEY_F4 = SDLK_F4,
        KEY_F5 = SDLK_F5,
        KEY_F6 = SDLK_F6,
        KEY_F7 = SDLK_F7,
        KEY_F8 = SDLK_F8,
        KEY_F9 = SDLK_F9,
        KEY_F10 = SDLK_F10,
        KEY_F11 = SDLK_F11,
        KEY_F12 = SDLK_F12,

        //Key state modifiers
        KEY_NUMLOCK = SDLK_NUMLOCK,
        KEY_CAPSLOCK = SDLK_CAPSLOCK,
        KEY_SCROLL_LOCK = SDLK_SCROLLOCK,
        KEY_RSHIFT = SDLK_RSHIFT,
        KEY_LSHIFT = SDLK_LSHIFT,
        KEY_RCTRL = SDLK_RCTRL,
        KEY_LCTRL = SDLK_LCTRL,
        KEY_RALT = SDLK_RALT,
        KEY_LALT = SDLK_LALT

    } Keys;

}
#endif /* __KEYS_H__ */
