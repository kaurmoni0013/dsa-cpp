/*
============================================================
LeetCode 19 - Remove Nth Node From End of List
============================================================

Problem:
Given the head of a linked list, remove the nth node from
the end of the list and return its head.

Example:

Input:
1 -> 2 -> 3 -> 4 -> 5
n = 2

Output:
1 -> 2 -> 3 -> 5


Approaches Implemented:

1. Length / Counting Approach
2. Fast and Slow Pointer Approach (without Dummy Node)

------------------------------------------------------------
Approach 1:
Time  : O(n)
Space : O(1)

Approach 2:
Time  : O(n)
Space : O(1)
============================================================
*/

#include <iostream>
using namespace std;



// Node

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

// Create Linked List

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
// Count Length and Find Position
// ============================================================

Node* removeNthUsingCount(Node* head, int n)
{
    int k = 0;

    Node* temp = head;
    Node* curr = head;

   
    // Step 1: Find length of linked list
  

    while (temp)
    {
        temp = temp->next;
        k++;
    }


    // If n == k, the head itself needs to be deleted


    if (n == k)
    {
        temp = head;

        head = head->next;

        delete temp;

        return head;
    }
     // Convert nth node from end into position from beginning

    k -= n;

    k--;
    // Move temp to the node before the node to delete

    temp = head;

    while (k--)
    {
        temp = temp->next;
    }
    // Delete the next node
    
    curr = temp;

    temp = temp->next;

    curr->next = temp->next;

    delete temp;


    return head;
}


// ============================================================
// APPROACH 2
// Fast and Slow Pointer - WITHOUT Dummy Node
// ============================================================

Node* removeNthUsingFastSlow(Node* head, int n)
{
    if (head == NULL)
        return head;


    Node* fast = head;
    Node* slow = head;


    // --------------------------------------------------------
    // Move fast n nodes ahead
    // --------------------------------------------------------

    for (int i = 0; i < n; i++)
    {
        fast = fast->next;
    }


    // --------------------------------------------------------
    // If fast becomes NULL,
    // the node to delete is the head
    // --------------------------------------------------------

    if (fast == NULL)
    {
        Node* temp = head;

        head = head->next;

        delete temp;

        return head;
    }


    // --------------------------------------------------------
    // Move both pointers
    //
    // When fast reaches the end,
    // slow will be at the node before the target.
    // --------------------------------------------------------

    while (fast->next != NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }

    // Delete node after slow

    Node* temp = slow->next;

    slow->next = temp->next;

    delete temp;


    return head;
}

// Main

int main()
{
    int arr[] = {1, 2, 3, 4, 5};

    int n = sizeof(arr) / sizeof(arr[0]);

    int removePosition = 2;

    // Approach 1
   

    Node* head1 = createList(arr, n);

    cout << "Original List: ";
    printList(head1);

    head1 = removeNthUsingCount(head1, removePosition);

    cout << "After Removing Nth Node (Count Approach): ";
    printList(head1);


    // Approach 2
    

    Node* head2 = createList(arr, n);

    head2 = removeNthUsingFastSlow(head2, removePosition);

    cout << "After Removing Nth Node (Fast/Slow Approach): ";
    printList(head2);


    return 0;
}