#include <iostream>
using namespace std;

const int MAX = 20;
int board[MAX][MAX];

void printSolution(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << (board[i][j] ? "Q " : ". ");
        }
        cout << endl;
    }
    cout << endl;
}

bool isSafe(int row, int col, int n) {
    for (int i = 0; i < row; i++)
        if (board[i][col]) return false;

    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        if (board[i][j]) return false;

    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
        if (board[i][j]) return false;

    return true;
}

void placeQueens(int row, int n) {
    if (row == n) {
        printSolution(n);
        return;
    }

    for (int col = 0; col < n; col++) {
        if (isSafe(row, col, n)) {
            board[row][col] = 1;
            placeQueens(row + 1, n);
            board[row][col] = 0;
        }
    }
}

void solveNQueens(int n) {
    placeQueens(0, n);
}

int main() {
    int n;
    cout << "Enter N: ";
    cin >> n;
    solveNQueens(n);
    return 0;
}
