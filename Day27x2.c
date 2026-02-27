#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

void insert(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (head == NULL) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

void createLoop(Node* head, int pos) {
    if (pos < 0) return;

    Node* loopNode = NULL;
    Node* temp = head;
    int index = 0;

    while (temp->next != NULL) {
        if (index == pos)
            loopNode = temp;
        temp = temp->next;
        index++;
    }

    if (index == pos)
        loopNode = temp;

    if (loopNode != NULL)
        temp->next = loopNode;
}

bool removeLoop(Node* head) {
    if (head == NULL || head->next == NULL)
        return false;

    Node* slow = head;
    Node* fast = head;
    bool loopExists = false;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            loopExists = true;
            break;
        }
    }

    if (!loopExists)
        return false;

    slow = head;

    if (slow == fast) {
        while (fast->next != slow)
            fast = fast->next;
    } else {
        while (slow->next != fast->next) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    fast->next = NULL;
    return true;
}

int main() {
    int n, val, pos;
    Node* head = NULL;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> val;
        insert(head, val);
    }

    cin >> pos;

    createLoop(head, pos);

    if (removeLoop(head))
        cout << "true";
    else
        cout << "false";

    return 0;
}