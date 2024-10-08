#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct student{ 
    char name[20];
    int age;
}student;

typedef struct struct2
{
    int p1;
    int p2;
}struct2; 

void print_struct(student a[],student b[],int n)
{
    for(int i = 0;i<n;i++)
    {
        printf("%s ",a[i].name);
        printf("%d\n",a[i].age);
    }
    
    printf("\n ----- \n");

    for(int i = 0;i<n;i++)
    {
        printf("%s ",b[i].name);
        printf("%d\n",b[i].age);
    }

    printf("\n ----- \n");
}

void swap_struct(student a[],student b[],int n)
{
    for(int i = 0;i<n;i++)
    {
        char dump[20];

        strcpy(dump,a[i].name);
        strcpy(a[i].name,b[i].name);
        strcpy(b[i].name,dump);

        int age;

        age = a[i].age;
        a[i].age = b[i].age;
        b[i].age = age;
    }

}

int main()
{
    student student1[5] = {
        {"oggy",7},
        {"beson",8},
        {"green",10},
        {"aston",12},
        {"gina",3}
    };

    student student2[5] = {
        {"han",17},
        {"ben",9},
        {"blue",1},
        {"len",13},
        {"tina",4}
    };

    print_struct(student1,student2,sizeof(student1)/sizeof(student));

    swap_struct(student1,student2,sizeof(student1)/sizeof(student));

    print_struct(student1,student2,sizeof(student1)/sizeof(student));
}