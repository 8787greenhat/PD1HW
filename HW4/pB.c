#include<stdio.h>

int main()
{
    int input;
    double e = 1.0f;

    scanf("%d",&input);

    for(int i = 1;i<=input;i++){
        double r = 1.0f;
        for(int j =1;j<=i;j++){
            r = r*j;
        }
        e = e + 1.0f/r;
    }
    printf("%.15lf",e);
}