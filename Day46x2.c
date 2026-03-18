#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    if (root == NULL) {
        *returnSize = 0;
        return NULL;
    }

    // Queue
    struct TreeNode* queue[2000];
    int front = 0, rear = 0;

    // Result storage
    int** result = (int**)malloc(sizeof(int*) * 2000);
    *returnColumnSizes = (int*)malloc(sizeof(int) * 2000);

    enqueue:
    queue[rear++] = root;

    int levelCount = 0;

    while (front < rear) {
        int levelSize = rear - front;

        // Allocate space for current level
        result[levelCount] = (int*)malloc(sizeof(int) * levelSize);
        (*returnColumnSizes)[levelCount] = levelSize;

        for (int i = 0; i < levelSize; i++) {
            struct TreeNode* node = queue[front++];
            result[levelCount][i] = node->val;

            if (node->left) queue[rear++] = node->left;
            if (node->right) queue[rear++] = node->right;
        }

        levelCount++;
    }

    *returnSize = levelCount;
    return result;
}