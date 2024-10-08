#include<stdio.h>
int main(){
    int day, start , count;
    printf("Enter number of days in month: \n");
    scanf("%d",&day);
    printf("Enter starting day of the week (1=Sun, 7=Sat): \n");
    scanf("%d",&start);
    count = start;
    for(int i = 0;i<=start-2;i++)
    {
        printf("   ");
    }
    for(int j=1;j<=day;j++){

        if(count ==7){
            if(j<10){

                printf(" %d",j);
            }else{
                printf("%d",j);
            }
            count = 1;
        }
        else if(count == 1){
            if(j<10){
                if(j==1){
                    printf(" %d ",j);
                }
                else{
                    printf("\n %d ",j);
                }
            }
            else{
                printf("\n%d ",j);
            }
            count = count+1;
        }
        else if(j == day){
            if(j<10){
                printf(" %d",j);
            }
            else{
                printf("%d",j);
            }
        }
        else if(count != 7){
            if(j<10){
                printf(" %d ",j);
            }
            else{
                printf("%d ",j);
            }
            count =count +1;
        }
        
        
    }
}