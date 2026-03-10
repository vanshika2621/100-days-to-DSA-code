#include <stdio.h>
#define MAX 100

int deque[MAX];
int front = -1, rear = -1;

/* Check if deque is full */
int isFull() {
    if ((front == 0 && rear == MAX-1) || (front == rear + 1))
        return 1;
    return 0;
}

/* Check if deque is empty */
int isEmpty() {
    if (front == -1)
        return 1;
    return 0;
}

/* Insert at front */
void push_front(int value) {
    if (isFull()) {
        printf("Deque Overflow\n");
        return;
    }

    if (front == -1) {
        front = rear = 0;
    }
    else if (front == 0) {
        front = MAX - 1;
    }
    else {
        front--;
    }

    deque[front] = value;
}

/* Insert at rear */
void push_back(int value) {
    if (isFull()) {
        printf("Deque Overflow\n");
        return;
    }

    if (front == -1) {
        front = rear = 0;
    }
    else if (rear == MAX - 1) {
        rear = 0;
    }
    else {
        rear++;
    }

    deque[rear] = value;
}

/* Delete from front */
void pop_front() {
    if (isEmpty()) {
        printf("Deque Underflow\n");
        return;
    }

    printf("Deleted element: %d\n", deque[front]);

    if (front == rear) {
        front = rear = -1;
    }
    else if (front == MAX - 1) {
        front = 0;
    }
    else {
        front++;
    }
}

/* Delete from rear */
void pop_back() {
    if (isEmpty()) {
        printf("Deque Underflow\n");
        return;
    }

    printf("Deleted element: %d\n", deque[rear]);

    if (front == rear) {
        front = rear = -1;
    }
    else if (rear == 0) {
        rear = MAX - 1;
    }
    else {
        rear--;
    }
}

/* Display deque */
void display() {
    int i;

    if (isEmpty()) {
        printf("Deque is empty\n");
        return;
    }

    printf("Deque elements: ");

    i = front;
    while (i != rear) {
        printf("%d ", deque[i]);
        i = (i + 1) % MAX;
    }

    printf("%d\n", deque[rear]);
}

/* Main function */
int main() {
    push_back(10);
    push_back(20);
    push_front(5);
    push_front(2);

    display();

    pop_front();
    pop_back();

    display();

    return 0;
}