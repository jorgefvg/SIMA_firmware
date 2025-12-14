/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : main.c
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2025 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "dfsdm.h"
#include "i2c.h"
#include "quadspi.h"
#include "spi.h"
#include "usart.h"
#include "usb_otg.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "API_delay.h"
#include "API_lcd.h"

#include "network.h"
#include "network_data.h"
#include "ai_platform.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define LED_TIME 4000
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
delay_t led_delay;

static ai_handle network = AI_HANDLE_NULL;

AI_ALIGNED(4) static ai_u8 activations[AI_NETWORK_DATA_ACTIVATIONS_SIZE];

AI_ALIGNED(4) static float in_data[AI_NETWORK_IN_1_SIZE];
AI_ALIGNED(4) static float out_data[AI_NETWORK_OUT_1_SIZE];

static const float scaler_mean[4] = {5.84166666f, 3.04833333f, 3.76999999f, 1.20499999f};
static const float scaler_scale[4] = {0.83741499f, 0.44665112f, 1.76113599f, 0.75947898f};

ai_buffer * ai_input;
ai_buffer * ai_output;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */
void API_AIMODEL_Init(void);

void API_AIMODEL_Run(float * in_data, float * out_data);

void API_AIMODEL_NormalizeInput(const float in[4], float out[4]);
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
void API_AIMODEL_Init(void) {
    ai_error err;
    const ai_handle act_addr[] = {activations};

    err = ai_network_create_and_init(&network, act_addr, NULL);

    if (err.type != AI_ERROR_NONE) {
        Error_Handler();
    }

    ai_input = ai_network_inputs_get(network, NULL);
    ai_output = ai_network_outputs_get(network, NULL);
}

void API_AIMODEL_Run(float * in_data, float * out_data) {
    ai_i32 nbatch;

    ai_input[0].data = AI_HANDLE_PTR(in_data);
    ai_output[0].data = AI_HANDLE_PTR(out_data);

    nbatch = ai_network_run(network, ai_input, ai_output);

    if (nbatch != 1) {
        Error_Handler();
    }
}

void API_AIMODEL_NormalizeInput(const float in[4], float out[4]) {
    for (int i = 0; i < 4; i++) {
        out[i] = (in[i] - scaler_mean[i]) / scaler_scale[i];
    }
}
/* USER CODE END 0 */

/**
 * @brief  The application entry point.
 * @retval int
 */
int main(void) {

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
    MX_DFSDM1_Init();
    MX_I2C2_Init();
    MX_QUADSPI_Init();
    MX_SPI3_Init();
    MX_USART1_UART_Init();
    MX_USART3_UART_Init();
    MX_USB_OTG_FS_PCD_Init();
    MX_I2C1_Init();
    /* USER CODE BEGIN 2 */

    // Inicializar LCD, delay, etc.
    API_DELAY_Init(&led_delay, LED_TIME);
    API_LCD_Init();

    // Inicializar Red Neuronal
    API_AIMODEL_Init();

    // Valores de ejemplo
    float example[4] = {6.0f, 2.2f, 4.0f, 1.0f};

    float norm_input[4];
    API_AIMODEL_NormalizeInput(example, norm_input);

    // Copiar a buffer de entrada
    for (int i = 0; i < 4; i++)
        in_data[i] = norm_input[i];

    // Ejecutar inferencia una sola vez
    API_AIMODEL_Run(in_data, out_data);

    // Determinar clase predicha
    int predicted = 0;
    float max_val = out_data[0];

    for (int i = 1; i < 3; i++) {
        if (out_data[i] > max_val) {
            max_val = out_data[i];
            predicted = i;
        }
    }

    // Mostrar resultado en el LCD
    API_LCD_CursorPosition(0, 0);
    API_LCD_WriteText("Datos de entrada");
    API_LCD_CursorPosition(1, 0);
    API_LCD_WriteText("Espere ...");
    HAL_Delay(4000);
    API_LCD_CleanScreen();

    API_LCD_CursorPosition(0, 0);
    API_LCD_WriteText("Longitud y ancho");
    API_LCD_CursorPosition(1, 0);
    API_LCD_WriteText("petalo y sepalo");
    HAL_Delay(4000);
    API_LCD_CleanScreen();

    API_LCD_CursorPosition(0, 0);
    API_LCD_WriteText("Longitud y ancho");
    API_LCD_CursorPosition(1, 0);
    API_LCD_WriteText("6.0,2.2,4.0,1.0");
    HAL_Delay(4000);
    API_LCD_CleanScreen();

    API_LCD_CursorPosition(0, 0);
    API_LCD_WriteText("Prediccion IA:");

    API_LCD_CursorPosition(1, 0);
    switch (predicted) {
    case 0:
        API_LCD_WriteText("Iris Setosa");
        break;
    case 1:
        API_LCD_WriteText("Iris Versicolor");
        break;
    case 2:
        API_LCD_WriteText("Iris Virginica");
        break;
    }

    /* USER CODE END 2 */

    /* Infinite loop */
    /* USER CODE BEGIN WHILE */
    while (1) {
        /* USER CODE END WHILE */

        /* USER CODE BEGIN 3 */
        if (API_DELAY_Read(&led_delay)) {
            HAL_GPIO_TogglePin(LED2_GPIO_Port, LED2_Pin);
        }
    }
    /* USER CODE END 3 */
}

/**
 * @brief System Clock Configuration
 * @retval None
 */
void SystemClock_Config(void) {
    RCC_OscInitTypeDef RCC_OscInitStruct = {0};
    RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

    /** Configure the main internal regulator output voltage
     */
    if (HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1) != HAL_OK) {
        Error_Handler();
    }

    /** Configure LSE Drive Capability
     */
    HAL_PWR_EnableBkUpAccess();
    __HAL_RCC_LSEDRIVE_CONFIG(RCC_LSEDRIVE_LOW);

    /** Initializes the RCC Oscillators according to the specified parameters
     * in the RCC_OscInitTypeDef structure.
     */
    RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_LSE | RCC_OSCILLATORTYPE_MSI;
    RCC_OscInitStruct.LSEState = RCC_LSE_ON;
    RCC_OscInitStruct.MSIState = RCC_MSI_ON;
    RCC_OscInitStruct.MSICalibrationValue = 0;
    RCC_OscInitStruct.MSIClockRange = RCC_MSIRANGE_6;
    RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
    RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_MSI;
    RCC_OscInitStruct.PLL.PLLM = 1;
    RCC_OscInitStruct.PLL.PLLN = 40;
    RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV7;
    RCC_OscInitStruct.PLL.PLLQ = RCC_PLLQ_DIV2;
    RCC_OscInitStruct.PLL.PLLR = RCC_PLLR_DIV2;
    if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK) {
        Error_Handler();
    }

    /** Initializes the CPU, AHB and APB buses clocks
     */
    RCC_ClkInitStruct.ClockType =
        RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
    RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
    RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
    RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
    RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

    if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_4) != HAL_OK) {
        Error_Handler();
    }

    /** Enable MSI Auto calibration
     */
    HAL_RCCEx_EnableMSIPLLMode();
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
 * @brief  This function is executed in case of error occurrence.
 * @retval None
 */
void Error_Handler(void) {
    /* USER CODE BEGIN Error_Handler_Debug */
    /* User can add his own implementation to report the HAL error return state */
    __disable_irq();
    while (1) {
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
void assert_failed(uint8_t * file, uint32_t line) {
    /* USER CODE BEGIN 6 */
    /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
    /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
