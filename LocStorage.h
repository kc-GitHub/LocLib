/**
 **********************************************************************************************************************
 * @file  LocStorage.h
 * @brief Rotuines to acces EEPROM on various platforms.
 ***********************************************************************************************************************
 */

#ifndef LOC_STORAGE_H
#define LOC_STORAGE_H

#include "LoclibData.h"
#include <Arduino.h>

class LocStorage
{
public:
    void Init();
    bool VersionCheck();
    bool AcOptionGet();
#if APP_CFG_UC == APP_CFG_UC_STM32
    uint8_t XpNetAddressGet(void);
    void XpNetAddressSet(uint8_t XpNetAddress);
#endif
    void AcOptionSet(uint8_t acOption);
    uint8_t NumberOfLocsGet();
    void NumberOfLocsSet(uint8_t numberOfLocs);
    bool LocDataGet(LocLibData* DataPtr, uint8_t Index);
    bool LocDataSet(LocLibData* DataPtr, uint8_t Index);

private:
#if APP_CFG_UC == APP_CFG_UC_STM32
    uint8_t I2CAddressAT24C256;
#endif
};

#endif