#include<iostream>
using namespace std;

int**AdditionMatrices(int **arr1, int **arr2,int rows,int cols){
    int**sum = new int*[rows];
    for(int i =0;i<rows;i++){
        sum[i] = new int[cols];
        for(int j =0;j<cols;j++){
            sum[i][j] = arr1[i][j] + arr2[i][j];
        }
    }
    return sum;
}

int** SubtractionMatrice(int **arr1, int** arr2, int rows, int cols){
    int **subtraction = new int*[rows];
    for(int i =0;i<rows;i++){
        subtraction[i] = new int[cols];
        for(int j =0;j<cols;j++){
           subtraction[i][j] =  arr1[i][j] - arr2[i][j]; 
        }
    }
    return subtraction;
}
int main(){
    int rows;
    int cols;
    cout<<"Enter the number of rows:"<<endl;
    cin>>rows;
    cout<<"Enter the number of cols:"<<endl;
    cin>>cols;
    
    int **arr1 = new int*[rows];
    int **arr2 = new int*[rows];
    for(int i =0;i<rows;i++){
        arr1[i] = new int[cols];
        arr2[i] = new int[cols];
    }
cout<<"Enter the elements of 1st Matrix: "<<endl;
    for(int i =0;i<rows;i++){
        for(int j =0;j<cols;j++){
            cin>>arr1[i][j];
        }
    }

cout<<"Enter the elements of 2nd Matrix: "<<endl;
for(int i =0;i<rows;i++){
    for(int j =0;j<cols;j++){
        cin>>arr2[i][j];
    }
}

int **sum = AdditionMatrices(arr1,arr2,rows,cols);
int **subtract = SubtractionMatrice(arr1,arr2,rows,cols);

cout<<"Sum of Two matrices is: "<<endl;
for(int i =0;i<rows;i++){
    for(int j =0;j<cols;j++){
        cout<<sum[i][j]<<" ";
    }
    cout<<endl;
}

cout<<"Difference is: "<<endl; 
for(int i =0;i<rows;i++){
    for(int j =0;j<cols;j++){
        cout<<subtract[i][j]<<" ";
    }
    cout<<endl;
}

for(int i =0;i<rows;i++){
    delete[]arr1[i];
    delete[]arr1[i];
    delete[]subtract[i];
    delete[]sum[i];
}
delete[]arr1;
    delete[]arr2;
    delete[]subtract;
    delete[]sum;


    return 0;
}