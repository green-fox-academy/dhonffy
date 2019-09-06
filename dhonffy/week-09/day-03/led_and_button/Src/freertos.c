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
#include "init.h"
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
osThreadId toggleLEDHandle;
osThreadId buttonHandle;

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */
   
/* USER CODE END FunctionPrototypes */

void StartDefaultTask(void const * argument);
void StartToggleLED(void const * argument);
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

  /* definition and creation of toggleLED */
  osThreadDef(toggleLED, StartToggleLED, osPriorityNormal, 0, 128);
  toggleLEDHandle = osThreadCreate(osThread(toggleLED), NULL);

  /* definition and creation of button */
  osThreadDef(button, startButton, osPriorityIdle, 0, 128);
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

/* USER CODE BEGIN Header_StartToggleLED */
/**
* @brief Function implementing the toggleLED thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartToggleLED */
void StartToggleLED(void const * argument)
{
  /* USER CODE BEGIN StartToggleLED */
  /* Infinite loop */
  for(;;)
  {
	osSignalWait(1, osWaitForever);

	for(int i = 0; i < 50; ++i){
	  HAL_GPIO_TogglePin(LED_GPIO_Port, LED_Pin);
	  osDelay(100);
	}
	osThreadResume(buttonHandle);
  }
  /* USER CODE END StartToggleLED */
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
	osSignalWait(1, osWaitForever);
	button_push_start_time = HAL_GetTick();
	while(HAL_GPIO_ReadPin(PB_POLLING_GPIO_Port, PB_POLLING_Pin)){
	  time_difference = HAL_GetTick() - button_push_start_time;
	  if(time_difference > 2000){
		osSignalSet(toggleLEDHandle, 1);
		button_push_start_time = HAL_GetTick();
		osThreadSuspend(NULL);
		break;
	  }
	}
  }
  /* USER CODE END startButton */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */
     
/* USER CODE END Application */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
