/*
    LeetCode 61 - Rotate List

    Approaches practiced:
    1. Repeatedly move the last node to the front.
    2. Use k % n to reduce unnecessary rotations.
    3. Optimal Circular Linked List approach.

    Final optimal complexity:
        Time  : O(n)
        Space : O(1)
*/

#include <iostream>
using namespace std;


// ============================================================
// Node Structure
// ============================================================

class Node
{
public:
    int data;
    Node* next;

    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};


// ============================================================
// Create Linked List
// ============================================================

Node* createList(int arr[], int n)
{
    if (n == 0)
        return NULL;

    Node* head = new Node(arr[0]);
    Node* tail = head;

    for (int i = 1; i < n; i++)
    {
        tail->next = new Node(arr[i]);
        tail = tail->next;
    }

    return head;
}


// ============================================================
// Print Linked List
// ============================================================

void printList(Node* head)
{
    Node* temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";

        temp = temp->next;
    }

    cout << endl;
}


// ============================================================
// APPROACH 1
// Repeatedly move the last node to the beginning
// ============================================================
//
// Example:
//
// 1 -> 2 -> 3 -> 4 -> 5
//
// Rotate once:
//
// 5 -> 1 -> 2 -> 3 -> 4
//
// Rotate again:
//
// 4 -> 5 -> 1 -> 2 -> 3
//
// Time  : O(n * k)
// Space : O(1)
//
// This was your first working approach.
// ============================================================

Node* rotateRepeated(Node* head, int k)
{
    if (head == NULL || head->next == NULL || k == 0)
        return head;

    while (k--)
    {
        Node* temp = head;

        // Find the second-last node
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }

        // Last node
        Node* last = temp->next;

        // Remove last node
        temp->next = NULL;

        // Put last node at the beginning
        last->next = head;
        head = last;
    }

    return head;
}


// ============================================================
// APPROACH 2
// Use k % n before repeated rotations
// ============================================================
//
// Observation:
//
// Rotating a list n times gives the original list.
//
// Example:
//
// n = 5
// k = 12
//
// 12 % 5 = 2
//
// Therefore, we only need 2 rotations.
//
// This is better than Approach 1 for very large k,
// but it can still be O(n^2) in the worst case.
//
// Time  : O(n^2) worst case
// Space : O(1)
// ============================================================

Node* rotateUsingModulo(Node* head, int k)
{
    if (head == NULL || head->next == NULL || k == 0)
        return head;

    // Find length
    int n = 0;

    Node* temp = head;

    while (temp != NULL)
    {
        n++;
        temp = temp->next;
    }

    // Reduce unnecessary rotations
    k = k % n;

    // Perform remaining rotations
    while (k)
    {
        temp = head;

        // Find second-last node
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }

        // Store last node
        Node* last = temp->next;

        // Remove last node
        temp->next = NULL;

        // Move last node to front
        last->next = head;
        head = last;

        k--;
    }

    return head;
}


// ============================================================
// APPROACH 3
// OPTIMAL: Circular Linked List
// ============================================================
//
// Example:
//
// Original:
//
// 1 -> 2 -> 3 -> 4 -> 5 -> NULL
//
// k = 2
//
// Step 1:
// Find length.
//
// n = 5
//
// Step 2:
//
// k = k % n
//
// 2 % 5 = 2
//
// Step 3:
// Find the old tail.
//
// 1 -> 2 -> 3 -> 4 -> 5
//                     ^
//                    tail
//
// Step 4:
// Connect tail to head.
//
// 1 -> 2 -> 3 -> 4 -> 5
// ^                   |
// |___________________|
//
// Now the list is circular.
//
// Step 5:
// Find the new tail.
//
// New tail position = n - k
//
// 5 - 2 = 3
//
// So node 3 becomes the new tail.
//
// The node after node 3 is the new head:
//
// 4 -> 5 -> 1 -> 2 -> 3
//
// Step 6:
// Break the circle after node 3.
//
// 3 -> NULL
//
// Final:
//
// 4 -> 5 -> 1 -> 2 -> 3 -> NULL
//
// Time  : O(n)
// Space : O(1)
// ============================================================

Node* rotateOptimal(Node* head, int k)
{
    if (head == NULL || head->next == NULL || k == 0)
        return head;

    // --------------------------------------------------------
    // Find length and old tail
    // --------------------------------------------------------

    int n = 1;

    Node* temp = head;

    while (temp->next != NULL)
    {
        n++;
        temp = temp->next;
    }

    // Remove unnecessary complete rotations
    k = k % n;

    // If k becomes 0, no rotation is needed.
    if (k == 0)
        return head;

    // Make the list circular
    temp->next = head;

    // --------------------------------------------------------
    // Find the new tail
    //
    // Since temp currently points to the old tail,
    // moving n-k times reaches the new tail.
    // --------------------------------------------------------

    int steps = n - k;

    while (steps--)
    {
        temp = temp->next;
    }

    // --------------------------------------------------------
    // The node after new tail is the new head
    // --------------------------------------------------------

    Node* newHead = temp->next;

    // --------------------------------------------------------
    // Break the circular list
    // --------------------------------------------------------

    temp->next = NULL;

    return newHead;
}


// ============================================================
// Main
// ============================================================

int main()
{
    int arr[] = {1, 2, 3, 4, 5};

    int n = sizeof(arr) / sizeof(arr[0]);

    int k = 2;


    // --------------------------------------------------------
    // Approach 1
    // --------------------------------------------------------

    Node* head1 = createList(arr, n);

    cout << "Original List: ";
    printList(head1);

    head1 = rotateRepeated(head1, k);

    cout << "Approach 1 - Repeated Rotation: ";
    printList(head1);


    // --------------------------------------------------------
    // Approach 2
    // --------------------------------------------------------

    Node* head2 = createList(arr, n);

    head2 = rotateUsingModulo(head2, k);

    cout << "Approach 2 - k % n + Repeated Rotation: ";
    printList(head2);


    // --------------------------------------------------------
    // Approach 3
    // --------------------------------------------------------

    Node* head3 = createList(arr, n);

    head3 = rotateOptimal(head3, k);

    cout << "Approach 3 - Circular List: ";
    printList(head3);


    return 0;
}