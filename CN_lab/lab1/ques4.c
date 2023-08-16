#include <stdio.h>

struct pkt {
    char ch1;
    char ch2[2];
    char ch3;
};

int main() {
    unsigned int number;
    printf("Enter a number (unsigned integer): ");
    scanf("%u", &number);

    struct pkt packet;
    packet.ch1 = (number >> 24) & 0xFF;
    packet.ch2[0] = (number >> 16) & 0xFF;
    packet.ch2[1] = (number >> 8) & 0xFF;
    packet.ch3 = number & 0xFF;

    printf("Content of each member of the structure:\n");
    printf("ch1: %d\n", packet.ch1);
    printf("ch2: %d %d\n", packet.ch2[0], packet.ch2[1]);
    printf("ch3: %d\n", packet.ch3);

    unsigned int originalNumber = 0;
    originalNumber |= ((unsigned int)packet.ch1) << 24;
    originalNumber |= ((unsigned int)packet.ch2[0]) << 16;
    originalNumber |= ((unsigned int)packet.ch2[1]) << 8;
    originalNumber |= packet.ch3;

    printf("\nOriginal Number: %u\n", originalNumber);

    return 0;
}

