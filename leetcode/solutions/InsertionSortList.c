/*
  Name: Chang Chen
  LeetCode Problem: https://leetcode.com/problems/insertion-sort-list/
*/
#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
}

struct ListNode* insertionSortList(struct ListNode* head) {
    if (!head || !head->next) return head;
   
    struct ListNode* dummy = malloc(sizeof(struct ListNode));
    dummy->next = head;

    struct ListNode* prev = head;
    struct ListNode* curr = head->next;

    while (curr) {
        if (prev->val <= curr-> val) {
            prev = prev->next;
            curr = curr->next;
        } else {
            struct ListNode* temp = dummy;
            while (curr->val > temp->next->val) {
                temp = temp->next;
            }
            prev->next = curr->next;
            curr->next = temp->next;
            temp->next = curr;

            curr = prev->next;
        }
    }
    return dummy->next;
}

/*
Time Complexity::
This results in a worst-case complexity of O(N^2), where N is the number of nodes in the linked list.
	•	The best case occurs when the list is already sorted in ascending order, leading to only one comparison per node, resulting in O(N).

Thus, the overall time complexity is O(N^2) in the worst case and O(N) in the best case.

space complexity is O(1).
*/