#include <iostream>
using namespace std;

const int MAX = 20;
int sol[MAX][MAX];

void printSolution(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << sol[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool isSafe(int maze[MAX][MAX], int x, int y, int n) {
    return (x >= 0 && y >= 0 && x < n && y < n && maze[x][y] == 1 && sol[x][y] == 0);
}

bool solveMazeUtil(int maze[MAX][MAX], int x, int y, int n) {
    if (x == n - 1 && y == n - 1) {
        sol[x][y] = 1;
        printSolution(n);
        return true;
    }

    if (isSafe(maze, x, y, n)) {
        sol[x][y] = 1;

        if (solveMazeUtil(maze, x + 1, y, n)) return true;
        if (solveMazeUtil(maze, x, y + 1, n)) return true;
        if (solveMazeUtil(maze, x - 1, y, n)) return true;
        if (solveMazeUtil(maze, x, y - 1, n)) return true;

        sol[x][y] = 0;
    }
    return false;
}

void solveMaze(int maze[MAX][MAX], int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            sol[i][j] = 0;

    if (!solveMazeUtil(maze, 0, 0, n))
        cout << "No path exists" << endl;
}

int main() {
    int n;
    int maze[MAX][MAX];

    cout << "Enter size of maze: ";
    cin >> n;

    cout << "Enter maze matrix (0 for blocked, 1 for open):" << endl;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> maze[i][j];

    solveMaze(maze, n);
    return 0;
}
