/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f7xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define I2C2_SCL_Pin GPIO_PIN_8
#define I2C2_SCL_GPIO_Port GPIOB
#define PUSH_BUTTON_UP_Pin GPIO_PIN_4
#define PUSH_BUTTON_UP_GPIO_Port GPIOB
#define PUSH_BUTTON_UP_EXTI_IRQn EXTI4_IRQn
#define I2C2_SDA_Pin GPIO_PIN_9
#define I2C2_SDA_GPIO_Port GPIOB
#define PUSH_BUTTON_LEFT_Pin GPIO_PIN_0
#define PUSH_BUTTON_LEFT_GPIO_Port GPIOI
#define PUSH_BUTTON_LEFT_EXTI_IRQn EXTI0_IRQn
#define PUSH_BUTTON_DOWN_Pin GPIO_PIN_7
#define PUSH_BUTTON_DOWN_GPIO_Port GPIOG
#define PUSH_BUTTON_DOWN_EXTI_IRQn EXTI9_5_IRQn
#define PUSH_BUTTON_RIGHT_Pin GPIO_PIN_6
#define PUSH_BUTTON_RIGHT_GPIO_Port GPIOG
#define PUSH_BUTTON_RIGHT_EXTI_IRQn EXTI9_5_IRQn
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
