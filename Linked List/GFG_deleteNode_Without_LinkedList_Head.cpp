/*
    GFG Problem: Delete a Node Without Head Pointer

    Problem:
    Given a node x in a singly linked list, delete this node
    without having access to the head of the linked list.

    Note:
    It is guaranteed that x is not the last node.
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
    void deleteNode(Node* x)
    {
        Node* temp = x->next;

        x->data = temp->data;
        x->next = temp->next;

        delete temp;
    }
};