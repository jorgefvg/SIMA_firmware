/**************************************************************************************************
 ** (c) Copyright 2025: Jorge Vásquez <jorgefernandov10@gmail.com>
 ** ALL RIGHTS RESERVED, DON'T USE OR PUBLISH THIS FILE WITHOUT AUTORIZATION
 *************************************************************************************************/

#ifndef API_INC_API_ERROR_H_
#define API_INC_API_ERROR_H_

/** @file API_error.h
 *  @brief Prototipos de funciones para la detección de errores en la API.
 *
 *  Este archivo declara las funciones utilizadas para manejar y reportar errores dentro de la API,
 * facilitando la depuración y el control de fallos.
 *
 * | REV | YYYY.MM.DD | Autor           | Descripción de los cambios                              |
 * |-----|------------|-----------------|---------------------------------------------------------|
 * |   1 | 2025.11.14 | Jorge Vásquez   | Versión inicial del archivo                             |
 *
 */

/* === Inclusiones de archivos externos ======================================================== */

/* === Cabecera C++ ============================================================================ */

#ifdef __cplusplus
extern "C" {
#endif

/* === Definicion y Macros ===================================================================== */

/* === Declaraciones de tipos de datos ========================================================= */

/* === Declaraciones de variables externas ===================================================== */

/* === Declaraciones de funciones externas ===================================================== */

/**
 * @brief Esta funcion se ejecuta en caso de que suceda un error en API.
 *
 */
void API_ERROR_LogError(void);

/* === Cierre de documentacion ================================================================= */
#ifdef __cplusplus
}
#endif

#endif /* API_INC_API_ERROR_H_ */
