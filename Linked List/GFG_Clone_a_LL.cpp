/*
============================================================
Problem: Clone a Linked List with Random Pointer
============================================================

Given a linked list where each node contains:
    1. data
    2. next pointer
    3. random pointer

The random pointer can point to any node in the list or NULL.

Clone the linked list and return the head of the cloned list.

Example:

Original:
    10 ------> 20 ------> 30
     |          |          |
     |random    |random    |random
     v          v          v
    30         NULL       10

Cloned:
    10' -----> 20' -----> 30'
     |          |          |
     v          v          v
    30'        NULL       10'


============================================================
Approaches
============================================================

Approach 1: Using a Search Function
-----------------------------------
1. Create a normal copy of the linked list.
2. For every original node, find the node pointed to by random.
3. Find the corresponding copied node by traversing both lists.
4. Set the copied node's random pointer.

Time Complexity: O(n^2)
Space Complexity: O(n) for the cloned list.

Approach 2: Using unordered_map
--------------------------------
1. Create a copy of every node.
2. Store:
       original node -> copied node
   in an unordered_map.
3. Traverse the original list again.
4. Set:
       copy->next = map[original->next]
       copy->random = map[original->random]

Time Complexity: O(n)
Extra Space: O(n) for the map
Space for cloned list: O(n)

Approach 3: Interleaving / In-place Mapping
-------------------------------------------
This is the approach used below.

We avoid using an unordered_map.

Phase 1: Create copied nodes and insert them after
         their corresponding original nodes.

Before:
    10 -> 20 -> 30 -> NULL

After:
    10 -> 10' -> 20 -> 20' -> 30 -> 30' -> NULL


Phase 2: Set random pointers.

For an original node:
    original->random

the corresponding copied node is:
    original->random->next

because every original node is immediately followed
by its copied node.

Example:
    10 -> 10' -> 20 -> 20' -> 30 -> 30'

If:
    10->random = 30

then:
    10->random->next = 30'

Therefore:
    10'->random = 30'


Phase 3: Separate the original and copied lists.

Before:
    10 -> 10' -> 20 -> 20' -> 30 -> 30'

After:

Original:
    10 -> 20 -> 30 -> NULL

Clone:
    10' -> 20' -> 30' -> NULL


============================================================
Complexity of This Solution
============================================================

Time Complexity: O(n)

Reason:
- Phase 1 visits every node once.
- Phase 2 visits every node once.
- Phase 3 visits every node once.

Total = O(n) + O(n) + O(n) = O(n)

Auxiliary Space: O(1)

No unordered_map or extra array is used.

The O(n) space occupied by the newly created cloned nodes
is required as output and is not counted as auxiliary space.


============================================================
Code
============================================================
*/

/* Structure of Linked List Node
class Node {
  public:
    int data;
    Node* next;
    Node* random;

    Node(int x) {
        data = x;
        next = random = nullptr;
    }
};*/
// Structure of Linked List Node
class Node {
  public:
    int data;
    Node* next;
    Node* random;

    Node(int x) {
        data = x;
        next = random = nullptr;
    };
class Solution {
  public:

    Node* cloneLinkedList(Node* head) {

        // Edge case: empty linked list
        if (head == nullptr)
            return nullptr;


        // -------------------------------------------------
        // PHASE 1: Create clone nodes and interleave them
        // -------------------------------------------------

        Node* curr1 = head;

        while (curr1) {

            Node* front1 = curr1->next;

            // Create copy of current node
            Node* curr2 = new Node(curr1->data);

            // Insert copy immediately after original
            curr1->next = curr2;
            curr2->next = front1;

            // Move to next original node
            curr1 = front1;
        }


        // -------------------------------------------------
        // PHASE 2: Set random pointers of cloned nodes
        // -------------------------------------------------

        curr1 = head;

        while (curr1) {

            Node* curr2 = curr1->next;

            // If original random exists,
            // copied random is random->next
            if (curr1->random) {
                curr2->random = curr1->random->next;
            }

            // Move to next original node
            curr1 = curr2->next;
        }


        // -------------------------------------------------
        // PHASE 3: Separate original and cloned lists
        // -------------------------------------------------

        curr1 = head;
        Node* headCopy = head->next;

        while (curr1) {

            Node* curr2 = curr1->next;

            // Restore original list
            curr1->next = curr2->next;

            // Connect cloned node to next cloned node
            if (curr2->next) {
                curr2->next = curr2->next->next;
            }

            // Move to next original node
            curr1 = curr1->next;
        }


        return headCopy;
    }
};


/*
============================================================
Important Pointer Logic
============================================================

After Phase 1:

    Original       Copy
       |             |
       v             v
    10 -> 10' -> 20 -> 20' -> 30 -> 30'


For random:

    original->random->next

gives the COPY of the random target.

Example:

    10.random = 30

Then:

    10.random->next
         |
         v
        30'

Therefore:

    10'.random = 30'


============================================================
Common Mistakes
============================================================

1. Forgetting to handle:
       head == NULL

2. Moving curr1 inside an if(random) block.

   Wrong:

       if (curr1->random) {
           ...
           curr1 = ...
       }

   If random == NULL, curr1 never moves and the loop
   becomes infinite.

3. During separation, moving to the copied node instead
   of the next original node.

4. Forgetting to restore the original list.

5. Returning head instead of headCopy.


============================================================
One-line Interview Explanation
============================================================

"I clone every node and interleave each clone with its
original, use the interleaving to assign random pointers
in O(1) extra space, and finally separate the two lists."
============================================================
*/
};
