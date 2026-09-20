#include<iostream>
using namespace std;

class Stack{
    int *arr;
    int size;
    int top;
    public:

    Stack(int n){
        size = n;
        top = -1;
        arr = new int[n];
    }

    // push
    void push(int value){
        if(top == size-1){
            cout<<"Stack overflow"<<endl;
            return;
        }
        else{ 
        arr[++top] = value;
         cout<<"pushed "<<arr[top]<<" into the stack"<<endl;
        }
    }

    // pop
    void pop(){
        if(top == -1){
            cout<<"Stack underflow"<<endl;;
            return;
        }
        else{
            cout<<"popped "<<arr[top]<<" from the stack"<<endl;
            top--;
        }
    }

    //Peek
    int peek(){
        if(top == -1){
            cout<<"Stack is Empty"<<endl;;
            return -1;
        }
        else{
            return arr[top];
        }
    }

    bool isEmpty(){
        return top == -1;
    }

    int isSize(){
        return top+1;
    }
};

int main(){
    Stack s(5);
    s.push(5);
    s.push(6);
    s.push(7);
    s.push(8);
    s.push(9);
    s.push(10);
    s.pop();
    cout<<s.peek()<<endl;;
    cout<<s.isEmpty()<<endl;
    cout<<s.isSize()<<endl;;
    s.pop();
}