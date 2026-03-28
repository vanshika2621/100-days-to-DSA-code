#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define structure
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

// Function to check mirror
bool isMirror(struct Node* t1, struct Node* t2) {
    // Both NULL → symmetric
    if (t1 == NULL && t2 == NULL)
        return true;

    // One NULL → not symmetric
    if (t1 == NULL || t2 == NULL)
        return false;

    // Check values and recursive mirror
    return (t1->data == t2->data) &&
           isMirror(t1->left, t2->right) &&
           isMirror(t1->right, t2->left);
}

// Main function to check symmetry
bool isSymmetric(struct Node* root) {
    if (root == NULL)
        return true;

    return isMirror(root->left, root->right);
}

// Example usage
int main() {
    /*
            1
          /   \
         2     2
        / \   / \
       3   4 4   3
    */

    struct Node* root = newNode(1);
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