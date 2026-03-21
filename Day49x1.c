#include <stdio.h>
#include <stdlib.h>

// ----------- Tree Node (if needed) -----------
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// ----------- Function to implement -----------
int solve(struct TreeNode* root) {
    // Write your logic here
    return 0;
}

// ----------- Helper to create node -----------
struct TreeNode* createNode(int val) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// ----------- Main function -----------
int main() {
    // Example tree (you can change input as needed)

    struct TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);

    int result = solve(root);
    printf("%d\n", result);

    return 0;
}