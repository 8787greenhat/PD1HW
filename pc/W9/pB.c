#include<stdio.h>
long sum =1;
long recursion(int x,int y){
    if(y==0){
        return sum;
    }else{
        sum = sum*x;
        recursion(x,y-1);
    }
}
int main(){
    int x,y;
    scanf("%d%d",&x,&y);
    printf("%ld",recursion(x,y));
}