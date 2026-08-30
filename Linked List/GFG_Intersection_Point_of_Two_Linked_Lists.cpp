/*
GFG Problem: Intersection Point of Two Linked Lists

Approach:
1. Find the length of both linked lists.
2. Find the difference between their lengths.
3. Move the pointer of the longer list forward by the difference.
4. Now both pointers have the same number of nodes remaining.
5. Move both pointers together.
6. The first node where both pointers are equal is the
   intersection point.
7. If there is no intersection, both pointers eventually
   become NULL.

Important:
Compare node addresses/pointers, not their data values.

Time Complexity: O(n + m)
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
    Node* intersectPoint(Node* head1, Node* head2)
    {
        Node* temp1 = head1;
        Node* temp2 = head2;

        int count1 = 0;
        int count2 = 0;

        // Find length of first list
        while (temp1)
        {
            temp1 = temp1->next;
            count1++;
        }

        // Find length of second list
        while (temp2)
        {
            temp2 = temp2->next;
            count2++;
        }

        temp1 = head1;
        temp2 = head2;

        // Move pointer of longer list ahead
        if (count1 > count2)
        {
            int step = count1 - count2;

            while (step--)
                temp1 = temp1->next;
        }
        else
        {
            int step = count2 - count1;

            while (step--)
                temp2 = temp2->next;
        }

        // Find intersection
        while (temp1 != temp2)
        {
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        return temp1;
    }
};