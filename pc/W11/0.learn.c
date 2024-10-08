#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10
#define max 100
#define min 10

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void Q(int *arr, int left, int right) {

    if(left>right) return;

    int key = arr[left];
    int r = right;
    int l = left + 1;

    for(;;)
    {
        while (l<=right)//form left find the num big than key 
        {
            if(arr[l]>key) break;
            l++;
        }
        while (r>left)//form right find the num small than key
        {
            if(arr[r]<key) break;
            r--;
        }
        if(l>r) break;//than two ptr1 and ptr2 
        swap(&arr[r],&arr[l]);
    }

    swap(&arr[r],&arr[left]);//set a new key
    Q(arr,left,r-1);
    Q(arr,r+1,right);
}

int main() {
    int arr[N];
    int size = sizeof(arr) / sizeof(int);

    srand((unsigned)time(NULL));

    for (int i = 0; i < size; i++) {
        arr[i] = rand() % (max - min + 1) + min;
    }

    for (int i = 0; i < size; i++) {
        printf("%3d ", arr[i]);
    }

    printf("\n------\n");

    Q(arr, 0, N - 1);

    for (int i = 0; i < size; i++) {
        printf("%3d ", arr[i]);
    }

    return 0;
}