#include <stdio.h>
#include <stdlib.h>

// Definition of tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// LCA function
struct Node* LCA(struct Node* root, int n1, int n2) {
    if (root == NULL)
        return NULL;

    // If either n1 or n2 matches root
    if (root->data == n1 || root->data == n2)
        return root;

    // Search in left and right subtree
    struct Node* left = LCA(root->left, n1, n2);
    struct Node* right = LCA(root->right, n1, n2);

    // If both sides return non-null → this is LCA
    if (left && right)
        return root;

    // Otherwise return non-null child
    return (left != NULL) ? left : right;
}