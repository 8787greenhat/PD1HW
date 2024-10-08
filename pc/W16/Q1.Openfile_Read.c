#include<stdio.h>


int main()
{
    FILE *fp = fopen("D:\\data\\code learn\\c\\frist\\pc\\W16\\sample.txt","r");
    char line[256]; 
    while (fgets(line, sizeof(line), fp) != NULL) {
        printf("%s", line);
    }

    rewind(fp);

    int num1, num2;
    while (fscanf(fp, "%d %d", &num1, &num2) == 2) {
        printf("Read: %d %d\n", num1, num2);
    }

    fclose(fp);
    return 0;
}