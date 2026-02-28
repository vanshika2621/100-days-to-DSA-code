#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

int main() {
    struct node *head = NULL, *temp = NULL, *newnode = NULL;
    int n, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("List is empty.\n");
        return 0;
    }

    for (i = 0; i < n; i++) {
        newnode = (struct node*)malloc(sizeof(struct node));
        
        if (newnode == NULL) {
            printf("Memory allocation failed.\n");
            return 1;
        }

        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if (head == NULL) {
            head = newnode;
            temp = head;
        } else {
            temp->next = newnode;
            temp = newnode;
        }
    }

    // Making it circular
    temp->next = head;

    // Traversal
    printf("\nCircular Linked List elements are:\n");

    temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);

    return 0;
}