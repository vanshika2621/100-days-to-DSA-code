// Function to reverse a linked list
struct ListNode* reverse(struct ListNode* head) {
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;
    struct ListNode* nextNode = NULL;

    while (curr != NULL) {
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }

    return prev;
}

bool isPalindrome(struct ListNode* head) {
    if (head == NULL || head->next == NULL)
        return true;

    struct ListNode *slow = head, *fast = head;

    // Step 1: Find middle
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Step 2: Reverse second half
    slow = reverse(slow);

    struct ListNode *first = head;
    struct ListNode *second = slow;

    // Step 3: Compare both halves
    while (second != NULL) {
        if (first->val != second->val)
            return false;

        first = first->next;
        second = second->next;
    }

    return true;
}