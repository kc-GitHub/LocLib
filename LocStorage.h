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
    void EmergencyOptionSet(uint8_t emergency);
    bool EmergencyOptionGet(void);
    uint8_t NumberOfLocsGet();
    void NumberOfLocsSet(uint8_t numberOfLocs);
    bool LocDataGet(LocLibData* DataPtr, uint8_t Index);
    bool LocDataSet(LocLibData* DataPtr, uint8_t Index);
    void SelectedLocIndexStore(uint8_t Index);
    uint8_t SelectedLocIndexGet();
    void EraseEeprom(void);
#if APP_CFG_UC == APP_CFG_UC_ESP8266
    void InvalidateAdc();
#endif

private:
#if APP_CFG_UC == APP_CFG_UC_STM32
    uint8_t I2CAddressAT24C256;
#endif
};

#endif
