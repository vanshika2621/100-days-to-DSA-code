#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

void enqueue(int value)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    if(front == NULL)
    {
        front = rear = newNode;
        rear->next = front;   // circular link
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
        rear->next = front;   // maintain circular structure
    }

    printf("Inserted: %d\n", value);
}

void dequeue()
{
    if(front == NULL)
    {
        printf("Queue is Empty\n");
        return;
    }

    struct Node *temp = front;

    if(front == rear)
    {
        front = rear = NULL;
    }
    else
    {
        front = front->next;
        rear->next = front;
    }

    printf("Deleted: %d\n", temp->data);
    free(temp);
}

void display()
{
    if(front == NULL)
    {
        printf("Queue is Empty\n");
        return;
    }

    struct Node *temp = front;

    printf("Queue: ");

    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while(temp != front);

    printf("\n");
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);

    display();

    dequeue();
    display();

    enqueue(40);
    display();

    return 0;
}