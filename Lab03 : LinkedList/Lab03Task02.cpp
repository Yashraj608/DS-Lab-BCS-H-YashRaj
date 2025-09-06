#include<iostream>
using namespace std;
class Node{
public:
int data ;
Node*next;
Node(int data){
     this->data = data;
     next= NULL;
}
};
class Linkedlist{
public:
Node*head;
Node*tail;
Linkedlist(){
    head = tail = NULL;
}
void pushfront(int data){
    Node*newNode = new Node(data);
    if(head == NULL){
        head = tail = newNode;
    }else{

        newNode->next = head;
        head = newNode;
    }
}

void pushback(int value){
Node*newNode = new Node(value);
if(head == NULL){
    head = tail = newNode;
}else{

    tail->next = newNode;
    tail = newNode;
    tail->next = NULL;
}
}


void printLinkedList(){
    Node*temp = head;
    while(temp != NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"null"<<endl;
}

void sort(){
    if(head == nullptr || head->next == nullptr){
        return;
    }
    Node*i,*j;
    for(i =head ;i != nullptr;i=i->next){
        for(j=i->next;j != nullptr;j=j->next){
            if(i->data > j->data){
                 int temp = i->data;
                 i->data = j->data;
                 j->data = temp;
            }
        }
    }
}


void merge(const Linkedlist&other){
    if(head==nullptr){
        head = other.head;
        tail = other.tail;
        return;
    }
    if(other.head == nullptr){
        return;
    }
    tail->next = other.head;
    tail = other.tail;
}
};
int main(){
    Linkedlist sll,sll1;
    sll.pushfront(23);
    sll.pushfront(24);
    sll.pushfront(29);
    sll.pushfront(27);
    sll.pushfront(28);
    sll.printLinkedList();


    sll1.pushback(20);
    sll1.pushback(32);
    sll1.pushback(33);
    sll1.pushback(21);
    sll1.printLinkedList();
    
    sll.merge(sll1);
    sll.printLinkedList();
    sll.sort();
    sll.printLinkedList();
    return 0;
}