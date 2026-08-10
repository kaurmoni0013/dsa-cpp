#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};
int main()
{
    // Node* head;
    // head = new Node(4);
    // cout<<head->data<<endl;
    // cout<<head->next;
    int arr[] = {2, 4, 6, 8};

    //* creating a linked list
    Node *head;
    head = NULL;
    for (int i = 0; i < 4; i++)
    {
        if (head == NULL)
            head = new Node(arr[i]);
        else
        {
            Node *temp;
            temp = new Node(arr[i]);
            temp->next = head;
            head = temp;
        }
    }

    // *Printing the linked list
    Node* temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}