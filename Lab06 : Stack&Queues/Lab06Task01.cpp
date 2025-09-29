#include<iostream>
using namespace std;
#define max 10
class Stack{
public:
int arr[max];
int top;
Stack(){
    top = -1;
}

void push(int value){
    if(top == max-1){
        return;
        cout<<"Stack Overflow !"<<endl;
    }else{
        arr[++top] = value;
    }
}

void pop(){
    if(top ==-1){
        cout<<"Stack is empty !"<<endl;
        return;
    }else{
    cout<<"Popped: "<<arr[top--]<<endl;
    }
}


int peek(){
    if(top <0){
        return -1;
    }else{
        return arr[top];
    }
}

bool isempty(){
    if(top ==-1){
        return true;
    }else{
        return false;
    }
}

bool isFull(){
    if(top == max-1){
        return true;
    }else{
        return false;
    }
}

void printStack(){
     if(isempty()){
        cout<<"Stack is empty !"<<endl;
     }else{
        for(int i =top ;i>=0;i--){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
     }
}

int size(){

    return top +1;
}
};

int main(){
    Stack s;
    s.push(3);
    s.push(2);
    s.push(10);
    s.push(9);
    s.push(7);
    s.push(5);
    s.printStack();
    s.pop();
    s.printStack();
    cout<<"Peek element is : " <<s.peek()<<endl;
    s.pop();
    s.printStack();
    cout<<"The size of Stack is : "<<s.size()<<endl;
        return 0;
}
