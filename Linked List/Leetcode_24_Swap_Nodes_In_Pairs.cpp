/*
LeetCode Problem: 24. Swap Nodes in Pairs

Problem:
Given a linked list, swap every two adjacent nodes and
return the modified list.

Example:

Input:
1 -> 2 -> 3 -> 4 -> 5

Output:
2 -> 1 -> 4 -> 3 -> 5


============================================================
APPROACH 1: RECURSIVE
============================================================

Idea:
1. Take the first two nodes.
2. Swap them by changing their next pointers.
3. Recursively swap the remaining list.
4. Connect the first node with the result of recursion.

Time Complexity: O(n)
Space Complexity: O(n) - recursion stack


============================================================
APPROACH 2: ITERATIVE
============================================================

Idea:
1. Maintain curr as the first node of the current pair.
2. Maintain prev to connect the previous swapped pair.
3. Swap the current two nodes using pointers.
4. Connect the previous pair with the current pair.
5. Move to the next pair.

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <iostream>
using namespace std;


// ============================================================
// NODE STRUCTURE
// ============================================================

class Node
{
public:
    int data;
    Node* next;

    Node(int x)
    {
        data = x;
        next = nullptr;
    }
};


// ============================================================
// APPROACH 1: RECURSIVE
// ============================================================

Node* swapPairsRecursive(Node* head)
{
    // 0 or 1 node
    if (head == nullptr || head->next == nullptr)
        return head;

    Node* first = head;
    Node* second = head->next;

    // Swap first pair
    first->next = second->next;
    second->next = first;

    // Swap remaining pairs
    first->next = swapPairsRecursive(first->next);

    // Second becomes new head
    return second;
}


// ============================================================
// APPROACH 2: ITERATIVE
// ============================================================

Node* swapPairsIterative(Node* head)
{
    // 0 or 1 node
    if (head == nullptr || head->next == nullptr)
        return head;

    Node* prev = nullptr;
    Node* curr = head;

    while (curr != nullptr && curr->next != nullptr)
    {
        Node* first = curr;
        Node* second = curr->next;

        // Swap the pair
        first->next = second->next;
        second->next = first;

        // Connect previous pair
        if (prev != nullptr)
        {
            prev->next = second;
        }
        else
        {
            // First swapped pair becomes new head
            head = second;
        }

        // Move to next pair
        prev = first;
        curr = first->next;
    }

    return head;
}


// ============================================================
// DISPLAY
// ============================================================

void display(Node* head)
{
    while (head != nullptr)
    {
        cout << head->data;

        if (head->next != nullptr)
            cout << " -> ";

        head = head->next;
    }

    cout << endl;
}


// ============================================================
// MAIN
// ============================================================

int main()
{
    Node* head = new Node(1);

    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    cout << "Original List: ";
    display(head);


    // Recursive
    Node* recursiveResult = swapPairsRecursive(head);

    cout << "After Recursive Swap: ";
    display(recursiveResult);


    // Create a fresh list for iterative approach
    Node* head2 = new Node(1);

    head2->next = new Node(2);
    head2->next->next = new Node(3);
    head2->next->next->next = new Node(4);
    head2->next->next->next->next = new Node(5);

    // Iterative
    Node* iterativeResult = swapPairsIterative(head2);

    cout << "After Iterative Swap: ";
    display(iterativeResult);


    return 0;
}