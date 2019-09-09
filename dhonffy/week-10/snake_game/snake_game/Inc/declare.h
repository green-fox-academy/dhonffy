#ifndef __DECLARE_H
#define __DECLARE_H



#define LEDMATRIX_ADDRESS 0B11100000

typedef enum field {
  EMPTY,
  SNAKE,
  FOOD
} field_t;

typedef enum direction {
  RIGHT,
  DOWN,
  LEFT,
  UP
} direction_t;

typedef enum state {
  WAITING_FOR_START,
  START
} state_t;

field_t map[8][8];
direction_t direction;
state_t game_state;

int snake_x;
int snake_y;

void clear_led_matrix();
int test;


#endif //__DECLARE_H
