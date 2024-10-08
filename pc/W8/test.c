#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main() {
    double  i= 0;
    srand((unsigned)time(NULL));
    for(int i = 0;i<=10;i++){
        int r = rand()%6 + 1;
        printf("%d",r);
        i = i+(double)r;
    }
    printf("\n%lf",i);
}