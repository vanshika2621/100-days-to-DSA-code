#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

struct TreeNode* buildTree(int arr[], int n) {
    if (n == 0) return NULL;

    struct TreeNode** nodes = (struct TreeNode**)malloc(n * sizeof(struct TreeNode*));

    for (int i = 0; i < n; i++) {
        if (arr[i] == -1)
            nodes[i] = NULL;
        else
            nodes[i] = newNode(arr[i]);
    }

    for (int i = 0; i < n; i++) {
        if (nodes[i] != NULL) {
            int left = 2 * i + 1;
            int right = 2 * i + 2;

            if (left < n)
                nodes[i]->left = nodes[left];
            if (right < n)
                nodes[i]->right = nodes[right];
        }
    }

    struct TreeNode* root = nodes[0];
    free(nodes);
    return root;
}

int cameras;

int dfs(struct TreeNode* root) {
    if (!root) return 2;

    int left = dfs(root->left);
    int right = dfs(root->right);

    if (left == 0 || right == 0) {
        cameras++;
        return 1;
    }

    if (left == 1 || right == 1)
        return 2;

    return 0;
}

int minCameraCover(struct TreeNode* root) {
    cameras = 0;
    if (dfs(root) == 0)
        cameras++;
    return cameras;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct TreeNode* root = buildTree(arr, n);

    printf("%d\n", minCameraCover(root));

    return 0;
}