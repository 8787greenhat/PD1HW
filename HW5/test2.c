#include<stdio.h>
#define Bool int
#define TRUE 1
#define FALSE 0
int main(){
    int a =0,b =0,c;
    scanf("%d%d%d",&a,&b,&c);
    printf("%d %d %d\n",a,b,c);
    char s;
    while ( (s = getchar()) != '\n' && s != EOF);
}