#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->prev = nullptr;
        this->next = nullptr;
    }
};

Node *create_Doubly_LL(vector<int> nums, int index, Node *prev, Node *next)
{
    if (nums.size() == index)
        return next;
    Node *temp = new Node(5);
    temp->prev = create_Doubly_LL(nums, index + 1, prev, next);
    return temp;
}

void displayForward(Node *head)
{

    Node *temp = head;

    while (temp != nullptr)
    {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5};
    int index = 0;
    Node *next = NULL, *prev = NULL;
    Node *head = create_Doubly_LL(nums, index, prev, next);
    displayForward(head);
}