
#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        next = NULL;
    }
};

// Create linked list recursively
Node* insertAtEnd(vector<int>& arr, int index) {
    if (index == arr.size())
        return NULL;

    Node* temp = new Node(arr[index]);
    temp->next = insertAtEnd(arr, index + 1);

    return temp;
}

// Insert a new node at a given position
Node* insertAtPosition(Node* head, int position, int value) {
    Node* newNode = new Node(value);

    // Insert at the beginning
    if (position == 1) {
        newNode->next = head;
        return newNode;
    }

    Node* temp = head;

    // Move to the node before the required position
    position--;
    while(position--) {
        temp = temp->next;
    }

    // Invalid position
    if (temp == NULL) {
        delete newNode;
        cout << "Invalid position!" << endl;
        return head;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}

// Print linked list
void printList(Node* head) {
    Node* temp = head;

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

int main() {
    vector<int> arr = {2, 3, 4, 5, 6};

    // Create linked list
    Node* head = insertAtEnd(arr, 0);

    cout << "Original linked list: ";
    printList(head);

    // Input position and value
    int position, value;

    cout << "Enter the position and value to insert: ";
    cin >> position >> value;

    // Insert node
    head = insertAtPosition(head, position, value);

    cout << "Linked list after insertion: ";
    printList(head);

    return 0;
}

