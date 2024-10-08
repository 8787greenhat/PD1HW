#include<stdio.h>
#define Bool int
#define TRUE 1
#define FALSE 0

int options = 0;
Bool open = FALSE;
int A,B,C,sum,money;
int tA,tB,tC,tMoney;
int gcd(int a, int b , int c){
    int num;
    int tem=a;       
    if(tem>b)     
    {
        tem=b;
    }
    if(tem>c)
    {
        tem=c;
    }
    for(int i=1;i<=tem;i++)   
    {
        if(a%i==0&&b%i==0&&c%i==0)  
        {
            num=i;
        }
    }
    return num;
}
int main(){
    printf("//////////Welcome to NCKU-PD1-Kirby-Shop\\\\\\\\\\\\\\\\\\\\\n");
    while(1){
        //²Ä¤@¤¶­±
        while(options != 1||options != 2||options != 3||options != 4){
            printf("Options: (1)Openning (2)List (3)Adding (4)Exit\n");
            scanf("%d",&options);
            if(options == 1||options == 2||options == 3||options == 4){
                break;
            }
            printf("Error: Please try again!\n");
        }
        //action 1 2 3 4
        switch (options)
        {
        //open
        case 1:
            if (open == FALSE){
                open = TRUE;
                printf("Your shop is openning!\n");
            }else{
                printf("Your Kirby shop has already opened :(\n");
            }
            break;
        //list
        case 2:
            printf("===================================\n");
            printf("Kirby-A: %d\n",tA);
            printf("Kirby-B: %d\n",tB);
            printf("Kirby-C: %d\n",tC);
            printf("Kirby: %d, Money: %d\n",tA+tB+tC,tMoney);
            printf("===================================\n");
            break;
        //count
        case 3://undone
            if(open!=TRUE){
                printf("Your Kirby shop has not opened\n");
                break;
            }
            A=B=C=0;
            int scanf_r;
            Bool test = TRUE;
            Bool error = FALSE;
            printf("Please enter three numbers: ");

            while(test == TRUE){//input test
                
                scanf_r = scanf("%d%d%d",&A,&B,&C);

                if(error == TRUE && A == -1 && B == -1 && C == -1){
                    error = FALSE;
                    break;
                }
                if (scanf_r ==3 ){//check 3 num scanf or not
                    int g = getchar();
                    if(g == 10){
                            if(A>0 && B>0 && C>0){//case negative num
                            test = FALSE;
                        }else{
                            printf("Error: Please try again or enter '-1 -1 -1' to make a new options: ");
                            error = TRUE;
                        }
                    }else{
                        printf("Error: Please try again or enter '-1 -1 -1' to make a new options: ");
                        error = TRUE;
                        char c;
                        while ( (c = getchar()) != '\n' && c != EOF);//clear buffer
                    }    
                }else if (scanf_r != 3 ){
                    error = TRUE;
                    char c;
                    while ( (c = getchar()) != '\n' && c != EOF);
                    printf("Error: Please try again or enter '-1 -1 -1' to make a new options: ");
                }
            }
            if (A==-1&&B==-1&&C==-1){break;}
            int box = 0;
            box =gcd(A,B,C);
            printf("Divide these Kirbys into %d boxes, with the number of Kirby in each box being %d, %d, and %d\n",box,A/box,B/box,C/box);
            printf("Price: %d\n",A+B+C-2*box);
            tA = tA +A;
            tB = tB +B;
            tC = tC + C;
            tMoney = tMoney + A+B+C-2*box;
            break;
        //exit
        case 4:
            return 0;
        }
    }
}