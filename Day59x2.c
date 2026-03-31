#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

struct TreeNode* build(int* inorder, int* postorder, int inStart, int inEnd, int* postIndex, int* map, int offset) {
    if (inStart > inEnd) return NULL;

    int val = postorder[*postIndex];
    (*postIndex)--;

    struct TreeNode* root = newNode(val);

    int pos = map[val + offset];

    root->right = build(inorder, postorder, pos + 1, inEnd, postIndex, map, offset);
    root->left = build(inorder, postorder, inStart, pos - 1, postIndex, map, offset);

    return root;
}

void preorder(struct TreeNode* root) {
    if (root == NULL) return;
    printf("%d ", root->val);
    preorder(root->left);
    preorder(root->right);
}

int main() {
    int n;
    scanf("%d", &n);

    int* inorder = (int*)malloc(sizeof(int) * n);
    int* postorder = (int*)malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++) scanf("%d", &inorder[i]);
    for (int i = 0; i < n; i++) scanf("%d", &postorder[i]);

    int offset = 3000;
    int size = 6001;
    int* map = (int*)malloc(sizeof(int) * size);

    for (int i = 0; i < n; i++) {
        map[inorder[i] + offset] = i;
    }

    int postIndex = n - 1;

    struct TreeNode* root = build(inorder, postorder, 0, n - 1, &postIndex, map, offset);

    preorder(root);

    free(inorder);
    free(postorder);
    free(map);

    return 0;
}