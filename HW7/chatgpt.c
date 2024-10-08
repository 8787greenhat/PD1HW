#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int n, m;

    // ?入n和m的值
    printf("??入n的值: ");
    scanf("%d", &n);
    printf("??入m的值: ");
    scanf("%d", &m);

    if (n <= 0 || m <= 0) {
        printf("n和m必?是正整?。\n");
        return 1;
    }

    int arr[] = {10, 4, 3, 7, 15, 2, 5}; // 你的??
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    if (n > arr_size) {
        printf("n不能大于??的大小。\n");
        return 1;
    }

    qsort(arr, arr_size, sizeof(int), compare);

    int closest_sum = 0;
    int current_sum = 0;
    int *selected_items = (int *)malloc(n * sizeof(int));

    if (selected_items == NULL) {
        printf("?存分配失?。\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        selected_items[i] = arr[i];
        current_sum += arr[i];
    }

    if (current_sum >= m) {
        closest_sum = current_sum;
    }

    for (int i = n; i < arr_size; i++) {
        current_sum = current_sum - selected_items[i % n] + arr[i];
        if (abs(m - current_sum) < abs(m - closest_sum)) {
            closest_sum = current_sum;
        }
        selected_items[i % n] = arr[i];
    }

    printf("最接近%d的和是%d。\n", m, closest_sum);

    free(selected_items);

    return 0;
}