/*
GFG Problem: Length of Loop

Approach:
1. Use Floyd's Cycle Detection Algorithm.
2. Move slow by 1 step and fast by 2 steps.
3. If slow and fast don't meet, there is no loop.
4. If they meet, keep fast at the meeting point.
5. Move slow one step at a time until it reaches fast again.
6. Count the number of nodes visited.

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
    int lengthOfLoop(Node* head)
    {
        Node* slow = head;
        Node* fast = head;

        // Detect loop
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
                break;
        }

        // No loop
        if (fast == nullptr || fast->next == nullptr)
            return 0;

        // Count loop length
        int count = 1;
        slow = slow->next;

        while (slow != fast)
        {
            count++;
            slow = slow->next;
        }

        return count;
    }
};