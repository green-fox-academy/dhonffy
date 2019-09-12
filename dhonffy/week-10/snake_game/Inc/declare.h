#ifndef __DECLARE_H
#define __DECLARE_H

#define LEDMATRIX_ADDRESS 0B11100000
#define LEDMATRIX_X_SIZE 8;
#define LEDMATRIX_Y_SIZE 8;

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

uint8_t players_score;
state_t game_state;
uint8_t column[8];
direction_t direction;
//int test;
coord_t deleted;
coord_t snake_head;
uint8_t snake_x;
uint8_t snake_y;
uint8_t food_x;
uint8_t food_y;
uint8_t snake_grow;
void clear_led_matrix();
uint8_t size;
int test1;
int test2;
int test3;
int test4;


#endif //__DECLARE_H
