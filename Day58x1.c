#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

int search(int inorder[], int start, int end, int val) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == val) return i;
    }
    return -1;
}

struct Node* build(int preorder[], int inorder[], int* preIndex, int inStart, int inEnd) {
    if (inStart > inEnd) return NULL;

    int rootVal = preorder[*preIndex];
    (*preIndex)++;
    struct Node* root = newNode(rootVal);

    if (inStart == inEnd) return root;

    int inIndex = search(inorder, inStart, inEnd, rootVal);

    root->left = build(preorder, inorder, preIndex, inStart, inIndex - 1);
    root->right = build(preorder, inorder, preIndex, inIndex + 1, inEnd);

    return root;
}

void postorder(struct Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main() {
    int n;
    scanf("%d", &n);

    int preorder[n], inorder[n];
    for (int i = 0; i < n; i++) scanf("%d", &preorder[i]);
    for (int i = 0; i < n; i++) scanf("%d", &inorder[i]);

    int preIndex = 0;

    struct Node* root = build(preorder, inorder, &preIndex, 0, n - 1);

    postorder(root);

    return 0;
}