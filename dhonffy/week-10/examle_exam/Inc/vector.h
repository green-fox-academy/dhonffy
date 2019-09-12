#ifndef __VECTOR_H
#define __VECTOR_H

#include "cmsis_os.h"

typedef struct air_pressure {
  float pressure_kPa;
  uint32_t timestamp_ms;
} air_pressure_t;

typedef struct vector{
    air_pressure_t *data;
    uint32_t capacity;
    uint32_t length;
} vector_t;

void vector_init(vector_t** vector);
void vector_push_back(vector_t** vector, air_pressure_t air_pressure);
void vector_pop_back(vector_t** vector);
air_pressure_t vector_at(vector_t* vector, uint32_t index);
uint32_t vector_size(vector_t* vector);
uint32_t vector_capacity(vector_t* vector);
uint8_t vector_empty(vector_t* vector);

#endif //__VECTOR_H
