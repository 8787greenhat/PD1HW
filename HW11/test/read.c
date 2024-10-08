#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define FileNAME "D:\\data\\code learn\\c\\frist\\HW11\\test\\test.txt"

void print_test(FILE *fp) {
    rewind(fp); // Rewind the file pointer to the beginning of the file

    char buffer[30];
    int i = 1;

    while (fscanf(fp, "%30s", buffer) == 1) {
        printf(">%d. %s\n", i++, buffer);
    }
}

void insert(FILE *fp) {
    char s[30];
    printf("input:");
    scanf("%s", s);
    fprintf(fp, "%s\n", s);
}

void search(FILE *fp)
{
    char s[30];
    char buffer[30];
    bool check = false;

    printf("search input:");
    scanf("%s",s);

    rewind(fp);

    while(fscanf(fp,"%30s", buffer) == 1)
    {
        if(strcmp(buffer, s) == 0)
        {
            check = true; 
            break;
        } 
    }

    check ? printf("true\n") : printf("false\n");
}

int main() {
    FILE *fp = fopen(FileNAME, "a+");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(EXIT_FAILURE);
    }

    int choice;
    while (1) {

        printf("1. Print\n2. Insert\n3. Search\n4. Quit\nEnter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            print_test(fp);
        } else if (choice == 2) {
            insert(fp);
        } else if (choice == 3) {
            search(fp);
        } else {
            break;
        }
    }

    fclose(fp);
    return 0;
}
