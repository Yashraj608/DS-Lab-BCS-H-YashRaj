//Sparse Matrix gives you the values in the row on the cols//
#include<iostream>
using namespace std;
int main(){
int rows,cols;
cout<<"Enter the rows: "<<endl;
cin>>rows;
cout<<"Enter the number of cols: "<<endl;
cin>>cols;
int **matrix = new int*[rows];
for(int i =0;i<rows;i++){
    matrix[i] = new int[cols];
}

for(int i =0;i<rows;i++){
    for(int j =0;j<cols;j++){
        cin>>matrix[i][j];
    }
}

cout<<"Original and in Normal form:"<<endl;
for(int i =0;i<rows;i++){
    for(int j =0;j<cols;j++){
        cout<<matrix[i][j]<<" ";
    }
    cout<<endl;
}

int Valueholder = 0;  //This will count the non zero values//
for(int i =0;i<rows;i++){
    for(int j =0;j<cols;j++){
        if(matrix[i][j] != '0'){
            Valueholder++;
        }
    }
}

int**sparse = new int*[Valueholder];
for(int i =0;i<Valueholder;i++){
    sparse[i] = new int[3];   //rows,cols,value//
}


int k =0;
for(int i =0;i<rows;i++){
    for(int j =0;j<cols;j++){
        if(matrix[i][j] != '0'){
            sparse[k][0] =i;
            sparse[k][1] = j;
            sparse[k][2] = matrix[i][j];
            k++;
        }
    }
}

cout<<"The sparse matrix is: "<<endl;
for(int i =0;i<Valueholder;i++){
    cout<<sparse[i][0]<<" "<<sparse[i][1]<<" "<<sparse[i][2]<<endl;
}

for(int i =0;i<rows;i++){
    delete[]matrix[i];
}
delete[]matrix;


for(int i =0;i,Valueholder;i++){
    delete[]sparse[i];
}
delete[]sparse;
    return 0;
}