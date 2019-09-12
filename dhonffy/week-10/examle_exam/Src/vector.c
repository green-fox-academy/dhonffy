#include "vector.h"

void vector_init(vector_t** head)
{
  vector_t* vector = *head;
  vector = NULL;
  vector->length = 0;
  vector->capacity = 0;
}

void vector_push_back(vector_t** vector, air_pressure_t air_pressure)
{
  vector_t* new_vector = *vector;
  if (new_vector->capacity <= new_vector->length){
    if (new_vector->capacity == 0){
      new_vector->capacity = 10;
      new_vector->data = pvPortMalloc(new_vector->capacity * sizeof(air_pressure_t));
    }
  }
  new_vector->data[new_vector->length] = air_pressure;
  ++new_vector->length;
  vector = &new_vector;
}

