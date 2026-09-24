/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : LAB 2 - EXERCISE 2
  ******************************************************************************
  */
/* USER CODE END Header */

#include "main.h"

/* Private variables ---------------------------------------------------------*/
TIM_HandleTypeDef htim2;


/* USER CODE BEGIN PV */

/*
 * ============================================================
 * BÀI 2 - MAPPING THEO ĐÚNG SƠ ĐỒ PROTEUS
 *
 * PA4  -> DOT
 * PA5  -> KHÔNG DÙNG
 *
 * PA6  -> EN0 -> LED 7 SEG 1
 * PA7  -> EN1 -> LED 7 SEG 2
 * PA8  -> EN2 -> LED 7 SEG 3
 * PA9  -> EN3 -> LED 7 SEG 4
 *
 * PB0  -> SEG0
 * PB1  -> SEG1
 * PB2  -> SEG2
 * PB3  -> SEG3
 * PB4  -> SEG4
 * PB5  -> SEG5
 * PB6  -> SEG6
 *
 * PNP active LOW:
 * LOW  = LED ON
 * HIGH = LED OFF
 * ============================================================
 */


/* Nội dung 4 LED 7 đoạn
 *
 * LED1 = 0
 * LED2 = 0
 * LED3 = 3
 * LED4 = 0
 *
 * Mỗi LED đổi sau 500 ms.
 */
uint8_t led_buffer[4] = {0, 0, 3, 0};


/* LED đang được bật */
uint8_t current_led = 0;


/* Bộ đếm Timer */
uint16_t counter_500ms = 0;
uint16_t counter_1s = 0;


/*
 * ============================================================
 * MÃ LED 7 ĐOẠN COMMON ANODE
 *
 * PB0 = SEG0
 * PB1 = SEG1
 * PB2 = SEG2
 * PB3 = SEG3
 * PB4 = SEG4
 * PB5 = SEG5
 * PB6 = SEG6
 *
 * 0 = sáng đoạn
 * 1 = tắt đoạn
 * ============================================================
 */
const uint8_t seg7_code[10] =
{
    0xC0,   // 0
    0xF9,   // 1
    0xA4,   // 2
    0xB0,   // 3
    0x99,   // 4
    0x92,   // 5
    0x82,   // 6
    0xF8,   // 7
    0x80,   // 8
    0x90    // 9
};


/* USER CODE END PV */


/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_TIM2_Init(void);


/* USER CODE BEGIN 0 */


/*
 * ============================================================
 * HIỂN THỊ 1 SỐ TRÊN 7 SEG
 * ============================================================
 */
void display7SEG(uint8_t num)
{
    uint8_t data;

    if (num > 9)
    {
        num = 0;
    }

    data = seg7_code[num];


    /* SEG0 -> PB0 */
    HAL_GPIO_WritePin(
        GPIOB,
        GPIO_PIN_0,
        (data & 0x01) ? GPIO_PIN_SET : GPIO_PIN_RESET
    );


    /* SEG1 -> PB1 */
    HAL_GPIO_WritePin(
        GPIOB,
        GPIO_PIN_1,
        (data & 0x02) ? GPIO_PIN_SET : GPIO_PIN_RESET
    );


    /* SEG2 -> PB2 */
    HAL_GPIO_WritePin(
        GPIOB,
        GPIO_PIN_2,
        (data & 0x04) ? GPIO_PIN_SET : GPIO_PIN_RESET
    );


    /* SEG3 -> PB3 */
    HAL_GPIO_WritePin(
        GPIOB,
        GPIO_PIN_3,
        (data & 0x08) ? GPIO_PIN_SET : GPIO_PIN_RESET
    );


    /* SEG4 -> PB4 */
    HAL_GPIO_WritePin(
        GPIOB,
        GPIO_PIN_4,
        (data & 0x10) ? GPIO_PIN_SET : GPIO_PIN_RESET
    );


    /* SEG5 -> PB5 */
    HAL_GPIO_WritePin(
        GPIOB,
        GPIO_PIN_5,
        (data & 0x20) ? GPIO_PIN_SET : GPIO_PIN_RESET
    );


    /* SEG6 -> PB6 */
    HAL_GPIO_WritePin(
        GPIOB,
        GPIO_PIN_6,
        (data & 0x40) ? GPIO_PIN_SET : GPIO_PIN_RESET
    );
}


/*
 * ============================================================
 * TẮT 4 LED 7 ĐOẠN
 *
 * PA6 = EN0
 * PA7 = EN1
 * PA8 = EN2
 * PA9 = EN3
 *
 * PNP active LOW
 * HIGH = OFF
 * ============================================================
 */
void disableAllLED(void)
{
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, GPIO_PIN_SET);
}


/*
 * ============================================================
 * BẬT 1 LED 7 ĐOẠN
 *
 * index = 0 -> PA6 -> EN0 -> LED1
 * index = 1 -> PA7 -> EN1 -> LED2
 * index = 2 -> PA8 -> EN2 -> LED3
 * index = 3 -> PA9 -> EN3 -> LED4
 * ============================================================
 */
void enableLED(uint8_t index)
{
    /* Tắt tất cả trước */
    disableAllLED();


    switch (index)
    {
        case 0:
            /* EN0 -> PA6 */
            HAL_GPIO_WritePin(
                GPIOA,
                GPIO_PIN_6,
                GPIO_PIN_RESET
            );
            break;


        case 1:
            /* EN1 -> PA7 */
            HAL_GPIO_WritePin(
                GPIOA,
                GPIO_PIN_7,
                GPIO_PIN_RESET
            );
            break;


        case 2:
            /* EN2 -> PA8 */
            HAL_GPIO_WritePin(
                GPIOA,
                GPIO_PIN_8,
                GPIO_PIN_RESET
            );
            break;


        case 3:
            /* EN3 -> PA9 */
            HAL_GPIO_WritePin(
                GPIOA,
                GPIO_PIN_9,
                GPIO_PIN_RESET
            );
            break;


        default:
            break;
    }
}


/* USER CODE END 0 */


/* ============================================================
 * MAIN
 * ============================================================ */
int main(void)
{
    /* Reset of all peripherals, Initializes the Flash interface
       and the Systick. */
    HAL_Init();


    /* Configure System Clock */
    SystemClock_Config();


    /* Initialize GPIO */
    MX_GPIO_Init();


    /* Initialize TIM2 */
    MX_TIM2_Init();


    /*
     * ========================================================
     * KHỞI TẠO BAN ĐẦU
     * ========================================================
     */


    /* Tắt toàn bộ LED 7 đoạn */
    disableAllLED();


    /*
     * DOT
     *
     * PA4 nối DOT.
     *
     * Do LED nối từ +3.3V xuống DOT:
     * LOW  -> LED sáng
     * HIGH -> LED tắt
     *
     * Ban đầu cho tắt.
     */
    HAL_GPIO_WritePin(
        GPIOA,
        GPIO_PIN_4,
        GPIO_PIN_SET
    );


    /* Đặt dữ liệu số LED1 */
    display7SEG(led_buffer[0]);


    /* Bật LED1 */
    enableLED(0);


    /*
     * ========================================================
     * START TIM2 INTERRUPT
     *
     * TIM2 interrupt mỗi 10 ms
     * ========================================================
     */
    HAL_TIM_Base_Start_IT(&htim2);


    /* Infinite loop */
    while (1)
    {
        /*
         * Không dùng HAL_Delay().
         *
         * Mọi việc được xử lý trong Timer Interrupt.
         */
    }
}


/* ============================================================
 * SYSTEM CLOCK
 *
 * HSI = 8 MHz
 * PLL = OFF
 * ============================================================ */
void SystemClock_Config(void)
{
    RCC_OscInitTypeDef RCC_OscInitStruct = {0};
    RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};


    RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;

    RCC_OscInitStruct.HSIState = RCC_HSI_ON;

    RCC_OscInitStruct.HSICalibrationValue =
        RCC_HSICALIBRATION_DEFAULT;

    RCC_OscInitStruct.PLL.PLLState =
        RCC_PLL_NONE;


    if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
    {
        Error_Handler();
    }


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


/* ============================================================
 * TIM2 INIT
 *
 * Clock = 8 MHz
 *
 * Prescaler = 7999
 * Period    = 9
 *
 * 8,000,000 / 8000 = 1000 Hz
 *
 * 1000 / 10 = 100 Hz
 *
 * => 1 interrupt = 10 ms
 * ============================================================ */
static void MX_TIM2_Init(void)
{
    TIM_ClockConfigTypeDef sClockSourceConfig = {0};
    TIM_MasterConfigTypeDef sMasterConfig = {0};


    htim2.Instance = TIM2;


    htim2.Init.Prescaler = 7999;


    htim2.Init.CounterMode =
        TIM_COUNTERMODE_UP;


    htim2.Init.Period = 9;


    htim2.Init.ClockDivision =
        TIM_CLOCKDIVISION_DIV1;


    htim2.Init.AutoReloadPreload =
        TIM_AUTORELOAD_PRELOAD_DISABLE;


    if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
    {
        Error_Handler();
    }


    sClockSourceConfig.ClockSource =
        TIM_CLOCKSOURCE_INTERNAL;


    if (HAL_TIM_ConfigClockSource(
            &htim2,
            &sClockSourceConfig) != HAL_OK)
    {
        Error_Handler();
    }


    sMasterConfig.MasterOutputTrigger =
        TIM_TRGO_RESET;


    sMasterConfig.MasterSlaveMode =
        TIM_MASTERSLAVEMODE_DISABLE;


    if (HAL_TIMEx_MasterConfigSynchronization(
            &htim2,
            &sMasterConfig) != HAL_OK)
    {
        Error_Handler();
    }
}


/* ============================================================
 * GPIO INIT
 *
 * PA4 -> DOT
 *
 * PA5 -> KHÔNG DÙNG
 *
 * PA6 -> EN0
 * PA7 -> EN1
 * PA8 -> EN2
 * PA9 -> EN3
 *
 * PB0 -> SEG0
 * PB1 -> SEG1
 * PB2 -> SEG2
 * PB3 -> SEG3
 * PB4 -> SEG4
 * PB5 -> SEG5
 * PB6 -> SEG6
 * ============================================================ */
static void MX_GPIO_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};


    /* Enable GPIO clocks */
    __HAL_RCC_GPIOA_CLK_ENABLE();
    __HAL_RCC_GPIOB_CLK_ENABLE();


    /*
     * ========================================================
     * GPIOA
     * ========================================================
     */


    /* Ban đầu:
     *
     * PA4 = HIGH -> DOT OFF
     *
     * PA6-PA9 = HIGH -> 4 LED OFF
     */
    HAL_GPIO_WritePin(
        GPIOA,
        GPIO_PIN_4 |
        GPIO_PIN_6 |
        GPIO_PIN_7 |
        GPIO_PIN_8 |
        GPIO_PIN_9,
        GPIO_PIN_SET
    );


    /*
     * PA4 = DOT
     * PA6 = EN0
     * PA7 = EN1
     * PA8 = EN2
     * PA9 = EN3
     */
    GPIO_InitStruct.Pin =
        GPIO_PIN_4 |
        GPIO_PIN_6 |
        GPIO_PIN_7 |
        GPIO_PIN_8 |
        GPIO_PIN_9;


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
     * ========================================================
     */


    /* Tắt toàn bộ SEG ban đầu */
    HAL_GPIO_WritePin(
        GPIOB,
        GPIO_PIN_0 |
        GPIO_PIN_1 |
        GPIO_PIN_2 |
        GPIO_PIN_3 |
        GPIO_PIN_4 |
        GPIO_PIN_5 |
        GPIO_PIN_6,
        GPIO_PIN_SET
    );


    /*
     * PB0-PB6 = SEG0-SEG6
     */
    GPIO_InitStruct.Pin =
        GPIO_PIN_0 |
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
        GPIOB,
        &GPIO_InitStruct
    );
}


/* ============================================================
 * TIMER INTERRUPT CALLBACK
 *
 * TIM2 interrupt = 10 ms
 * ============================================================ */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    if (htim->Instance == TIM2)
    {
        /*
         * Mỗi lần vào callback = 10 ms
         */


        /* ====================================================
         * ĐỔI LED 7 ĐOẠN MỖI 500 ms
         *
         * 500 / 10 = 50 lần interrupt
         * ====================================================
         */
        counter_500ms++;


        if (counter_500ms >= 50)
        {
            counter_500ms = 0;


            /*
             * Chuyển sang LED tiếp theo
             */
            current_led++;


            if (current_led >= 4)
            {
                current_led = 0;
            }


            /*
             * Tắt LED cũ
             */
            disableAllLED();


            /*
             * Đưa dữ liệu số mới lên SEG
             */
            display7SEG(
                led_buffer[current_led]
            );


            /*
             * Bật LED mới
             */
            enableLED(current_led);
        }


        /* ====================================================
         * DOT ĐỔI TRẠNG THÁI MỖI 1 GIÂY
         *
         * 1000 / 10 = 100 lần interrupt
         * ====================================================
         */
        counter_1s++;


        if (counter_1s >= 100)
        {
            counter_1s = 0;


            /*
             * PA4 = DOT
             */
            HAL_GPIO_TogglePin(
                GPIOA,
                GPIO_PIN_4
            );
        }
    }
}


/* ============================================================
 * ERROR HANDLER
 * ============================================================ */
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
    /* User can add implementation to report file name
       and line number */
}

#endif
