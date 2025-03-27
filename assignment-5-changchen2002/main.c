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

char getFirstChar(char *geneticString) {
    char firstChar = geneticString[0];
    memmove(geneticString, geneticString + 1, strlen(geneticString));
    return firstChar;
}

Node* constructTree(char *geneticString) {
    if (geneticString[0] == '\0') {
        return NULL;
    }
    
    char firstChar = getFirstChar(geneticString);
    if(firstChar == '\n') {
        return NULL;
    }

    Node *root = createNode(firstChar);
    root->left = constructTree(geneticString);
    root->right = constructTree(geneticString);

    return root;
}

void preorderTraversal(Node* root) {
    if (root == NULL) return;
    printf("%c", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void inorderTraversal(Node* root) {
    if (root == NULL) return;
    inorderTraversal(root->left);
    printf("%c", root->data);
    inorderTraversal(root->right);
}

void postorderTraversal(Node* root) {
    // TODO : Write your code here
    if (root == NULL) return;  
    postorderTraversal(root->left);
    postorderTraversal(root->right);
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

void enqueue(Queue* q, Node* treeNode) {
    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
    newNode->treeNode = treeNode;
    newNode->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        return;
    }
    q->rear->next = newNode;
    q->rear = newNode;
}

Node* dequeue(Queue* q) {
    if (q->front == NULL) return NULL;
    QueueNode* temp = q->front;
    Node* treeNode = temp->treeNode;
    q->front = q->front->next;
    if (q->front == NULL) q->rear = NULL;
    free(temp);
    return treeNode;
}

void breadthFirstTraversal(Node* root) {
    // TODO : Write your code here
    Queue* q = createQueue();
    enqueue(q, root);

    while (q->front != NULL) {
        Node* curr = dequeue(q);
        printf("%c ", curr->data);

        if (curr->left) enqueue(q, curr->left);
        if (curr->right) enqueue(q, curr->right);
    }
}

int main() {
    char geneticString[] = "A\nB\nC\n\nD\n\n\n";
    Node* root = constructTree(geneticString);

    printf("Preorder Traversal: ");
    preorderTraversal(root);
    printf("\n");

    printf("Inorder Traversal: ");
    inorderTraversal(root);
    printf("\n");

    printf("Postorder Traversal: ");
    postorderTraversal(root);
    printf("\n");

    printf("Breadth-First Traversal: ");
    breadthFirstTraversal(root);
    printf("\n");

    return 0;
}
