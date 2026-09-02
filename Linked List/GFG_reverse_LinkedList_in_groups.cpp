/*
    GFG: Reverse a Linked List in Groups

    Requirement:
    Reverse every k nodes.
    If the number of nodes left at the end is less than k,
    those remaining nodes are ALSO reversed.

    Example:
    1 -> 2 -> 3 -> 4 -> 5, k = 3
    Output:
    3 -> 2 -> 1 -> 5 -> 4

    APPROACH:
    1. Create a dummy node before the head.
    2. 'first' points to the node before the current group.
    3. Take the first node of the group as 'second'.
    4. Reverse exactly k nodes OR until NULL, whichever comes first.
       This is what makes the GFG version reverse the leftover group.
    5. Connect the reversed group back.
    6. Move 'first' to the old first node ('second'), which is now
       the tail of the reversed group.
    7. Repeat until all nodes are processed.

    TIME:  O(n)
    SPACE: O(1) auxiliary space
*/

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


class Solution {
public:
    Node* reverseKGroup(Node* head, int k) {
        Node* dummy = new Node(0);
        dummy->next = head;

        Node* first = dummy;

        while (first->next != nullptr) {

            int x = k;

            Node* second = first->next;
            Node* prev = first;
            Node* curr = first->next;

            // Reverse k nodes, or all remaining nodes if fewer than k exist.
            while (x && curr != nullptr) {
                Node* front = curr->next;

                curr->next = prev;
                prev = curr;
                curr = front;

                x--;
            }

            // Connect previous part to reversed group.
            first->next = prev;

            // Connect tail of reversed group to remaining list.
            second->next = curr;

            // Move to the next group.
            first = second;
        }

        return dummy->next;
    }
};

/*
    NOTE:
    GFG Node normally uses:
        int data;
        Node* next;

    So this solution uses Node and node->data indirectly through the
    existing GFG Node definition. Paste only the Solution class into GFG.
*/
