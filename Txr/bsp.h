//****************************************************************************
// This program is open source software: you can redistribute it and/or
// modify it under the terms of the GNU General Public License as published
// by the Free Software Foundation.
//
// This program is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
// or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
// for more details.
//****************************************************************************

#ifndef bsp_h
#define bsp_h

#include <avr/io.h>   // AVR I/O

#define MAX_POT_VAL           1024
#define MIN_POT_VAL           0
#define NUM_POSITION_BUTTONS  4

// Switches and buttons
#define ZMODE_SW   4  // ZMODE switch
#define FREE_SW    12 // Free mode switch
#define cBUTTON    A5 // Calibrate button
#define p1BUTTON   A1 // Preset 1
#define p2BUTTON   A2 // Preset 2
#define p3BUTTON   A3 // Preset 3
#define p4BUTTON   A4 // Preset 4

// LEDs
#define SPEED_LED1       3  // Red LED
#define SPEED_LED2       5  // Amber #1 LED
#define SPEED_LED3_1     11 // enc RED
#define SPEED_LED3_2     10 // red GREEN (mix with red for amber)
#define SPEED_LED4       6  // Green LED
#define SPEED_LED5       9  // Green LED
#define GREEN_LED        0  // Green #2 LED
#define ENC_RED_LED      11 // Start record mode, red LED built into rotary encoder
#define ENC_GREEN_LED    10 // Green led in record mode, green LED built into rotary encoder

// Outputs
#define GREEN_LED_ON()         (PORTB |= (1 << (5)))
#define GREEN_LED_OFF()        (PORTB &= ~(1 << (5)))
#define GREEN_LED_TOGGLE()     (PORTB ^= (1 << (5)))
#define GREEN2_LED_ON()        (PORTD |= (1 << (2)))
#define GREEN2_LED_OFF()       (PORTD &= ~(1 << (2)))
#define GREEN2_LED_TOGGLE()    (PORTD ^= (1 << (2)))
#define WHITE_LED_ON()         (PORTC |= (1 << (7)))
#define WHITE_LED_OFF()        (PORTC &= ~(1 << (7)))
#define WHITE_LED_TOGGLE()     (PORTC ^= (1 << (7)))
#define AMBER2_LED_ON()        (PORTD |= (1 << (7)))
#define AMBER2_LED_OFF()       (PORTD &= ~(1 << (7)))
#define AMBER2_LED_TOGGLE()    (PORTD ^= (1 << (7)))
#define AMBER_LED_ON()         (PORTC |= (1 << (6)))
#define AMBER_LED_OFF()        (PORTC &= ~(1 << (6)))
#define AMBER_LED_TOGGLE()     (PORTC ^= (1 << (6)))
#define RED_LED_ON()           (PORTD |= (1 << (0)))
#define RED_LED_OFF()          (PORTD &= ~(1 << (0)))
#define RED_LED_TOGGLE()       (PORTD ^= (1 << (0)))
#define ENC_GREEN_LED_ON()     analogWrite(10, 255)
#define ENC_GREEN_LED_OFF()    analogWrite(10, 0)
#define ENC_GREEN_LED_TOGGLE() (PORTB ^= (1 << (6)))
#define ENC_RED_LED_ON()       (PORTB |= (1 << (7)))
#define ENC_RED_LED_OFF()      (PORTB &= ~(1 << (7)))
#define ENC_RED_LED_TOGGLE()   (PORTB ^= (1 << (7)))

// Inputs
#define PBUTTON1_ON()     (PINF & 0x40)
#define PBUTTON2_ON()     (PINF & 0x20)
#define PBUTTON3_ON()     (PINF & 0x10)
#define PBUTTON4_ON()     (PINF & 0x02)
#define PBUTTONS()        (PINF & 0x72)
#define CALBUTTON_ON()    (PINF & 0x01)
#define ZSWITCH_ON()      (PIND & 0x10)
#define FREESWITCH_ON()   (PIND & 0x40)
#define MODE_SWITCHES()   (PIND & 0x50)  // to see if either have changed

// Modes
enum {
  FREE_MODE,
  PLAY_BACK_MODE,
  Z_MODE
};

// Sys timer tick per seconds
#define BSP_TICKS_PER_SEC    256

void BSP_init(void);
long BSP_get_encoder();
int BSP_get_pot();
int BSP_get_mode();
void BSP_turn_on_speed_LED(char num);
void BSP_turn_off_speed_LED(char num);
bool BSP_serial_available();
char BSP_serial_read();
int BSP_serial_write(char* buffer, int length);
void BSP_assert(bool condition);
unsigned long BSP_millis();

/////////////////////////////////////////////////////////////////////
// NOTE: The CPU clock frequency F_CPU is defined externally for each
// Arduino board

#endif  // bsp_h
