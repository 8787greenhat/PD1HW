#include <stdio.h>

void swap(int *c, int *d) {
    int temp = *c;
    *c = *d;
    *d = temp;
}

int main() {
    int a,b;
    
    scanf("%d %d", &a, &b);
    
    printf("before:\n");
    printf("%d %d\n", a, b);
    
    swap(&a,&b);
    
    printf("after:\n");
    printf("%d %d\n", a, b);
}