#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

struct TreeNode* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct TreeNode** queue = (struct TreeNode**)malloc(n * sizeof(struct TreeNode*));
    int front = 0, rear = 0;

    struct TreeNode* root = createNode(arr[0]);
    queue[rear++] = root;

    int i = 1;
    while (i < n) {
        struct TreeNode* current = queue[front++];

        if (i < n && arr[i] != -1) {
            current->left = createNode(arr[i]);
            queue[rear++] = current->left;
        }
        i++;

        if (i < n && arr[i] != -1) {
            current->right = createNode(arr[i]);
            queue[rear++] = current->right;
        }
        i++;
    }

    free(queue);
    return root;
}

struct TreeNode* searchBST(struct TreeNode* root, int val) {
    while (root != NULL) {
        if (root->val == val) return root;
        else if (val < root->val) root = root->left;
        else root = root->right;
    }
    return NULL;
}

void printLevelOrder(struct TreeNode* root) {
    if (!root) {
        printf("[]\n");
        return;
    }

    struct TreeNode** queue = (struct TreeNode**)malloc(5000 * sizeof(struct TreeNode*));
    int front = 0, rear = 0;

    queue[rear++] = root;

    printf("[");
    while (front < rear) {
        struct TreeNode* node = queue[front++];
        printf("%d", node->val);

        if (front < rear || node->left || node->right)
            printf(",");

        if (node->left) queue[rear++] = node->left;
        if (node->right) queue[rear++] = node->right;
    }
    printf("]\n");

    free(queue);
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int val;
    scanf("%d", &val);

    struct TreeNode* root = buildTree(arr, n);
    struct TreeNode* result = searchBST(root, val);

    printLevelOrder(result);

    return 0;
}