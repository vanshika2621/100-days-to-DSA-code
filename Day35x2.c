#include <stdio.h>
#define MAX 100

int stack1[MAX], stack2[MAX];
int top1 = -1, top2 = -1;

void push(int x)
{
    stack1[++top1] = x;
}

int pop()
{
    if(top2 == -1)
    {
        while(top1 != -1)
        {
            stack2[++top2] = stack1[top1--];
        }
    }

    if(top2 == -1)
    {
        printf("Queue is empty\n");
        return -1;
    }

    return stack2[top2--];
}

int peek()
{
    if(top2 == -1)
    {
        while(top1 != -1)
        {
            stack2[++top2] = stack1[top1--];
        }
    }

    if(top2 == -1)
    {
        printf("Queue is empty\n");
        return -1;
    }

    return stack2[top2];
}

int empty()
{
    if(top1 == -1 && top2 == -1)
        return 1;
    return 0;
}

int main()
{
    push(1);
    push(2);
    push(3);

    printf("Front element: %d\n", peek());

    printf("Removed: %d\n", pop());
    printf("Removed: %d\n", pop());

    if(empty())
        printf("Queue is empty\n");
    else
        printf("Queue is not empty\n");

    return 0;
}