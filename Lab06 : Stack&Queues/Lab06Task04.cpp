#include<iostream>
using namespace std;
#define SIZE 5

class CircularQueue {
private:
    int arr[SIZE];
    int start, end;

public:
    CircularQueue() {
        start = end = -1;
    }

    void enqueue(int value){
        if ((end + 1)% SIZE == start){
            cout << "Queue Overflow!";
            return;
        }
        if (start == -1 && end == -1){
            start = end = 0;
            arr[end] = value;
        } else {
            end = (end + 1) % SIZE;
            arr[end] = value;
        }
    }

    void dequeue(){
        if (start == -1){
            cout << "Queue Underflow!";
            return;
        }
        if (start == end){
            cout << "Dequeued: " << arr[start] << endl;
            start = end = -1;
        } else {
            cout << "Dequeued: " << arr[start] << endl;
            start = (start + 1) % SIZE;
        }
    }

    int peek(){
        if (start == -1){
            cout << "Queue is empty!";
            return -1;
        }
        return arr[start];
    }

    void print(){
        if (start == -1){
            cout << "Queue is empty!";
            return;
        }
        cout << "Queue elements: ";
        int i = start;
        while (true) {
            cout << arr[i] << " ";
            if (i == end){
             break;
            }    
            i = (i + 1) % SIZE;
        }
        cout << endl;
    }
};

int main(){
    CircularQueue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.print();

    q.dequeue();
    q.dequeue();
    q.print();

    q.enqueue(50);
    q.enqueue(60);
    q.print();

    q.enqueue(70);
    return 0;
}
