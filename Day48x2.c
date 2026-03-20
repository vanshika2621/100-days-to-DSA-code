#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int solve(struct TreeNode* root, int isLeft) {
    if (root == NULL)
        return 0;

    if (root->left == NULL && root->right == NULL && isLeft)
        return root->val;

    return solve(root->left, 1) + solve(root->right, 0);
}

int sumOfLeftLeaves(struct TreeNode* root) {
    return solve(root, 0);
}

int main() {
    struct TreeNode* root = createNode(3);
    root->left = createNode(9);
    root->right = createNode(20);
    root->right->left = createNode(15);
    root->right->right = createNode(7);

    int result = sumOfLeftLeaves(root);
    printf("%d", result);

    return 0;
}