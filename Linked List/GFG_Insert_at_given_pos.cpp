/*
GFG Problem: Insert at a Given Position in Doubly Linked List

Approach:
1. If the list is empty, create a new node.
2. Move to the p-th node.
3. Create a new node with value x.
4. Insert the new node after the p-th node.
5. Update both next and prev pointers.

Time Complexity: O(p)
Space Complexity: O(1)
*/

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;
    Node* prev;

    Node(int x)
    {
        data = x;
        next = nullptr;
        prev = nullptr;
    }
};

class Solution
{
public:
    Node* insertAtPos(Node* head, int pos, int x)
    {
        // If list is empty
        if (head == nullptr)
            return new Node(x);

        Node* curr = head;

        // Move to the p-th node
        while (pos--)
        {
            curr = curr->next;
        }

        Node* temp = new Node(x);

        // Connect temp with curr and next node
        temp->next = curr->next;
        temp->prev = curr;

        curr->next = temp;

        // If there is a next node
        if (temp->next != nullptr)
            temp->next->prev = temp;

        return head;
    }
};