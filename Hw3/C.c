#include<stdio.h>

int main(){
    int a,b,c;
    int result = 0;
    scanf("%d-%d-%d",&a,&b,&c);
    if(a==b && b == c){
        result = result + 300;
    }if(a + b < c){
        result = result + 150;
    }if(a ==c){
        result = result + 100;
    }if(a <b){
        result = result + 50;
    }
    printf("%d",result);

}