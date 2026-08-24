#include <iostream>
using namespace std;

/*
    LeetCode 2 - Add Two Numbers
    Difficulty: Medium
    Topic: Linked List

    Idea:
    The digits are stored in reverse order.

    Example:
    l1 = 2 -> 4 -> 3   represents 342
    l2 = 5 -> 6 -> 4   represents 465

    Result:
    7 -> 0 -> 8        represents 807


    Core Formula:

        sum = digit1 + digit2 + carry

        digit = sum % 10
        carry = sum / 10
*/


struct ListNode {
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};


ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

    // Dummy node makes result-list construction easier
    ListNode* dummy = new ListNode(0);
    ListNode* tail = dummy;

    int carry = 0;

    // Continue while either list has nodes
    // or a carry is still remaining
    while (l1 || l2 || carry) {

        int sum = carry;

        // Add digit from first number
        if (l1) {
            sum += l1->val;
            l1 = l1->next;
        }

        // Add digit from second number
        if (l2) {
            sum += l2->val;
            l2 = l2->next;
        }

        // Extract digit and carry
        int digit = sum % 10;
        carry = sum / 10;

        // Add digit to result list
        tail->next = new ListNode(digit);
        tail = tail->next;
    }

    // Dummy node is not part of the answer
    return dummy->next;
}


/*
    Example:

    l1 = 2 -> 4 -> 3
    l2 = 5 -> 6 -> 4

    Step 1:
        2 + 5 = 7
        digit = 7
        carry = 0

    Step 2:
        4 + 6 = 10
        digit = 0
        carry = 1

    Step 3:
        3 + 4 + 1 = 8
        digit = 8
        carry = 0

    Result:

        7 -> 0 -> 8


    Complexity:

        Time  : O(max(n, m))
        Space : O(max(n, m))
                  (result linked list)
*/