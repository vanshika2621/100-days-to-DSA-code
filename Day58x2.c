#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

int findIndex(int* inorder, int start, int end, int val) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == val) return i;
    }
    return -1;
}

struct TreeNode* build(int* preorder, int* inorder, int* preIndex, int inStart, int inEnd) {
    if (inStart > inEnd) return NULL;

    struct TreeNode* root = newNode(preorder[*preIndex]);
    (*preIndex)++;

    if (inStart == inEnd) return root;

    int inIndex = findIndex(inorder, inStart, inEnd, root->val);

    root->left = build(preorder, inorder, preIndex, inStart, inIndex - 1);
    root->right = build(preorder, inorder, preIndex, inIndex + 1, inEnd);

    return root;
}

void postorder(struct TreeNode* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->val);
}

int main() {
    int n;
    scanf("%d", &n);

    int preorder[n], inorder[n];

    for (int i = 0; i < n; i++) scanf("%d", &preorder[i]);
    for (int i = 0; i < n; i++) scanf("%d", &inorder[i]);

    int preIndex = 0;

    struct TreeNode* root = build(preorder, inorder, &preIndex, 0, n - 1);

    postorder(root);

    return 0;
}