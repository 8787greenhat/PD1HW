#include <stdio.h>
#include <stdlib.h>

static int tets[50][50][50] = {0};

int main()
{
    int *p = &tets[0][5][0];

    printf("%d\n",p);
    printf("%d\n",*(p-4));//why it not is null
    printf("%d\n",n);

}