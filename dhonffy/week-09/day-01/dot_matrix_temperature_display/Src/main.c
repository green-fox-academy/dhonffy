/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "i2c.h"
#include "tim.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define TEMP_SENSOR_ADDRESS 0B10010001
#define LEDMATRIX_ADDRESS 0B11100000
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
I2C_HandleTypeDef hi2c1;
uint8_t read_temp_val;
uint8_t time_elapsed = 0;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */
void clear_led_matrix();
void set_led_matrix(const uint8_t* data);
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
void clear_led_matrix(){
  uint8_t buff[2];

  for(int i=0; i<16; i++)
  {
	buff[0] = i;
	buff[1] = 0x00;
	HAL_I2C_Master_Transmit(&hi2c1, LEDMATRIX_ADDRESS, buff, 2, 100);
  }
}

void set_led_matrix(const uint8_t* data){
  clear_led_matrix();
  uint8_t buff[2];

  for(int i=0; i<8; i++)
  {
    buff[0] = i*2;
    buff[1] = (data[i] >> 1) | (data[i] << 7);
    HAL_I2C_Master_Transmit(&hi2c1, LEDMATRIX_ADDRESS, buff, 2, 100);
  }
}
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */
  

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */
  uint8_t init1 = 0b00100001;
  uint8_t init2 = 0b10000001;
  uint8_t read_temp_reg = 0;
  uint8_t tens;
  uint8_t ones;
  //data matrix
  uint8_t data[8] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

  const uint8_t data0[] = {0x7c, 0xc6, 0x7c};
  const uint8_t data1[] = {0x20, 0x40, 0xfe};
  const uint8_t data2[] = {0x4e, 0x9a, 0x72};
  const uint8_t data3[] = {0x92, 0x92, 0x7c};
  const uint8_t data4[] = {0xf0, 0x10, 0xfe};
  const uint8_t data5[] = {0xf2, 0x92, 0x9c};
  const uint8_t data6[] = {0x6c, 0x92, 0x8c};
  const uint8_t data7[] = {0x80, 0x8e, 0xf0};
  const uint8_t data8[] = {0x6c, 0x92, 0x6c};
  const uint8_t data9[] = {0x62, 0x92, 0x7c};
  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_I2C1_Init();
  MX_TIM2_Init();
  /* USER CODE BEGIN 2 */

  //init LED matrix
  HAL_I2C_Master_Transmit(&hi2c1, LEDMATRIX_ADDRESS, &init1, 1, 100);
  HAL_I2C_Master_Transmit(&hi2c1, LEDMATRIX_ADDRESS, &init2, 1, 100);

  HAL_TIM_Base_Start_IT(&htim2);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    if (time_elapsed == 0){
      continue;
    }
    time_elapsed = 0;
	HAL_I2C_Master_Transmit(&hi2c1, TEMP_SENSOR_ADDRESS, &read_temp_reg, sizeof(read_temp_reg), 100);
	HAL_I2C_Master_Receive(&hi2c1, TEMP_SENSOR_ADDRESS, &read_temp_val, sizeof(read_temp_val), 100);
	tens = read_temp_val / 10;
	ones = read_temp_val % 10;
	for (int i = 0; i < 3; ++i) {
      switch (tens) {
        case 0: break;
        case 1: data[i] = data1[i];
                break;
        case 2: data[i] = data2[i];
                break;
        case 3: data[i] = data3[i];
                break;
        case 4: data[i] = data4[i];
                break;
        case 5: data[i] = data5[i];
                break;
        case 6: data[i] = data6[i];
                break;
        case 7: data[i] = data7[i];
                break;
        case 8: data[i] = data8[i];
                break;
        case 9: data[i] = data9[i];
      }
      switch (ones) {
        case 0: data[i + 4] = data0[i];
                break;
        case 1: data[i + 4] = data1[i];
                break;
        case 2: data[i + 4] = data2[i];
                break;
        case 3: data[i + 4] = data3[i];
                break;
        case 4: data[i + 4] = data4[i];
                break;
        case 5: data[i + 4] = data5[i];
                break;
        case 6: data[i + 4] = data6[i];
                break;
        case 7: data[i + 4] = data7[i];
                break;
        case 8: data[i + 4] = data8[i];
                break;
        case 9: data[i + 4] = data9[i];
      }
	}
	set_led_matrix(data);
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInitStruct = {0};

  /** Configure LSE Drive Capability 
  */
  HAL_PWR_EnableBkUpAccess();
  /** Configure the main internal regulator output voltage 
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE2);
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 10;
  RCC_OscInitStruct.PLL.PLLN = 210;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_I2C1;
  PeriphClkInitStruct.I2c1ClockSelection = RCC_I2C1CLKSOURCE_PCLK1;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  Period elapsed callback in non blocking mode
  * @note   This function is called  when TIM14 interrupt took place, inside
  * HAL_TIM_IRQHandler(). It makes a direct call to HAL_IncTick() to increment
  * a global variable "uwTick" used as application time base.
  * @param  htim : TIM handle
  * @retval None
  */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  /* USER CODE BEGIN Callback 0 */
  if (htim->Instance == TIM2) {
    time_elapsed = 1;
  }
  /* USER CODE END Callback 0 */
  if (htim->Instance == TIM14) {
    HAL_IncTick();
  }
  /* USER CODE BEGIN Callback 1 */

  /* USER CODE END Callback 1 */
}

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */

  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{ 
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
