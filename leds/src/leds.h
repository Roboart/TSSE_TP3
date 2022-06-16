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
 * @brief Enciende led solicitado
 * 
 * @param led Numero de led que se requiere encender
 */
void LedTurnOn(uint8_t led);

/**
 * @brief apaga led solicitado
 * 
 * @param led Numero de led que se requiere apagar
 */
void LedTurnOff(uint8_t led);

/**
 * @brief Enciende todos los leds
 * 
 * @param direccion Direccion del puerto GPIO que controla todos los leds.
 */
void LedTurnOnAll(uint16_t *direccion);

/**
 * @brief Enciende led solicitado
 * 
 * @param led Numero de led que se requiere encender
 */
void LedTurnOffAll(uint16_t *direccion);

/**
 * @brief Apaga todos los leds
 * 
 * @param direccion Direccion del puerto GPIO que controla todos los leds.
 */
bool LedGetState(uint8_t led);

#endif