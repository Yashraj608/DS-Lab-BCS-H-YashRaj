#include<iostream>
using namespace std;
const int n =9;

void printSudoku(int board[n][n]){
for(int i =0;i<n;i++){
    for(int j =0;j<n;j++){
        cout<<board[i][j]<<" ";
    }
    cout<<endl;
}
}


bool isSafe(int board[n][n], int rows,int cols, int digit){
    //Horizontal check
        for(int j =0;j<n;j++){
            if(board[rows][j]==digit){
                   return false;
            }
        }
    //Vertical Check
        for(int i =0;i<n;i++){
            if(board[i][cols]==digit){
                return false;
            }
        }
//Grid Check
        int startRow = (rows/3)*3;
        int startCol = (cols/3)*3;
        for(int i =0;i<3;i++){
            for(int j=0;j<3;j++){
                if(board[startRow+i][startCol+j]==digit){
                    return false;
                }
            }
        }

        return true;
}

bool SudokuSolver(int board[n][n]){
    int row =0;
    int cols=0;
    bool empty=false;

    for(int i =0;i<n && !empty;i++){
        for(int j =0;j<n;j++){
            if(board[i][j] == 0){
                row = i;
                cols = j;
                empty = true;
                break;
            }
        }
    }

    for(int digit = 1;digit<=9;digit++){
        if(isSafe(board,row,cols,digit)){
            board[row][cols] = digit;


            if(SudokuSolver(board)){
                return true;
            }
            board[row][cols] = 0;
        }
    }
    if(!empty){
        return true;
    }

return false;
}
int main(){
  int board[n][n];

  cout<<"Enter the elements of sudoku: "<<endl;
  for(int i =0;i<n;i++){
    for(int j =0;j<n;j++){
        cin>>board[i][j];
    }
}
cout<<"Sudoku Board is: "<<endl;
printSudoku(board);


if(SudokuSolver(board)){
    cout<<" Solved "<<endl;
    printSudoku(board);
}else{
    cout<<"Sudoku Not Solved"<<endl;
}
    return 0;
}