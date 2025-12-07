#include "unity.h"
#include "API_lcd.h"

// Mocks
#include "mock_API_lcd_port.h"

void setUp(void) {
}
void tearDown(void) {
}

/* TEST: API_LCD_Init */

void test_API_LCD_Init(void) {
    // Secuencia esperada

    // 1) delay 20ms
    API_LCD_PORT_Delay_Expect(DELAY20ms);

    // 2) Primer envío de 0x30 (init)
    API_LCD_PORT_WriteByte_Expect(COMANDO_INIT1 + COMANDO + EN + BL);
    API_LCD_PORT_Delay_Expect(DELAY1ms);

    API_LCD_PORT_WriteByte_Expect(COMANDO_INIT1 + COMANDO + BL);
    API_LCD_PORT_Delay_Expect(DELAY1ms);

    // 3) delay 10ms
    API_LCD_PORT_Delay_Expect(DELAY10ms);

    // 4) Segundo envío de 0x30
    API_LCD_PORT_WriteByte_Expect(COMANDO_INIT1 + COMANDO + EN + BL);
    API_LCD_PORT_Delay_Expect(DELAY1ms);

    API_LCD_PORT_WriteByte_Expect(COMANDO_INIT1 + COMANDO + BL);
    API_LCD_PORT_Delay_Expect(DELAY1ms);

    // 5) delay 1ms
    API_LCD_PORT_Delay_Expect(DELAY1ms);

    // 6) Tercer envío de 0x30
    API_LCD_PORT_WriteByte_Expect(COMANDO_INIT1 + COMANDO + EN + BL);
    API_LCD_PORT_Delay_Expect(DELAY1ms);

    API_LCD_PORT_WriteByte_Expect(COMANDO_INIT1 + COMANDO + BL);
    API_LCD_PORT_Delay_Expect(DELAY1ms);

    // 7) Enviar 0x20 (modo 4 bits)
    API_LCD_PORT_WriteByte_Expect(COMANDO_INIT2 + COMANDO + EN + BL);
    API_LCD_PORT_Delay_Expect(DELAY1ms);

    API_LCD_PORT_WriteByte_Expect(COMANDO_INIT2 + COMANDO + BL);
    API_LCD_PORT_Delay_Expect(DELAY1ms);

    // Envio de comandos utilizando la funcion interna Envia8bitsLcd()

    // Envio del comando _4BIT_MODE (0x28)
    // alto nibble
    API_LCD_PORT_WriteByte_Expect((0x28 & HIGH_NIBBLE) + COMANDO + EN + BL);
    API_LCD_PORT_Delay_Expect(DELAY1ms);
    API_LCD_PORT_WriteByte_Expect((0x28 & HIGH_NIBBLE) + COMANDO + BL);
    API_LCD_PORT_Delay_Expect(DELAY1ms);
    // bajo nibble
    API_LCD_PORT_WriteByte_Expect(((0x28 << LOW_NIBBLE)) + COMANDO + EN + BL);
    API_LCD_PORT_Delay_Expect(DELAY1ms);
    API_LCD_PORT_WriteByte_Expect(((0x28 << LOW_NIBBLE)) + COMANDO + BL);
    API_LCD_PORT_Delay_Expect(DELAY1ms);
    API_LCD_PORT_Delay_Expect(DELAY2ms);

    // Envio del comando DISPLAY_CONTROL (0x08)
    // alto nibble
    API_LCD_PORT_WriteByte_Expect((0x08 & HIGH_NIBBLE) + COMANDO + EN + BL);
    API_LCD_PORT_Delay_Expect(DELAY1ms);
    API_LCD_PORT_WriteByte_Expect((0x08 & HIGH_NIBBLE) + COMANDO + BL);
    API_LCD_PORT_Delay_Expect(DELAY1ms);
    // bajo nibble
    API_LCD_PORT_WriteByte_Expect(((0x08 << LOW_NIBBLE)) + COMANDO + EN + BL);
    API_LCD_PORT_Delay_Expect(DELAY1ms);
    API_LCD_PORT_WriteByte_Expect(((0x08 << LOW_NIBBLE)) + COMANDO + BL);
    API_LCD_PORT_Delay_Expect(DELAY1ms);
    API_LCD_PORT_Delay_Expect(DELAY2ms);

    // Envio del comando RETURN_HOME
    API_LCD_PORT_WriteByte_Expect((RETURN_HOME & HIGH_NIBBLE) + COMANDO + EN + BL);
    API_LCD_PORT_Delay_Expect(DELAY1ms);
    API_LCD_PORT_WriteByte_Expect((RETURN_HOME & HIGH_NIBBLE) + COMANDO + BL);
    API_LCD_PORT_Delay_Expect(DELAY1ms);
    API_LCD_PORT_WriteByte_Expect(((RETURN_HOME << LOW_NIBBLE)) + COMANDO + EN + BL);
    API_LCD_PORT_Delay_Expect(DELAY1ms);
    API_LCD_PORT_WriteByte_Expect(((RETURN_HOME << LOW_NIBBLE)) + COMANDO + BL);
    API_LCD_PORT_Delay_Expect(DELAY1ms);
    API_LCD_PORT_Delay_Expect(DELAY2ms);

    // Envio del comando ENTRY_MODE + AUTOINCREMENT
    uint8_t em = ENTRY_MODE + AUTOINCREMENT;
    API_LCD_PORT_WriteByte_Expect((em & HIGH_NIBBLE) + COMANDO + EN + BL);
    API_LCD_PORT_Delay_Expect(DELAY1ms);
    API_LCD_PORT_WriteByte_Expect((em & HIGH_NIBBLE) + COMANDO + BL);
    API_LCD_PORT_Delay_Expect(DELAY1ms);
    API_LCD_PORT_WriteByte_Expect((em << LOW_NIBBLE) + COMANDO + EN + BL);
    API_LCD_PORT_Delay_Expect(DELAY1ms);
    API_LCD_PORT_WriteByte_Expect((em << LOW_NIBBLE) + COMANDO + BL);
    API_LCD_PORT_Delay_Expect(DELAY1ms);
    API_LCD_PORT_Delay_Expect(DELAY2ms);

    // Envio del comando DISPLAY_CONTROL + DISPLAY_ON
    uint8_t dc = DISPLAY_CONTROL + DISPLAY_ON;
    API_LCD_PORT_WriteByte_Expect((dc & HIGH_NIBBLE) + COMANDO + EN + BL);
    API_LCD_PORT_Delay_Expect(DELAY1ms);
    API_LCD_PORT_WriteByte_Expect((dc & HIGH_NIBBLE) + COMANDO + BL);
    API_LCD_PORT_Delay_Expect(DELAY1ms);
    API_LCD_PORT_WriteByte_Expect((dc << LOW_NIBBLE) + COMANDO + EN + BL);
    API_LCD_PORT_Delay_Expect(DELAY1ms);
    API_LCD_PORT_WriteByte_Expect((dc << LOW_NIBBLE) + COMANDO + BL);
    API_LCD_PORT_Delay_Expect(DELAY1ms);
    API_LCD_PORT_Delay_Expect(DELAY2ms);

    // Envio del comando CLEAN_LCD
    uint8_t cl = CLEAN_LCD;
    API_LCD_PORT_WriteByte_Expect((cl & HIGH_NIBBLE) + COMANDO + EN + BL);
    API_LCD_PORT_Delay_Expect(DELAY1ms);
    API_LCD_PORT_WriteByte_Expect((cl & HIGH_NIBBLE) + COMANDO + BL);
    API_LCD_PORT_Delay_Expect(DELAY1ms);
    API_LCD_PORT_WriteByte_Expect((cl << LOW_NIBBLE) + COMANDO + EN + BL);
    API_LCD_PORT_Delay_Expect(DELAY1ms);
    API_LCD_PORT_WriteByte_Expect((cl << LOW_NIBBLE) + COMANDO + BL);
    API_LCD_PORT_Delay_Expect(DELAY1ms);
    API_LCD_PORT_Delay_Expect(DELAY2ms);

    // Ejecutar función
    API_LCD_Init();
}

/* TEST: API_LCD_CleanScreen */

void test_API_LCD_CleanScreen_should_send_clean_command(void) {
    // CLEAN_LCD -> Envia8bitsLcd -> Envia4bitsLcd -> PORT_WriteByte (2 veces por nibble)
    // Se envían 2 nibbles, cada uno genera 2 WriteByte
    // Total: 4 llamadas a WriteByte + 1 delay final

    // HIGH nibble
    API_LCD_PORT_WriteByte_ExpectAnyArgs();
    API_LCD_PORT_Delay_Expect(DELAY1ms);
    API_LCD_PORT_WriteByte_ExpectAnyArgs();
    API_LCD_PORT_Delay_Expect(DELAY1ms);

    // LOW nibble
    API_LCD_PORT_WriteByte_ExpectAnyArgs();
    API_LCD_PORT_Delay_Expect(DELAY1ms);
    API_LCD_PORT_WriteByte_ExpectAnyArgs();
    API_LCD_PORT_Delay_Expect(DELAY1ms);

    // Delay final del CleanScreen
    API_LCD_PORT_Delay_Expect(DELAY2ms);

    API_LCD_CleanScreen();
}

/* TEST: API_LCD_CursorPosition */

void test_API_LCD_CursorPosition_row0(void) {
    uint8_t expected = POSICION_FILA1 | 5;

    // HIGH nibble
    API_LCD_PORT_WriteByte_ExpectAnyArgs();
    API_LCD_PORT_Delay_Expect(DELAY1ms);
    API_LCD_PORT_WriteByte_ExpectAnyArgs();
    API_LCD_PORT_Delay_Expect(DELAY1ms);

    // LOW nibble
    API_LCD_PORT_WriteByte_ExpectAnyArgs();
    API_LCD_PORT_Delay_Expect(DELAY1ms);
    API_LCD_PORT_WriteByte_ExpectAnyArgs();
    API_LCD_PORT_Delay_Expect(DELAY1ms);

    API_LCD_CursorPosition(0, 5);
}

void test_API_LCD_CursorPosition_row1(void) {
    uint8_t expected = POSICION_FILA2 | 3;

    // Espera misma secuencia de nibble alto y bajo
    API_LCD_PORT_WriteByte_ExpectAnyArgs();
    API_LCD_PORT_Delay_Expect(DELAY1ms);
    API_LCD_PORT_WriteByte_ExpectAnyArgs();
    API_LCD_PORT_Delay_Expect(DELAY1ms);

    API_LCD_PORT_WriteByte_ExpectAnyArgs();
    API_LCD_PORT_Delay_Expect(DELAY1ms);
    API_LCD_PORT_WriteByte_ExpectAnyArgs();
    API_LCD_PORT_Delay_Expect(DELAY1ms);

    API_LCD_CursorPosition(1, 3);
}

/* TEST: API_lcd_WriteText */

void test_API_LCD_WriteText_should_send_characters(void) {
    char text[] = "AB";

    // 'A'
    API_LCD_PORT_WriteByte_ExpectAnyArgs();
    API_LCD_PORT_Delay_Expect(DELAY1ms);
    API_LCD_PORT_WriteByte_ExpectAnyArgs();
    API_LCD_PORT_Delay_Expect(DELAY1ms);
    API_LCD_PORT_WriteByte_ExpectAnyArgs();
    API_LCD_PORT_Delay_Expect(DELAY1ms);
    API_LCD_PORT_WriteByte_ExpectAnyArgs();
    API_LCD_PORT_Delay_Expect(DELAY1ms);

    // 'B'
    API_LCD_PORT_WriteByte_ExpectAnyArgs();
    API_LCD_PORT_Delay_Expect(DELAY1ms);
    API_LCD_PORT_WriteByte_ExpectAnyArgs();
    API_LCD_PORT_Delay_Expect(DELAY1ms);
    API_LCD_PORT_WriteByte_ExpectAnyArgs();
    API_LCD_PORT_Delay_Expect(DELAY1ms);
    API_LCD_PORT_WriteByte_ExpectAnyArgs();
    API_LCD_PORT_Delay_Expect(DELAY1ms);

    API_LCD_WriteText(text);
}

/* TEST: API_LCD_WriteNumber */

void test_API_LCD_WriteNumber_should_convert_and_send(void) {
    // Para el número 123 se enviará: "123"
    // 3 caracteres → repetir la secuencia de WriteByte 3 veces

    for (int i = 0; i < 3; i++) {
        // Cada byte genera 4 llamadas WriteByte + 4 Delay
        API_LCD_PORT_WriteByte_ExpectAnyArgs();
        API_LCD_PORT_Delay_Expect(DELAY1ms);
        API_LCD_PORT_WriteByte_ExpectAnyArgs();
        API_LCD_PORT_Delay_Expect(DELAY1ms);
        API_LCD_PORT_WriteByte_ExpectAnyArgs();
        API_LCD_PORT_Delay_Expect(DELAY1ms);
        API_LCD_PORT_WriteByte_ExpectAnyArgs();
        API_LCD_PORT_Delay_Expect(DELAY1ms);
    }

    API_LCD_WriteNumber(123);
}
