/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    if (!root) {
        *returnSize = 0;
        return NULL;
    }

    // Queue for BFS
    struct TreeNode* queue[2000];
    int front = 0, rear = 0;

    queue[rear++] = root;

    int** result = (int**)malloc(sizeof(int*) * 2000);
    *returnColumnSizes = (int*)malloc(sizeof(int) * 2000);

    int levelCount = 0;

    while (front < rear) {
        int size = rear - front;  // nodes at current level

        result[levelCount] = (int*)malloc(sizeof(int) * size);
        (*returnColumnSizes)[levelCount] = size;

        for (int i = 0; i < size; i++) {
            struct TreeNode* curr = queue[front++];

            result[levelCount][i] = curr->val;

            if (curr->left)
                queue[rear++] = curr->left;

            if (curr->right)
                queue[rear++] = curr->right;
        }

        levelCount++;
    }

    *returnSize = levelCount;
    return result;
}