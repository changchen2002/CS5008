#include <stdio.h>
#include <stdlib.h>
struct Node {
    int value;
    struct Node* left;
    struct Node* right;
} Node;

struct Node* createNode(int item){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->value = item;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* searchValue(struct Node* root, int value){
    // TO: Write your code here
    if (root == NULL || root->value == value){
        return root;
    }

    if (root->value > value){
        return searchValue(root->left, value);
    }
    else if (root->value < value){
        return searchValue(root->right, value);
    }
}

int main(){
    struct Node* root = createNode(25);
    root->left = createNode(15);
    root->right = createNode(50);
    root->left->left = createNode(10);
    root->left->right = createNode(20);
    root->right->left = createNode(35);
    root->right->right = createNode(75);
    printf(searchValue(root, 20) != NULL ? "Value 20 Found\n" : "Value 20 Not Found\n");
    printf(searchValue(root, 40) != NULL ? "Value 40 Found\n" : "Value 40 Not Found\n");
    return 0;
}
