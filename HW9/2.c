#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned int mantissa : 23;
    unsigned int exponent : 8;
    unsigned int sign : 1;
} FloatBitField;

// Function to print binary representation of an integer
void printBinary(unsigned int num, int bits) {
    for (int i = bits - 1; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
    }
}

void bits_to_f_c(int sign, int exponent, int mantissa) {
    union {
        float floatValue;
        FloatBitField bit;
    } u;

    u.bit.sign = sign;
    u.bit.exponent = exponent;
    u.bit.mantissa = mantissa;

    printf("Float value using Bit Field: %f\n", u.floatValue);
}

int main() {
    char binaryString[32];  // Assuming 32-bit float representation

    printf("Input binary string: ");
    scanf("%s", binaryString);

    // Convert binary string to integer
    int binaryValue = strtol(binaryString, NULL, 2);

    // Separate bit pattern into sign, exponent, and mantissa
    int sign = (binaryValue >> 31) & 1;
    int exponent = (binaryValue >> 23) & 0xFF;
    int mantissa = binaryValue & 0x7FFFFF;

    // Call bits_to_f_c with separated values
    bits_to_f_c(sign, exponent, mantissa);

    return 0;
}
