#ifndef __VECTOR_H
#define __VECTOR_H

#include "cmsis_os.h"

typedef struct air_pressure {
  float pressure_kPa;
  uint32_t timestamp_ms;
} air_pressure_t;

typedef struct vector{
    air_pressure_t *data;
    uint8_t capacity;
    uint8_t length;
} vector_t;

void vector_init(vector_t** vector);
void vector_push_back(vector_t** vector, air_pressure_t air_pressure);



#endif //__VECTOR_H
