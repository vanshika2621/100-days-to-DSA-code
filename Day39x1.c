#include <stdio.h>

#define MAX 100

int heap[MAX];
int size = 0;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* Heapify upwards after insertion */
void heapifyUp(int index)
{
    int parent = (index - 1) / 2;

    while (index > 0 && heap[parent] > heap[index])
    {
        swap(&heap[parent], &heap[index]);
        index = parent;
        parent = (index - 1) / 2;
    }
}

/* Heapify downwards after deletion */
void heapifyDown(int index)
{
    int left, right, smallest;

    while (1)
    {
        left = 2 * index + 1;
        right = 2 * index + 2;
        smallest = index;

        if (left < size && heap[left] < heap[smallest])
            smallest = left;

        if (right < size && heap[right] < heap[smallest])
            smallest = right;

        if (smallest != index)
        {
            swap(&heap[index], &heap[smallest]);
            index = smallest;
        }
        else
            break;
    }
}

/* Insert element */
void insert(int value)
{
    if (size == MAX)
    {
        printf("Heap is full\n");
        return;
    }

    heap[size] = value;
    heapifyUp(size);
    size++;
}

/* Delete minimum element */
int deleteMin()
{
    if (size == 0)
    {
        printf("Heap is empty\n");
        return -1;
    }

    int min = heap[0];
    heap[0] = heap[size - 1];
    size--;

    heapifyDown(0);

    return min;
}

/* Display heap */
void display()
{
    for (int i = 0; i < size; i++)
        printf("%d ", heap[i]);
    printf("\n");
}

int main()
{
    insert(40);
    insert(20);
    insert(10);
    insert(30);
    insert(50);

    printf("Min Heap: ");
    display();

    printf("Deleted Min: %d\n", deleteMin());

    printf("Heap after deletion: ");
    display();

    return 0;
}