#include<stdio.h>
#include<stdlib.h>

int main()
{
    int ***p1;
    int ****p2 = &p1;
    int ***p3 = *p2;

    printf("%p\n",p1);
    printf("%p",p3); 
    free(p1);
    free(p2);
    free(p3);
}