/*
LeetCode Problem: Linked List Cycle

Approach:
Use Floyd's Cycle Detection Algorithm (Tortoise and Hare).

1. slow moves one node at a time.
2. fast moves two nodes at a time.
3. If there is a cycle, slow and fast will eventually meet.
4. If fast reaches NULL, there is no cycle.

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <iostream>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode* next;

    ListNode(int x)
    {
        val = x;
        next = nullptr;
    }
};

class Solution
{
public:
    bool hasCycle(ListNode* head)
    {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
            {
                return true;
            }
        }

        return false;
    }
};