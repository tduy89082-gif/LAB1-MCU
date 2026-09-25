/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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


#define SCAN_COUNT      250
#define SCAN_DELAY_MS   2

/* Mau den */
#define RED      0
#define YELLOW   1
#define GREEN    2

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

void display7SEG(int num, uint32_t GPIO_Pin);

void allLEDOff(void);

void showTraffic(
    uint8_t verticalColor,
    uint8_t horizontalColor,
    GPIO_PinState phase
);

void runTrafficSecond(
    int verticalDisplay,
    int horizontalDisplay,
    uint8_t verticalColor,
    uint8_t horizontalColor
);

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */



void display7SEG(int num, uint32_t GPIO_Pin)
{
    char segNumber[10] =
    {
        0xC0,
        0xF9,
        0xA4,
        0xB0,
        0x99,
        0x92,
        0x82,
        0xF8,
        0x80,
        0x90
    };

    for (int i = 0; i < 7; ++i)
    {
        HAL_GPIO_WritePin(
            GPIOB,
            GPIO_Pin << i,
            (segNumber[num] >> i) & 1
        );
    }
}



void allLEDOff(void)
{
    HAL_GPIO_WritePin(
        GPIOA,
        GPIO_PIN_1 |
        GPIO_PIN_2 |
        GPIO_PIN_3 |
        GPIO_PIN_4 |
        GPIO_PIN_5 |
        GPIO_PIN_6,
        GPIO_PIN_SET
    );
}



void showTraffic(
    uint8_t verticalColor,
    uint8_t horizontalColor,
    GPIO_PinState phase
)
{
    HAL_GPIO_WritePin(
        GPIOA,
        GPIO_PIN_1 |
        GPIO_PIN_2 |
        GPIO_PIN_3 |
        GPIO_PIN_4 |
        GPIO_PIN_5 |
        GPIO_PIN_6,
        GPIO_PIN_SET
    );



    if (horizontalColor == RED)
    {
        HAL_GPIO_WritePin(
            GPIOA,
            GPIO_PIN_1,
            phase
        );
    }

    else if (horizontalColor == YELLOW)
    {
        HAL_GPIO_WritePin(
            GPIOA,
            GPIO_PIN_2,
            phase
        );
    }

    else if (horizontalColor == GREEN)
    {
        HAL_GPIO_WritePin(
            GPIOA,
            GPIO_PIN_3,
            phase
        );
    }


    if (verticalColor == RED)
    {
        HAL_GPIO_WritePin(
            GPIOA,
            GPIO_PIN_4,
            phase
        );
    }

    else if (verticalColor == YELLOW)
    {
        HAL_GPIO_WritePin(
            GPIOA,
            GPIO_PIN_5,
            phase
        );
    }

    else if (verticalColor == GREEN)
    {
        HAL_GPIO_WritePin(
            GPIOA,
            GPIO_PIN_6,
            phase
        );
    }
}



void runTrafficSecond(
    int verticalDisplay,
    int horizontalDisplay,
    uint8_t verticalColor,
    uint8_t horizontalColor
)
{
    for (int i = 0; i < SCAN_COUNT; i++)
    {
        /*
         * ====================================================
         * PHA 1
         * ====================================================
         */
        showTraffic(
            verticalColor,
            horizontalColor,
            GPIO_PIN_RESET
        );


        display7SEG(
            verticalDisplay,
            GPIO_PIN_0
        );

        display7SEG(
            horizontalDisplay,
            GPIO_PIN_7
        );

        HAL_Delay(SCAN_DELAY_MS);


        /*
         * ====================================================
         * PHA 2
         * ====================================================
         */
        showTraffic(
            verticalColor,
            horizontalColor,
            GPIO_PIN_SET
        );

        display7SEG(
            verticalDisplay,
            GPIO_PIN_0
        );

        display7SEG(
            horizontalDisplay,
            GPIO_PIN_7
        );

        HAL_Delay(SCAN_DELAY_MS);
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

    allLEDOff();

    /* USER CODE END 2 */


    /* Infinite loop */
    while (1)
    {

        runTrafficSecond(
            5,
            3,
            RED,
            GREEN
        );


        runTrafficSecond(
            4,
            2,
            RED,
            GREEN
        );


        runTrafficSecond(
            3,
            1,
            RED,
            GREEN
        );



        runTrafficSecond(
            2,
            2,
            RED,
            YELLOW
        );


        runTrafficSecond(
            1,
            1,
            RED,
            YELLOW
        );





        runTrafficSecond(
            3,
            5,
            GREEN,
            RED
        );


        runTrafficSecond(
            2,
            4,
            GREEN,
            RED
        );



        runTrafficSecond(
            1,
            3,
            GREEN,
            RED
        );



        runTrafficSecond(
            2,
            2,
            YELLOW,
            RED
        );



        runTrafficSecond(
            1,
            1,
            YELLOW,
            RED
        );


        /*
         * ====================================================
         * QUAY LAI GIAI DOAN 1
         * ====================================================
         */
    }


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


    /*
     * HSI Clock
     */
    RCC_OscInitStruct.OscillatorType =
        RCC_OSCILLATORTYPE_HSI;

    RCC_OscInitStruct.HSIState =
        RCC_HSI_ON;

    RCC_OscInitStruct.HSICalibrationValue =
        RCC_HSICALIBRATION_DEFAULT;

    RCC_OscInitStruct.PLL.PLLState =
        RCC_PLL_NONE;


    if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
    {
        Error_Handler();
    }


    /*
     * CPU / AHB / APB Clock
     */
    RCC_ClkInitStruct.ClockType =
        RCC_CLOCKTYPE_HCLK |
        RCC_CLOCKTYPE_SYSCLK |
        RCC_CLOCKTYPE_PCLK1 |
        RCC_CLOCKTYPE_PCLK2;

    RCC_ClkInitStruct.SYSCLKSource =
        RCC_SYSCLKSOURCE_HSI;

    RCC_ClkInitStruct.AHBCLKDivider =
        RCC_SYSCLK_DIV1;

    RCC_ClkInitStruct.APB1CLKDivider =
        RCC_HCLK_DIV1;

    RCC_ClkInitStruct.APB2CLKDivider =
        RCC_HCLK_DIV1;


    if (HAL_RCC_ClockConfig(
            &RCC_ClkInitStruct,
            FLASH_LATENCY_0) != HAL_OK)
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


    /*
     * ========================================================
     * GPIO CLOCK
     * ========================================================
     */
    __HAL_RCC_GPIOA_CLK_ENABLE();
    __HAL_RCC_GPIOB_CLK_ENABLE();





    HAL_GPIO_WritePin(
        GPIOA,
        GPIO_PIN_1 |
        GPIO_PIN_2 |
        GPIO_PIN_3 |
        GPIO_PIN_4 |
        GPIO_PIN_5 |
        GPIO_PIN_6,
        GPIO_PIN_SET
    );



    GPIO_InitStruct.Pin =
        GPIO_PIN_1 |
        GPIO_PIN_2 |
        GPIO_PIN_3 |
        GPIO_PIN_4 |
        GPIO_PIN_5 |
        GPIO_PIN_6;

    GPIO_InitStruct.Mode =
        GPIO_MODE_OUTPUT_PP;

    GPIO_InitStruct.Pull =
        GPIO_NOPULL;

    GPIO_InitStruct.Speed =
        GPIO_SPEED_FREQ_LOW;


    HAL_GPIO_Init(
        GPIOA,
        &GPIO_InitStruct
    );


    /*
     * ========================================================
     * GPIOB
     *
     * PB0 -> PB13
     * Cho 2 7SEG
     * ========================================================
     */

    HAL_GPIO_WritePin(
        GPIOB,
        GPIO_PIN_0 |
        GPIO_PIN_1 |
        GPIO_PIN_2 |
        GPIO_PIN_3 |
        GPIO_PIN_4 |
        GPIO_PIN_5 |
        GPIO_PIN_6 |
        GPIO_PIN_7 |
        GPIO_PIN_8 |
        GPIO_PIN_9 |
        GPIO_PIN_10 |
        GPIO_PIN_11 |
        GPIO_PIN_12 |
        GPIO_PIN_13,
        GPIO_PIN_RESET
    );


    GPIO_InitStruct.Pin =
        GPIO_PIN_0 |
        GPIO_PIN_1 |
        GPIO_PIN_2 |
        GPIO_PIN_3 |
        GPIO_PIN_4 |
        GPIO_PIN_5 |
        GPIO_PIN_6 |
        GPIO_PIN_7 |
        GPIO_PIN_8 |
        GPIO_PIN_9 |
        GPIO_PIN_10 |
        GPIO_PIN_11 |
        GPIO_PIN_12 |
        GPIO_PIN_13;

    GPIO_InitStruct.Mode =
        GPIO_MODE_OUTPUT_PP;

    GPIO_InitStruct.Pull =
        GPIO_NOPULL;

    GPIO_InitStruct.Speed =
        GPIO_SPEED_FREQ_LOW;


    HAL_GPIO_Init(
        GPIOB,
        &GPIO_InitStruct
    );
}


/* USER CODE BEGIN 4 */

/* USER CODE END 4 */


/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
    __disable_irq();

    while (1)
    {
    }
}


#ifdef USE_FULL_ASSERT

void assert_failed(uint8_t *file, uint32_t line)
{
}

#endif
