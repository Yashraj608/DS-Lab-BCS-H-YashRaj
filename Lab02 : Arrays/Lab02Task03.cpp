#include<iostream>
using namespace std;
int main(){
    int rows;
    cout<<"Enter the rows: "<<endl;
    cin>>rows;
    int **arr = new int*[rows];
    int *cols = new int[rows];
    for(int i=0;i<rows;i++){
        cout<<"Enter the cols: "<<i+1<<"row :"<<endl;
        cin>>cols[i];
        arr[i] = new int[cols[i]];
    }

    cout<<"Enter the elements : "<<endl;
    for(int i =0;i<rows;i++){
        for(int j =0;j<cols[i];j++){
            cin>>arr[i][j];
        }
    }

    for(int i=0;i<rows;i++){
        for(int j =0;j<cols[i];j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    int*avg = new int[rows];
    for(int i =0;i<rows;i++){
        int sum =0;
        for(int j=0;j<cols[i];j++){
       sum += arr[i][j];
        }
        avg[i] = sum/cols[i]; 
    }

    for(int i =0;i<rows;i++){
        cout<<"Average is: "<<avg[i]<<endl;
    }
    
    return 0;
}