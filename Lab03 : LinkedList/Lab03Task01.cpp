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


Node* reverse(Node*head){
  Node*current = head;
  Node*prev = NULL;
  Node*next = NULL;
while(current != NULL){
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
}
return prev;
}


//To find the palindrome :
// 1. reverse the linkedlist 
// 2. find the mid 
// 3. check the reversed part with the non-reversed part
bool palindrome(){

    if(head == NULL || head->next == NULL){
        return true;
    }
    Node*slow = head;
    Node*fast = head;
    while(fast != NULL && fast->next != NULL){
     slow = slow->next;
     fast= fast->next->next;
    }
    Node*second = reverse(slow);
    Node*firsthalf = head;
    Node*temp = second;

    bool ispalindrome = true;
    while(temp != NULL){   //Traversing the linkedlist//
        if(firsthalf->data != temp->data){
             ispalindrome = false;
             break;
        }
        firsthalf = firsthalf->next;
        temp = temp->next;
    }
    return ispalindrome;
}
};
int main(){
    Linkedlist l;
    l.pushfront(21);
    l.pushfront(43);
    l.pushfront(23);
    l.pushfront(43);
    l.printLinkedList();
    l.head = l.reverse(l.head);
    l.printLinkedList();

    if(l.palindrome()){
        cout<<"The linkedlist is a palindrome"<<endl;
    }
    else{
        cout<<"The linkedlist is not a palindrome"<<endl;
    }

    return 0;
}