
#include "crc.h"

uint16_t Compute_CRC16(uint8_t byteVal, uint16_t crc, int bits){
    crc ^= (byteVal << (16 - bits)); // 8 bit -> 8 bit shift left, 4 bit -> 12 bit shift left
    int i;

    for (i = 0; i < bits; i++) {
        if ((crc & 0x8000) != 0) { // most significant bit set, shift crc register and perform XOR operation, taking not-saved 9th set bit into account
            crc = (uint16_t)((crc << 1) ^ CRC16_POLY);
        } else { // most significant bit not set, go to next bit
            crc <<= 1;
        }
    }

    return crc;
}
