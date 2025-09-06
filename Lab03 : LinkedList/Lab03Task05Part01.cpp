#include<iostream>
using namespace std;
class Node{
    public:
Node*next;
int data;
Node(int data){
    this->data = data;
    next = nullptr;
}
};

class SingleLinkedlist{
    Node*head,*tail;
public:
SingleLinkedlist(){
    head = tail =nullptr;
}

void pushfront(int value){
    Node*newNode = new Node(value);
    if(head == nullptr){
        head = tail = newNode;
    }else{
        newNode->next = head;
        head = newNode;
    }
}

void pushback(int value){
    Node*newNode = new Node(value);
    if(head == nullptr){
        head = tail = newNode;
    }else{
        tail->next = newNode;
        tail = newNode;
    }
}
Node*getNode()const{
    return head;
}

void display(){
    Node*temp = head;
    while(temp != nullptr){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}
};

class DoubleNode{
public:
int data;
DoubleNode*next;
DoubleNode*prev;

DoubleNode(int value){
    this->data = value;
    next = prev = nullptr;
}
};

class doublelinkedlist{
public:
DoubleNode*head ,*tail;
doublelinkedlist(){
    head = tail = nullptr;
}

doublelinkedlist(const SingleLinkedlist& sll){
    head = tail = nullptr;
    Node*current = sll.getNode();
    while (current)
    {
        pushback(current->data);
        current =current->next;
    }
    
}

void pushback(int value){
    DoubleNode*newNode = new DoubleNode(value);
    if(head == nullptr){
         head = tail = newNode;
    }
    else{
        newNode->prev =tail;
        tail->next = newNode;
        tail = newNode; 
    }
}


void displayforward(){
    DoubleNode*temp = head;
    while(temp != nullptr){
        cout<<temp->data<<"<->";
        temp = temp->next;
    }
    cout<<"Null"<<endl;
}

void displayBackward(){
    DoubleNode*temp  = tail;
    while(temp != nullptr){
        cout<<temp->data<<"<->";
        temp = temp->prev;
    }
    cout<<"Null"<<endl;
}
};
int main(){
    SingleLinkedlist sll;
    sll.pushfront(20);
    sll.pushfront(25);
    sll.pushfront(28);
    sll.pushfront(22);
    sll.pushfront(24);
    sll.display();

    doublelinkedlist dll(sll);
    cout<<"Displaying in forward manner: "<<endl;
    dll.displayforward();
    cout<<"Displaying in backward manner: "<<endl;
    dll.displayBackward();

    return 0;
}