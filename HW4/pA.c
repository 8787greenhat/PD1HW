#include<stdio.h>
int main(){
    int day, start , count;
    printf("Enter number of days in month: \n");
    scanf("%d",&day);
    printf("Enter starting day of the week (1=Sun, 7=Sat): \n");
    scanf("%d",&start);
    count = start-1;
    for(int i =0; i<=start-2;i++){
        printf("   ");
    }
    for(int j =1; j<= day; j++){
        if(count ==7){
            count =0;
        }
        
        if (j<10){
            if(count!=7){
                printf(" %d ",j);
            }
            else if(count ==0){
                printf("\n %d ",j);
            }
            else{
                printf(" %d",j);
            }
        }
        if (j>=10){
            if(count!=7){
                printf("%d ",j);
            }
            else if(count==0){
                printf("\n%d",j);
            }
            else{
                printf("%d",j);
            }   
        }
        count = count +1;
    }
}