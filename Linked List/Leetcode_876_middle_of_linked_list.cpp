/*
    LeetCode 876 - Middle of the Linked List

    Approaches practiced:
    1. Count the nodes and then traverse to the middle.
    2. Slow and Fast Pointer approach.

    Both approaches:
        Time  : O(n)
        Space : O(1)

    The Slow/Fast approach is better because it finds the middle
    in a single traversal.
*/

#include <iostream>
using namespace std;


// ============================================================
// Node Structure
// ============================================================

class Node
{
public:
    int data;
    Node* next;

    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};


// ============================================================
// Create Linked List
// ============================================================

Node* createList(int arr[], int n)
{
    if (n == 0)
        return NULL;

    Node* head = new Node(arr[0]);
    Node* tail = head;

    for (int i = 1; i < n; i++)
    {
        tail->next = new Node(arr[i]);
        tail = tail->next;
    }

    return head;
}


// ============================================================
// Print Linked List
// ============================================================

void printList(Node* head)
{
    Node* temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}


// ============================================================
// APPROACH 1
// Count the nodes first and then find the middle
// ============================================================
//
// Example:
//
// 1 -> 2 -> 3 -> 4 -> 5
//
// Number of nodes = 5
//
// 5 / 2 = 2
//
// Move 2 steps from head:
//
// 1 -> 2 -> 3
//          ^
//        middle
//
// For an even list:
//
// 1 -> 2 -> 3 -> 4 -> 5 -> 6
//
// 6 / 2 = 3
//
// Moving 3 steps gives node 4.
// This gives the SECOND middle node.
//
// Time  : O(n)
// Space : O(1)
// ============================================================

Node* middleUsingCount(Node* head)
{
    int count = 0;

    Node* temp = head;

    // Count the number of nodes
    while (temp != NULL)
    {
        temp = temp->next;
        count++;
    }

    // Move to the middle
    temp = head;

    count = count / 2;

    while (count)
    {
        temp = temp->next;
        count--;
    }

    return temp;
}


// ============================================================
// APPROACH 2
// Slow and Fast Pointer
// ============================================================
//
// slow moves 1 step
// fast moves 2 steps
//
// Example:
//
// 1 -> 2 -> 3 -> 4 -> 5
//
// Initially:
//
// slow = 1
// fast = 1
//
// After 1 iteration:
//
// slow = 2
// fast = 3
//
// After 2 iterations:
//
// slow = 3
// fast = 5
//
// When fast reaches the end,
// slow is at the middle.
//
// Time  : O(n)
// Space : O(1)
// ============================================================

Node* middleUsingSlowFast(Node* head)
{
    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}


// ============================================================
// Main
// ============================================================

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    Node* head = createList(arr, n);

    cout << "Linked List: ";
    printList(head);

    Node* middle1 = middleUsingCount(head);

    cout << "Middle using Count Approach: ";
    cout << middle1->data << endl;

    Node* middle2 = middleUsingSlowFast(head);

    cout << "Middle using Slow/Fast Approach: ";
    cout << middle2->data << endl;

    return 0;
}