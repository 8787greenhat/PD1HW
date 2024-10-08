#include<stdio.h>
#include<stdlib.h>

//pointer
void f_to_bit_a(float f)
{
    printf("pointer:");
    int *n = (int*)&f;
    for(int i = 31;i>=0;i--)
    {
        printf("%d",(*n>>i)&1);
    }
    printf("\n");
}

void bit_to_f_a(int bit)
{
    printf("pointer: %f\n", *((float*)&bit));
}

//union
typedef union
{
    float f;
    unsigned int n;
}f_union;


void f_to_bit_b(float f)
{
    f_union u;
    u.f = f;
    printf("union  :");
    for(int i = 31;i>=0;i--)
    {
        printf("%d",(u.n>>i)&1);
    }
    printf("\n");
}

void bit_to_f_b(int bit)
{
    printf("union  :");
    f_union u;
    u.n = bit;
    printf("%f\n",u.f);
}

//bit pattern

typedef struct  {
    unsigned int mantissa : 23;
    unsigned int exponent : 8;
    unsigned int sign : 1;
}FloatBitField;

void f_to_bit_c(float f)
{
    union{
        float f;
        FloatBitField bits;
    }u;

    u.f = f;

    printf("pattern:");

    printf("%d",u.bits.sign);

    for (int i = 8 - 1; i >= 0; i--) {
        printf("%d", (u.bits.exponent >> i) & 1);
    }

    for (int i = 23 - 1; i >= 0; i--) {
        printf("%d", (u.bits.mantissa >> i) & 1);
    }
    printf("\n");
}

void printBinary(unsigned int num, int bits) {
    for (int i = bits - 1; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
    }
}

void bit_to_f_c(int sign, int exponent, int mantissa) {
    union {
        float floatValue;
        FloatBitField bit;
    } u;

    u.bit.sign = sign;
    u.bit.exponent = exponent;
    u.bit.mantissa = mantissa;

    printf("pattern:%f", u.floatValue);
}


//function

void f_to_bit(float f)
{
   f_to_bit_a(f);
   f_to_bit_b(f);
   f_to_bit_c(f);
}

int main()
{   
    float f;

    printf("input float:");
    scanf("%f",&f);
    f_to_bit(f);



    char binaryString[32];  
    printf("Input binary string: ");
    scanf("%s", binaryString);

    int i = atof(binaryString);
    printf("i=%d\n",i);

    // 避免遺失第一個零
    int binaryValue = strtol(binaryString, NULL, 2);
    int sign = (binaryValue >> 31) & 1;
    int exponent = (binaryValue >> 23) & 0xFF;
    int mantissa = binaryValue & 0x7FFFFF;

    bit_to_f_a(binaryValue);
    bit_to_f_b(binaryValue);
    bit_to_f_c(sign, exponent, mantissa);

    return 0;
   
}