#include <stdio.h>

#define BUCKETS 10

void bucketSort(int arr[], int n) {
    int buckets[BUCKETS][n];
    int count[BUCKETS] = {0};

    for (int i = 0; i < n; i++) {
        int index = arr[i] / BUCKETS;
        buckets[index][count[index]++] = arr[i];
    }

    int index = 0;
    for (int i = 0; i < BUCKETS; i++) {
        for (int j = 0; j < count[i] - 1; j++) {
            for (int k = j + 1; k < count[i]; k++) {
                if (buckets[i][j] > buckets[i][k]) {
                    int temp = buckets[i][j];
                    buckets[i][j] = buckets[i][k];
                    buckets[i][k] = temp;
                }
            }
        }
        for (int j = 0; j < count[i]; j++) {
            arr[index++] = buckets[i][j];
        }
    }
}

int main() {
    int arr[] = {42, 32, 33, 52, 37, 47, 51, 29};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    bucketSort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
