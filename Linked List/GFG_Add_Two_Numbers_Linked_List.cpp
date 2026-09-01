/*
===========================================================
GFG: Add Two Numbers Represented by Linked Lists
===========================================================

Each linked list represents a number.

Example:

List 1: 2 -> 4 -> 3
List 2: 5 -> 6 -> 4

Numbers:
243 + 564 = 807

Output:
8 -> 0 -> 7

===========================================================
APPROACH:
===========================================================

1. Reverse both linked lists recursively.
2. Add the numbers digit by digit.
3. Maintain a carry.
4. Create a new linked list for the result.
5. Reverse the result list.
6. Remove leading zeros from the result.
7. Return the result.

===========================================================
IMPORTANT:
===========================================================

For GFG's Node structure, the value is stored in:

    node->data

not:

    node->val

===========================================================
TIME COMPLEXITY:
O(n + m)

SPACE COMPLEXITY:
O(n + m)

O(n + m) is used for the result nodes.
Recursive reverse also uses call-stack space.
===========================================================
*/

#include <iostream>
using namespace std;


// Node Structure
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


// Solution
class Solution
{
public:

    // Recursive function to reverse linked list
    Node* reverse(Node* curr, Node* prev)
    {
        if (curr == nullptr)
            return prev;

        Node* front = curr->next;

        curr->next = prev;

        return reverse(front, curr);
    }


    Node* addTwoLists(Node* head1, Node* head2)
    {
        // Reverse both lists
        Node* first = reverse(head1, nullptr);
        Node* second = reverse(head2, nullptr);

        Node* l1 = first;
        Node* l2 = second;


        // Dummy node for result
        Node* dummy = new Node(0);
        Node* tail = dummy;

        int carry = 0;


        // Add both numbers
        while (l1 || l2 || carry)
        {
            int sum = carry;

            if (l1)
            {
                sum += l1->data;
                l1 = l1->next;
            }

            if (l2)
            {
                sum += l2->data;
                l2 = l2->next;
            }


            int digit = sum % 10;
            carry = sum / 10;


            // Create result node
            tail->next = new Node(digit);
            tail = tail->next;
        }


        // Remove dummy node
        Node* result = dummy->next;


        // Reverse result
        result = reverse(result, nullptr);


        // Remove leading zeros
        while (result->data == 0 && result->next != nullptr)
        {
            result = result->next;
        }


        return result;
    }
};