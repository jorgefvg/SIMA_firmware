/**************************************************************************************************
 ** (c) Copyright 2025: Jorge Vásquez <jorgefernandov10@gmail.com>
 ** ALL RIGHTS RESERVED, DON'T USE OR PUBLISH THIS FILE WITHOUT AUTORIZATION
 *************************************************************************************************/

#ifndef API_INC_API_DELAY_PORT_H_
#define API_INC_API_DELAY_PORT_H_

/** @file API_delay_port.h
 *  @brief Prototipos de funciones para la comunicación entre API_delay y la HAL de ST.
 *
 *  Este archivo declara las funciones utilizadas en API_delay_port.c, las cuales permiten
 * interactuar con la HAL de STM32 para obtener una marca de tiempo en milisegundos.
 *
 * @note API para el manejo de delays no bloqueantes de bajo nivel.
 *
 * | REV | YYYY.MM.DD | Autor           | Descripción de los cambios                              |
 * |-----|------------|-----------------|---------------------------------------------------------|
 * |   1 | 2025.11.14 | Jorge Vásquez   | Versión inicial del archivo                             |
 *
 */

/* === Inclusiones de archivos externos ======================================================== */
#include <stdint.h>
#include "API_delay.h"

/* === Cabecera C++ ============================================================================ */

#ifdef __cplusplus
extern "C" {
#endif

/* === Definicion y Macros ===================================================================== */

/* === Declaraciones de tipos de datos ========================================================= */

/* === Declaraciones de variables externas ===================================================== */

/* === Declaraciones de funciones externas ===================================================== */

/**
 * @brief Obtiene la cuenta de ticks en ms como base de tiempo.
 *
 * El valor se obtiene de la función HAL_GetTick().
 * @return tick_t Valor actual de la cuenta de ticks en milisegundos.
 */
tick_t API_DELAY_PORT_GetTime(void);

/* === Cierre de documentacion ================================================================= */
#ifdef __cplusplus
}
#endif

#endif /* API_INC_API_DELAY_PORT_H_ */
