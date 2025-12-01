#include "unity.h"
#include "API_delay.h"

// Mocks
#include "mock_API_delay_port.h"
#include "mock_API_error.h"

delay_t delay;

void setUp(void) {
    // Reiniciamos estructura
    delay.startTime = 0;
    delay.duration = 0;
    delay.running = false;
}

void tearDown(void) {
}

// Nota sobre porque no se agregan pruebas con punteros == NULL:
// No se prueban los casos donde 'delay == NULL' porque las funciones del módulo invocan
// API_ERROR_LogError() ante errores fatales. Esta función detiene la ejecución entrando en un bucle
// infinito, comportamiento adecuado para sistemas embebidos pero incompatible con pruebas
// unitarias, ya que Ceedling no puede continuar la ejecución después del bucle.

/* TEST: API_DELAY_Init */

void test_API_DELAY_Init_debe_configurar_duracion_y_poner_running_en_false(void) {

    API_ERROR_LogError_Ignore(); // No esperamos errores aquí

    API_DELAY_Init(&delay, 100);

    TEST_ASSERT_EQUAL(100, delay.duration);
    TEST_ASSERT_FALSE(delay.running);
}

void test_API_DELAY_Init_debe_llamar_error_si_duration_es_cero(void) {

    API_ERROR_LogError_Expect();

    API_DELAY_Init(&delay, 0);
}

/* TEST: API_DELAY_Read */

void test_API_DELAY_Read_debe_iniciar_delay_la_primera_vez(void) {

    API_ERROR_LogError_Ignore();

    // Primera llamada → debe obtener una marca de tiempo y activar running
    API_DELAY_PORT_GetTime_ExpectAndReturn(50);

    bool_t result = API_DELAY_Read(&delay);

    TEST_ASSERT_TRUE(delay.running);
    TEST_ASSERT_EQUAL(50, delay.startTime);
    TEST_ASSERT_FALSE(result);
}

void test_API_DELAY_Read_debe_retornar_true_si_el_tiempo_expira(void) {

    delay.duration = 100;
    delay.running = true;
    delay.startTime = 1000;

    API_ERROR_LogError_Ignore();

    // Tiempo actual = 1100 - 1000 → delay cumplido
    API_DELAY_PORT_GetTime_ExpectAndReturn(1100);

    bool_t result = API_DELAY_Read(&delay);

    TEST_ASSERT_TRUE(result);
    TEST_ASSERT_FALSE(delay.running);
}

void test_API_DELAY_Read_debe_retornar_false_si_el_tiempo_aun_no_expira(void) {

    delay.duration = 100;
    delay.running = true;
    delay.startTime = 1000;

    API_ERROR_LogError_Ignore();

    API_DELAY_PORT_GetTime_ExpectAndReturn(1050); // No ha pasado suficiente tiempo

    bool_t result = API_DELAY_Read(&delay);

    TEST_ASSERT_FALSE(result);
    TEST_ASSERT_TRUE(delay.running);
}

/* TEST: API_DELAY_Write */

void test_API_DELAY_Write_debe_actualizar_duracion_correctamente(void) {

    API_ERROR_LogError_Ignore();

    API_DELAY_Write(&delay, 300);

    TEST_ASSERT_EQUAL(300, delay.duration);
}

void test_API_DELAY_Write_debe_llamar_error_si_duration_es_cero(void) {

    API_ERROR_LogError_Expect();

    API_DELAY_Write(&delay, 0);
}
