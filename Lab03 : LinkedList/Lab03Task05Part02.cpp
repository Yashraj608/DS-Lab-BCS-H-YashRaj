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

class CNode{
public:
int data;
CNode*next;
CNode(int value){
    this->data= value;
    next = nullptr;
}
};

class CircularLinkedList {
    CNode* head;
    CNode* tail;
public:
    CircularLinkedList() {
        head = tail = nullptr;
    }

    CircularLinkedList(const SingleLinkedlist& sll) {
        head = tail = nullptr;
        Node* current = sll.getNode();
        while (current) {
            pushBack(current->data);
            current = current->next;
        }
        if (tail){
         tail->next = head;
        }    
    }

    void pushBack(int value) {
        CNode* newNode = new CNode(value);
        if (head == nullptr) {
            head = tail = newNode;
            newNode->next = head;
        } else {
            tail->next = newNode;
            tail = newNode;
            tail->next = head;
        }
    }

    void display() {
        if (!head) {
            cout << "List is empty\n";
            return;
        }
        CNode* temp = head;
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(back to head)\n";
    }
};

int main() {
    SingleLinkedlist sll;
    sll.pushback(10);
    sll.pushback(20);
    sll.pushback(30);
    sll.pushback(40);

    cout << "Singly Linked List: ";
    sll.display();

    CircularLinkedList cll(sll);
    cout << "Circular Linked List: ";
    cll.display();

    return 0;
}