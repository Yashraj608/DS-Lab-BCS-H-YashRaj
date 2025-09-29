#include<iostream>
using namespace std;

class Node{
public:
int data;
Node*next;
Node(int data){
    this->data = data;
    next = nullptr;
}
};

class Stack{
public:
Node*top;
Stack(){
    top = nullptr;
}

void push(int value){
    Node*newNode = new Node(value);
    newNode->next = top;
    top = newNode;
}

void pop(){
    if(top ==nullptr){
        cout<<"Stack is empty !"<<endl;
        return;
    }else{

        Node*temp = top;
        top = top->next;
        delete temp;
    }
}

bool isEmpty(){
    if(top== nullptr){
        return true;
    }else{
        return false;
    }
}

bool isFull(){
    Node*temp = new(nothrow)Node(0);
    if(temp == nullptr){
        return true;
    }else{
        delete temp;
        return false;
    }
}

int peek(){
    return top->data;
}

void printStack(){
    if(top == nullptr){
        cout<<"Stack is empty !"<<endl;
        return;
    }
    Node*temp = top;
    while(temp != nullptr){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
};
int main(){
Stack s;
s.push(3);
s.push(9);
s.push(4);
s.push(5);
s.push(8);
s.printStack();
cout<<"Peek or Top is: "<<s.peek()<<endl;
s.pop();
cout<<"after popping : ";
s.printStack();
    return 0;
}