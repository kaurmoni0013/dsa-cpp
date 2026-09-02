/*
    LeetCode 25: Reverse Nodes in k-Group

    Requirement:
    Reverse every group of exactly k nodes.
    If fewer than k nodes remain at the end,
    DO NOT reverse them.

    Example:
    1 -> 2 -> 3 -> 4 -> 5, k = 3
    Output:
    3 -> 2 -> 1 -> 4 -> 5

    APPROACH:
    1. Create a dummy node before head.
    2. 'first' points to the node before the current group.
    3. Before reversing, check whether at least k nodes exist.
       - If fewer than k exist, return the answer without reversing.
    4. Reverse exactly k nodes.
    5. Connect the reversed group back.
    6. Move 'first' to the old first node ('second'), now the tail
       of the reversed group.
    7. Repeat.

    TIME:  O(n)
    SPACE: O(1) auxiliary space
*/
class ListNode
{
public:
    int data;
    ListNode* next;

    ListNode(int x)
    {
        data = x;
        next = nullptr;
    }
};


class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* first = dummy;

        while (first->next != nullptr) {

            // STEP 1: Check whether k nodes are available.
            ListNode* check = first->next;

            for (int i = 0; i < k; i++) {
                if (check == nullptr) {
                    // Fewer than k nodes remain.
                    // LeetCode requires them to stay unchanged.
                    return dummy->next;
                }

                check = check->next;
            }

            // STEP 2: Reverse exactly k nodes.
            int x = k;

            ListNode* second = first->next;
            ListNode* prev = first;
            ListNode* curr = first->next;

            while (x && curr != nullptr) {

                ListNode* front = curr->next;

                curr->next = prev;
                prev = curr;
                curr = front;

                x--;
            }

            // STEP 3: Connect the reversed group.
            first->next = prev;
            second->next = curr;

            // STEP 4: Move to the next group.
            first = second;
        }

        return dummy->next;
    }
};

/*
    IMPORTANT DIFFERENCE FROM GFG:

    GFG:
        1 -> 2 -> 3 -> 4 -> 5, k=3
        3 -> 2 -> 1 -> 5 -> 4

    LeetCode 25:
        1 -> 2 -> 3 -> 4 -> 5, k=3
        3 -> 2 -> 1 -> 4 -> 5

    The ONLY conceptual difference is the k-node availability check.
*/
