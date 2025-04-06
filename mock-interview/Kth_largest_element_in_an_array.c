/*
  Name: Chang Chen
  LeetCode Problem: https://leetcode.com/problems/kth-largest-element-in-an-array/description/
*/
#include <stdio.h>

void minHeapify(int *heap, int i, int heapSize) {
    int smallest = i, left = 2 * i + 1, right = 2 * i + 2;

    if (left < heapSize && heap[left] < heap[smallest])
        smallest = left;
    if (right < heapSize && heap[right] < heap[smallest])
        smallest = right;
    
    if (smallest != i) {
        int temp = heap[i];
        heap[i] = heap[smallest];
        heap[smallest] = temp;
        minHeapify(heap, smallest, heapSize);
    }
}

// Build a heap
void buildMinHeap(int *heap, int heapSize) {
    for (int i = heapSize / 2 - 1; i >= 0; i--)
        minHeapify(heap, i, heapSize);
}

// Find Kth Largest using Min Heap
int findKthLargest(int *nums, int numsSize, int k) {
    int *heap = (int *)malloc(k * sizeof(int));
    
    for (int i = 0; i < k; i++)
        heap[i] = nums[i];
    
    buildMinHeap(heap, k);

    for (int i = k; i < numsSize; i++) {
        if (nums[i] > heap[0]) { // If current number is larger than heap's root
            heap[0] = nums[i];
            minHeapify(heap, 0, k);
        }
    }

    int kthLargest = heap[0]; // Root of min heap is the Kth largest element
    free(heap);
    return kthLargest;
}

/*
Time Complexity:

Building the initial heap (buildMinHeap):
    Heapify is called for the first k elements.
    Each minHeapify takes O(log k) time.
    Since we heapify from k/2 down to 0, the total time is O(k) (tight bound, not O(k log k) due to the way heap construction works).
Processing the remaining n - k elements:
    For each of the remaining n - k elements, we:
        Compare with the heap's root (O(1)).
        If larger, replace the root and heapify (O(log k)).
    Worst case: All n - k elements trigger a heapify → O((n - k) log k).
Total Time Complexity:
O(k) (build heap) + O((n - k) log k) (processing) = O(n log k) (since k ≤ n).

Space Complexity:
    O(k) to store the min-heap of size k.
    
Edge Cases to Consider
    k = 1 (Find the maximum element):
    The heap will always contain the single largest element seen so far.
    Correctly returns the maximum.
    k = numsSize (Find the smallest element):
    The heap will contain all elements, and the root will be the k-th largest (i.e., the smallest element).
    Correctly returns the minimum.
    k > numsSize (Invalid input):
    The function does not explicitly handle this case.
    Should return an error or handle gracefully (e.g., return INT_MIN or assert k <= numsSize).
    Empty array (numsSize = 0):
    The function does not handle this case.
    Should return an error or handle gracefully (e.g., return INT_MIN).
    All elements are the same:
    The heap will always contain k copies of the same value.
    Correctly returns that value.
    Large k (e.g., k = n/2):
    The heap size remains k, so the algorithm remains efficient (O(n log k)).
    Input with duplicates:
    The function works correctly even if duplicates exist (since it maintains the k largest distinct or non-distinct elements).
*/