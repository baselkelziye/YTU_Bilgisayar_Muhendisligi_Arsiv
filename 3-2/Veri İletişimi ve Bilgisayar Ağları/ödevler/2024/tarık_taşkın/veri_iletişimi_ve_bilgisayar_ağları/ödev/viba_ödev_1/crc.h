
#ifndef CRC_H
#define CRC_H

#include <stdint.h>

#define CRC16_POLY 0x1021

uint16_t Compute_CRC16(uint8_t byteVal, uint16_t crc, int bits);

#endif // CRC_H
