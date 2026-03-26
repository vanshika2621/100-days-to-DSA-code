#include <stdio.h>
#include <stdlib.h>

// Binary Tree Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Stack structure
struct Stack {
    int top;
    int capacity;
    struct Node** array;
};

// Create stack
struct Stack* createStack(int capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (struct Node**)malloc(capacity * sizeof(struct Node*));
    return stack;
}

// Check if empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Push
void push(struct Stack* stack, struct Node* node) {
    stack->array[++stack->top] = node;
}

// Pop
struct Node* pop(struct Stack* stack) {
    if (isEmpty(stack))
        return NULL;
    return stack->array[stack->top--];
}

// Create new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Zigzag traversal
void zigzagTraversal(struct Node* root) {
    if (root == NULL)
        return;

    struct Stack* s1 = createStack(100); // left to right
    struct Stack* s2 = createStack(100); // right to left

    push(s1, root);

    while (!isEmpty(s1) || !isEmpty(s2)) {

        // Left to Right
        while (!isEmpty(s1)) {
            struct Node* temp = pop(s1);
            printf("%d ", temp->data);

            if (temp->left)
                push(s2, temp->left);
            if (temp->right)
                push(s2, temp->right);
        }

        // Right to Left
        while (!isEmpty(s2)) {
            struct Node* temp = pop(s2);
            printf("%d ", temp->data);

            if (temp->right)
                push(s1, temp->right);
            if (temp->left)
                push(s1, temp->left);
        }
    }
}

// Driver code
int main() {
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    printf("Zigzag Traversal: ");
    zigzagTraversal(root);

    return 0;
}