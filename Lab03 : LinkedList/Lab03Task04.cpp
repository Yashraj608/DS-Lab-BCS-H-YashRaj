#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class CircularLinkedList {
public:
    Node* head;
    CircularLinkedList() : head(nullptr) {}

    void createList(int n) {
        if (n <= 0) return;
        head = new Node(1);
        Node* last = head;
        for (int i = 2; i <= n; i++) {
            last->next = new Node(i);
            last = last->next;
        }
        last->next = head;
    }

    int josephus(int k) {
        Node* curr = head;
        Node* prev = nullptr;
        while (curr->next != curr) {
            for (int count = 1; count < k; count++) {
                prev = curr;
                curr = curr->next;
            }
            prev->next = curr->next;
            delete curr;
            curr = prev->next;
        }
        return curr->data;
    }
};

int main() {
    int n = 7, k = 3;
    CircularLinkedList cll;
    cll.createList(n);
    cout << "Survivor is at position: " << cll.josephus(k) << endl;
    return 0;
}
