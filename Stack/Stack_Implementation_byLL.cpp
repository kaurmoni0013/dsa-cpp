 #include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node*next;
    Node(int value){
        data = value;
        next = NULL;
    }
};


class Stack{
    Node*top;
    int size;
    public:
    Stack(){
        top = NULL;
        size = 0;
    }

    //* push
    void push(int value){
        Node*temp = new Node(value);
        temp->next = top;
        top = temp;
        size++;
        cout<<"Push "<<value<<" into the stack"<<endl;
    }

    //* pop
    void pop(){
        if(top == NULL){
            cout<<"Stack underflow"<<endl;
        }
        else{
            Node*temp = top;
            cout<<"Popped "<<top->data<<" from the stack"<<endl;
            top = top->next;
            delete temp;
            size--;
        }
    }

    // * peek
    int peek(){
        if(top == NULL){
            cout<<"Stack is underflow"<<endl;
            return -1;
        }

        else
        return top->data;
    }

    bool isEmpty(){
    return top == NULL;
    }
    // * size
    int isSize(){
        return size;

    }
};


int main(){
    Stack s;
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