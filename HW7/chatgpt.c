#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int n, m;

    // ?�Jn�Mm����
    printf("??�Jn����: ");
    scanf("%d", &n);
    printf("??�Jm����: ");
    scanf("%d", &m);

    if (n <= 0 || m <= 0) {
        printf("n�Mm��?�O����?�C\n");
        return 1;
    }

    int arr[] = {10, 4, 3, 7, 15, 2, 5}; // �A��??
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    if (n > arr_size) {
        printf("n����j�_??���j�p�C\n");
        return 1;
    }

    qsort(arr, arr_size, sizeof(int), compare);

    int closest_sum = 0;
    int current_sum = 0;
    int *selected_items = (int *)malloc(n * sizeof(int));

    if (selected_items == NULL) {
        printf("?�s���t��?�C\n");
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

    printf("�̱���%d���M�O%d�C\n", m, closest_sum);

    free(selected_items);

    return 0;
}