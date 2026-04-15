#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node *next;
};

//  create a new node
struct Node* createValue(int value) {
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));

    if (n == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }

    n->data = value;
    n->next = NULL;
    return n;
}

//insert at end
void insertEnd(struct Node **head, struct Node **tail, int value) {
    struct Node *newNode = createValue(value);

    if (*head == NULL) {
        *head = newNode;
        *tail = newNode;
    } else {
        (*tail)->next = newNode;
        *tail = newNode;
    }
}

// display the list
void display(struct Node *head) {
    struct Node *temp = head;

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// delete a node from head of the linked list
struct Node *deletenodehead(struct Node* head){
     if(head == NULL || head -> next == NULL){
        printf("Linked list is empty")
        return NULL ;
    }
    struct Node *temp = head;
    head = head -> next ;
    free(temp); 
    return head;
}

// delete a node from Tail of the linked list
struct Node *deletenodetail(struct Node* head){
    if(head == NULL || head -> next == NULL){
        printf("Linked list is empty")
        return NULL ;
    }
    if(head == tail){
        free(head);
    }
    struct Node *temp = head;
    while(temp -> next != tail){
        temp = temp -> next ;
    }
    free(temp -> next);
    temp -> next = NULL ;
    return head;
}
// delete a node from 


int main() {
    struct Node *head = NULL;
    struct Node *tail = NULL;
    int value;
    char choice;

    do {
        printf("Enter data: ");
        scanf("%d", &value);

        insertEnd(&head, &tail, value);

        printf("Do you want to continue? (y/n): ");
        scanf(" %c", &choice);

    } while (choice == 'y' || choice == 'Y');

    printf("\nLinked List: ");
    display(head);

    return 0;
}