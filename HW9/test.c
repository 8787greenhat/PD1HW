#include<stdio.h>

int main()
{
    float f1 = 1.175494350822287507968736537222245677818665556772087521508751706278417259454727172851560500000000000000000000000000000000e-38f;
    float f2 = 1.175494350822287500e-38f;
    if( f1==f2 ) { printf("%.100e = %.100e", f1, f2); }
    else { printf("%.100e != %.100e", f1, f2); }
}