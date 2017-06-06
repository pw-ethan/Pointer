#include "conversion.h"

void get_byte_order() {
    int num = 0x12345678;
    char *pc = (char *) &num;
    if (*pc == 0x12) {
        printf("big endian\n");
    } else {
        printf("little endian\n");
    }
}

int isPositive(float number) {
    Conversion conversion = { .fNum = number };
    return (conversion.uiNum & 0x80000000) == 0;
}
