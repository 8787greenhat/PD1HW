#include<stdio.h>
#include<stdlib.h>
int values[] = {10,88,56,100,2,25};
int cmpfunc(const void *a,const void *b)
{
    return (*(int*)a - *(int*)b);
}

int main()
{
    qsort(values,6,sizeof(int),cmpfunc);

    for(int n=0;n<6;n++)
    {
        printf("%d ",values[n]);
    }
}