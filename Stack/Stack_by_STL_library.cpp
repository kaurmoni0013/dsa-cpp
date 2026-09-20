#include<iostream>
#include<stack>
using namespace std;

int main(){
    stack<int>S;
    S.push(2);
    S.push(3);
    S.push(1);
    cout<<S.size()<<endl;
    S.pop();  //top
    cout<<S.top()<<endl;
    cout<<S.empty()<<endl;
}
