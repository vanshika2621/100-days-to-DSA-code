#include <stdio.h>
#include <stdlib.h>

// Tree Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Queue Node (stores tree node + horizontal distance)
struct QNode {
    struct Node* node;
    int hd;
};

// Create new tree node
struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// Simple Queue implementation
struct QNode queue[1000];
int front = 0, rear = 0;

void enqueue(struct Node* node, int hd) {
    queue[rear].node = node;
    queue[rear].hd = hd;
    rear++;
}

struct QNode dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front == rear;
}

// Build tree from level order input
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct Node* root = newNode(arr[0]);

    struct Node* q[1000];
    int f = 0, r = 0;
    q[r++] = root;

    int i = 1;
    while (i < n) {
        struct Node* curr = q[f++];

        // Left child
        if (arr[i] != -1) {
            curr->left = newNode(arr[i]);
            q[r++] = curr->left;
        }
        i++;

        if (i >= n) break;

        // Right child
        if (arr[i] != -1) {
            curr->right = newNode(arr[i]);
            q[r++] = curr->right;
        }
        i++;
    }

    return root;
}

// Vertical Order Traversal
void verticalOrder(struct Node* root) {
    if (root == NULL) return;

    // Map using arrays (HD range assumption)
    int map[2000][100];
    int size[2000] = {0};

    int offset = 1000; // to handle negative HD

    enqueue(root, 0);

    while (!isEmpty()) {
        struct QNode temp = dequeue();
        struct Node* node = temp.node;
        int hd = temp.hd + offset;

        map[hd][size[hd]++] = node->data;

        if (node->left)
            enqueue(node->left, temp.hd - 1);

        if (node->right)
            enqueue(node->right, temp.hd + 1);
    }

    // Print from leftmost to rightmost
    for (int i = 0; i < 2000; i++) {
        if (size[i] > 0) {
            for (int j = 0; j < size[i]; j++) {
                printf("%d ", map[i][j]);
            }
            printf("\n");
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* root = buildTree(arr, n);

    verticalOrder(root);

    return 0;
}