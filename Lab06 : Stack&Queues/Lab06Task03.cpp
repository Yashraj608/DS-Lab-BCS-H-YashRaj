#include<iostream>
using namespace std;
# define size 10
class Queue{
public:
int q[size];
int start = -1,end = -1;
int currentSize = 0;


void push(int value){
    if(currentSize == size){
        cout<<"Queue Overflow !"<<endl;
        return;
    }
      if(currentSize == 0){
        start = end =0;
      }else{
          end = (end+1)%size;
      }
          q[end] = value; 
          currentSize++;
}

void pop(){
    if(currentSize == 0){
        cout<<"Queue is empty !"<<endl;
        return;
    }else{
        cout<<"Removed : "<<q[start]<<endl;
        start = (start+1)%size;
        currentSize--;
    }

    if(currentSize ==0){
        start = -1;
        end = -1;
    }
}

int peek(){
    if(currentSize == 0){
        cout<<"Queue is empty"<<endl;
        return -1;
    }else{
        return q[start];
    }
}


int getSize(){
    return currentSize;
}
void print(){
    if(currentSize == 0){
        cout<<"Queue is emepty !"<<endl;
        return;
    }
    cout<<"Queue Elements are: "<<endl;
    for(int i =0;i <currentSize;i++){
        int index = (start +i)%size;
        cout<<q[index]<<" ";
    }
    cout<<endl;
}
};
int main(){
    Queue q;
    q.push(1);
    q.push(3);
    q.push(8);
    q.push(5);
    q.print();
    cout<<"Top Element is: "<<q.peek()<<endl;
    q.pop();
    q.print();
    cout<<"Size of Queue is: "<<q.getSize()<<endl;
    return 0;
}