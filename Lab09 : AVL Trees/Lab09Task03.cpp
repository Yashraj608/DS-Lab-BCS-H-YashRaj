#include <iostream>
using namespace std;

struct Node {
    int severity;
    Node* left;
    Node* right;
    int height;

    Node(int severity) {
        this->severity = severity;
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
    cout << type << " rotation performed at patient severity " << key << endl;
}

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* t = x->right;

    x->right = y;
    y->left = t;

    y->height = 1 + max(height(y->left), height(y->right));
    x->height = 1 + max(height(x->left), height(x->right));

    printRotation("right", x->severity);
    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* t = y->left;

    y->left = x;
    x->right = t;

    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));

    printRotation("left", y->severity);
    return y;
}

Node* insertSeverity(Node* root, int severity) {
    if (!root)
        return new Node(severity);

    if (severity < root->severity)
        root->left = insertSeverity(root->left, severity);
    else if (severity > root->severity)
        root->right = insertSeverity(root->right, severity);
    else
        return root;

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = getBalance(root);
    cout << "balance factor at patient severity " << root->severity << " is " << balance << endl;

    if (balance > 1 && severity < root->left->severity)
        return rightRotate(root);

    if (balance < -1 && severity > root->right->severity)
        return leftRotate(root);

    if (balance > 1 && severity > root->left->severity) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && severity < root->right->severity) {
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

Node* deleteSeverity(Node* root, int severity) {
    if (!root)
        return root;

    if (severity < root->severity)
        root->left = deleteSeverity(root->left, severity);
    else if (severity > root->severity)
        root->right = deleteSeverity(root->right, severity);
    else {
        if (!root->left || !root->right) {
            Node* temp = root->left ? root->left : root->right;

            if (!temp) {
                temp = root;
                root = nullptr;
            } else
                *root = *temp;

            delete temp;
        } else {
            Node* temp = minValueNode(root->right);
            root->severity = temp->severity;
            root->right = deleteSeverity(root->right, temp->severity);
        }
    }

    if (!root)
        return root;

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = getBalance(root);
    cout << "balance factor at patient severity " << root->severity << " after deletion = " << balance << endl;

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

int highestSeverity(Node* root) {
    if (!root)
        return -1;
    Node* current = root;
    while (current->right)
        current = current->right;
    return current->severity;
}

void printHeight(Node* root) {
    cout << "current height of the AVL tree is " << height(root) << endl;
}

int main() {
    Node* root = nullptr;

    int severities[] = {50, 80, 30, 90, 70, 60};
    int n = 6;

    for (int i = 0; i < n; i++) {
        cout << "new patient arrives with severity score: " << severities[i] << endl;
        root = insertSeverity(root, severities[i]);
        printHeight(root);
        cout << "highest severity patient currently: " << highestSeverity(root) << endl;
    }

    int discharged[] = {80, 30};
    int m = 2;

    for (int i = 0; i < m; i++) {
        cout << "patient discharged with severity score: " << discharged[i] << endl;
        root = deleteSeverity(root, discharged[i]);
        printHeight(root);
        cout << "highest severity patient currently: " << highestSeverity(root) << endl;
    }

    return 0;
}
