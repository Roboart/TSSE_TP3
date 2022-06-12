#include "leds.h"
#include "errores.h"

#define LED_TO_BIT_OFFSET 1
#define BIT_MASK 1
#define LEDS_ALL_OFF 0
#define LEDS_ALL_ON 0xFFFF
#define UPPER_LIMIT 16
#define LOWER_LIMIT 1

static uint16_t *puerto;

static uint16_t ledToMask(uint8_t led){
    return BIT_MASK <<(led - LED_TO_BIT_OFFSET);
}

void LedsInit(uint16_t *direccion){
    puerto = direccion;
    *puerto = LEDS_ALL_OFF;
}

void LedTurnOn(uint8_t led){
    if(led > UPPER_LIMIT || led < LOWER_LIMIT){
        Registrar(ALERTA,"Numero de led debe ser entre 1 y 16");
    }
    else{
        *puerto |= ledToMask(led);
    }
}

void LedTurnOff(uint8_t led){
    *puerto &= ~ledToMask(led);
}

void LedTurnOnAll(uint16_t *direccion){
    puerto = direccion;
    *puerto = LEDS_ALL_ON;
}

void LedTurnOffAll(uint16_t *direccion){
    puerto = direccion;
    *puerto = LEDS_ALL_OFF;
}

bool LedGetState(uint8_t led){
    return *puerto & ledToMask(led);
}



