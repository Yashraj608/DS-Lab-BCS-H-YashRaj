#include<iostream>
using namespace std;
int main(){
    int benches;  //Rows//
    int seats; //Cols//
    cout<<"Enter the number off benches(rows):"<<endl;
    cin>>benches;
    cout<<"Enter the number of seats:"<<endl;
    cin>>seats;
    int**arr = new int*[benches];
 
    for(int i =0;i<benches;i++){
     arr[i] = new int[seats]{0};
    }

    for(int i =0;i<benches;i++){
        for(int j =0;j<seats;j++){
            cin>>arr[i][j];
        }
    }

    for(int i =0;i<benches;i++){
        for(int j =0;j<seats;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    for(int i =0;i<benches;i++){
    delete[]arr[i];
    }
    delete[]arr;
    return 0;
}