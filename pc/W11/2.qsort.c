#include <stdio.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void QSORT(int *nums, int left, int right){  
    
    if(left>=right) return;
    
    int l=left+1;//form list left side
    int r=right;//form list right side
    int key=nums[left];//use the frist element in list to 
    
    for(;;)
    {
        while (l<=right)//form left find the num big than key 
        {
            if(nums[l]>key) break;
            l++;
        }
        while (r>left)//form rigth find the num small than key
        {
            if(nums[r]<key) break;
            r--;
        }
        if(l>r) break;//than two ptr1 and ptr2 
        swap(&nums[r],&nums[l]);
    }

    swap(&nums[r],&nums[left]);//set a new compare number    
    QSORT(nums,left,r-1);
    QSORT(nums,r+1,right);
}

int main(void){
    
    int array[10];
    int len = sizeof(array) / sizeof(int);
    
    for(int i = 0; i < len; i++){
        scanf("%d",&array[i]);
    }
    
    QSORT(array,0,9);

    for(int i=0; i<10; i++){
        printf("%d ",array[i]);
    }
}