#include <stdio.h>
#include <stdlib.h>

#define MAX 10000

typedef struct {
    int stack[MAX];
    int minStack[MAX];
    int top;
} MinStack;

MinStack* minStackCreate() {
    MinStack* obj = (MinStack*)malloc(sizeof(MinStack));
    obj->top = -1;
    return obj;
}

void minStackPush(MinStack* obj, int val) {
    obj->top++;
    obj->stack[obj->top] = val;

    if (obj->top == 0 || val <= obj->minStack[obj->top - 1])
        obj->minStack[obj->top] = val;
    else
        obj->minStack[obj->top] = obj->minStack[obj->top - 1];
}

void minStackPop(MinStack* obj) {
    if (obj->top >= 0)
        obj->top--;
}

int minStackTop(MinStack* obj) {
    return obj->stack[obj->top];
}

int minStackGetMin(MinStack* obj) {
    return obj->minStack[obj->top];
}

void minStackFree(MinStack* obj) {
    free(obj);
}