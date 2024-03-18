#include "Header.h"

void init(List& list) {
    list.head = NULL;
}

void printList(List& list) {
    node* p = list.head;
    while (p != NULL) {
        cout << p->data << "->";
        p = p->next;
    }
    cout << "->NULL" << endl;
}

void addHead(List& list, int x) {
    node* temp = new node;
    temp->data = x;
    temp->next = list.head;
    list.head = temp;
}

void addTail(List& list, int x) {
    node* p = list.head;
    while (p->next != NULL) {
        p = p->next;
    }
    node* temp = new node;
    temp->data = x;
    temp->next = NULL;
    p->next = temp;
}

void input(List& list, int n, int x) {
    cin >> x;
    addHead(list, x);
    for (int i = 1; i < n; i++) {
        cin >> x;
        addTail(list, x);
    }
}

node* merge(node* firstNode, node* secondNode) {
    node* merged = new node;
    node* temp = new node;

    merged = temp;

    while (firstNode != NULL && secondNode != NULL) {

        if (firstNode->data <= secondNode->data) {
            temp->next = firstNode;
            firstNode = firstNode->next;
        }

        else {
            temp->next = secondNode;
            secondNode = secondNode->next;
        }
        temp = temp->next;
    }


    while (firstNode != NULL) {
        temp->next = firstNode;
        firstNode = firstNode->next;
        temp = temp->next;
    }

    while (secondNode != NULL) {
        temp->next = secondNode;
        secondNode = secondNode->next;
        temp = temp->next;
    }

    return merged->next;
}


node* middle(node* head) {
    node* slow = head;
    node* fast = head->next;

    while (!slow->next && (!fast && !fast->next)) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}


node* sortLinkedList(node* head) {
    if (head->next == NULL) {
        return head;
    }
    node* mid = new node;
    node* head2 = new node;
    mid = middle(head);
    head2 = mid->next;
    mid->next = NULL;
    node* finalhead = merge(sortLinkedList(head), sortLinkedList(head2));
    return finalhead;
}