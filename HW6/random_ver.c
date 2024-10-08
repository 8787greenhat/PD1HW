#include<stdio.h>
#include <stdlib.h>
#include <time.h>
// rand()%(最大值-最小值+1)+ 最小值 值放進陣列
int action_1(){ //done
    int l;
    l = rand()%(20000-5000+1)+5000;
    printf ("%d\n",l);
    int arr[l];
    for (int i = 0 ;i<= l-1; i++){
        int randnum;
        randnum = rand()%(1000000001);
        arr[i] = randnum;
        if(i<l-1){
            printf("%d ",randnum);
        }else{
            printf("%d\n",randnum);
        }
    }
    for (int i = l-1;i>=0;i--){
        if(i !=0){
            printf("%d ",arr[i]);
        }else{
            printf("%d",arr[i]);
        }
    }
}

int action_2(){
    long l;
    l = rand()%(200000-5000+1)+5000;
    printf("%ld");
    long long truesum;
    truesum = (l*(l+1))/2;
    long arr[l+1];
    for(long i = 0;i<=l+1;i++){
        arr[i] = i;
    }
    long j = rand()%l+1;
    for(long i = j;i<=l;i++){
        arr[i] = arr[i+1];
    }
    for(int i = 1; i<=l-1;i++){
        truesum = truesum - arr[i];
        if(i<l-1){
            printf("%ld ",arr[i]);
        }else{
            printf("%ld\n",arr[i]);
        }
    }
    printf("%lld",truesum);
}

int action_3(){
    int array_l;
    array_l = rand()%(100000-50000+1)+50000;
    printf("%d\n",array_l);
    int arr[array_l-1];
    long prefix_sum[array_l];//prefix sum array(serach google:)

    for(int i = 0;i<= array_l-1;i++){//store input
        int j = rand()%1000000000+1;
        arr[i] = j;
        if(i<array_l-1){
            printf("%d ",j);
        }else{
            printf("%d\n",j);
        }
    }
    prefix_sum[0] = 0;//aviod prefix_sum[0] be random num;
    for(int j = 1;j<=array_l;j++){//prefix sum
        prefix_sum[j] = prefix_sum[j-1]+arr[j-1];
    }

    int serach_times;
    serach_times = rand()%(100000-50000+1)+50000;
    printf("%d\n",serach_times);
    long sum[serach_times-1];
    for(int i = 0;i<=serach_times-1;i++){//run serach times then stroge the result
        int start,end =0;
        start = rand()%(array_l-2)+1;
        while(end<start){
            end = rand()%(array_l-1)+1;
        }
        printf("%d %d\n",start,end);
        sum[i] = (long)prefix_sum[end] - (long)prefix_sum[start-1];
    }
    for(int i = 0;i<=serach_times-1;i++){//print out results
        if(i<serach_times-1){
            printf("%ld\n",sum[i]);
        }else{
            printf("%ld",sum[i]);
        }
        
    }
}

int action_4(){
    int row,colum;
    row = rand()%(1000-500+1)+500;
    colum = rand()%(1000-500+1)+500;
    printf("%d %d\n",row,colum);
    int arr[row][colum];
    for(int i = 0;i<=row-1;i++){//input 
        for(int j = 0;j<=colum-1;j++){
            int num = rand()%1000+1;
            arr[i][j] = num;
            if(j<colum-1){
                printf("%d ",num);
            }else{
                printf("%d",num);
            }
        }
        printf("\n");
    }
    for(int j =0;j<=4;j++){//exchange
        int a,b;
        int c,d;
        a = rand()%row+1;
        b = rand()%colum+1;
        c = rand()%row+1;
        d = rand()%colum+1;
        printf("%d %d %d %d\n",a,b,c,d);
        int temp = arr[c-1][d-1];
        arr[c-1][d-1] = arr[a-1][b-1];
        arr[a-1][b-1] = temp;
    }
    for(int i = 0;i<=row-1;i++){//print
        for(int j = 0;j<=colum-1;j++){
            if(j<colum-1){
                printf("%d ",arr[i][j]);
            }else{
                printf("%d",arr[i][j]);
            }
        }
        if(i<row-1){
             printf("\n");
        }
    }
}

int main(){
    srand((unsigned)time(NULL));
    int opt;
    scanf("%d",&opt);
    if(opt == 1){
        action_1();
    }else if(opt == 2){
        action_2();
    }else if(opt == 3){
        action_3();
    }else if(opt ==4){
        action_4();
    }
}