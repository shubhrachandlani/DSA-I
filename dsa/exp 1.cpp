#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* createNode(int data) {
    Node* newNode = new Node();
    if (!newNode) {
        cout << "Memory error\n";
        return nullptr;
    }
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

// Function to insert a node at the beginning of the list
void insertAtBeginning(Node*& head, int data) {
    Node* newNode = createNode(data);
    newNode->next = head;
    head = newNode;
}

// Function to insert a node at the end of the list
void insertAtEnd(Node*& head, int data) {
    Node* newNode = createNode(data);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to delete a node from the beginning of the list
void deleteFromBeginning(Node*& head) {
    if (head == nullptr) {
        cout << "List is empty\n";
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
}

// Function to delete a node from the end of the list
void deleteFromEnd(Node*& head) {
    if (head == nullptr) {
        cout << "List is empty\n";
        return;
    }
    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }
    Node* temp = head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
}

// Function to traverse the list and print the elements
void traverseList(Node* head) {
    if (head == nullptr) {
        cout << "List is empty\n";
        return;
    }
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    Node* head = nullptr;

    // Insertion examples
    insertAtEnd(head, 10);
    insertAtEnd(head, 20);
    insertAtBeginning(head, 5);
    insertAtEnd(head, 30);

    cout << "List after insertion: ";
    traverseList(head);

    // Deletion examples
    deleteFromBeginning(head);
    cout << "List after deleting from beginning: ";
    traverseList(head);

    deleteFromEnd(head);
    cout << "List after deleting from end: ";
    traverseList(head);

    return 0;
}