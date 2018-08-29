/**
 **********************************************************************************************************************
 * @file  Loclib.h
 * @brief Supporting routines for WifiManualControl to handle locomotive data.
 ***********************************************************************************************************************
 */

#ifndef LOC_LIB_H
#define LOC_LIB_H

#include "LocStorage.h"
#include "LoclibData.h"
#include <Arduino.h>

class LocLib
{
public:
    /**
     * Function options.
     */
    enum function
    {
        functionOff = 0,
        functionOn,
        functionNone
    };

    /**
     * Enum for storage options in EEPROM.
     */
    enum store
    {
        storeAdd = 0,
        storeAddNoAutoSelect,
        storeChange,
    };

    /* Constructor. */
    LocLib();

    /**
     * Init of loc module.
     */
    void Init(LocStorage Storage);

    /**
     * Get pointer to data of selected loc.
     */
    LocLibData* DataGet();

    /**
     * Increase, decrease, stop or reverse direction of selected loc.
     */
    bool SpeedSet(int8_t Delta);

    /**
     * Get actual speed of selected loc.
     */
    uint8_t SpeedGet(void);

    /**
     * Write direct actual speed of selected loc.
     */
    void SpeedUpdate(uint8_t Speed);

    /**
     * Update decoder type of selected loc.
     */
    void DecoderStepsUpdate(decoderSteps Steps);

    /**
     * Get actual decoder steps of selected loc,
     */
    decoderSteps DecoderStepsGet(void);

    /**
     * Toggle direction of selected loc.
     */
    void DirectionToggle(void);

    /**
     * Get actual direction of selected loc,
     */
    direction DirectionGet(void);

    /**
     * Set direction of actual selected loc.
     */
    void DirectionSet(direction dir);

    /**
     * Write direct function data for selected loc.
     */
    void FunctionUpdate(uint32_t FunctionData);

    /**
     * Toggle selected function of selected loc.
     */
    void FunctionToggle(uint8_t number);

    /**
     * Get the assigned function to a button.
     */
    uint8_t FunctionAssignedGet(uint8_t number);

    /**
     * Get the assigned functions of a loc in EEPROM.
     */
    bool FunctionAssignedGetStored(uint16_t address, uint8_t* functions);

    /**
     * Get the status of a function.
     */
    function FunctionStatusGet(uint32_t number);

    /**
     * Get the next or previous loc from stored in EEPROM.
     */
    uint16_t GetNextLoc(int8_t Delta);

    /**
     * Get address of actual selected loc.
     */
    uint16_t GetActualLocAddress(void);

    /**
     * Check if loc is present in EEPROM.
     */
    uint8_t CheckLoc(uint16_t address);

    /**
     * Store locomotive in EEPROM.
     */
    bool StoreLoc(uint16_t address, uint8_t* FunctionAssigment, store storeAction);

    /**
     * Remove loc with given address from EEPROM.
     */
    bool RemoveLoc(uint16_t address);

    /**
     * Remove all locs from EEPROM.
     */
    void RemoveAllLocs(void);

    /**
     * Get actual number of locs in EEPROM.
     */
    uint16_t GetNumberOfLocs(void);

    /**
     * Get the index of the selected loc.
     */
    uint8_t GetActualSelectedLocIndex(void);

    /**
     * Sort loc data in EEPROM.
     */
    void LocBubbleSort(void);

    /**
     * Read locdata direct based on index.
     */
    LocLibData* LocGetAllDataByIndex(uint8_t Index);

    /**
     * Set default loc data (1 loc with address 3) in EEPROM.
     */
    void InitialLocStore(void);

    /**
     * Check for min/max loc address.
     */
    uint16_t limitLocAddress(uint16_t locAddress);

private:
    /**
     * Increase the speed.
     */
    void SpeedIncrease(void);

    /**
     * Decrease the speed.
     */
    void SpeedDecrease(void);

    /**
     * Set speed to zero or change direction when speed already 0.
     */
    void SpeedStopOrChangeDirection(void);

    LocLibData m_LocLibData; /* Data of actual selected loc. */
    LocStorage m_LocStorage;
    uint8_t m_NumberOfLocs;      /* Number of locs. */
    bool m_AcOption;             /* Direction change only with direction button. */
    uint8_t m_ActualSelectedLoc; /* Actual selected loc. */

    static const uint8_t MaxNumberOfLocs  = 64; /* Max number of locs. */
    static const uint16_t ADDRESS_LOC_MIN = 1;
    static const uint16_t ADDRESS_LOC_MAX = 9999;
};

#endif
