/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include <stdlib.h>

// Stack implementation using array
#define MAX 1000

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    
    int stack1[MAX], stack2[MAX];
    int top1 = -1, top2 = -1;
    
    // Push all elements of l1 to stack1
    while (l1 != NULL) {
        stack1[++top1] = l1->val;
        l1 = l1->next;
    }
    
    // Push all elements of l2 to stack2
    while (l2 != NULL) {
        stack2[++top2] = l2->val;
        l2 = l2->next;
    }
    
    int carry = 0;
    struct ListNode* result = NULL;
    
    // Add until both stacks empty
    while (top1 >= 0 || top2 >= 0 || carry) {
        
        int sum = carry;
        
        if (top1 >= 0)
            sum += stack1[top1--];
        
        if (top2 >= 0)
            sum += stack2[top2--];
        
        carry = sum / 10;
        
        struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newNode->val = sum % 10;
        newNode->next = result;
        result = newNode;
    }
    
    return result;
}