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
#include "usart.h"
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
osThreadId task_1Handle;
osThreadId task_2_01Handle;
osThreadId task_2_02Handle;
osThreadId task_3_01Handle;
osThreadId task_3_02Handle;
osThreadId task_3_03Handle;
osThreadId task_3_04Handle;

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */
   
/* USER CODE END FunctionPrototypes */

void StartDefaultTask(void const * argument);
void startTask_1(void const * argument);
void startTask_2_01(void const * argument);
void startTask_2_02(void const * argument);
void startTask_3_01(void const * argument);
void startTask_3_02(void const * argument);
void startTask_3_03(void const * argument);
void startTask_3_04(void const * argument);

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

  /* definition and creation of task_1 */
  osThreadDef(task_1, startTask_1, osPriorityIdle, 0, 128);
  task_1Handle = osThreadCreate(osThread(task_1), NULL);

  /* definition and creation of task_2_01 */
  osThreadDef(task_2_01, startTask_2_01, osPriorityIdle, 0, 128);
  task_2_01Handle = osThreadCreate(osThread(task_2_01), NULL);

  /* definition and creation of task_2_02 */
  osThreadDef(task_2_02, startTask_2_02, osPriorityLow, 0, 128);
  task_2_02Handle = osThreadCreate(osThread(task_2_02), NULL);

  /* definition and creation of task_3_01 */
  osThreadDef(task_3_01, startTask_3_01, osPriorityIdle, 0, 128);
  task_3_01Handle = osThreadCreate(osThread(task_3_01), NULL);

  /* definition and creation of task_3_02 */
  osThreadDef(task_3_02, startTask_3_02, osPriorityLow, 0, 128);
  task_3_02Handle = osThreadCreate(osThread(task_3_02), NULL);

  /* definition and creation of task_3_03 */
  osThreadDef(task_3_03, startTask_3_03, osPriorityBelowNormal, 0, 128);
  task_3_03Handle = osThreadCreate(osThread(task_3_03), NULL);

  /* definition and creation of task_3_04 */
  osThreadDef(task_3_04, startTask_3_04, osPriorityNormal, 0, 128);
  task_3_04Handle = osThreadCreate(osThread(task_3_04), NULL);

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

/* USER CODE BEGIN Header_startTask_1 */
/**
* @brief Function implementing the task_1 thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_startTask_1 */
void startTask_1(void const * argument)
{
  /* USER CODE BEGIN startTask_1 */
  /* Infinite loop */
  argument_t arg = *((argument_t*)argument);
  for(;;)
  {
	arg.task_name = 1;
	arg.frequency = 1000;
	char* text;
	//sprintf(text, "Task%d is running.", arg.task_name);
	//sprintf(text, "Task is running.");
	int text_length = 16;
	HAL_UART_Transmit(&huart1, "Task", 4, 1000);
	HAL_UART_Transmit(&huart1, (char)&arg.task_name, 1, 1000);
	HAL_UART_Transmit(&huart1, " is running.\r\n", 14, 1000);

    osDelay(arg.frequency);
  }
  /* USER CODE END startTask_1 */
}

/* USER CODE BEGIN Header_startTask_2_01 */
/**
* @brief Function implementing the task_2_01 thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_startTask_2_01 */
void startTask_2_01(void const * argument)
{
  /* USER CODE BEGIN startTask_2_01 */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END startTask_2_01 */
}

/* USER CODE BEGIN Header_startTask_2_02 */
/**
* @brief Function implementing the task_2_02 thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_startTask_2_02 */
void startTask_2_02(void const * argument)
{
  /* USER CODE BEGIN startTask_2_02 */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END startTask_2_02 */
}

/* USER CODE BEGIN Header_startTask_3_01 */
/**
* @brief Function implementing the task_3_01 thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_startTask_3_01 */
void startTask_3_01(void const * argument)
{
  /* USER CODE BEGIN startTask_3_01 */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END startTask_3_01 */
}

/* USER CODE BEGIN Header_startTask_3_02 */
/**
* @brief Function implementing the task_3_02 thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_startTask_3_02 */
void startTask_3_02(void const * argument)
{
  /* USER CODE BEGIN startTask_3_02 */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END startTask_3_02 */
}

/* USER CODE BEGIN Header_startTask_3_03 */
/**
* @brief Function implementing the task_3_03 thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_startTask_3_03 */
void startTask_3_03(void const * argument)
{
  /* USER CODE BEGIN startTask_3_03 */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END startTask_3_03 */
}

/* USER CODE BEGIN Header_startTask_3_04 */
/**
* @brief Function implementing the task_3_04 thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_startTask_3_04 */
void startTask_3_04(void const * argument)
{
  /* USER CODE BEGIN startTask_3_04 */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END startTask_3_04 */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */
     
/* USER CODE END Application */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
