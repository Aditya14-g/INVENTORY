#include <stdio.h>

int isLittleEndian() {
    unsigned int num = 1;
    return *((unsigned char*)&num);
}
unsigned int convertEndianness(unsigned int num) {
    return ((num >> 24) & 0xFF) | ((num >> 8) & 0xFF00) | ((num << 8) & 0xFF0000) | ((num << 24) & 0xFF000000);
}

int main() {
    unsigned int number;
    printf("Enter a number (unsigned integer): ");
    scanf("%u", &number);

    printf("Memory Address  ->    value");
    printf("\n----------------------------");
    
    unsigned char *ptr = (unsigned char *)&number;
    for (int i = 0; i < sizeof(number); i++) {
        printf("\n%d: \t\t%02X", &ptr[i], ptr[i]);
    }
    if (isLittleEndian()) {
        printf("\n\nThe host machine is in Little Endian.\n");
        number = convertEndianness(number);
    } else {
        printf("\n\nThe host machine is in Big Endian.\n");
        number = convertEndianness(number);
    }
    printf("\nConverted Number: %u\n", number);

    return 0;
}