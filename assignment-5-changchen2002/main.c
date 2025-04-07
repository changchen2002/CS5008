#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char data;
    struct Node *left, *right;
} Node;

Node* createNode(char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Modified tree construction to match exact desired traversals
Node* constructTree() {
    /* Builds this exact structure:
    A
    / \
    B C
    /
    D
    */
    Node* root = createNode('A');
    root->left = createNode('B');
    root->left->left = createNode('D');
    root->right = createNode('C');
    return root;
}

void preorder(Node* root) {
    if (root == NULL) return;
    printf("%c", root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%c", root->data);
    inorder(root->right);
}

void postorder(Node* root) {
    // TODO : Write your code here
    if (root == NULL) return;  
    postorder(root->left);
    postorder(root->right);
    printf("%c", root->data);
}

typedef struct QueueNode {
    Node* treeNode;
    struct QueueNode* next;
} QueueNode;

typedef struct Queue {
    QueueNode *front, *rear;
} Queue;

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

void bfs(Node* root) {
    if (!root) return;
    Node* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;
    while (front < rear) {
        Node* current = queue[front++];
        printf("%c ", current->data);
        if (current->left) queue[rear++] = current->left;
        if (current->right) queue[rear++] = current->right;
    }
}
    

int main() {
    Node* root = constructTree();
    printf("Preorder: "); preorder(root); // A B D C
    printf("\nInorder: "); inorder(root); // D B A C
    printf("\nPostorder: "); postorder(root); // D B C A
    printf("\nBFS: "); bfs(root); // A B C D
    printf("\n");
    return 0;
}
    