#ifndef CONVERSION_H_INCLUDED
#define CONVERSION_H_INCLUDED

#include <stdio.h>

void get_byte_order();

typedef union _conversion {
    float fNum;
    unsigned int uiNum;
} Conversion;

int isPositive(float number);

#endif // CONVERSION_H_INCLUDED
