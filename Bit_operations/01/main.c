#include <stdio.h>

int main(void) {

    int a = 0xDDCCAABB;
    unsigned char c;
    c = (a & 0xFF);
    printf("first byte = %x\n" , c);
    c = ((a >> 8 ) & 0xFF);
    printf("second byte = %x\n", c);
    c = ((a >> 16 ) & 0xFF);
    printf("third byte = %x\n", c);
    c = ((a >> 24 ) & 0xFF);
    printf("fourth byte = %x\n", c);
    a = (a & 0xFF88FFFF);
    printf("number with 3 bytes changed = %x\n", a);
    return 0;
} 