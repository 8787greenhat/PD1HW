#include<stdio.h>

int action_1(){ 
    int l;
    scanf("%d",&l);
    int arr[l];
    for (int i = 0 ;i<= l-1; i++){
        scanf("%d",&arr[i]);
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
    int l;
    scanf("%d",&l);
    long truesum;
    truesum = (l*(l+1))/2;
    for(int i = 0;i<=l-2;i++){
        long j;
        scanf("%ld",&j);
        truesum = truesum - j;
    }
    printf("%ld",truesum);
}

int action_3(){
    int array_l;
    scanf("%d",&array_l);
    int arr[array_l-1];
    long prefix_sum[array_l];//prefix sum array(serach google:)

    for(int i = 0;i<= array_l-1;i++){//store input

        scanf("%d",&arr[i]);
    }
    prefix_sum[0] = 0;//aviod prefix_sum[0] be random num;
    for(int j = 1;j<=array_l;j++){//prefix sum
        prefix_sum[j] = prefix_sum[j-1]+arr[j-1];
    }

    int serach_times;
    scanf("%d",&serach_times);
    long sum[serach_times-1];
    for(int i = 0;i<=serach_times-1;i++){//run serach times then stroge the result
        int start,end;
        scanf("%d%d",&start,&end);
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
    scanf("%d%d",&row,&colum);
    int arr[row][colum];
    for(int i = 0;i<=row-1;i++){//input 
        for(int j = 0;j<=colum-1;j++){
            scanf("%d",&(arr[i][j]));
        }
    }
    for(int j =0;j<=4;j++){//exchange
        int a,b;
        int c,d;
        scanf("%d%d%d%d",&a,&b,&c,&d);
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