/*
 * settings.h
 *
 *  Created on: 23.08.2017
 *      Author: PR6
 */

#ifndef SETTINGS_H_
#define SETTINGS_H_
#include "stm32f7xx_hal.h"
#include "stm32f7xx_hal_flash.h"
#include "stm32f7xx_hal_flash_ex.h"
#include "eeprom.h"
#define EEPROM_START_ADDR 0x08020000
#define MODE_OFFSET 0
#define IP_OFFSET 0x4
#define MASK_OFFSET 0x8
#define GATE_OFFSET 0xC
#define PORT_OFFSET 0x10
HAL_StatusTypeDef writeEEPROMSettings(uint8_t mode, uint32_t ip,uint16_t port,uint32_t mask,uint32_t gate);
HAL_StatusTypeDef writeEEPROMByte(uint32_t address, uint8_t data);
HAL_StatusTypeDef writeEEPROMDoubleWord(uint32_t address, uint32_t data);
uint8_t readEEPROMByte(uint32_t address);
uint32_t readEEPROMDoubleWord(uint32_t address) ;
uint8_t readNrOfPowerOn();
HAL_StatusTypeDef writeNrOfPowerOn(uint8_t data);
uint8_t readModeSettings();
HAL_StatusTypeDef writeModeSettings(uint8_t mode);
uint32_t readIPSettings();
HAL_StatusTypeDef writeIPSettings(uint32_t ip);
uint32_t readNetMaskSettings();
HAL_StatusTypeDef writeNetMaskSettings(uint32_t netmask);
uint32_t readGateWaySettings();
HAL_StatusTypeDef writeGateWaySettings(uint32_t gateway);
uint32_t readEEPROMWord(uint32_t address);
uint16_t readPortSettings();
HAL_StatusTypeDef writePortSettings(uint16_t port);
HAL_StatusTypeDef writeEEPROMWord(uint32_t address, uint16_t data);
#endif /* SETTINGS_H_ */
