#ifndef __DECLARE_H
#define __DECLARE_H
#include "vector.h"

#define ANALOG_MAX 4096
#define ANALOG_MIN 0
#define PRESSURE_MAX 120
#define PRESSURE_MIN 90


uint8_t test;
vector_t *air_pressure;
air_pressure_t new_air_pressure;
air_pressure_t read_data;
uint32_t size_of_vector;
uint32_t capacity_of_vector;
uint8_t empty;
uint32_t prev_start_time;



#endif //__DECLARE_H
