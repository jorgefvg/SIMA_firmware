/**************************************************************************************************
 ** (c) Copyright 2025: Jorge Vásquez <jorgefernandov10@gmail.com>
 ** ALL RIGHTS RESERVED, DON'T USE OR PUBLISH THIS FILE WITHOUT AUTORIZATION
 *************************************************************************************************/

#ifndef API_INC_API_LCD_PORT_H_
#define API_INC_API_LCD_PORT_H_

/** @file API_lcd_port.h
 *  @brief Prototipos de funciones para la comunicacion de API_lcd y la HAL de ST.
 *
 * @note API para el manejo del LCD de bajo nivel.
 *
 * | REV | YYYY.MM.DD | Autor           | Descripción de los cambios                              |
 * |-----|------------|-----------------|---------------------------------------------------------|
 * |   1 | 2025.12.2  | Jorge Vásquez   | Versión inicial del archivo                             |
 *
 */

/* === Inclusiones de archivos externos ======================================================== */
#include <stdint.h>

/* === Cabecera C++ ============================================================================ */

#ifdef __cplusplus
extern "C" {
#endif

/* === Definicion y Macros ===================================================================== */

/* === Declaraciones de tipos de datos ========================================================= */

/* === Declaraciones de variables externas ===================================================== */

/* === Declaraciones de funciones externas ===================================================== */

/**
 * @brief Funcion que recibe el valor de un delay.
 * @param delay valor del delay
 * @return none
 */
void API_LCD_PORT_Delay(uint32_t delay);

/**
 * @brief Funciòn que manda el byte a escribir en el LCD16x2 por I2C.
 * @param valor valor a mandar por el puerto I2C
 * @return none
 */
void API_LCD_PORT_WriteByte(uint8_t valor);

/* === Cierre de documentacion ================================================================= */
#ifdef __cplusplus
}
#endif

#endif /* API_INC_API_LCD_PORT_H_ */
