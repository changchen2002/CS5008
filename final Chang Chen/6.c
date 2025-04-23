#include <stdio.h>
#include <stdbool.h>

int cmp(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

bool twoSum(int A[], int n, int x) {
    qsort(A, n, sizeof(int), cmp);
    int l = 0, r = n - 1;
    while (l < r) {
        if (A[l] + A[r] == x) {
            return true;
        } else if (A[l] + A[r] < x) {
            l++;
        } else {
            r--;
        }
    }
    return false;
}
