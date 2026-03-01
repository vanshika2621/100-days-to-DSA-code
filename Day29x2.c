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

// Add two linked lists
struct Node* addTwoNumbers(struct Node* l1, struct Node* l2) {
    struct Node* dummy = createNode(0);
    struct Node* current = dummy;
    int carry = 0;

    while (l1 != NULL || l2 != NULL || carry != 0) {
        int sum = carry;

        if (l1 != NULL) {
            sum += l1->data;
            l1 = l1->next;
        }

        if (l2 != NULL) {
            sum += l2->data;
            l2 = l2->next;
        }

        carry = sum / 10;
        current->next = createNode(sum % 10);
        current = current->next;
    }

    struct Node* result = dummy->next;
    free(dummy);  // free dummy node
    return result;
}

// Display list
void display(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
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

// Main
int main() {
    struct Node* l1 = NULL;
    struct Node* l2 = NULL;
    struct Node* result = NULL;

    int n1, n2, value;

    printf("Enter number of digits in first number: ");
    scanf("%d", &n1);

    for (int i = 0; i < n1; i++) {
        printf("Enter digit: ");
        scanf("%d", &value);
        l1 = insertEnd(l1, value);
    }

    printf("Enter number of digits in second number: ");
    scanf("%d", &n2);

    for (int i = 0; i < n2; i++) {
        printf("Enter digit: ");
        scanf("%d", &value);
        l2 = insertEnd(l2, value);
    }

    printf("First Number: ");
    display(l1);

    printf("Second Number: ");
    display(l2);

    result = addTwoNumbers(l1, l2);

    printf("Sum: ");
    display(result);

    freeList(l1);
    freeList(l2);
    freeList(result);

    return 0;
}