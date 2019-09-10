#ifndef __DECLARE_H
#define __DECLARE_H



#define LEDMATRIX_ADDRESS 0B11100000

typedef enum direction {
  RIGHT,
  DOWN,
  LEFT,
  UP,
  STOP
} direction_t;

typedef enum state {
  STARTING,
  RUN,
  GAME_OVER
} state_t;

state_t game_state;
uint8_t column[8];
direction_t direction;
int test;


uint8_t snake_x;
uint8_t snake_y;

void clear_led_matrix();
int test;


#endif //__DECLARE_H
