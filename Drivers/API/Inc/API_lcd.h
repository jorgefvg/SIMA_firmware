/**************************************************************************************************
 ** (c) Copyright 2025: Jorge Vásquez <jorgefernandov10@gmail.com>
 ** ALL RIGHTS RESERVED, DON'T USE OR PUBLISH THIS FILE WITHOUT AUTORIZATION
 *************************************************************************************************/

#ifndef API_INC_API_LCD_H_
#define API_INC_API_LCD_H_

/** @file API_lcd.h
 *  @brief Prototipos de funciones para utilizar una pantalla LCD16x2.
 *
 * @note API para el manejo del LCD de alto nivel.
 *
 * | REV | YYYY.MM.DD | Autor           | Descripción de los cambios                              |
 * |-----|------------|-----------------|---------------------------------------------------------|
 * |   1 | 2025.12.2  | Jorge Vásquez   | Versión inicial del archivo                             |
 *
 *  @startuml
 *  hide footbox
 *  title Diagrama de secuencia: API_lcd
 *
 *  actor "Aplicación (main.c)" as Main
 *  participant "API_lcd" as LCD
 *  participant "API_lcd_port" as Port
 *  participant "HAL de STM32" as Hal
 *
 *  ' --- Inicialización general ---
 *  Main -> LCD : API_LCD_Init()
 *  LCD -> Port : API_LCD_PORT_WriteByte()\n(envío de comandos de init)
 *  Port -> Hal : HAL_I2C_Master_Transmit()
 *  Hal --> Port
 *
 *  ' --- Posicionar el cursor ---
 *  Main -> LCD : API_LCD_CursorPosition(row, col)
 *  LCD -> Port : API_LCD_PORT_WriteByte()\n(escritura dirección DDRAM)
 *  Port -> Hal : HAL_I2C_Master_Transmit()
 *  Hal --> Port
 *
 *  ' --- Escribir texto ---
 *  Main -> LCD : API_LCD_WriteText(texto)
 *  loop Envío de cada carácter
 *      LCD -> Port : API_LCD_PORT_WriteByte()
 *      Port -> Hal : HAL_I2C_Master_Transmit()
 *      Hal --> Port
 *  end
 *
 *  ' --- Escribir número ---
 *  Main -> LCD : API_LCD_WriteNumber(valor)
 *  LCD -> LCD : Conversión a string (sprintf)
 *  loop Envío de cada carácter
 *      LCD -> Port : API_LCD_PORT_WriteByte()
 *      Port -> Hal : HAL_I2C_Master_Transmit()
 *      Hal --> Port
 *  end
 *
 *  ' --- Limpiar pantalla ---
 *  Main -> LCD : API_LCD_CleanScreen()
 *  LCD -> Port : API_LCD_PORT_WriteByte()\n(comando clear display)
 *  Port -> Hal : HAL_I2C_Master_Transmit()
 *  Hal --> Port
 *
 *  @enduml
 *
 */

/* === Inclusiones de archivos externos ======================================================== */
#include <stdint.h>

/* === Cabecera C++ ============================================================================ */

#ifdef __cplusplus
extern "C" {
#endif

/* === Definicion y Macros ===================================================================== */

// Demoras necesarias
#define DELAY20ms 20
#define DELAY10ms 10
#define DELAY2ms  2
#define DELAY1ms  1

// Comandos de inicializacion de la pantalla HD44780
#define COMANDO_INIT1 0x30 // por defecto se debe de mandar tres veces al iniciar
#define COMANDO_INIT2 0x20 // para indicar que se trabajara en modo de 4 bits

// Definimos si es un comando o dato que queremos enviar al LCD
#define DATO    1
#define COMANDO 0

// Bits de ENABLE y BACK LIGHT
#define EN (1 << 2)
#define BL (1 << 3)

// Manejo de nibbles
#define HIGH_NIBBLE 0xf0
#define LOW_NIBBLE  4

// Direccion del LCD
#define LCD_DIR 0x27

// Posicion del cursor
#define POSICION_FILA1 0x80
#define POSICION_FILA2 0xC0

// Señales de control
#define CLEAN_LCD            1
#define RETURN_HOME          (1 << 1)
#define ENTRY_MODE           (1 << 2)
#define DISPLAY_CONTROL      (1 << 3)
#define CURSOR_DISPLAY_SHIFT (1 << 4)
#define FUNTION_SET          (1 << 5)
#define SET_CGRAM            (1 << 6)
#define SET_DDRAM            (1 << 7)
#define DISPLAY_ON           (1 << 2)
#define CURSOR_ON            (1 << 1)
#define CURSOR_BLINK         1
#define AUTOINCREMENT        (1 << 1)
#define _4BIT_MODE           0x28

/* === Declaraciones de tipos de datos ========================================================= */

/* === Declaraciones de variables externas ===================================================== */

/* === Declaraciones de funciones externas ===================================================== */

/**
 * @brief Inicializo el LCD16x2.
 *
 * Configuracion inicial del LCD16x2.
 * @return none
 */
void API_LCD_Init(void);

/**
 * @brief Funcion que borra la pantalla del LCD16x2
 * @return none
 */
void API_LCD_CleanScreen(void);

/**
 * @brief Funcion para indicar la posicion de escritura en la pantalla LCD16x2
 * @param row mandamos posicion de la fila (0 = fila uno, 1 = fila dos)
 * @param col mandamos posicion de la columna (columnas disponibles de 0 a 15)
 * @return void
 */
void API_LCD_CursorPosition(uint8_t row, uint8_t column);

/**
 * @brief  Funcion que envia un texto al LCD16x2
 * @param  texto puntero a un string de caracteres a enviar
 * @return void
 */
void API_LCD_WriteText(char * texto);

/**
 * @brief  Funcion que convierte un numero a cadena de caracteres y lo envia al LCD16x2.
 * @param  valor dato a enviar al LCD16x2.
 * @return void
 */
void API_LCD_WriteNumber(int valor);

/* === Cierre de documentacion ================================================================= */
#ifdef __cplusplus
}
#endif

#endif /* API_INC_API_LCD_H_ */
