#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* deleteFirstOccurrence(struct Node* head, int key) {
    
    if (head == NULL) {
        return head;
    }

    // If first node contains key
    if (head->data == key) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    struct Node* current = head;

    while (current->next != NULL && current->next->data != key) {
        current = current->next;
    }

    if (current->next != NULL) {
        struct Node* temp = current->next;
        current->next = temp->next;
        free(temp);
    }

    return head;
}