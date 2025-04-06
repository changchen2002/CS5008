/*
  Name: Chang Chen
  LeetCode Problem: https://leetcode.com/problems/3sum-closest/description/
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int compare(const void* a, const void* b) { //Takes two void* pointers that point to elements being compared
    return (*(int*)a - *(int*)b); // Subtraction for comparison
}

int threeSumClosest(int* nums, int numsSize, int target) {
    qsort(nums, numsSize, sizeof(int), compare); //time: O(nlogn). space: O(logn)/O(n)

    int closest = nums[0] + nums[1] + nums[2]; 

    for (int i = 0; i < numsSize - 2; i++) {
        int l = i + 1, r = numsSize - 1;
        while (l < r) {
            int sum = nums[i] + nums[l] + nums[r];
            if (sum == target) return sum;
            
            if (abs(sum - target) < abs(closest - target)) {
                closest = sum;
            }

            if (sum < target) {
                l++;
            } else {
                r--;
            }
        }
    }
    return closest;
}

/*
two-pointer 
time: 
O(n log n) for sorting
O(n²) for the nested loops (outer loop runs n times, inner while loop runs at most n times)
O(n²) n sqare

Edge Cases
Minimum array size: The function assumes at least 3 elements exist. If numsSize < 3, it would lead to undefined behavior.
Integer overflow: When calculating sums or differences, there's no protection against integer overflow.
Duplicate elements: The code handles duplicate elements correctly since it processes all elements during iteration.
Empty array: Not handled, would cause undefined behavior.
Large distance from target: Works correctly as abs() handles large differences properly.
Initial assumption: The code assumes nums[0] + nums[1] + nums[2] is a valid starting point for closestSum, which might not be optimal but works for the algorithm.
*/