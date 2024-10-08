#include <stdio.h>

int main()
{
    char str[] = "THE SKY IS BLUE";

    printf("The value returned by printf() for the above string is : %d\n", printf("%s", str));

    int x, y, z;

    printf("The value returned by the scanf() function is : %d\n\n",scanf("%d%d%d", &x, &y, &z));

    printf("x = %d\n", x);
    printf("y = %d\n", y);
    printf("z = %d\n", z);
    printf("\n");

    int i, a = 200, b = 100;
    i = scanf("%d/%d", &a, &b);
    printf("scanf return value =%d\n", i);
    if (i != 3)
        i = scanf("%d/%d", &a, &b);
    printf("%d/%d\n", a, b);

    return 0;
}

// 1. Compile and Run this C program.
// 2. modify the program to make the output clear by using '\n'
// 3. In command line, try to run command 'echo $?' to know the meaning of shell variable $?