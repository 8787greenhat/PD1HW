#include<stdio.h>
//gobal
int floder[20][2];
int floder_total =0;

int input_file(int name,int size) 
{
    for(int i = 0;i<=19;i++){//find the empty place to storge file 
        if(floder[i][0] == 0){
            floder[i][0] = name;
            floder[i][1] = size;
            floder_total +=1;
            break;
        }
    }
}

int delete_file() 
{
    printf("Hard drive exceeds its capacity, please enter the number of files to be deleted: ");
    int d_num;//delete how many file
    int file_size;
    scanf("%d%d",&d_num,&file_size);
    int temp =0;
    while(d_num != 0){//loop delete times
        if(floder[temp][0]!=0){//make sure not delete empty place again
            if(d_num!=1){
                printf("%d ",floder[temp][0]);
            }else{
                printf("%d\n",floder[temp][0]);
            }
            floder[temp][0] = 0;
            floder[temp][1] = 0;
            d_num = d_num-1;
            floder_total -=1;
        }
        temp = temp +1;//check next element at list
    }
}
void fun_1() 
{
    printf("Please input file name and file size: ");
    int name,size;
    scanf("%d%d",&name,&size);
    if(floder_total <=19) 
    {
        input_file(name,size);

    }else 
    {
        delete_file();
    }
}
void fun_2()
{
    int ser_file;
    printf("Please input the file name: ");
    scanf("%d",&ser_file);
    for(int i = 0;i<=19;i++)
    {
        if(floder[i][0] == ser_file)
        {
            printf("YES\n");
            return;
        }
    }
    printf("NO\n");

}

int main() 
{    
    int options_state;
    while(1) 
    {
        printf("Options: ");
        scanf("%d",&options_state);

        if(options_state == 1) 
        {
            fun_1();
        }
        else if(options_state == 2)
        {
            fun_2();
        }
        else if(options_state == 3)
        { 
            return 0;
        }
        else if(options_state == 4) //debug
        {
            for(int i = 0;i<=19;i++)
            {
                for(int j = 0;j<=1;j++)
                {
                    printf("%d ",floder[i][j]);
                }
                printf("\n");
            }
        }
    }
    
}