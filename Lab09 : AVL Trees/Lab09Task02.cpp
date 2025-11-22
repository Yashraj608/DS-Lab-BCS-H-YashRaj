#include <iostream>
using namespace std;

struct Node {
    int price;
    Node* left;
    Node* right;
    int height;

    Node(int price) {
        this->price = price;
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
    cout << type << " rotation performed at price " << key << endl;
}

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* t = x->right;

    x->right = y;
    y->left = t;

    y->height = 1 + max(height(y->left), height(y->right));
    x->height = 1 + max(height(x->left), height(x->right));

    printRotation("right", x->price);
    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* t = y->left;

    y->left = x;
    x->right = t;

    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));

    printRotation("left", y->price);
    return y;
}

Node* insertPrice(Node* root, int price) {
    if (!root)
        return new Node(price);

    if (price < root->price)
        root->left = insertPrice(root->left, price);
    else if (price > root->price)
        root->right = insertPrice(root->right, price);
    else
        return root;

    root->height = 1 + max(height(root->left), height(root->right));
    int balance = getBalance(root);

    cout << "balance factor at price " << root->price << " is " << balance << endl;

    if (balance > 1 && price < root->left->price)
        return rightRotate(root);

    if (balance < -1 && price > root->right->price)
        return leftRotate(root);

    if (balance > 1 && price > root->left->price) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && price < root->right->price) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void rangeQuery(Node* root, int X, int Y) {
    if (!root)
        return;

    if (root->price > X)
        rangeQuery(root->left, X, Y);

    if (root->price >= X && root->price <= Y)
        cout << root->price << " ";

    if (root->price < Y)
        rangeQuery(root->right, X, Y);
}

void printHeight(Node* root) {
    cout << "current height of the AVL tree is " << height(root) << endl;
}

int main() {
    Node* root = nullptr;

    int prices[] = {100, 50, 200, 150, 250, 75, 125};
    int n = 7;

    for (int i = 0; i < n; i++) {
        cout << "adding product price: " << prices[i] << endl;
        root = insertPrice(root, prices[i]);
        printHeight(root);
    }

    int X, Y;
    cout << "enter the price range (X Y): ";
    cin >> X >> Y;
    cout << "product prices in the range [" << X << ", " << Y << "] are: ";
    rangeQuery(root, X, Y);
    cout << endl;

    return 0;
}
