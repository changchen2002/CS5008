/*
  Name: Chang Chen
  LeetCode Problem: https://leetcode.com/problems/find-the-duplicate-number/description/
*/
#include <stdio.h>

int findDuplicate(int* nums, int numsSize) {
    int slow = nums[0], fast = nums[0];
    do {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast); //first intersection.
    slow = nums[0]; 
    while (slow != fast) {
        slow = nums[slow];
        fast = nums[fast];
    }
    return slow; // second intersection is the result
}


/*
Floyd's cycle detection algorithm
Time Complexity: O(n)

The first loop (cycle detection) runs at most O(n) times
The second loop (finding the entrance to the cycle) runs at most O(n) times
Overall: O(n)

Space Complexity: O(1)
Only using two pointers (slow and fast) regardless of input size

it treats the array as a linked list where the indices are nodes and values are "next" pointers. 
Since there's a duplicate, this creates a cycle in this virtual linked list, which the algorithm detects and then finds the start of this cycle (the duplicate number).
*/