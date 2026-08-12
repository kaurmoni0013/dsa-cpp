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

// Insert a node at the end
void insertAtEnd(Node *&head, Node *&tail, int value)
{
    Node *newNode = new Node(value);

    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
}

// Delete the first node
void deleteFirstNode(Node *&head, Node *&tail)
{
    if (head == NULL)
        return;

    Node *temp = head;
    head = head->next;

    delete temp;

    // If list becomes empty
    if (head == NULL)
        tail = NULL;
}

// Delete the last node
void deleteLastNode(Node *&head, Node *&tail)
{
    if (head == NULL)
        return;

    // Only one node
    if (head->next == NULL)
    {
        delete head;
        head = NULL;
        tail = NULL;
        return;
    }

    // Find the node before the last node
    Node *temp = head;

    while (temp->next != tail)
    {
        temp = temp->next;
    }

    // Delete last node
    delete tail;

    // Update tail
    tail = temp;
    tail->next = NULL;
}

// Delete at a particular point
void delteParticularNode(Node *&head, int x)
{
    if (head != NULL)
    {
        Node *curr = head, *prev = NULL;
        x--;
        if (x == 0)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            return;
        }
        while (x-- && curr != NULL)
        {
            prev = curr;
            curr = curr->next;
        }
        if(curr!=NULL){
        prev->next = curr->next;
        delete curr;
        }
    }
}

// Delete last node through recurssion
Node* deleteNode(Node*curr , int x){
    if(x==1){
        Node* temp = curr->next;
        delete curr;
        return temp;
    }
    curr->next = deleteNode(curr->next,x-1);
    return curr;
}


// Print the linked list
void printList(Node *head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    int arr[] = {2, 3, 4, 5, 6};

    // Insert elements
    for (int i = 0; i < 5; i++)
    {
        insertAtEnd(head, tail, arr[i]);
    }

    cout << "Original Linked List: ";
    printList(head);

    // // Delete first node
    // deleteFirstNode(head, tail);

    // cout << "After deleting first node: ";
    // printList(head);

    // // Delete last node
    // deleteLastNode(head, tail);

    // cout << "After deleting last node: ";
    // printList(head);

    // delteParticularNode(head, 0);

    deleteNode(head,3);

    cout << "After deleting particular node: ";
    printList(head);

    

    return 0;
}