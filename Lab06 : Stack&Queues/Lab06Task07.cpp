#include <iostream>
using namespace std;

#define SIZE 10

struct Process{
    int id;
    int priority;
};

class Queue{
    Process arr[SIZE];
    int start, end, count;
public:
    Queue(){
        start = 0;
        end = -1;
        count = 0;
    }
    bool isFull(){return count == SIZE;}
    bool isEmpty(){return count == 0;}
    void enqueue(Process p){
        if(isFull()){
            cout << "Queue Overflow!" << endl;
            return;
        }
        end = (end + 1) % SIZE;
        arr[end] = p;
        count++;
    }
    Process dequeue(){
        if(isEmpty()){
            cout << "Queue Underflow!" << endl;
            return {-1, -1};
        }
        Process temp = arr[start];
        start = (start + 1) % SIZE;
        count--;
        return temp;
    }
};

class Stack{
    Process arr[SIZE];
    int top;
public:
    Stack(){top = -1;}
    bool isFull(){return top == SIZE - 1;}
    bool isEmpty(){return top == -1;}
    void push(Process p){
        if(isFull()){
            cout << "Stack Overflow!" << endl;
            return;
        }
        arr[++top] = p;
    }
    Process pop(){
        if(isEmpty()){
            cout << "Stack Underflow!" << endl;
            return {-1, -1};
        }
        return arr[top--];
    }
};

class JobScheduler{
    Queue arrivalQueue;
    Stack executionStack;
public:
    void addProcess(int id, int priority){
        Process p = {id, priority};
        cout << "Process " << id << " (Priority: " << priority << ") arrived." << endl;
        arrivalQueue.enqueue(p);
    }
    void scheduleProcesses(){
        while(!arrivalQueue.isEmpty()){
            Process p = arrivalQueue.dequeue();
            executionStack.push(p);
            cout << "Scheduled Process " << p.id << " (Priority: " << p.priority << ") into Stack." << endl;
        }
    }
    void executeProcesses(){
        while(!executionStack.isEmpty()){
            Process p = executionStack.pop();
            cout << "Executing Process " << p.id << " with Priority " << p.priority << endl;
        }
    }
};

int main(){
    JobScheduler scheduler;
    scheduler.addProcess(101, 1);
    scheduler.addProcess(102, 3);
    scheduler.addProcess(103, 2);
    scheduler.addProcess(104, 5);
    scheduler.scheduleProcesses();
    scheduler.executeProcesses();
    return 0;
}
