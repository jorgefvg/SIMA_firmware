/**************************************************************************************************
 ** (c) Copyright 2025: Jorge Vásquez <jorgefernandov10@gmail.com>
 ** ALL RIGHTS RESERVED, DON'T USE OR PUBLISH THIS FILE WITHOUT AUTORIZATION
 *************************************************************************************************/

/** @file API_delay.c
 *  @brief Implementación de la comunicación entre API_lcd y la HAL de STM32.
 *
 * | REV | YYYY.MM.DD | Autor           | Descripción de los cambios                              |
 * |-----|------------|-----------------|---------------------------------------------------------|
 * |   1 | 2025.11.14 | Jorge Vásquez   | Versión inicial del archivo                             |
 *
 */

/* === Inclusiones de cabeceras ================================================================ */
#include "API_lcd_port.h"
#include "stm32l4xx_hal.h"
#include "API_lcd.h"
#include "i2c.h"

/* === Definicion y Macros ===================================================================== */

/* == Declaraciones de tipos de datos internos ================================================= */

/* === Definiciones de variables internas ====================================================== */

/* === Definiciones de variables externas ====================================================== */

/* === Declaraciones de funciones internas ===================================================== */

/* === Definiciones de funciones internas ====================================================== */

/* === Definiciones de funciones externas ====================================================== */

void API_LCD_PORT_Delay(uint32_t delay) {
    HAL_Delay(delay);
}

void API_LCD_PORT_WriteByte(uint8_t valor) {
    if (HAL_I2C_Master_Transmit(&hi2c1, LCD_DIR << 1, &valor, sizeof(valor), HAL_MAX_DELAY))
        ;
}

/* === Cierre de documentacion ================================================================= */
