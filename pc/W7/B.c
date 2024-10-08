#include <stdio.h>

int main()
{
    printf("Please input two integer and get their GCD(greastest common divisor).\n");
    int a, b, gcd;
    scanf("%d%d", &a, &b);
     while(b != 0){
        gcd = b;
        b = a % b;
        a = gcd;
    }
    
    
    printf("The GCD of the two numbers is %d.\n", gcd);
    return 0;
}