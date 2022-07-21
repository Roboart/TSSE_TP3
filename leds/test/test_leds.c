/*

Revisar limites de los parametros.

*/

#include "unity.h"
#include "leds.h"
#include "mock_errores.h"

uint16_t ledsVirtuales;

void setUp(void){
    LedsInit(&ledsVirtuales);
}

// Después de la incialización todos los led deben quedar apagados.
void test_LedsOffAfterCreate(void){
    uint16_t ledsVirtuales = 0xFFFF;
    LedsInit(&ledsVirtuales);
    TEST_ASSERT_EQUAL_HEX16(0X0000,ledsVirtuales);
}

// Se puede prender un LED individual.
void test_TurnOnOneLed(void){
    LedTurnOn(5);
    TEST_ASSERT_EQUAL_HEX16(1 << 4,ledsVirtuales);
}

// Se puede apagar un LED individual.
void test_TurnOffOneLed(void){
    LedTurnOn(5);
    LedTurnOff(5);
    TEST_ASSERT_EQUAL_HEX16(0 << 4,ledsVirtuales);
}

// Se pueden prender y apagar múltiples LED’s.
void test_TurnOnAndOffManyLeds(void){
    LedTurnOn(5);
    LedTurnOn(11);
    LedTurnOff(3);
    LedTurnOff(11);    
    TEST_ASSERT_EQUAL_HEX16(1 << 4,ledsVirtuales);
}

//Se pueden prender todos los LEDs de una vez.
void test_TurnOnAllLeds(void){
    LedTurnOnAll(&ledsVirtuales);
    TEST_ASSERT_EQUAL_HEX16(0xFFFF,ledsVirtuales);
}

//Se pueden apagar todos los LEDs de una vez.
void test_TurnOffAllLeds(void){
    LedTurnOffAll(&ledsVirtuales);
    TEST_ASSERT_EQUAL_HEX16(0x0000,ledsVirtuales);
}

//Se puede consultar el estado de un LED apagado.
void test_getStateWhenLedIsOff(void){
    bool ledState = true;
    ledState = LedGetState(2);
    TEST_ASSERT_FALSE(ledState);
}

//Se puede consultar el estado de un LED prendido.
void test_getStateWhenLedIsOn(void){
    bool ledState = true;
    LedTurnOn(2);
    
    ledState = LedGetState(2);
    TEST_ASSERT_TRUE(ledState);
}

//Revisar parámetros fuera de los limites.
void test_InvalidUpperLimitTurnOnLed(void){
    RegistrarMensaje_Expect(ALERTA, "LedTurnOn",0,"Numero de led debe ser entre 1 y 16");
    RegistrarMensaje_IgnoreArg_linea();
    LedTurnOn(-17);
}