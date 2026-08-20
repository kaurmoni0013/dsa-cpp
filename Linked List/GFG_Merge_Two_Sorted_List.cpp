/*
GFG Problem: Merge Two Sorted Linked Lists

Approach:
1. Create a dummy node to simplify the merging process.
2. Maintain a tail pointer to the last node of the merged list.
3. Compare the values of both sorted lists.
4. Attach the smaller node to the merged list.
5. Move the corresponding list pointer forward.
6. When one list becomes empty, attach the remaining nodes
   of the other list.
7. Skip the dummy node and return the actual head.

Time Complexity: O(n + m)
Space Complexity: O(1) auxiliary space
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
    Node* sortedMerge(Node* head1, Node* head2)
    {
        // Dummy node
        Node* head = new Node(0);
        Node* tail = head;

        while (head1 && head2)
        {
            if (head1->data <= head2->data)
            {
                tail->next = head1;
                head1 = head1->next;
            }
            else
            {
                tail->next = head2;
                head2 = head2->next;
            }

            tail = tail->next;
        }

        // Attach remaining nodes
        if (head1)
            tail->next = head1;
        else
            tail->next = head2;

        // Skip dummy node
        head = head->next;

        return head;
    }
};