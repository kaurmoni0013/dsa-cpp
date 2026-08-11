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
  Node* insertAtEnd(vector<int>&arr,int index) {
        if(index == arr.size())
        return NULL;
        Node *temp =new Node(arr[index]);
        temp->next = insertAtEnd(arr,index+1);
        return temp;
    }

int main(){
    Node* head;
    head =NULL;
    vector<int>arr = {2,3,4,5,6};
    head = insertAtEnd(arr, 0);
    

// *Printing the linked list
    Node* temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}