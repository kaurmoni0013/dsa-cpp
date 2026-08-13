/*
    LeetCode 206: Reverse Linked List

    Problem:
    Given the head of a singly linked list, reverse the list
    and return the reversed list.

    Example:
    Input:
        1 -> 2 -> 3 -> 4 -> 5 -> NULL

    Output:
        5 -> 4 -> 3 -> 2 -> 1 -> NULL


    Approaches:
    1. Array / Vector Approach
    2. Iterative Pointer Approach
    3. Recursive Pointer Approach
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// --------------------------------------------------
// Node Structure
// --------------------------------------------------

class Node
{
public:
    int data;
    Node* next;

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

// --------------------------------------------------
// Print Linked List
// --------------------------------------------------

void printList(Node* head)
{
    Node* temp = head;

    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

// ==================================================
// Approach 1: Array / Vector
//
// Time Complexity: O(n)
// Space Complexity: O(n)
// ==================================================

Node* reverseListUsingVector(Node* head)
{
    vector<int> num;

    Node* temp = head;

    // Store linked list values in vector
    while (temp != nullptr)
    {
        num.push_back(temp->data);
        temp = temp->next;
    }

    // Reverse the vector
    reverse(num.begin(), num.end());

    // Put reversed values back into linked list
    temp = head;

    int i = 0;

    while (temp != nullptr)
    {
        temp->data = num[i];

        i++;
        temp = temp->next;
    }

    return head;
}

// ==================================================
// Approach 2: Iterative
//
// Time Complexity: O(n)
// Space Complexity: O(1)
// ==================================================

Node* reverseListIterative(Node* head)
{
    Node* temp = nullptr;
    Node* curr;

    while (head)
    {
        // Save the next node
        curr = head->next;

        // Reverse the link
        head->next = temp;

        // Move temp forward
        temp = head;

        // Move head forward
        head = curr;
    }

    return temp;
}

// ==================================================
// Approach 3: Recursive
//
// Time Complexity: O(n)
// Space Complexity: O(n)
// ==================================================

Node* reverseListRecursive(Node* curr, Node* prev)
{
    // Base case
    if (curr == nullptr)
        return prev;

    // Save the next node
    Node* fut = curr->next;

    // Reverse the current node's link
    curr->next = prev;

    // Recursive call
    return reverseListRecursive(fut, curr);
}

// Wrapper function
Node* reverseListRecursive(Node* head)
{
    Node* prev = nullptr;

    return reverseListRecursive(head, prev);
}

// --------------------------------------------------
// Main
// --------------------------------------------------

int main()
{
    // Creating Linked List
    // 1 -> 2 -> 3 -> 4 -> 5 -> NULL

    Node* head = new Node(1);

    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    cout << "Original Linked List: ";
    printList(head);

    // --------------------------------------------------
    // Approach 1: Vector
    // --------------------------------------------------

    head = reverseListUsingVector(head);

    cout << "After Vector Approach: ";
    printList(head);

    // --------------------------------------------------
    // Approach 2: Iterative
    // --------------------------------------------------

    head = reverseListIterative(head);

    cout << "After Iterative Approach: ";
    printList(head);

    // --------------------------------------------------
    // Approach 3: Recursive
    // --------------------------------------------------

    head = reverseListRecursive(head);

    cout << "After Recursive Approach: ";
    printList(head);

    return 0;
}