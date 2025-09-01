#include<iostream>
using namespace std;

int main() {
    int categories;
    cin >> categories;

    int** books = new int*[categories];
    int* booksCount = new int[categories];

    for (int i = 0; i < categories; i++) {
        cin >> booksCount[i];
        books[i] = new int[booksCount[i]];
    }

    for (int i = 0; i < categories; i++) {
        for (int j = 0; j < booksCount[i]; j++) {
            cin >> books[i][j];
        }
    }

    int searchId;
    cin >> searchId;

    bool found = false;
    for (int i = 0; i < categories; i++) {
        for (int j = 0; j < booksCount[i]; j++) {
            if (books[i][j] == searchId) {
                cout << "Book found in category " << i + 1 << endl;
                found = true;
            }
        }
    }

    if (!found) cout << "Book not found" << endl;

    for (int i = 0; i < categories; i++) {
        delete[] books[i];
    }
    delete[] books;
    delete[] booksCount;

    return 0;
}
