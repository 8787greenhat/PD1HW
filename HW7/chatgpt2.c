#include <stdio.h>
#include <stdlib.h>
#define N 21

int list_name[N] = {0};//Input file name
int list_size[N] = {0};//Input file data size
int k = 0;//To record how many file in list
int choose[N] = {0}; // To keep track of selected items
int closest_sum = 0; // To track the closest sum
int best_choice[N]; // To store the best choice
int choose_file, choose_size;//delete file & total size sum 

void rev(int idx, int sum, int count); 
void add(int file_name,int file_size);
void del();
void func_1();
void func_2();

int main() {
    int opt;
    while(1) 
    {
        printf("Options: ");
        scanf("%d",&opt);

        if(opt == 1) 
        {
            func_1();
        }
        else if(opt == 2)
        {
            func_2();
        }
        else if(opt == 3)
        { 
            return 0;
        }
        else if(opt == 4)
        {
            for(int i = 0;i<N;i++)
            {
                printf("%d ",list_name[i]);
                printf("%d\n",list_size[i]);
            }
        }
    }   
}

void add(int file_name,int file_size)
{
    for(int i = 0;i<N;i++){//find the empty place to storge file 
        if(list_name[i] == 0){
            list_name[i] = file_name;
            list_size[i] = file_size;
            k = k +1;
            break;
        }
    }
    if(k == N)
    {
        del();
    }
}

void del()
{
    printf("Hard drive exceeds its capacity, please enter the number of files to be deleted: ");
    scanf("%d%d", &choose_file, &choose_size);
    rev(0, 0, 0);

    if (closest_sum > 0) {
        for (int i = 0; i < N; i++) {
            if (best_choice[i] == 1) {
                printf("%d ", list_name[i]);
                list_name[i] = 0;
                k = k -1;
            }
        }
        printf("\n");
    } else {
        printf("No valid subset found.\n");
    }
}

void rev(int idx, int sum, int count) 
{
    if (count == choose_file) 
    {
        int diff = abs(choose_size - sum);
        int closest_diff = abs(choose_size - closest_sum);

        if (diff < closest_diff || (diff == closest_diff && sum > closest_sum))
        {
            closest_sum = sum;
            for (int i = 0; i < N; i++) 
            {
                best_choice[i] = choose[i];
            }
        }
        return;
    }

    if (idx == N) 
    {
        return;
    }

    choose[idx] = 1;
    rev(idx + 1, sum + list_size[idx], count + 1);
    choose[idx] = 0;
    rev(idx + 1, sum, count);
}

void func_1()
{
    printf("Please input file name and file size: ");
    int name,size;
    scanf("%d%d",&name,&size);
    add(name,size);
}

void func_2()
{
    int find_file;
    printf("Please input the file name: ");
    scanf("%d",&find_file);
    for(int i = 0;i<N;i++)
    {
        if(list_name[i] == find_file)
        {
            printf("YES\n");
            return;
        }
    }
    printf("NO\n");
}