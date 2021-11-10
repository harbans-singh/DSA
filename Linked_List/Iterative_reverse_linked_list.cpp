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
    cout << endl;
}

Node* iterativeReverse(Node* head) {
    Node* current = head;
    Node* prev = NULL;
    Node* next = NULL;
    while(current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

int main() {
    Node* head = NULL;
    frontInsert(head, 5);
    frontInsert(head, 6);
    frontInsert(head, 7);
    frontInsert(head, 8);
    frontInsert(head, 9);
    printList(head);
    head = iterativeReverse(head);
    printList(head);
    return 0;
}