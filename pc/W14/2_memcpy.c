#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int s1[] = {1,2,3,4,5};
int s2[] = {6,7,8,9,10};

void swap1( void* a, void* b, size_t size)
{
    void *tmp = malloc(size);

    memcpy(tmp,s1,size);
    memcpy(s1,s2,size);
    memcpy(s2,tmp,size);
    free(tmp);
}

void swap2( void* a, void* b, size_t size)
{
    char *tmp = malloc(size);

    strcpy(tmp,a);
    strcpy(a,b);
    strcpy(b,tmp);

    free(tmp);
}

void swap3( void* a,void* b, size_t size)
{
    char *tmp = malloc(size);

    for(int i = 0;i<size;i++)
    {
        *((char*)tmp + i) = *((char*)a + i);
        *((char*)a + i) = *((char*)b + i);
        *((char*)b + i) = *((char*)tmp + i);
    }
}
int main()
{
    int n = sizeof(s1)/sizeof(int);
    swap3(s1,s2,sizeof(s1));

    for(int i= 0;i<n;i++)
    {
        if(i==0){ printf("s1: ");}
        printf("%d ",s1[i]);
    }

    printf("\n");

    for(int i= 0;i<n;i++)
    {
        if(i==0){ printf("s2: ");}
        printf("%d ",s2[i]);
    }
}