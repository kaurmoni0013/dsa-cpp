/*
GFG Problem: Reverse a Doubly Linked List

Approach:
1. Traverse the list using curr.
2. Swap next and prev of every node.
3. After swapping, curr->prev points to the next
   node that needs to be processed.
4. Update head with curr.
5. Return the new head.

Time Complexity: O(n)
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
    Node* reverse(Node* head)
    {
        Node* curr = head;

        while (curr != nullptr)
        {
            swap(curr->prev, curr->next);

            head = curr;

            curr = curr->prev;
        }

        return head;
    }
};