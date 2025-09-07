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
Node* reverseKtimes(Node*head, int k){
    int count=0;
    Node*temp = head;
    while(count < k){ 
        if(temp == nullptr){
            return head;
        }
        temp = temp->next;
        count ++;
    }
  Node*previousNode = reverseKtimes(temp,k);

  count = 0; temp = head;
  while(count < k){
       Node*next = temp->next;
       temp->next = previousNode;
       previousNode = temp;
       temp = next;
       count++;
  }
  return previousNode;
}
};
int main(){
    Linkedlist ll;
    ll.pushfront(23);
    ll.pushback(33);
    ll.pushback(86);
    ll.pushback(43);
    ll.printLinkedList();
    int k =2;
    ll.head = ll.reverseKtimes(ll.head,k);
    ll.printLinkedList();


    return 0;
}