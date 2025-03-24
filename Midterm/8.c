#include <stdio.h>
// TODO: Implement the swap function
void swap(int arr[], int a, int b) {
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

// TODO: Implement the partition function
int partition(int arr[], int left, int right) {
    int pivot = arr[right];
    int i = left - 1;
    for (int j = left; j < right; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr, i, j);
        }
    }
    i++;
    swap(arr, i, right);
    return i;
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5}; // You can modify this array for testing
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int pi = partition(arr, 0, n - 1);

    printf("Partitioned array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Pivot element is at index: %d\n", pi);

    return 0;
}
