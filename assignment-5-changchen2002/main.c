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
   // TODO : Write your code here
}

void preorderTraversal(Node* root) {
   // TODO : Write your code here

}

void inorderTraversal(Node* root) {
     // TODO : Write your code here

}

void postorderTraversal(Node* root) {
     // TODO : Write your code here

}

void breadthFirstTraversal(Node* root) {
   // TODO : Write your code here

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
