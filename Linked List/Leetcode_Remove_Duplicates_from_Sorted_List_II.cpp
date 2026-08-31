/*
===========================================================
LeetCode 82: Remove Duplicates from Sorted List II
===========================================================

QUESTION:

Given the head of a sorted linked list, delete all nodes that
have duplicate numbers, leaving only distinct numbers.

Example:

1 -> 2 -> 2 -> 3

Output:

1 -> 3

Example:

1 -> 2 -> 2 -> 3 -> 3 -> 4

Output:

1 -> 4

===========================================================
APPROACH:
===========================================================

Use a dummy node and two pointers: prev and temp.

1. Create a dummy node before head.

       dummy -> head

2. prev points to the last node confirmed to be unique.

3. temp traverses the list.

4. Since the list is sorted, duplicate values are adjacent.

5. If:

       temp->val == temp->next->val

   then temp belongs to a duplicate group.

6. Use curr to skip the complete duplicate group.

7. Connect:

       prev->next = curr

8. Move temp to curr.

9. If temp is unique:

       prev = temp
       temp = temp->next

10. Return dummy->next.

===========================================================
TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(1)
===========================================================
*/

#include <iostream>
using namespace std;


// Node Structure
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


// Solution
class Solution
{
public:

    ListNode* deleteDuplicates(ListNode* head)
    {
        if (head == nullptr)
            return head;

        // Create dummy node
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        // temp = current node
        ListNode* temp = head;

        // prev = last confirmed unique node
        ListNode* prev = dummy;

        while (temp != nullptr && temp->next != nullptr)
        {
            // Duplicate found
            if (temp->val == temp->next->val)
            {
                ListNode* curr = temp->next;

                // Skip complete duplicate group
                while (curr != nullptr && temp->val == curr->val)
                {
                    curr = curr->next;
                }

                // Remove duplicate group
                prev->next = curr;

                // Continue from next different value
                temp = curr;
            }
            else
            {
                // Current node is unique
                prev = temp;
                temp = temp->next;
            }
        }

        return dummy->next;
    }
};