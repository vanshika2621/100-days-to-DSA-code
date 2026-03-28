#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Definition for a binary tree node
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Helper function to create a new node
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Mirror check function
bool isMirror(struct TreeNode* left, struct TreeNode* right) {
    // Both NULL → symmetric
    if (left == NULL && right == NULL)
        return true;

    // One NULL → not symmetric
    if (left == NULL || right == NULL)
        return false;

    // Check value + mirror structure
    return (left->val == right->val) &&
           isMirror(left->left, right->right) &&
           isMirror(left->right, right->left);
}

// Main function
bool isSymmetric(struct TreeNode* root) {
    if (root == NULL)
        return true;

    return isMirror(root->left, root->right);
}

// Example test
int main() {
    /*
            1
          /   \
         2     2
        / \   / \
       3   4 4   3
    */

    struct TreeNode* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(2);
    root->left->left = newNode(3);
    root->left->right = newNode(4);
    root->right->left = newNode(4);
    root->right->right = newNode(3);

    if (isSymmetric(root))
        printf("Tree is symmetric\n");
    else
        printf("Tree is not symmetric\n");

    return 0;
}