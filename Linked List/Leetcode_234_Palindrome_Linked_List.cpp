/*
============================================================
LeetCode 234 - Palindrome Linked List
============================================================

Problem:
Given the head of a singly linked list, determine whether
the linked list is a palindrome.

A palindrome reads the same forward and backward.

Example:

Input:
1 -> 2 -> 2 -> 1

Output:
true


Approaches Implemented:
1. Vector / Array Approach
2. Middle + Reverse Second Half Approach

------------------------------------------------------------
Approach 1:
Time  : O(n)
Space : O(n)

Approach 2:
Time  : O(n)
Space : O(1)
============================================================
*/

#include <iostream>
#include <vector>
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

    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}


// ============================================================
// APPROACH 1
// Store Linked List Values in Vector
// ============================================================

bool isPalindromeUsingVector(Node* head)
{
    Node* curr = head;

    vector<int> temp;


    // --------------------------------------------------------
    // Store all linked list values in vector
    // --------------------------------------------------------

    while (curr)
    {
        temp.push_back(curr->data);

        curr = curr->next;
    }


    // --------------------------------------------------------
    // Two pointers
    // One starts from beginning
    // One starts from end
    // --------------------------------------------------------

    int s = 0;
    int e = temp.size() - 1;


    while (s < e)
    {
        // If values don't match, it is not a palindrome
        if (temp[s] != temp[e])
        {
            return false;
        }

        s++;
        e--;
    }


    return true;
}


// ============================================================
// APPROACH 2
// Middle + Reverse Second Half
// O(1) Extra Space
// ============================================================

bool isPalindromeOptimized(Node* head)
{
    // Empty list or one-node list is always a palindrome
    if (head == NULL || head->next == NULL)
    {
        return true;
    }


    // --------------------------------------------------------
    // Step 1: Find the middle using slow and fast pointers
    // --------------------------------------------------------

    Node* slow = head;
    Node* fast = head;


    while (fast && fast->next)
    {
        slow = slow->next;

        fast = fast->next->next;
    }


    // --------------------------------------------------------
    // Step 2: Reverse the second half
    //
    // slow points to the beginning of the second half.
    // --------------------------------------------------------

    Node* curr = slow;
    Node* prev = NULL;


    while (curr)
    {
        Node* next = curr->next;

        curr->next = prev;

        prev = curr;

        curr = next;
    }


    // --------------------------------------------------------
    // Step 3: Compare first half and reversed second half
    // --------------------------------------------------------

    Node* p1 = head;
    Node* p2 = prev;


    while (p2)
    {
        if (p1->data != p2->data)
        {
            return false;
        }

        p1 = p1->next;
        p2 = p2->next;
    }


    return true;
}


// ============================================================
// Main
// ============================================================

int main()
{
    int arr[] = {1, 2, 2, 1};

    int n = sizeof(arr) / sizeof(arr[0]);


    Node* head1 = createList(arr, n);
    Node* head2 = createList(arr, n);


    cout << "Linked List: ";
    printList(head1);


    // --------------------------------------------------------
    // Approach 1
    // --------------------------------------------------------

    if (isPalindromeUsingVector(head1))
    {
        cout << "Vector Approach: Palindrome" << endl;
    }
    else
    {
        cout << "Vector Approach: Not Palindrome" << endl;
    }


    // --------------------------------------------------------
    // Approach 2
    // --------------------------------------------------------

    if (isPalindromeOptimized(head2))
    {
        cout << "Optimized Approach: Palindrome" << endl;
    }
    else
    {
        cout << "Optimized Approach: Not Palindrome" << endl;
    }


    return 0;
}  