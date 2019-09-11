/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */     
#include "declare.h"
#include "i2c.h"
#include "linked_list.h"
#include "rng.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */


/* USER CODE END Variables */
osThreadId defaultTaskHandle;
osThreadId displayDotHandle;
osThreadId moveDotHandle;
osThreadId initHandle;
osThreadId gameOverHandle;

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

void StartDefaultTask(void const * argument);
void startDisplayDot(void const * argument);
void startMoveDot(void const * argument);
void startInit(void const * argument);
void startGameOver(void const * argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */
       
  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* definition and creation of defaultTask */
  osThreadDef(defaultTask, StartDefaultTask, osPriorityNormal, 0, 128);
  defaultTaskHandle = osThreadCreate(osThread(defaultTask), NULL);

  /* definition and creation of displayDot */
  osThreadDef(displayDot, startDisplayDot, osPriorityHigh, 0, 128);
  displayDotHandle = osThreadCreate(osThread(displayDot), NULL);

  /* definition and creation of moveDot */
  osThreadDef(moveDot, startMoveDot, osPriorityHigh, 0, 128);
  moveDotHandle = osThreadCreate(osThread(moveDot), NULL);

  /* definition and creation of init */
  osThreadDef(init, startInit, osPriorityRealtime, 0, 128);
  initHandle = osThreadCreate(osThread(init), NULL);

  /* definition and creation of gameOver */
  osThreadDef(gameOver, startGameOver, osPriorityIdle, 0, 128);
  gameOverHandle = osThreadCreate(osThread(gameOver), NULL);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

}

/* USER CODE BEGIN Header_StartDefaultTask */
/**
  * @brief  Function implementing the defaultTask thread.
  * @param  argument: Not used 
  * @retval None
  */
/* USER CODE END Header_StartDefaultTask */
void StartDefaultTask(void const * argument)
{
    
    
    
    
    
    

  /* USER CODE BEGIN StartDefaultTask */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END StartDefaultTask */
}

/* USER CODE BEGIN Header_startDisplayDot */
/**
* @brief Function implementing the displayDot thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_startDisplayDot */
void startDisplayDot(void const * argument)
{
  /* USER CODE BEGIN startDisplayDot */
  /* Infinite loop */
  for(;;)
  {
	clear_led_matrix();
	uint8_t buff[2];
	for(int i=0; i<8; i++){
	  buff[0] = i*2;
	  buff[1] = (column[i] >> 1) | (column[i] << 7);
	  HAL_I2C_Master_Transmit(&hi2c1, LEDMATRIX_ADDRESS, buff, 2, 100);
	}
    osSignalWait(1, osWaitForever);
  }
  /* USER CODE END startDisplayDot */
}

/* USER CODE BEGIN Header_startMoveDot */
/**
* @brief Function implementing the moveDot thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_startMoveDot */
void startMoveDot(void const * argument)
{
  /* USER CODE BEGIN startMoveDot */
  /* Infinite loop */
  for(;;)
  {
	osDelay(1000);
	uint8_t x = linked_list_get_x(snake, 0);
	uint8_t y = linked_list_get_y(snake, 0);
	if (direction == RIGHT){
	  if(linked_list_get_x(snake, 0) >= 7){
		osThreadResume(gameOverHandle);
	  }else{
		x = linked_list_get_x(snake, 0) + 1;
	  }
	}else if (direction == LEFT){
	  if(linked_list_get_x(snake, 0) <= 0){
		osThreadResume(gameOverHandle);
	  }else{
		x = linked_list_get_x(snake, 0) - 1;
	  }
	}else if (direction == UP){
	  if(linked_list_get_y(snake, 0) <= 0){
		osThreadResume(gameOverHandle);
	  }else{
		y = linked_list_get_y(snake, 0) - 1;
	  }
	}else if (direction == DOWN){
	  if(linked_list_get_y(snake, 0) >= 7){
		osThreadResume(gameOverHandle);
	  }else{
		y = linked_list_get_y(snake, 0) + 1;
	  }
	}
	coord_t data = {x, y};
	deleted = linked_list_pop_back(&snake);
	linked_list_push_front(&snake, data);

	for(int i = 0; i < 8; ++i){
	  column[i] = 0;
	}

	for(int i = 0; i < linked_list_size(snake); ++i){
	  column[linked_list_get_x(snake, i)] |= 1 << (7 - (int)linked_list_get_y(snake, i));
	}
	column[food_x] |= 1 << (7 - food_y);
	osSignalSet(displayDotHandle, 1);
	size = linked_list_size(snake);
  }
  /* USER CODE END startMoveDot */
}

/* USER CODE BEGIN Header_startInit */
/**
* @brief Function implementing the init thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_startInit */
void startInit(void const * argument)
{
  /* USER CODE BEGIN startInit */
  /* Infinite loop */

  for(;;)
  {
	snake = linked_list_create();

	coord_t snake_head = {2, 0};
	linked_list_push_back(&snake, snake_head);
	coord_t snake_1 = {1, 0};
	linked_list_push_back(&snake, snake_1);
	coord_t snake_2 = {0, 0};
	linked_list_push_back(&snake, snake_2);
	direction = RIGHT;
	for(int i = 0; i<8; ++i){
	  column[i] = 0;
	}
	for(int i = 0; i < linked_list_size(snake); ++i){
	  column[linked_list_get_x(snake, i)] |= 1 << (7 - linked_list_get_y(snake, i));
	}
	do{
	  food_x = HAL_RNG_GetRandomNumber(&hrng) % LEDMATRIX_X_SIZE;
	  food_y = HAL_RNG_GetRandomNumber(&hrng) % LEDMATRIX_Y_SIZE;
	}while(((&snake[0])->data.x == food_x && (&snake[0])->data.y == food_y) ||
		   ((&snake[1])->data.x == food_x && (&snake[1])->data.y == food_y) ||
		   ((&snake[2])->data.x == food_x && (&snake[2])->data.y == food_y));
	column[food_x] |= 1 << (7 - food_y);
	coord_t food = {food_x, food_y};

    game_state = STARTING;
    osThreadSuspend(gameOverHandle);
    osThreadSuspend(moveDotHandle);
    osDelay(100);

    osSignalSet(displayDotHandle, 1);

    osThreadSuspend(NULL);
  }

  /* USER CODE END startInit */
}

/* USER CODE BEGIN Header_startGameOver */
/**
* @brief Function implementing the gameOver thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_startGameOver */
void startGameOver(void const * argument)
{
  /* USER CODE BEGIN startGameOver */
  /* Infinite loop */
  for(;;)
  {
	osThreadSuspend(moveDotHandle);
	game_state = GAME_OVER;
	column[0] = 0x01;
	column[1] = 0x63;
	column[2] = 0x66;
	column[3] = 0x04;
	column[4] = 0x04;
	column[5] = 0x66;
	column[6] = 0x63;
	column[7] = 0x01;
	osSignalSet(displayDotHandle, 1);
	osDelay(3000);
    osThreadResume(initHandle);

  }
  /* USER CODE END startGameOver */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */
     
/* USER CODE END Application */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
