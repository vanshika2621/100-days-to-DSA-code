#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int x) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = x;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct Node* buildTree(int v[], int n) {
    if (n == 0 || v[0] == -1) return NULL;

    struct Node** q = (struct Node**)malloc(n * sizeof(struct Node*));
    int front = 0, rear = 0;

    struct Node* root = newNode(v[0]);
    q[rear++] = root;

    int i = 1;

    while (front < rear && i < n) {
        struct Node* curr = q[front++];

        if (i < n && v[i] != -1) {
            curr->left = newNode(v[i]);
            q[rear++] = curr->left;
        }
        i++;

        if (i < n && v[i] != -1) {
            curr->right = newNode(v[i]);
            q[rear++] = curr->right;
        }
        i++;
    }

    return root;
}

void rightView(struct Node* root) {
    if (!root) return;

    struct Node** q = (struct Node**)malloc(1000 * sizeof(struct Node*));
    int front = 0, rear = 0;

    q[rear++] = root;

    while (front < rear) {
        int size = rear - front;

        for (int i = 0; i < size; i++) {
            struct Node* curr = q[front++];

            if (i == size - 1)
                printf("%d ", curr->data);

            if (curr->left)
                q[rear++] = curr->left;

            if (curr->right)
                q[rear++] = curr->right;
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int* v = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) scanf("%d", &v[i]);

    struct Node* root = buildTree(v, n);
    rightView(root);

    return 0;
}
