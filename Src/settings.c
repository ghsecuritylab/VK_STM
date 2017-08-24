/*
 * settings.c
 *
 *  Created on: 24.08.2017
 *      Author: PR6
 */
#include "settings.h"

HAL_StatusTypeDef writeEEPROMSettings(uint8_t mode, uint32_t ip,uint32_t mask,uint32_t gate){
	HAL_FLASH_Unlock();
	FLASH_Erase_Sector(FLASH_SECTOR_4,VOLTAGE_RANGE);
	HAL_FLASH_Lock();
	writeModeSettings(mode);
	writeIPSettings(ip);
	writeNetMaskSettings(mask);
	return writeGateWaySettings(gate);

}
HAL_StatusTypeDef writeEEPROMByte(uint32_t address, uint8_t data)
 {
    HAL_StatusTypeDef  status;
    address = address + EEPROM_START_ADDR;
    HAL_FLASH_Unlock();  //Unprotect the EEPROM to allow writing
    status =  HAL_FLASH_Program(FLASH_TYPEPROGRAM_BYTE, address, data);
    HAL_FLASH_Lock();  // Reprotect the EEPROM
    return status;
}
HAL_StatusTypeDef writeEEPROMDoubleWord(uint32_t address, uint32_t data)
 {
    HAL_StatusTypeDef  status;
    address = address + EEPROM_START_ADDR;
    HAL_FLASH_Unlock();  //Unprotect the EEPROM to allow writing
    status = HAL_FLASH_Program (FLASH_TYPEPROGRAM_WORD, address, data);
    HAL_FLASH_Lock();   // Reprotect the EEPROM

    return status;
}
uint8_t readEEPROMByte(uint32_t address) {
    uint32_t tmp = 0;
    address = address + EEPROM_START_ADDR;
    tmp = *(__IO uint8_t*)address;
    return tmp;
}
uint32_t readEEPROMDoubleWord(uint32_t address) {
    uint32_t tmp = 0;
    address = address + EEPROM_START_ADDR;
    tmp = *(__IO uint32_t*)address;
    return tmp;
}
uint8_t readNrOfPowerOn()
{
	return readEEPROMByte(10);
}
HAL_StatusTypeDef writeNrOfPowerOn(uint8_t data)
{
	return writeEEPROMByte(10,data);
}

uint8_t readModeSettings()
{
	return readEEPROMByte(MODE_OFFSET);
}
HAL_StatusTypeDef writeModeSettings(uint8_t mode)
{
	return writeEEPROMByte(MODE_OFFSET,mode);
}
uint32_t readIPSettings()
{
	return readEEPROMDoubleWord(IP_OFFSET);
}
HAL_StatusTypeDef writeIPSettings(uint32_t ip)
{
	return writeEEPROMDoubleWord(IP_OFFSET,ip);
}
uint32_t readNetMaskSettings()
{
	return readEEPROMDoubleWord(MASK_OFFSET);
}
HAL_StatusTypeDef writeNetMaskSettings(uint32_t netmask)
{
	return writeEEPROMDoubleWord(MASK_OFFSET,netmask);
}
uint32_t readGateWaySettings()
{
	return readEEPROMDoubleWord(GATE_OFFSET);
}
HAL_StatusTypeDef writeGateWaySettings(uint32_t gateway)
{
	return writeEEPROMDoubleWord(GATE_OFFSET,gateway);
}
