#define LEDMATRIX_ADDRESS 0B11100000

typedef enum map {
	EMPTY,
	SNAKE,
	FOOD,
} map_t;


void clear_led_matrix();
