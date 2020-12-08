/**
 **********************************************************************************************************************
 * @file  LoclibData.h
 * @brief Data of loc.
 ***********************************************************************************************************************
 */

#ifndef LOC_LIB_DATA_H
#define LOC_LIB_DATA_H

#include "LoclibData.h"
#include <Arduino.h>
#include <app_cfg.h>

/**
 * Decoder steps of a loc.
 */
enum decoderSteps
{
    decoderStep14 = 0,
    decoderStep28,
    decoderStep128
};

/**
 * Direction of a loc.
 */
enum direction
{
    directionForward = 0,
    directionBackWard
};
/**
 * Actual loc data of selected loc.
 */
struct LocLibData
{
    uint16_t Addres;                                    //  2 bytes, Address of loc
    uint16_t Speed;                                     //  2 bytes, Actual speed of loc
    direction Dir;                                      //  1 byte,  Direction of loc
    decoderSteps Steps;                                 //  1 byte,  Decoder steps of loc
    uint32_t Function;                                  //  4 bytes, Actual functions of loc.
    uint8_t FunctionAssignment[MAX_FUNCTION_BUTTONS];   // 10 bytes, Assigned functions to buttons of loc.
    char Name[11];                                      // 11 bytes, Name of loc.
};

#endif
