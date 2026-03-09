#include <stdio.h>

#define MAX 100

int pq[MAX];
int size = -1;

// Insert element
void enqueue(int value) {
    if (size == MAX - 1) {
        printf("Queue Overflow\n");
        return;
    }
    size++;
    pq[size] = value;
}

// Find index of highest priority element (smallest value)
int findMin() {
    int min = 0;
    for (int i = 1; i <= size; i++) {
        if (pq[i] < pq[min]) {
            min = i;
        }
    }
    return min;
}

// Delete highest priority element
void dequeue() {
    if (size == -1) {
        printf("Queue Underflow\n");
        return;
    }

    int index = findMin();
    printf("Deleted element: %d\n", pq[index]);

    for (int i = index; i < size; i++) {
        pq[i] = pq[i + 1];
    }

    size--;
}

// Display queue
void display() {
    if (size == -1) {
        printf("Queue is empty\n");
        return;
    }

    printf("Priority Queue elements:\n");
    for (int i = 0; i <= size; i++) {
        printf("%d ", pq[i]);
    }
    printf("\n");
}

int main() {
    enqueue(30);
    enqueue(10);
    enqueue(50);
    enqueue(20);

    display();

    dequeue();
    display();

    return 0;
}