#include <iostream>
using namespace std;

// Node of Doubly Linked List
class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int data) {
        this->data = data;
        this->prev = nullptr;
        this->next = nullptr;
    }
};

// Doubly Linked List
class DoublyLinkedList {
public:
    Node* head;
    Node* tail;

    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    // -------------------------------------------------------
    // INSERT AT START
    // -------------------------------------------------------
    void insertAtStart(int data) {

        Node* newNode = new Node(data);

        // If list is empty
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
            return;
        }

        // Connect new node with current head
        newNode->next = head;
        head->prev = newNode;

        // Move head to new node
        head = newNode;
    }

    // -------------------------------------------------------
    // INSERT AT END
    // -------------------------------------------------------
    void insertAtEnd(int data) {

        Node* newNode = new Node(data);

        // If list is empty
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
            return;
        }

        // Connect new node with current tail
        tail->next = newNode;
        newNode->prev = tail;

        // Move tail to new node
        tail = newNode;
    }

    // -------------------------------------------------------
    // DISPLAY FORWARD
    // -------------------------------------------------------
    void displayForward() {

        Node* temp = head;

        while (temp != nullptr) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }

        cout << "NULL" << endl;
    }

    // -------------------------------------------------------
    // DISPLAY BACKWARD
    // -------------------------------------------------------
    void displayBackward() {

        Node* temp = tail;

        while (temp != nullptr) {
            cout << temp->data << " <-> ";
            temp = temp->prev;
        }

        cout << "NULL" << endl;
    }
};

// -------------------------------------------------------
// MAIN FUNCTION
// -------------------------------------------------------
int main() {

    DoublyLinkedList dll;

    // Insert at start
    dll.insertAtStart(20);
    dll.insertAtStart(10);

    // Insert at end
    dll.insertAtEnd(30);
    dll.insertAtEnd(40);

    cout << "Forward Traversal: ";
    dll.displayForward();

    cout << "Backward Traversal: ";
    dll.displayBackward();

    return 0;
}