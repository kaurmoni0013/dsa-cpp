/*
GFG Problem: Remove Duplicates from a Sorted Linked List

Approach:
1. Since the linked list is sorted, duplicate values will be next to each other.
2. Start from the head.
3. If the current node and next node have the same value,
   delete the next node.
4. Do not move temp after deleting because there may be
   more duplicate nodes.
5. Otherwise, move temp to the next node.

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

    Node(int x)
    {
        data = x;
        next = nullptr;
    }
};

class Solution
{
public:
    Node* removeDuplicates(Node* head)
    {
        if (head == nullptr)
            return head;

        Node* temp = head;

        while (temp != nullptr && temp->next != nullptr)
        {
            // Duplicate found
            if (temp->data == temp->next->data)
            {
                Node* curr = temp->next;

                temp->next = curr->next;

                delete curr;
            }
            else
            {
                temp = temp->next;
            }
        }

        return head;
    }
};