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
#include "vector.h"
#include <usart.h>
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
osThreadId printHandle;
osThreadId initHandle;
osThreadId buttonHandle;

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */
   
/* USER CODE END FunctionPrototypes */

void StartDefaultTask(void const * argument);
void startPrint(void const * argument);
void startInit(void const * argument);
void startButton(void const * argument);

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

  /* definition and creation of print */
  osThreadDef(print, startPrint, osPriorityIdle, 0, 128);
  printHandle = osThreadCreate(osThread(print), NULL);

  /* definition and creation of init */
  osThreadDef(init, startInit, osPriorityRealtime, 0, 128);
  initHandle = osThreadCreate(osThread(init), NULL);

  /* definition and creation of button */
  osThreadDef(button, startButton, osPriorityNormal, 0, 128);
  buttonHandle = osThreadCreate(osThread(button), NULL);

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

/* USER CODE BEGIN Header_startPrint */
/**
* @brief Function implementing the print thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_startPrint */
void startPrint(void const * argument)
{
  /* USER CODE BEGIN startPrint */
  /* Infinite loop */
  for(;;)
  {
	for (int i = 0; i < vector_size(vector); ++i){
	  HAL_UART_Transmit(&huart1, (vector->begin)[i], 5, 1000);
	}
	osDelay(1000);
  }
  /* USER CODE END startPrint */
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
	vector_init(&vector);
    osSignalWait(1, osWaitForever);
  }
  /* USER CODE END startInit */
}

/* USER CODE BEGIN Header_startButton */
/**
* @brief Function implementing the button thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_startButton */
void startButton(void const * argument)
{
  /* USER CODE BEGIN startButton */
  /* Infinite loop */
  for(;;)
  {
	uint32_t random_number;
	osSignalWait(1, osWaitForever);
	uint32_t button_push_start_time = HAL_GetTick();
	while(HAL_GPIO_ReadPin(PB_POLLING_GPIO_Port, PB_POLLING_Pin)){
	  uint32_t time_difference = HAL_GetTick() - button_push_start_time;
	  if(time_difference > 1000){
		HAL_RNG_GenerateRandomNumber(&hrng, &random_number);
		vector_push_back(vector, random_number);
		button_push_start_time = HAL_GetTick();
	  }
	}
  }
  /* USER CODE END startButton */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */
     
/* USER CODE END Application */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
