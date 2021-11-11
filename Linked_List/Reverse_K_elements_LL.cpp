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

Node* KrecursiveReverse(Node* head, int k) {
    if(head == NULL) {
        return NULL;
    }
    Node* current = head;
    Node* prev = NULL;
    Node* next = NULL;
    int count {1};
    while(current != NULL && count <= k) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }
    Node* shead = KrecursiveReverse(current, k);
    head->next = shead;
    return prev;
}

int main() {
    Node* head = NULL;
    int k {0};
    cout << "Enter number of elements to reverse: ";
    cin >> k;
    frontInsert(head, 11);
    frontInsert(head, 10);
    frontInsert(head, 9);
    frontInsert(head, 8);
    frontInsert(head, 7);
    frontInsert(head, 6);
    frontInsert(head, 5);
    frontInsert(head, 4);
    frontInsert(head, 3);
    frontInsert(head, 2);
    frontInsert(head, 1);
    printList(head);
    head = KrecursiveReverse(head, k);
    printList(head);
    return 0;
}