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

int line[8];


/* USER CODE END Variables */
osThreadId defaultTaskHandle;
osThreadId displayDotHandle;
osThreadId moveDotHandle;
osThreadId initHandle;

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */
   
/* USER CODE END FunctionPrototypes */

void StartDefaultTask(void const * argument);
void startDisplayDot(void const * argument);
void startMoveDot(void const * argument);
void startInit(void const * argument);

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
	  line[i] = 1 * (int)map[7][i] + 2 * (int)map[6][i] + 4 * (int)map[5][i] + 8 * (int)map[4][i]
				+ 16 * (int)map[3][i] + 32 * (int)map[2][i] + 64 * (int)map[1][i] + 128 * (int)map[0][i];
	}
	for(int i=0; i<8; i++){
	  buff[0] = i*2;
	  buff[1] = (line[i] >> 1) | (line[i] << 7);
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
	map[snake_y][snake_x] = EMPTY;
	if (direction == RIGHT){
	  snake_x += 1;
	}else if (direction == LEFT){
      snake_x -= 1;
	}else if (direction == UP){
	  snake_y -= 1;
	}else if (direction == DOWN){
	  snake_y += 1;
	}
	map[snake_y][snake_x] = SNAKE;
	osSignalSet(displayDotHandle, 1);
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
    map[snake_y][snake_x] = SNAKE;
    osThreadSuspend(moveDotHandle);
    osThreadTerminate(NULL);
  }
  /* USER CODE END startInit */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */
     
/* USER CODE END Application */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
