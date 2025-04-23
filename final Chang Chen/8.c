#include <stdio.h>
void biDirectionalBubbleSort(int arr[], int n) {
    int start = 0, end = n - 1;
    int swapped;
    while (start < end) {
        swapped = 0;
        // Left to right pass (move largest to the end)
        for (int i = start; i < end; i++) {
            if (arr[i] > arr[i + 1]) {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                swapped = 1;
            }
        } 
        // TODO: move end pointer
        end--;

        if (!swapped) break;

        swapped = 0;

        // Right to left pass (move smallest to the start)
        for (int i = end; i > start; i--) {
            // TODO: Write your code here
            if (arr[i - 1] > arr[i]) {
                int temp = arr[i];
                arr[i] = arr[i - 1];
                arr[i - 1] = temp;
                swapped = 1;
            }
        }
        // TODO: move start pointer
        start++;

        if (!swapped) break;
    }
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Original array: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");

    biDirectionalBubbleSort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
    

/*
(b)
First pass it moves the largest element to the end of the array, 
and the second pass moves the smallest element to the beginning of the array. 
This process continues until no swaps are made in a complete pass, indicating that the array is sorted.

(c)
O(n^2) in the worst case, 
because in the worst case, we have to make n passes through the array,
and in each pass, we have to compare n elements.

O(n) in the best case (when the array is already sorted), 
because we only need to make one pass through the array, and since swapped = 0 we'll break out of the loop.

(d)
It improves bubble sort by keeping track of the last position where a swap occurred.
This allows the algorithm to reduce the range of elements that need to be sorted in subsequent passes.

It is helpful when the array is partially sorted,
as it will break out of the loop earlier when no swap are made, and reduce the number of comparisons.
*/