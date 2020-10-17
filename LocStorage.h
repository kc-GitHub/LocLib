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
    /*
     * Init module.
     */
    void Init();

    /**
     * Check EEPROM version.
     */
    bool VersionCheck();

#if APP_CFG_UC == APP_CFG_UC_STM32
    /**
     * Get XPressNet address of device.
     */
    uint8_t XpNetAddressGet(void);

    /**
     * Set XPressNet device address.
     */
    void XpNetAddressSet(uint8_t XpNetAddress);
#endif

    /**
     * Check if so called AC option is active. AC option does not allow speed and direction change with
     * rotary encoder.
     */
    bool AcOptionGet();

    /**
     * Set(1) or reset(0) AC option.
     */
    void AcOptionSet(uint8_t acOption);

    /**
     * Set (1) or reset (0) the emergency stop option.
     */
    void EmergencyOptionSet(uint8_t emergency);

    /**
     * Get emergency option.
     */
    bool EmergencyOptionGet(void);

    /**
     * Get number of stored locomotives.
     */
    uint8_t NumberOfLocsGet();

    /**
     * Set number of stores locomotives.
     */
    void NumberOfLocsSet(uint8_t numberOfLocs);

    bool LocDataGet(LocLibData* DataPtr, uint8_t Index);
    bool LocDataSet(LocLibData* DataPtr, uint8_t Index);
    void SelectedLocIndexStore(uint8_t Index);
    uint8_t SelectedLocIndexGet();
    void EraseEeprom(void);

private:
#if APP_CFG_UC == APP_CFG_UC_STM32
    uint8_t I2CAddressAT24C256;
#endif
};

#endif
