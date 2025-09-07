#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* child;

    Node(int val) {
        data = val;
        next = NULL;
        child = NULL;
    }
};

Node* flatten(Node* head) {
    if (head == NULL) return NULL;

    Node* curr = head;

    while (curr != NULL) {
        if (curr->child != NULL) {
            Node* childList = flatten(curr->child);
            Node* nextNode = curr->next;

            curr->next = childList;
            curr->child = NULL;

            Node* temp = childList;
            while (temp->next != NULL) {
                temp = temp->next;
            }

            temp->next = nextNode;
        }
        curr = curr->next;
    }

    return head;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    head->next->child = new Node(6);
    head->next->child->next = new Node(7);
    head->next->child->next->child = new Node(8);
    head->next->child->next->child->next = new Node(9);

    head = flatten(head);

    cout << "Flattened List: ";
    printList(head);

    return 0;
}
