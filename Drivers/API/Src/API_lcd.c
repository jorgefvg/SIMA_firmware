/**************************************************************************************************
 ** (c) Copyright 2025: Jorge Vásquez <jorgefernandov10@gmail.com>
 ** ALL RIGHTS RESERVED, DON'T USE OR PUBLISH THIS FILE WITHOUT AUTORIZATION
 *************************************************************************************************/

/** @file API_delay.c
 *  @brief Implementacion de una api para manejo de un LCD16x2.
 *
 * | REV | YYYY.MM.DD | Autor           | Descripción de los cambios                              |
 * |-----|------------|-----------------|---------------------------------------------------------|
 * |   1 | 2025.11.14 | Jorge Vásquez   | Versión inicial del archivo                             |
 *
 */

/* === Inclusiones de cabeceras ================================================================ */
#include "API_lcd.h"
#include "API_lcd_port.h"
#include <stdbool.h>
#include <stdio.h>

/* === Definicion y Macros ===================================================================== */

/* == Declaraciones de tipos de datos internos ================================================= */

/* === Definiciones de variables internas ====================================================== */

/* === Definiciones de variables externas ====================================================== */

/* === Declaraciones de funciones internas ===================================================== */

/**
 * @brief Función para el envio de 4 bits al LCD16x2
 * @param valor valor a enviar
 * @param tipo envia un comando o dato (comando = 0, dato = 1)
 * @return none
 */
static void Envia4bitsLcd(uint8_t valor, bool tipo);

/**
 * @brief Función que parte el envio de 1 byte en nible alto y bajo para trabajar en 4 bits
 * @param valor valor a enviar
 * @param tipo envia un comando o dato (comando = 0, dato = 1)
 * @return none
 */
static void Envia8bitsLcd(uint8_t valor, bool tipo);

/* === Definiciones de funciones internas ====================================================== */

static void Envia4bitsLcd(uint8_t valor, bool tipo) {

    API_LCD_PORT_WriteByte(valor + tipo + EN + BL);
    API_LCD_PORT_Delay(DELAY1ms);

    API_LCD_PORT_WriteByte(valor + tipo + BL);
    API_LCD_PORT_Delay(DELAY1ms);
}

static void Envia8bitsLcd(uint8_t valor, bool tipo) {
    Envia4bitsLcd(valor & HIGH_NIBBLE, tipo);
    Envia4bitsLcd(valor << LOW_NIBBLE, tipo);
}

/* === Definiciones de funciones externas ====================================================== */

void API_LCD_CleanScreen(void) {
    Envia8bitsLcd(CLEAN_LCD, COMANDO);
    API_LCD_PORT_Delay(DELAY2ms);
}

void API_LCD_CursorPosition(uint8_t row, uint8_t column) {
    switch (row) {
    case 0:
        column |= POSICION_FILA1;
        break;
    case 1:
        column |= POSICION_FILA2;
        break;
    }

    Envia8bitsLcd(column, COMANDO);
}

void API_LCD_WriteText(char * texto) {
    while (*texto)
        Envia8bitsLcd(*texto++, DATO);
}

void API_LCD_WriteNumber(int valor) {
    char buffer[12];
    sprintf(buffer, "%d", valor);
    API_LCD_WriteText(buffer);
}

void API_LCD_Init(void) {

    API_LCD_PORT_Delay(DELAY20ms);
    Envia4bitsLcd(COMANDO_INIT1, COMANDO);
    API_LCD_PORT_Delay(DELAY10ms);
    Envia4bitsLcd(COMANDO_INIT1, COMANDO);
    API_LCD_PORT_Delay(DELAY1ms);
    Envia4bitsLcd(COMANDO_INIT1, COMANDO);
    Envia4bitsLcd(COMANDO_INIT2, COMANDO);

    Envia8bitsLcd(_4BIT_MODE, COMANDO);
    API_LCD_PORT_Delay(DELAY2ms);
    Envia8bitsLcd(DISPLAY_CONTROL, COMANDO);
    API_LCD_PORT_Delay(DELAY2ms);
    Envia8bitsLcd(RETURN_HOME, COMANDO);
    API_LCD_PORT_Delay(DELAY2ms);
    Envia8bitsLcd(ENTRY_MODE + AUTOINCREMENT, COMANDO);
    API_LCD_PORT_Delay(DELAY2ms);
    Envia8bitsLcd(DISPLAY_CONTROL + DISPLAY_ON, COMANDO);
    API_LCD_PORT_Delay(DELAY2ms);
    Envia8bitsLcd(CLEAN_LCD, COMANDO);
    API_LCD_PORT_Delay(DELAY2ms);
}

/* === Cierre de documentacion ================================================================= */
