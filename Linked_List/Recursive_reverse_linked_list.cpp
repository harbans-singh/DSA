#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

void frontInsert(Node* &head, int data) {
    if(head == NULL) {
        head = new Node(data);
        return;
    }
    Node* temp = new Node(data);
    temp->next = head;
    head = temp;
}

void printList(Node* head) {
    while(head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}

Node* recursiveReverse(Node* head) {
    if(head->next == NULL || head == NULL) {
        return head;
    }
    Node* shead = recursiveReverse(head->next);
    head->next->next = head;
    head = NULL;
    return shead;
}

int main() {
    Node* head = NULL;
    frontInsert(head, 5);
    frontInsert(head, 6);
    frontInsert(head, 7);
    frontInsert(head, 8);
    frontInsert(head, 9);
    printList(head);
    head = recursiveReverse(head);
    printList(head);
    return 0;
}