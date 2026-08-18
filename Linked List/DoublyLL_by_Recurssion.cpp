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

// Insert at Start using recursion
Node *insertAtStart(vector<int> &arr, int index, Node *front)
{
    if (index < 0)
    {
        return front;
    }

    Node *temp = new Node(arr[index]);

    temp->next = front;

    if (front != NULL)
    {
        front->prev = temp;
    }

    temp->prev = NULL;

    return insertAtStart(arr, index - 1, temp);
}

// Insert at End using recursion
Node *insertAtEnd(vector<int> &arr, int index, Node *back)
{
    if (index == arr.size())
    {
        return NULL;
    }

    Node *temp = new Node(arr[index]);

    temp->prev = back;
    temp->next = insertAtEnd(arr, index + 1, temp);

    return temp;
}

// Display
void display(Node *head)
{
    if (head == nullptr)
    {
        cout << "NULL" << endl;
        return;
    }

    cout << head->data << " <-> ";

    display(head->next);
}

int main()
{
    vector<int> arr = {1, 2, 3, 4};

    Node *head1 = insertAtStart(arr, arr.size() - 1, NULL);

    Node *head2 = insertAtEnd(arr, 0, NULL);

    cout << "Insert at Start: ";
    display(head1);

    cout << "Insert at End: ";
    display(head2);

    return 0;
}