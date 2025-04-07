/*
  Name: Chang Chen
  LeetCode Problem: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
*/
#include <stdio.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
    if ((preorderSize <= 0) || (inorderSize <= 0))return NULL;

    struct TreeNode* root = malloc(sizeof(struct TreeNode));
    root->val = preorder[0];
    int i = 0;

    for(; i < inorderSize; ++i) {
        if (inorder[i] == root->val)
            break;
    }
    root->left = buildTree(preorder + 1, i, inorder, i);
    root->right = buildTree(preorder + i + 1, preorderSize - i - 1, inorder + i + 1, inorderSize - i - 1);
    return root;
}

/*
Time Complexity: O(n²)

The main bottleneck is the linear search in the inorder array to find the root position, which is O(n)
This search is performed for each node, resulting in O(n²) overall
In better implementations, a hash map could be used to reduce this to O(n)


Space Complexity: O(n)
O(n) for the constructed tree nodes
O(h) additional space for the recursion stack, where h is the height of the tree (worst case O(n) for skewed trees)

Edge Cases:
Empty arrays: Handled correctly by returning NULL when preorderSize or inorderSize is 0
Memory allocation failure: No check for malloc failure; would result in undefined behavior if memory allocation fails
Invalid input: Assumes the input arrays are valid and represent the same tree; no validation for duplicates
Single node tree: Handles correctly
Skewed trees: Will work, but the recursion depth could approach n for completely skewed trees
Arrays not representing a valid tree: No validation that the arrays actually represent a valid binary tree
Pointer arithmetic: Uses pointer arithmetic to pass subarrays, which is efficient but prone to errors if indices are miscalculated

The first element in the preorder array is always the root
Elements to the left of the root in the inorder array belong to the left subtree
Elements to the right of the root in the inorder array belong to the right subtree
*/