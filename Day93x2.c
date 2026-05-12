#include <stdio.h>

#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

// Insert operation
void enqueue(int value)
{
    if(rear == MAX - 1)
    {
        printf("Queue Overflow\n");
    }
    else
    {
        if(front == -1)
        {
            front = 0;
        }

        rear++;
        queue[rear] = value;

        printf("%d inserted into queue\n", value);
    }
}

// Delete operation
void dequeue()
{
    if(front == -1 || front > rear)
    {
        printf("Queue Underflow\n");
    }
    else
    {
        printf("%d deleted from queue\n", queue[front]);
        front++;
    }
}

// Display queue
void display()
{
    int i;

    if(front == -1 || front > rear)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Queue elements are:\n");

        for(i = front; i <= rear; i++)
        {
            printf("%d\n", queue[i]);
        }
    }
}

int main()
{
    enqueue(5);
    enqueue(10);
    enqueue(15);

    display();

    dequeue();

    display();

    return 0;
}