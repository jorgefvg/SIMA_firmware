/**************************************************************************************************
 ** (c) Copyright 2025: Jorge Vásquez <jorgefernandov10@gmail.com>
 ** ALL RIGHTS RESERVED, DON'T USE OR PUBLISH THIS FILE WITHOUT AUTORIZATION
 *************************************************************************************************/

/** @file API_delay.c
 *  @brief Implementacion de un delay no bloqueante.
 *
 * | REV | YYYY.MM.DD | Autor           | Descripción de los cambios                              |
 * |-----|------------|-----------------|---------------------------------------------------------|
 * |   1 | 2025.11.14 | Jorge Vásquez   | Versión inicial del archivo                             |
 *
 */

/* === Inclusiones de cabeceras ================================================================ */
#include "API_delay.h"
#include "API_delay_port.h"
#include "API_error.h"
#include <stddef.h>

/* === Definicion y Macros ===================================================================== */

/* == Declaraciones de tipos de datos internos ================================================= */

/* === Definiciones de variables internas ====================================================== */

/* === Definiciones de variables externas ====================================================== */

/* === Declaraciones de funciones internas ===================================================== */

/* === Definiciones de funciones internas ====================================================== */

/* === Definiciones de funciones externas ====================================================== */

void API_DELAY_Init(delay_t * delay, tick_t duration) {

    /* Inicializa el error*/
    if (delay == NULL || duration == 0) {
        API_ERROR_LogError();
    }

    delay->duration = duration;
    delay->running = false;
}

bool_t API_DELAY_Read(delay_t * delay) {

    bool_t return_value = false;

    if (delay == NULL) {
        API_ERROR_LogError();
    }

    if (delay->running == false) {
        delay->startTime = API_DELAY_PORT_GetTime();
        delay->running = true;
    } else if (API_DELAY_PORT_GetTime() - delay->startTime >= delay->duration) {
        delay->running = false;
        return_value = true;
    }

    return return_value;
}

void API_DELAY_Write(delay_t * delay, tick_t duration) {

    if (delay == NULL || duration == 0) {
        API_ERROR_LogError();
    }

    delay->duration = duration;
}

/* === Cierre de documentacion ================================================================= */
