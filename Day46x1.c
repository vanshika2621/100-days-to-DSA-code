#include <stdio.h>
#include <stdlib.h>

// Tree Node
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Create new node
struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Queue structure
#define MAX 1000

struct TreeNode* queue[MAX];
int front = 0, rear = 0;

// Enqueue
void enqueue(struct TreeNode* node) {
    queue[rear++] = node;
}

// Dequeue
struct TreeNode* dequeue() {
    return queue[front++];
}

// Check if queue is empty
int isEmpty() {
    return front == rear;
}

// Level Order Traversal
void levelOrder(struct TreeNode* root) {
    if (root == NULL) return;

    enqueue(root);

    while (!isEmpty()) {
        int levelSize = rear - front;

        for (int i = 0; i < levelSize; i++) {
            struct TreeNode* node = dequeue();
            printf("%d ", node->val);

            if (node->left) enqueue(node->left);
            if (node->right) enqueue(node->right);
        }
        printf("\n"); // new level
    }
}

// Main function
int main() {
    /*
        Tree:
              3
             / \
            9  20
               / \
              15  7
    */

    struct TreeNode* root = createNode(3);
    root->left = createNode(9);
    root->right = createNode(20);
    root->right->left = createNode(15);
    root->right->right = createNode(7);

    printf("Level Order Traversal:\n");
    levelOrder(root);

    return 0;
}