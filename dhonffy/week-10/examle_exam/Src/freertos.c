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
#include "gpio.h"
#include "adc.h"
#include "stdio.h"
#include "string.h"
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
osThreadId adcReadHandle;
osThreadId printHandle;
osMutexId vectorMutexHandle;
osMutexId ReadWriteMutexHandle;

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */
   
/* USER CODE END FunctionPrototypes */

void StartDefaultTask(void const * argument);
void startAdcRead(void const * argument);
void start_print(void const * argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */
       
  /* USER CODE END Init */

  /* Create the mutex(es) */
  /* definition and creation of vectorMutex */
  osMutexDef(vectorMutex);
  vectorMutexHandle = osMutexCreate(osMutex(vectorMutex));

  /* definition and creation of ReadWriteMutex */
  osMutexDef(ReadWriteMutex);
  ReadWriteMutexHandle = osMutexCreate(osMutex(ReadWriteMutex));

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

  /* definition and creation of adcRead */
  osThreadDef(adcRead, startAdcRead, osPriorityHigh, 0, 512);
  adcReadHandle = osThreadCreate(osThread(adcRead), NULL);

  /* definition and creation of print */
  osThreadDef(print, start_print, osPriorityIdle, 0, 512);
  printHandle = osThreadCreate(osThread(print), NULL);

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

/* USER CODE BEGIN Header_startAdcRead */
/**
* @brief Function implementing the adcRead thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_startAdcRead */
void startAdcRead(void const * argument)
{
  /* USER CODE BEGIN startAdcRead */
  /* Infinite loop */
  for(;;)
  {
	osSignalWait(1, osWaitForever);
	HAL_ADC_Start(&hadc3);
	if (HAL_ADC_PollForConversion(&hadc3, 10) == HAL_OK) {
	  new_air_pressure.timestamp_ms = HAL_GetTick();
	  new_air_pressure.pressure_kPa = HAL_ADC_GetValue(&hadc3) *
				 (PRESSURE_MAX - PRESSURE_MIN) /
			     (ANALOG_MAX - ANALOG_MIN) + PRESSURE_MIN;
	}
	osMutexWait(ReadWriteMutexHandle, osWaitForever);
	vector_push_back(&air_pressure, new_air_pressure);
	osMutexRelease(ReadWriteMutexHandle);

	/*if(test == 0){
	  osSignalWait(9, osWaitForever);
	}
	empty = vector_empty(air_pressure);
    vector_push_back(&air_pressure, new_air_pressure);
	test++;
	new_air_pressure.pressure_kPa += 1.5;
	new_air_pressure.timestamp_ms += 1;
	vector_push_back(&air_pressure, new_air_pressure);
	new_air_pressure.pressure_kPa += (float)test;
	new_air_pressure.timestamp_ms += (uint32_t)test;
    osDelay(1000);
    vector_pop_back(&air_pressure);
    read_data = vector_at(air_pressure, (uint32_t)(test - 9));
    size_of_vector = vector_size(air_pressure);
    capacity_of_vector = vector_capacity(air_pressure);
    osDelay(1000);*/
  }
  /* USER CODE END startAdcRead */
}

/* USER CODE BEGIN Header_start_print */
/**
* @brief Function implementing the print thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_start_print */
void start_print(void const * argument)
{
  /* USER CODE BEGIN start_print */
  /* Infinite loop */
  for(;;)
  {
	char text[50];
	sprintf(text, "-------------------\r\n");
	HAL_UART_Transmit(&huart1, (uint8_t*)text, strlen(text), 100);
	if(vector_empty(air_pressure)){
	  sprintf(text, "Vector is empty\r\n");
      HAL_UART_Transmit(&huart1, (uint8_t*)text, strlen(text), 100);
	}else{
	  for(uint32_t i = 0; i < vector_size(air_pressure); ++i){
		osMutexWait(ReadWriteMutexHandle, osWaitForever);
		read_data = vector_at(air_pressure, i);
		osMutexRelease(ReadWriteMutexHandle);
   	    sprintf(text, "%lu.   %lums %lukPa\r\n",
			  i + 1, read_data.timestamp_ms,
			  (uint32_t)read_data.pressure_kPa);
        HAL_UART_Transmit(&huart1, (uint8_t*)text, strlen(text), 100);
	  }
	}
    osDelay(1000);
  }
  /* USER CODE END start_print */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */
     
/* USER CODE END Application */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
