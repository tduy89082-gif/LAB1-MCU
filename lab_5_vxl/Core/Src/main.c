/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2026 STMicroelectronics.
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
/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);

/* USER CODE BEGIN PFP */
void display7SEG(int num);
void clear7SEG(void);
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/*
 * ============================================================
 * BAI 4 - HIEN THI LED 7 DOAN
 *
 * SEG_A -> PB0
 * SEG_B -> PB1
 * SEG_C -> PB2
 * SEG_D -> PB3
 * SEG_E -> PB4
 * SEG_F -> PB5
 * SEG_G -> PB6
 *
 * 7SEG-COM-ANODE:
 * GPIO = 0 -> sang
 * GPIO = 1 -> tat
 * ============================================================
 */

void display7SEG(int num)
{
    switch (num)
    {
        case 0:
            HAL_GPIO_WritePin(GPIOB, SEG_A_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOB, SEG_B_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOB, SEG_C_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOB, SEG_D_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOB, SEG_E_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOB, SEG_F_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOB, SEG_G_Pin, GPIO_PIN_SET);
            break;

        case 1:
            HAL_GPIO_WritePin(GPIOB, SEG_A_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(GPIOB, SEG_B_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOB, SEG_C_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOB, SEG_D_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(GPIOB, SEG_E_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(GPIOB, SEG_F_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(GPIOB, SEG_G_Pin, GPIO_PIN_SET);
            break;

        case 2:
            HAL_GPIO_WritePin(GPIOB, SEG_A_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOB, SEG_B_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOB, SEG_C_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(GPIOB, SEG_D_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOB, SEG_E_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOB, SEG_F_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(GPIOB, SEG_G_Pin, GPIO_PIN_RESET);
            break;

        case 3:
            HAL_GPIO_WritePin(GPIOB, SEG_A_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOB, SEG_B_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOB, SEG_C_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOB, SEG_D_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOB, SEG_E_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(GPIOB, SEG_F_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(GPIOB, SEG_G_Pin, GPIO_PIN_RESET);
            break;

        case 4:
            HAL_GPIO_WritePin(GPIOB, SEG_A_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(GPIOB, SEG_B_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOB, SEG_C_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOB, SEG_D_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(GPIOB, SEG_E_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(GPIOB, SEG_F_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOB, SEG_G_Pin, GPIO_PIN_RESET);
            break;

        case 5:
            HAL_GPIO_WritePin(GPIOB, SEG_A_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOB, SEG_B_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(GPIOB, SEG_C_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOB, SEG_D_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOB, SEG_E_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(GPIOB, SEG_F_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOB, SEG_G_Pin, GPIO_PIN_RESET);
            break;

        case 6:
            HAL_GPIO_WritePin(GPIOB, SEG_A_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOB, SEG_B_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(GPIOB, SEG_C_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOB, SEG_D_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOB, SEG_E_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOB, SEG_F_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOB, SEG_G_Pin, GPIO_PIN_RESET);
            break;

        case 7:
            HAL_GPIO_WritePin(GPIOB, SEG_A_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOB, SEG_B_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOB, SEG_C_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOB, SEG_D_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(GPIOB, SEG_E_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(GPIOB, SEG_F_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(GPIOB, SEG_G_Pin, GPIO_PIN_SET);
            break;

        case 8:
            HAL_GPIO_WritePin(GPIOB, SEG_A_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOB, SEG_B_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOB, SEG_C_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOB, SEG_D_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOB, SEG_E_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOB, SEG_F_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOB, SEG_G_Pin, GPIO_PIN_RESET);
            break;

        case 9:
            HAL_GPIO_WritePin(GPIOB, SEG_A_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOB, SEG_B_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOB, SEG_C_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOB, SEG_D_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOB, SEG_E_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(GPIOB, SEG_F_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOB, SEG_G_Pin, GPIO_PIN_RESET);
            break;

        default:
            clear7SEG();
            break;
    }
}


/* Tat tat ca LED 7 doan */
void clear7SEG(void)
{
    HAL_GPIO_WritePin(GPIOB,
                      SEG_A_Pin |
                      SEG_B_Pin |
                      SEG_C_Pin |
                      SEG_D_Pin |
                      SEG_E_Pin |
                      SEG_F_Pin |
                      SEG_G_Pin,
                      GPIO_PIN_SET);
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

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();

  /* USER CODE BEGIN 2 */

  /* Tat 6 LED giao thong luc dau */
  HAL_GPIO_WritePin(GPIOA, LED1_Pin, GPIO_PIN_RESET);
  HAL_GPIO_WritePin(GPIOA, LED2_Pin, GPIO_PIN_RESET);
  HAL_GPIO_WritePin(GPIOA, LED3_Pin, GPIO_PIN_RESET);
  HAL_GPIO_WritePin(GPIOA, LED4_Pin, GPIO_PIN_RESET);
  HAL_GPIO_WritePin(GPIOA, LED5_Pin, GPIO_PIN_RESET);
  HAL_GPIO_WritePin(GPIOA, LED6_Pin, GPIO_PIN_RESET);

  /* Tat LED 7 doan */
  clear7SEG();

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */

  while (1)
  {

    /*
     * =========================================================
     * GIU NGUYEN LOGIC BAI 3
     *
     * LEDRED  -> LED1
     * LEDYEL  -> LED2
     * LEDGRE  -> LED3
     *
     * LEDRED1 -> LED6
     * LEDYEL1 -> LED5
     * LEDGRE1 -> LED4
     *
     * =========================================================
     */


    /*
     * ---------------------------------------------------------
     * TRANG THAI 1
     *
     * Giong het Bai 3:
     *
     * HAL_GPIO_TogglePin(GPIOA, LEDRED_Pin);
     * HAL_GPIO_TogglePin(GPIOB, LEDGRE1_Pin);
     *
     * Thay bang:
     * LEDRED  -> LED1
     * LEDGRE1 -> LED4
     *
     * Thoi gian: 3 giay
     * ---------------------------------------------------------
     */

    HAL_GPIO_TogglePin(GPIOA, LED1_Pin);
    HAL_GPIO_TogglePin(GPIOA, LED4_Pin);

    display7SEG(3);
    HAL_Delay(1000);

    display7SEG(2);
    HAL_Delay(1000);

    display7SEG(1);
    HAL_Delay(1000);


    /*
     * ---------------------------------------------------------
     * TRANG THAI 2
     *
     * Giong het Bai 3:
     *
     * HAL_GPIO_TogglePin(GPIOB, LEDYEL1_Pin);
     * HAL_GPIO_TogglePin(GPIOB, LEDGRE1_Pin);
     *
     * Thay bang:
     * LEDYEL1 -> LED5
     * LEDGRE1 -> LED4
     *
     * Thoi gian: 2 giay
     * ---------------------------------------------------------
     */

    HAL_GPIO_TogglePin(GPIOA, LED5_Pin);
    HAL_GPIO_TogglePin(GPIOA, LED4_Pin);

    display7SEG(2);
    HAL_Delay(1000);

    display7SEG(1);
    HAL_Delay(1000);


    /*
     * ---------------------------------------------------------
     * TRANG THAI 3
     *
     * Giong het Bai 3:
     *
     * HAL_GPIO_TogglePin(GPIOB, LEDRED1_Pin);
     * HAL_GPIO_TogglePin(GPIOB, LEDYEL1_Pin);
     * HAL_GPIO_TogglePin(GPIOA, LEDGRE_Pin);
     * HAL_GPIO_TogglePin(GPIOA, LEDRED_Pin);
     *
     * Thay bang:
     * LEDRED1 -> LED6
     * LEDYEL1 -> LED5
     * LEDGRE  -> LED3
     * LEDRED  -> LED1
     *
     * Thoi gian: 3 giay
     * ---------------------------------------------------------
     */

    HAL_GPIO_TogglePin(GPIOA, LED6_Pin);
    HAL_GPIO_TogglePin(GPIOA, LED5_Pin);
    HAL_GPIO_TogglePin(GPIOA, LED3_Pin);
    HAL_GPIO_TogglePin(GPIOA, LED1_Pin);

    display7SEG(3);
    HAL_Delay(1000);

    display7SEG(2);
    HAL_Delay(1000);

    display7SEG(1);
    HAL_Delay(1000);


    /*
     * ---------------------------------------------------------
     * TRANG THAI 4
     *
     * Giong het Bai 3:
     *
     * HAL_GPIO_TogglePin(GPIOA, LEDGRE_Pin);
     * HAL_GPIO_TogglePin(GPIOA, LEDYEL_Pin);
     *
     * Thay bang:
     * LEDGRE  -> LED3
     * LEDYEL  -> LED2
     *
     * Thoi gian: 2 giay
     * ---------------------------------------------------------
     */

    HAL_GPIO_TogglePin(GPIOA, LED3_Pin);
    HAL_GPIO_TogglePin(GPIOA, LED2_Pin);

    display7SEG(2);
    HAL_Delay(1000);

    display7SEG(1);
    HAL_Delay(1000);


    /*
     * ---------------------------------------------------------
     * KET THUC CHU KY
     *
     * Giong het Bai 3:
     *
     * HAL_GPIO_TogglePin(GPIOA, LEDYEL_Pin);
     * HAL_GPIO_TogglePin(GPIOB, LEDRED1_Pin);
     *
     * Thay bang:
     * LEDYEL  -> LED2
     * LEDRED1 -> LED6
     * ---------------------------------------------------------
     */

    HAL_GPIO_TogglePin(GPIOA, LED2_Pin);
    HAL_GPIO_TogglePin(GPIOA, LED6_Pin);

    clear7SEG();

  }

  /* USER CODE END WHILE */

  /* USER CODE BEGIN 3 */

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

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;

  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType =
      RCC_CLOCKTYPE_HCLK |
      RCC_CLOCKTYPE_SYSCLK |
      RCC_CLOCKTYPE_PCLK1 |
      RCC_CLOCKTYPE_PCLK2;

  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}


/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();


  /*
   * =========================================================
   * GPIOA
   *
   * LED1 -> PA1
   * LED2 -> PA2
   * LED3 -> PA3
   * LED4 -> PA4
   * LED5 -> PA5
   * LED6 -> PA6
   * =========================================================
   */

  HAL_GPIO_WritePin(GPIOA,
                    LED1_Pin |
                    LED2_Pin |
                    LED3_Pin |
                    LED4_Pin |
                    LED5_Pin |
                    LED6_Pin,
                    GPIO_PIN_RESET);

  GPIO_InitStruct.Pin =
      LED1_Pin |
      LED2_Pin |
      LED3_Pin |
      LED4_Pin |
      LED5_Pin |
      LED6_Pin;

  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;

  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);


  /*
   * =========================================================
   * GPIOB
   *
   * SEG_A -> PB0
   * SEG_B -> PB1
   * SEG_C -> PB2
   * SEG_D -> PB3
   * SEG_E -> PB4
   * SEG_F -> PB5
   * SEG_G -> PB6
   * =========================================================
   */

  HAL_GPIO_WritePin(GPIOB,
                    SEG_A_Pin |
                    SEG_B_Pin |
                    SEG_C_Pin |
                    SEG_D_Pin |
                    SEG_E_Pin |
                    SEG_F_Pin |
                    SEG_G_Pin,
                    GPIO_PIN_SET);

  GPIO_InitStruct.Pin =
      SEG_A_Pin |
      SEG_B_Pin |
      SEG_C_Pin |
      SEG_D_Pin |
      SEG_E_Pin |
      SEG_F_Pin |
      SEG_G_Pin;

  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;

  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
}


/* USER CODE BEGIN 4 */

/* USER CODE END 4 */


/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */

  __disable_irq();

  while (1)
  {
  }

  /* USER CODE END Error_Handler_Debug */
}


#ifdef USE_FULL_ASSERT

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

  /* User can add implementation to report the file name and line number */

  /* USER CODE END 6 */
}

#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
