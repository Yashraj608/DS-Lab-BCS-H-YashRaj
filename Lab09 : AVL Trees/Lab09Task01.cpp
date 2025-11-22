#include <iostream>
using namespace std;

struct Node {
    int rollNumber;
    Node *left, *right;
    int height;

    Node(int rollNumber) {
        this->rollNumber = rollNumber;
        this->left = nullptr;
        this->right = nullptr;
        this->height = 1;
    }
};

int height(Node* n) {
    return n ? n->height : 0;
}

int getBalance(Node* n) {
    return n ? height(n->left) - height(n->right) : 0;
}

void printRotation(const string &type, int key) {
    cout << "rotation performed: " << type << " at roll number " << key << endl;
}

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* t = x->right;

    x->right = y;
    y->left = t;

    y->height = 1 + max(height(y->left), height(y->right));
    x->height = 1 + max(height(x->left), height(x->right));

    printRotation("right rotation", x->rollNumber);
    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* t = y->left;

    y->left = x;
    x->right = t;

    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));

    printRotation("left rotation", y->rollNumber);
    return y;
}

Node* insertrollnumber(Node* root, int rollNumber) {
    if (!root)
        return new Node(rollNumber);

    if (rollNumber < root->rollNumber)
        root->left = insertrollnumber(root->left, rollNumber);
    else if (rollNumber > root->rollNumber)
        root->right = insertrollnumber(root->right, rollNumber);
    else
        return root;

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = getBalance(root);
    cout << "balance factor at " << root->rollNumber << " = " << balance << endl;

    if (balance > 1 && rollNumber < root->left->rollNumber)
        return rightRotate(root);

    if (balance < -1 && rollNumber > root->right->rollNumber)
        return leftRotate(root);

    if (balance > 1 && rollNumber > root->left->rollNumber) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && rollNumber < root->right->rollNumber) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

Node* minValueNode(Node* node) {
    Node* current = node;
    while (current->left)
        current = current->left;
    return current;
}

Node* deleterollnumber(Node* root, int rollNumber) {
    if (!root)
        return root;

    if (rollNumber < root->rollNumber)
        root->left = deleterollnumber(root->left, rollNumber);
    else if (rollNumber > root->rollNumber)
        root->right = deleterollnumber(root->right, rollNumber);
    else {
        if (!root->left || !root->right) {
            Node* temp = root->left ? root->left : root->right;

            if (!temp) {
                temp = root;
                root = nullptr;
            } else
                *root = *temp;

            delete temp;
        } 
        else {
            Node* temp = minValueNode(root->right);
            root->rollNumber = temp->rollNumber;
            root->right = deleterollnumber(root->right, temp->rollNumber);
        }
    }

    if (!root)
        return root;

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = getBalance(root);
    cout << "balance factor at " << root->rollNumber << " after deletion = " << balance << endl;

    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void printHeight(Node* root) {
    cout << "avl tree height = " << height(root) << endl;
}

int main() {
    Node* root = nullptr;

    int inserts[] = {50, 30, 70, 20, 40, 60, 80};

    for (int i = 0; i < 7; i++) {
        cout << "inserting roll number: " << inserts[i] << endl;
        root = insertrollnumber(root, inserts[i]);
        printHeight(root);
    }

    int deletes[] = {70, 30, 60};

    for (int i = 0; i < 3; i++) {
        cout << "deleting roll number: " << deletes[i] << endl;
        root = deleterollnumber(root, deletes[i]);
        printHeight(root);
    }

    return 0;
}
