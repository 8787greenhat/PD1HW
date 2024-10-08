#include<stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
    srand((unsigned)time(NULL));
    int b = rand()%(200000-5000+1)+5000;
    printf("%d",b);
}