#include<iostream>
#include<vector>
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
  Node* insertAtStart(vector<int>&arr,int index,Node*prev) {
        if(index == arr.size())
        return prev;
        Node *temp =new Node(arr[index]);
        temp->next = prev;
        return insertAtStart(arr,index+1,temp);
       
 
    }

int main(){
    Node* head,*prev;
    head = NULL,prev = NULL;
    vector<int>arr = {2,3,4,5,6};
    head = insertAtStart(arr, 0,prev);
    

// *Printing the linked list
    Node* temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}