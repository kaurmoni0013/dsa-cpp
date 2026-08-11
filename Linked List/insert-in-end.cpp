#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        next = NULL;
    } 
};

int main(){
    Node* head,*tail;
    head =NULL,tail = NULL;
    int arr[] = {2,3,4,5,6};
    // Insert the value at end
    for(int i=0;i<5;i++){
        // If linked list is empty
        if(head == NULL){
            head = new Node(arr[i]);
            tail = head;
        }
        // if linked list exist
        else{
        //     Node *tail = head;
        //     while(tail->next!=NULL){
        //         tail = tail->next;
        //     }
        //     tail->next = new Node(arr[i]);
        // }
//  directly add the node in the end without traversing the whole list
            tail->next = new Node(arr[i]);
            tail = tail->next;

    }
}

      // *Printing the linked list
    Node* temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}