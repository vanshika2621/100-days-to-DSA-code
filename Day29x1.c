#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Create new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert at end
struct Node* insertEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);

    if (head == NULL)
        return newNode;

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

// Rotate list right by k
struct Node* rotateRight(struct Node* head, int k) {
    if (head == NULL || head->next == NULL || k == 0)
        return head;

    struct Node* temp = head;
    int length = 1;

    // Find length
    while (temp->next != NULL) {
        temp = temp->next;
        length++;
    }

    // Make circular
    temp->next = head;

    // Effective rotations
    k = k % length;
    int stepsToNewHead = length - k;

    struct Node* newTail = head;

    for (int i = 1; i < stepsToNewHead; i++)
        newTail = newTail->next;

    struct Node* newHead = newTail->next;
    newTail->next = NULL;  // Break circle

    return newHead;
}

// Display list
void display(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Free memory
void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// Main function
int main() {
    struct Node* head = NULL;
    int n, value, k;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter value: ");
        scanf("%d", &value);
        head = insertEnd(head, value);
    }

    printf("Enter k: ");
    scanf("%d", &k);

    printf("Original List:\n");
    display(head);

    head = rotateRight(head, k);

    printf("Rotated List:\n");
    display(head);

    freeList(head);

    return 0;
}