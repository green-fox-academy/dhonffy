#include "vector.h"

void vector_init(vector_t** vector)
{
  vector_t* new_vector = *vector;
  new_vector = NULL;
  new_vector->length = 0;
  new_vector->capacity = 0;
  *vector = new_vector;
}

void vector_push_back(vector_t** vector, air_pressure_t air_pressure)
{
  vector_t* new_vector = *vector;
  if (new_vector->capacity <= new_vector->length){
    if (new_vector->capacity == 0){
      new_vector->capacity = 10;
      new_vector->data = pvPortMalloc(new_vector->capacity * sizeof(air_pressure_t));
    }else{
      new_vector->capacity *= 2;
      air_pressure_t *p = new_vector->data;
      new_vector->data = pvPortMalloc(new_vector->capacity * sizeof(air_pressure_t));
      for(int i = 0; i < new_vector->length;++i){
    	new_vector->data[i] = p[i];
      }
      vPortFree(p);
    }
  }
  new_vector->data[new_vector->length] = air_pressure;
  ++new_vector->length;
  vector = &new_vector;
}

void vector_pop_back(vector_t **vector)
{
    vector_t *new_vector = *vector;
    --new_vector->length;
    vector = &new_vector;
}

air_pressure_t vector_at(vector_t* vector, uint32_t index)
{
    return vector->data[index];
}

uint32_t vector_size(vector_t* vector)
{
    return  vector->length;
}

uint32_t vector_capacity(vector_t* vector)
{
    return  vector->capacity;
}
