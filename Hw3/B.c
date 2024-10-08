#include<stdio.h>

int main(){
    int a,b,c;
    int result = 0;
    scanf("%d-%d-%d",&a,&b,&c);
    if(a==b && b == c){
        result = 300;
    }else if(a + b < c){
        result = 150;
    }else if(a ==c){
        result = 100;
    }else if(a <b){
        result = 50;
    }
    printf("%d",result);

}