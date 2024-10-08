#include <stdio.h>
int main( ) {
    int in,a;
    scanf("%d",&in);
    a = in%10 * 10;
    a = a + (in/10)%10;
    a = a + (in/100)*100;
    printf("%d",a*2023);
}