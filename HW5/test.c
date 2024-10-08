#include<stdio.h>
#define TRUE 1
#define FALSE 0
#define bool int
int main()
{
    int a,b,c=0;
    int r;
    bool t = TRUE;
    bool error = FALSE;
    while(t == TRUE){
        r = scanf("%d%d%d",&a,&b,&c);
        int g = getchar();

        if(error == TRUE && a == -1 && b == -1 && c == -1){
            error = FALSE;
            break;
        }

        if(r == 3 && (g ==10 || a == EOF)){
            if(a>=0&&b>=0&&c>=0){
                t = FALSE;
            }else{
                printf("error1");
                error = TRUE;
            }
        }else if(r != 3 || (g!=10 && g!=EOF)){
            printf("error3");
            printf("%d",r);
            error = TRUE;
            if (r !=2){
                int s;
                while ((s = getchar()) != '\n' && s != EOF);
            }
        }
    }
    printf("%d %d %d",a,b,c);
}