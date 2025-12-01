/**************************************************************************************************
 ** (c) Copyright 2025: Jorge Vásquez <jorgefernandov10@gmail.com>
 ** ALL RIGHTS RESERVED, DON'T USE OR PUBLISH THIS FILE WITHOUT AUTORIZATION
 *************************************************************************************************/

#ifndef API_INC_API_DELAY_H_
#define API_INC_API_DELAY_H_

/** @file API_delay.h
 *  @brief Prototipos de funciones para la gestión de delays no bloqueantes.
 *
 *  Se declaran las funciones utilizadas en API_delay.c, las cuales permiten implementar
 * retardos sin bloquear la ejecución del programa principal.
 *
 * @note API para el manejo de delays no bloqueantes de alto nivel.
 *
 * | REV | YYYY.MM.DD | Autor           | Descripción de los cambios                              |
 * |-----|------------|-----------------|---------------------------------------------------------|
 * |   1 | 2025.11.14 | Jorge Vásquez   | Versión inicial del archivo                             |
 *
 *  @startuml
 *  hide footbox
 *  title Diagrama de secuencia: API_delay
 *
 *  actor "Aplicación (main.c)" as Main
 *  participant "API_delay" as Delay
 *  participant "API_delay_port" as Port
 *  participant "HAL de STM32" as Hal
 *
 *  Main -> Delay : API_DELAY_Init()
 *
 *  Main -> Delay : API_DELAY_Read()
 *  Delay -> Port : API_DELAY_PORT_GetTime()
 *  Port -> Hal : HAL_GetTick()
 *  Hal --> Port : cantidad de tick actual (1 tick = 1 ms)
 *  Port --> Delay : tiempo actual en ms
 *  Delay --> Main : true si expiró el delay y false en caso contrario
 *
 *  Main -> Delay : API_DELAY_Write()
 *  @enduml
 *
 */

/* === Inclusiones de archivos externos ======================================================== */
#include <stdint.h>
#include <stdbool.h>

/* === Cabecera C++ ============================================================================ */

#ifdef __cplusplus
extern "C" {
#endif

/* === Definicion y Macros ===================================================================== */

/* === Declaraciones de tipos de datos ========================================================= */

/**
 * @brief Tipo de datos para almacenar un entero sin signo de 32 bits.
 *
 * Típicamente usado para contar ticks o unidades de tiempo en ms.
 */
typedef uint32_t tick_t;

/**
 * @brief Tipo de datos para almacenar un valor booleano (true/false).
 *
 */
typedef bool bool_t;

/**
 * @brief Estructura para gestionar retardos no bloqueantes.
 *
 * Permite medir intervalos de tiempo sin detener la ejecución del programa.
 */
typedef struct {
    tick_t startTime; //!< Tiempo de inicio del retardo (marca de referencia).
    tick_t duration;  //!< Duración total del retardo.
    bool_t running;   //!< Indica si el retardo está activo.
} delay_t;

/* === Declaraciones de variables externas ===================================================== */

/* === Declaraciones de funciones externas ===================================================== */

/**
 * @brief  Funcion que inicializa el delay no bloqueante.
 * @param  delay Puntero a la estructura para gestionar retardos no bloqueantes.
 * @param  duration Duración del delay o retardo.
 * @return None
 */
void API_DELAY_Init(delay_t * delay, tick_t duration);

/**
 * @brief  Funcion para obtener el estado del delay.
 * @param  delay Puntero a la estructura para gestionar retardos no bloqueantes.
 * @return bool_t Estado del delay, retorna false si aun sigue contando y retorna true si se cumplio
 * el tiempo.
 */
bool_t API_DELAY_Read(delay_t * delay);

/**
 * @brief  Funcion que actualiza la duración del retardo.
 * @param  delay Puntero a la estructura para gestionar retardos no bloqueantes.
 * @param  duration Duración del delay o retardo.
 * @return None
 */
void API_DELAY_Write(delay_t * delay, tick_t duration);

/* === Cierre de documentacion ================================================================= */
#ifdef __cplusplus
}
#endif

#endif /* API_INC_API_DELAY_H_ */
