#include<stdio.h>

int main(){
    long long a,b,result;
    scanf("%lld%lld",&a,&b);
    result = a+b;
    if ((a>=0 && b<=0) || (a<=0 && b>=0)){
        printf("No");
    }else if(a>=0){
        if (b > (9223372036854775807LL-a)){
            printf("Yes");
        }else{
            printf("No");
        }
    }else if(a<=0){
        if (b < (-9223372036854775807LL - 1LL-a)){
            printf("Yes");
        }else{
            printf("No");
        }
    }

}