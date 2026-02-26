#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

int main() {
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;
    int n, value;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        printf("Enter value: ");
        scanf("%d", &value);

        // Dynamic memory allocation
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;
        newNode->prev = NULL;

        // If list is empty
        if(head == NULL) {
            head = newNode;
        }
        else {
            temp = head;

            // Traverse to last node
            while(temp->next != NULL) {
                temp = temp->next;
            }

            temp->next = newNode;
            newNode->prev = temp;
        }
    }

    // Forward Traversal
    printf("\nForward Traversal: ");
    temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    // Backward Traversal
    printf("\nBackward Traversal: ");
    if(head != NULL) {
        temp = head;

        // Move to last node
        while(temp->next != NULL) {
            temp = temp->next;
        }

        while(temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->prev;
        }
    }

    return 0;
}