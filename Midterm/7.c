#include <stdio.h>
int binarySearch(int arr[ ], int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        // TODO: Complete the function
        if (target == arr[mid]) {
            return mid;
        } else if (target < arr[mid]) {
            return binarySearch(arr, left, mid - 1, target);
        } else {
            return binarySearch(arr, mid + 1, right, target);
        }
    }
    return -1;
}
int main() {
    int arr[ ] = {2, 4, 6, 8, 10, 12, 14, 16};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 10;
    // TODO: Call the binarySearch function and print the result
    int index = binarySearch(arr, 0, n - 1, target);
    if (index != -1) {
        printf("Target is at index %d\n", index);
    } else {
        printf("Couldn't find the target");
    }
    return 0;
}
