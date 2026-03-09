#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *heap;
    int size;
    int k;
} KthLargest;

// swap function
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// heapify up
void heapifyUp(KthLargest* obj, int index) {
    while(index > 0) {
        int parent = (index - 1) / 2;
        if(obj->heap[parent] > obj->heap[index]) {
            swap(&obj->heap[parent], &obj->heap[index]);
            index = parent;
        } else break;
    }
}

// heapify down
void heapifyDown(KthLargest* obj, int index) {
    while(1) {
        int left = 2*index + 1;
        int right = 2*index + 2;
        int smallest = index;

        if(left < obj->size && obj->heap[left] < obj->heap[smallest])
            smallest = left;

        if(right < obj->size && obj->heap[right] < obj->heap[smallest])
            smallest = right;

        if(smallest != index) {
            swap(&obj->heap[index], &obj->heap[smallest]);
            index = smallest;
        } else break;
    }
}

// create object
KthLargest* kthLargestCreate(int k, int* nums, int numsSize) {
    KthLargest* obj = (KthLargest*)malloc(sizeof(KthLargest));
    obj->heap = (int*)malloc(sizeof(int) * k);
    obj->size = 0;
    obj->k = k;

    for(int i = 0; i < numsSize; i++) {
        // reuse add logic
        if(obj->size < k) {
            obj->heap[obj->size++] = nums[i];
            heapifyUp(obj, obj->size - 1);
        } else if(nums[i] > obj->heap[0]) {
            obj->heap[0] = nums[i];
            heapifyDown(obj, 0);
        }
    }

    return obj;
}

// add new value
int kthLargestAdd(KthLargest* obj, int val) {
    if(obj->size < obj->k) {
        obj->heap[obj->size++] = val;
        heapifyUp(obj, obj->size - 1);
    }
    else if(val > obj->heap[0]) {
        obj->heap[0] = val;
        heapifyDown(obj, 0);
    }

    return obj->heap[0];
}

// free memory
void kthLargestFree(KthLargest* obj) {
    free(obj->heap);
    free(obj);
}