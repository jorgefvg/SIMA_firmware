/**************************************************************************************************
 ** (c) Copyright 2025: Jorge Vásquez <jorgefernandov10@gmail.com>
 ** ALL RIGHTS RESERVED, DON'T USE OR PUBLISH THIS FILE WITHOUT AUTORIZATION
 *************************************************************************************************/

/** @file API_delay_port.c
 *  @brief Implementación de la comunicación entre API_delay y la HAL de STM32.
 *
 * | REV | YYYY.MM.DD | Autor           | Descripción de los cambios                              |
 * |-----|------------|-----------------|---------------------------------------------------------|
 * |   1 | 2025.11.14 | Jorge Vásquez   | Versión inicial del archivo                             |
 *
 */

/* === Inclusiones de cabeceras ================================================================ */
#include "API_delay_port.h"
#include "stm32l4xx_hal.h"

/* === Definicion y Macros ===================================================================== */

/* == Declaraciones de tipos de datos internos ================================================= */

/* === Definiciones de variables internas ====================================================== */

/* === Definiciones de variables externas ====================================================== */

/* === Declaraciones de funciones internas ===================================================== */

/* === Definiciones de funciones internas ====================================================== */

/* === Definiciones de funciones externas ====================================================== */

tick_t API_DELAY_PORT_GetTime(void) {

    tick_t time = HAL_GetTick();

    return time;
}

/* === Cierre de documentacion ================================================================= */
