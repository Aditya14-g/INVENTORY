#include <stdio.h>

int main() {
    unsigned int number;
    printf("Enter a number (unsigned integer): ");
    scanf("%u", &number);
    unsigned char byte1 = (number >> 24) & 0xFF;
    unsigned char byte2 = (number >> 16) & 0xFF;
    unsigned char byte3 = (number >> 8) & 0xFF;
    unsigned char byte4 = number & 0xFF;

    printf("Byte 1: %u\n", byte4);
    printf("Byte 2: %u\n", byte3);
    printf("Byte 3: %u\n", byte2);
    printf("Byte 4: %u\n", byte1);

    return 0;
}
