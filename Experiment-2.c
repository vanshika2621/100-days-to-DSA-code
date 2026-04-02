#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

// Enqueue Operation (Customer Enters)
void enqueue(int customer) {
    if (rear == MAX - 1) {
        printf("Queue Overflow! Shop is full.\n");
        return;
    }
    if (front == -1)
        front = 0;
    rear++;
    queue[rear] = customer;
    printf("Customer %d entered the shop.\n", customer);
}

// Dequeue Operation (Customer Served)
void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow! No customers.\n");
        return;
    }
    printf("Customer %d served by Sales Assistant.\n", queue[front]);
    front++;
}

// Display Queue
void display() {
    if (front == -1 || front > rear) {
        printf("No customers in queue.\n");
        return;
    }
    printf("Customers in queue: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    int choice, customer;

    while (1) {
        printf("\n1. Add Customer\n2. Serve Customer\n3. Display Queue\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Customer ID: ");
                scanf("%d", &customer);
                enqueue(customer);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }
}
