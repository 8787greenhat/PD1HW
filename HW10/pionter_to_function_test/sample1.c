#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef double (*F)(double x,int n);

double power(double x,int n){return pow(x,n);}

double multiply(double x,int n){return (x*n);}

double divide(double x,int n)
{   
    if(n == 0)
    {
        printf("error,can not divide to zero");
    }
    return (x/n);
}

double powerpower(F func,double x,int n,int m){return pow(func(x,n),m);}

int main(int argc,char *argv[])
{
    if(argc != 4)
    {
        printf("參數數量不符\n");
    }
    double x = atof(argv[1]);
    int n = atoi(argv[2]);
    int m = atoi(argv[3]);
    F func[] = {power,multiply,divide};
    for(int i = 0;i<3;i++)
    {
        double result = powerpower(func[i],x,n,m);
        printf("%lf\n",result);
    }
}

