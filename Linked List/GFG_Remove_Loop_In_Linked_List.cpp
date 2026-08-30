/*
GFG Problem: Remove Loop in Linked List

Approach:
1. Use Floyd's Cycle Detection Algorithm.
2. Move slow by 1 step and fast by 2 steps.
3. If they don't meet, there is no loop.
4. If they meet, reset slow to head.
5. Move slow and fast one step at a time.
6. When they meet, they are at the starting node of the loop.
7. Move fast until fast->next becomes the loop starting node.
8. Set fast->next = NULL to remove the loop.

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
    void removeLoop(Node* head)
    {
        Node* slow = head;
        Node* fast = head;

        // Step 1: Detect loop
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
                break;
        }

        // No loop
        if (fast == nullptr || fast->next == nullptr)
            return;

        // Step 2: Find starting point of loop
        slow = head;

        while (slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }

        // Step 3: Find last node of loop
        while (fast->next != slow)
        {
            fast = fast->next;
        }

        // Step 4: Remove loop
        fast->next = nullptr;
    }
};