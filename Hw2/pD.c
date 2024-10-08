#include<stdio.h>
int main(){
    int a,b,N,sum;
    scanf("%d%d%d",&a,&b,&N);
    sum =  b * (1<<a)  - N/(1<<b) * (a ^ b) - (a&b)+ (a|b);
    printf("%d",sum);
}