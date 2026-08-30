/*
    GFG Problem: Delete Node at a Given Position

    Given the head of a linked list and an integer x,
    delete the node at position x and return the updated head.

    Positions use 1-based indexing.

    Example:
    Input:  10 -> 20 -> 30 -> 40 -> NULL
    x = 3

    Output: 10 -> 20 -> 40 -> NULL
*/

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

// --------------------------------------------------
// Approach 1: Iterative
// Time Complexity: O(n)
// Space Complexity: O(1)
// --------------------------------------------------

Node *deleteNode(Node *head, int x)
{
    // Empty list
    if (head == nullptr)
        return head;

    // Delete first node
    if (x == 1)
    {
        Node *temp = head;
        head = head->next;

        delete temp;

        return head;
    }

    Node *curr = head;
    Node *prev = nullptr;

    // Reach the node at position x
    for (int i = 1; i < x && curr != nullptr; i++)
    {
        prev = curr;
        curr = curr->next;
    }

    // Position does not exist
    if (curr == nullptr)
        return head;

    // Delete the node
    prev->next = curr->next;

    delete curr;

    return head;
}

// --------------------------------------------------
// Approach 2: Recursive
// Time Complexity: O(n)
// Space Complexity: O(n)
// --------------------------------------------------

Node *deleteNodeRecursive(Node *head, int x)
{
    // Empty list or invalid position
    if (head == nullptr)
        return head;

    // Delete first node
    if (x == 1)
    {
        Node *temp = head;
        head = head->next;

        delete temp;

        return head;
    }

    // Recursively move to the required position
    head->next = deleteNodeRecursive(head->next, x - 1);

    return head;
}

// --------------------------------------------------
// Print Linked List
// --------------------------------------------------

void printList(Node *head)
{
    Node *temp = head;

    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}