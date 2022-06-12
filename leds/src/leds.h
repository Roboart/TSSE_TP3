#ifndef _LEDS_H
#define _LEDS_H

#include <stdint.h>
#include <stdbool.h>
/**
 * @brief Configura la biblioteca y apaga todos los leds
 * 
 * @param direccion Direccion del puerto GPIO que controla todos los leds. 
 */
void LedsInit(uint16_t *direccion);

/**
 * @brief 
 * 
 * @param led 
 */
void LedTurnOn(uint8_t led);
void LedTurnOff(uint8_t led);
void LedTurnOnAll(uint16_t *direccion);
void LedTurnOffAll(uint16_t *direccion);
bool LedGetState(uint8_t led);
#endif
