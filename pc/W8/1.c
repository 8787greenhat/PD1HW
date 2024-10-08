#include <stdio.h>
int i = 0;
int num;
int binary[1000];

void decimalToBinary(int num) {   
    if (num == 0) {
        printf("0");
        return;
    }
    while (num > 0){
        binary[i] = num%2;
        num = num/2;
        i ++;
    }
    
}

int main() {
    printf("Enter a decimal number: ");
    scanf("%d", &num);
    decimalToBinary(num);
    for (int j = i-1; j>=0;j--){
        printf("%d",binary[j]);
    }

    return 0;
}