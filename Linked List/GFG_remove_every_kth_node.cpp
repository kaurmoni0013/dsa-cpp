/*
============================================================
GFG - Delete Every Kth Node
============================================================

Problem:
Given a linked list and an integer k, delete every kth node
from the linked list.

Example:

Input:
1 -> 2 -> 3 -> 4 -> 5
k = 2

Output:
1 -> 3 -> 5


Approach:
Use three important variables:

    prev  -> previous node
    curr  -> current node
    count -> position/count of current node

When count == k:

    1. Delete curr
    2. Connect prev to curr->next
    3. Move curr to the next node
    4. Reset count to 1

Time  : O(n)
Space : O(1)

============================================================
*/

#include <iostream>
using namespace std;


// ============================================================
// Node
// ============================================================

class Node
{
public:

    int data;
    Node* next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
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
// Delete Every Kth Node
// ============================================================

Node* deleteK(Node* head, int k)
{
    // --------------------------------------------------------
    // If k = 1, every node is deleted.
    // --------------------------------------------------------

    if (k == 1)
        return NULL;


    Node* prev = NULL;
    Node* curr = head;

    int count = 1;


    // --------------------------------------------------------
    // Traverse the linked list
    // --------------------------------------------------------

    while (curr)
    {
        // ----------------------------------------------------
        // If current node is the kth node
        // ----------------------------------------------------

        if (count == k)
        {
            Node* temp = curr;


            // Connect previous node to next node
            prev->next = curr->next;


            // Move curr to the next node
            curr = prev->next;


            // Delete kth node
            delete temp;


            // Restart counting
            count = 1;
        }


        // ----------------------------------------------------
        // Normal movement
        // ----------------------------------------------------

        else
        {
            prev = curr;

            curr = curr->next;

            count++;
        }
    }


    return head;
}


// ============================================================
// Main
// ============================================================

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};

    int n = sizeof(arr) / sizeof(arr[0]);

    int k = 3;


    Node* head = createList(arr, n);


    cout << "Original List: ";
    printList(head);


    head = deleteK(head, k);


    cout << "After Deleting Every " << k << "th Node: ";
    printList(head);


    return 0;
}