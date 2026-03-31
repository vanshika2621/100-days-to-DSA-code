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

struct Node* build(int inorder[], int postorder[], int inStart, int inEnd, int* postIndex, int map[]) {
    if (inStart > inEnd) return NULL;

    int val = postorder[*postIndex];
    (*postIndex)--;

    struct Node* root = newNode(val);

    int pos = map[val];

    root->right = build(inorder, postorder, pos + 1, inEnd, postIndex, map);
    root->left = build(inorder, postorder, inStart, pos - 1, postIndex, map);

    return root;
}

void preorder(struct Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

int main() {
    int n;
    scanf("%d", &n);

    int inorder[n], postorder[n];

    for (int i = 0; i < n; i++) scanf("%d", &inorder[i]);
    for (int i = 0; i < n; i++) scanf("%d", &postorder[i]);

    int map[1000];
    for (int i = 0; i < n; i++) map[inorder[i]] = i;

    int postIndex = n - 1;

    struct Node* root = build(inorder, postorder, 0, n - 1, &postIndex, map);

    preorder(root);

    return 0;
}