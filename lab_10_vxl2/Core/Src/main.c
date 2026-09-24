#include "main.h"

void SystemClock_Config(void);
static void MX_GPIO_Init(void);

/* =========================================================
   MAPPING 12 LED
   LED1  = PA4
   LED2  = PA5
   LED3  = PA6
   LED4  = PA7
   LED5  = PA8
   LED6  = PA9
   LED7  = PA10
   LED8  = PA11
   LED9  = PA12
   LED10 = PA13
   LED11 = PA14
   LED12 = PA15

   SET   = LED SANG
   RESET = LED TAT
   ========================================================= */


/* Tat tat ca 12 LED */
void clearAllClock(void)
{
    HAL_GPIO_WritePin(GPIOA,
                      GPIO_PIN_4  | GPIO_PIN_5  | GPIO_PIN_6  | GPIO_PIN_7 |
                      GPIO_PIN_8  | GPIO_PIN_9  | GPIO_PIN_10 | GPIO_PIN_11 |
                      GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_15,
                      GPIO_PIN_RESET);
}


/* Bat LED tuong ung voi so 0 -> 11 */
void setNumberOnClock(int num)
{
    switch (num)
    {
        case 0:
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
            break;

        case 1:
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET);
            break;

        case 2:
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_SET);
            break;

        case 3:
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, GPIO_PIN_SET);
            break;

        case 4:
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_SET);
            break;

        case 5:
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, GPIO_PIN_SET);
            break;

        case 6:
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, GPIO_PIN_SET);
            break;

        case 7:
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, GPIO_PIN_SET);
            break;

        case 8:
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, GPIO_PIN_SET);
            break;

        case 9:
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_13, GPIO_PIN_SET);
            break;

        case 10:
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_14, GPIO_PIN_SET);
            break;

        case 11:
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_SET);
            break;

        default:
            break;
    }
}


/* =========================================================
   MAIN
   ========================================================= */

int main(void)
{
    HAL_Init();

    SystemClock_Config();

    MX_GPIO_Init();


    int hour = 3;
    int minute = 10;
    int second = 0;

    /* Tat het truoc */
    clearAllClock();

    /* Hien thi gio = 3 */
    setNumberOnClock(hour);

    /* Hien thi phut = 10 */
    setNumberOnClock(minute);

    /* Hien thi giay = 0 */
    setNumberOnClock(second);


    while (1)
    {
        /* =================================================
           CHAY KIM GIAY

           LED giay se chay:
           LED1 -> LED2 -> ... -> LED12
           ================================================= */

        HAL_Delay(1000);

        clearAllClock();



        setNumberOnClock(hour);
        setNumberOnClock(minute);

        second++;

        if (second >= 12)
        {
            second = 0;

            minute++;

            if (minute >= 12)
            {
                minute = 0;

                hour++;

                if (hour >= 12)
                {
                    hour = 0;
                }
            }
        }

        setNumberOnClock(second);
    }
}


/* =========================================================
   SYSTEM CLOCK
   ========================================================= */

void SystemClock_Config(void)
{
    RCC_OscInitTypeDef RCC_OscInitStruct = {0};
    RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

    RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
    RCC_OscInitStruct.HSIState = RCC_HSI_ON;
    RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
    RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;

    if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
    {
        Error_Handler();
    }

    RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK |
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


/* =========================================================
   GPIO INIT
   ========================================================= */

static void MX_GPIO_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    __HAL_RCC_GPIOA_CLK_ENABLE();

    GPIO_InitStruct.Pin = GPIO_PIN_4  |
                          GPIO_PIN_5  |
                          GPIO_PIN_6  |
                          GPIO_PIN_7  |
                          GPIO_PIN_8  |
                          GPIO_PIN_9  |
                          GPIO_PIN_10 |
                          GPIO_PIN_11 |
                          GPIO_PIN_12 |
                          GPIO_PIN_13 |
                          GPIO_PIN_14 |
                          GPIO_PIN_15;

    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;

    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    /* Tat het LED khi khoi dong */
    HAL_GPIO_WritePin(GPIOA,
                      GPIO_PIN_4  | GPIO_PIN_5  | GPIO_PIN_6  | GPIO_PIN_7 |
                      GPIO_PIN_8  | GPIO_PIN_9  | GPIO_PIN_10 | GPIO_PIN_11 |
                      GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_15,
                      GPIO_PIN_RESET);
}


/* =========================================================
   ERROR HANDLER
   ========================================================= */

void Error_Handler(void)
{
    __disable_irq();

    while (1)
    {
    }
}
