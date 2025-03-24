#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};

void deleteLast(struct Node** head) {
    // Check if the list is empty
    if (*head == NULL) {
        return; // List is empty, nothing to remove
    }
    // If the list has only one node
    
    if ((*head)->next == NULL){
        free(*head);
        *head = NULL;
        return;
    }
    // Find the second-to-last node
    struct Node* curr = *head;
    while (curr->next->next != NULL){
        curr = curr->next;
    }
    // After reaching the second-to-last node, remove the last node
    free(curr->next);
    curr->next = NULL;
    return;
}

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(30);

    printf("Original List: ");
    printList(head);

    deleteLast(&head);
    printf("List after removing last node: ");
    printList(head);

    return 0;
}
