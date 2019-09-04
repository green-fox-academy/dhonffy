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
osThreadId ToggleLED_1Handle;
osThreadId ToggleLED_2Handle;

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */
   
/* USER CODE END FunctionPrototypes */

void StartDefaultTask(void const * argument);
void StartToggleLED_1(void const * argument);
void StartToggleLED_2(void const * argument);

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

  /* definition and creation of ToggleLED_1 */
  osThreadDef(ToggleLED_1, StartToggleLED_1, osPriorityIdle, 0, 128);
  ToggleLED_1Handle = osThreadCreate(osThread(ToggleLED_1), NULL);

  /* definition and creation of ToggleLED_2 */
  osThreadDef(ToggleLED_2, StartToggleLED_2, osPriorityIdle, 0, 128);
  ToggleLED_2Handle = osThreadCreate(osThread(ToggleLED_2), NULL);

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

/* USER CODE BEGIN Header_StartToggleLED_1 */
/**
* @brief Function implementing the ToggleLED_1 thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartToggleLED_1 */
void StartToggleLED_1(void const * argument)
{
  /* USER CODE BEGIN StartToggleLED_1 */
  /* Infinite loop */
  for(;;)
  {
	for (int i = 0; i < 25; ++i){
	  HAL_GPIO_TogglePin(LED_1_GPIO_Port, LED_1_Pin);
      osDelay(200);
	}
	osThreadSuspend(NULL);
	for (int i = 0; i < 5; ++i){
	  HAL_GPIO_TogglePin(LED_1_GPIO_Port, LED_1_Pin);
      osDelay(1000);
	}
	osThreadResume(ToggleLED_2Handle);
  }
  /* USER CODE END StartToggleLED_1 */
}

/* USER CODE BEGIN Header_StartToggleLED_2 */
/**
* @brief Function implementing the ToggleLED_2 thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartToggleLED_2 */
void StartToggleLED_2(void const * argument)
{
  /* USER CODE BEGIN StartToggleLED_2 */
  /* Infinite loop */
  for(;;)
  {
	for (int i = 0; i < 20; ++i){
	  HAL_GPIO_TogglePin(LED_2_GPIO_Port, LED_2_Pin);
      osDelay(500);
	}
    osThreadResume(ToggleLED_1Handle);
    osThreadSuspend(NULL);
  }
  /* USER CODE END StartToggleLED_2 */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */
     
/* USER CODE END Application */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
