/*
  Name: Chang Chen
  LeetCode Problem: https://leetcode.com/problems/sort-list/
*/
#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
}

struct ListNode* getMiddleNode(struct ListNode* head) {
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    struct ListNode* prev = NULL;

    while (fast != NULL && fast->next != NULL) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    if (prev != NULL) {
        prev->next = NULL;
    }

    return slow; 
}

struct ListNode* mergeTwoSortedList(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode dummy = malloc(sizeof(struct ListNode));
    dummy->next = NULL;
    struct ListNode* p = dummy;

    while (l1 != NULL && l2 != NULL) {
        if (l1->val < l2->val) {
            p->next = l1;
            l1 = l1->next;
        } else {
            p->next = l2;
            l2 = l2->next;
        }
        p = p->next;
    }

    if (l1 != NULL) {
        p->next = l1;
    } else {
        p->next = l2;
    }

    return dummy.next;
}

struct ListNode* sortList(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head; 
    }

    struct ListNode* mid = getMiddleNode(head);

    struct ListNode* left = sortList(head);
    struct ListNode* right = sortList(mid);

    return mergeTwoSortedList(left, right);
}

/*
Time Complexity: O(n log n)

The algorithm divides the list into halves recursively, which gives us log n levels
At each level, we do O(n) work:

Finding the middle of the list is O(n)
Merging two sorted lists is O(n)

Space Complexity: O(log n)

The extra space is used for the recursion stack
Since we're dividing the list in half at each step, the maximum recursion depth is log n
Note: This is better than typical array-based merge sort which usually requires O(n) extra space

merge sort for an array
Space Complexity: O(n)
This is the key difference from the linked list implementation
Array-based merge sort typically requires O(n) extra space for the merging step
This is because when merging two sorted subarrays, we usually need a temporary array to store the merged result
Unlike the linked list version which just changes pointers, with arrays we need to copy elements

Edge Cases:

Empty list/Single node list: Handled correctly with the base case check if (head == NULL || head->next == NULL)
Already sorted list: The algorithm still works correctly but performs unnecessary splits and merges
List with all identical values: Should work correctly
Circular lists: Not handled; would cause infinite loops in getMiddleNode
Memory allocation: No new nodes are created, only pointers are modified
Stack overflow: For extremely large lists
*/