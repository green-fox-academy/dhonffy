#ifndef __DECLARE_H
#define __DECLARE_H

#define LEDMATRIX_ADDRESS 0B11100000

#include "cmsis_os.h"
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

typedef struct coord{
  uint8_t x;
  uint8_t y;
}coord_t;

typedef struct linked_list_node{
  coord_t data;
  struct linked_list_node* next;
}linked_list_node_t;

linked_list_node_t* snake;

state_t game_state;
uint8_t column[8];
direction_t direction;
//int test;


uint8_t snake_x;
uint8_t snake_y;

void clear_led_matrix();
uint8_t size;
//int test1;
//int test2;
//int test3;
//int test4;
//linked_list_node_t* snake2;

#endif //__DECLARE_H
