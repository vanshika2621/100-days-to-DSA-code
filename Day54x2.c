#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Queue for BFS
struct Queue {
    struct TreeNode** arr;
    int front, rear, size, capacity;
};

struct Queue* createQueue(int capacity) {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->capacity = capacity;
    q->front = q->size = 0;
    q->rear = capacity - 1;
    q->arr = (struct TreeNode**)malloc(capacity * sizeof(struct TreeNode*));
    return q;
}

int isEmpty(struct Queue* q) {
    return q->size == 0;
}

void enqueue(struct Queue* q, struct TreeNode* node) {
    q->rear = (q->rear + 1) % q->capacity;
    q->arr[q->rear] = node;
    q->size++;
}

struct TreeNode* dequeue(struct Queue* q) {
    struct TreeNode* node = q->arr[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size--;
    return node;
}

// Main function
int** zigzagLevelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    if (!root) {
        *returnSize = 0;
        return NULL;
    }

    int capacity = 1000;
    int** result = (int**)malloc(capacity * sizeof(int*));
    *returnColumnSizes = (int*)malloc(capacity * sizeof(int));
    *returnSize = 0;

    struct Queue* q = createQueue(1000);
    enqueue(q, root);

    int leftToRight = 1;

    while (!isEmpty(q)) {
        int levelSize = q->size;
        int* level = (int*)malloc(levelSize * sizeof(int));

        for (int i = 0; i < levelSize; i++) {
            struct TreeNode* node = dequeue(q);

            int index = leftToRight ? i : (levelSize - 1 - i);
            level[index] = node->val;

            if (node->left)
                enqueue(q, node->left);
            if (node->right)
                enqueue(q, node->right);
        }

        result[*returnSize] = level;
        (*returnColumnSizes)[*returnSize] = levelSize;
        (*returnSize)++;

        leftToRight = !leftToRight; // flip direction
    }

    return result;
}