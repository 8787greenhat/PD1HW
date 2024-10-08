#include<stdio.h>
int a,b,c =0;
int r;
int main(){
    while(1){
        char c;
        while (  (c = getchar()) != '\n' && c != EOF);
        r = scanf("%d%d%d",&a,&b,&c);
        if (r==0){
            printf("error\n");
            printf("%d %d %d\n",a,b,c);
        }else{
            if (ferror(stdin)==1){
                printf("%d %d %d\n",a,b,c);
            }else{
                char c = getchar();
                printf("buffer not end:%s\n",c);
            }
        }
        if(a==-1&&b==-1&c==-1){
            break;
        }
    }
}