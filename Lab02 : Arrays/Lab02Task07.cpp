#include<iostream>
using namespace std;
int main(){
    int department;
    cout<<"Enter the number of departments: "<<endl;
    cin>>department;

    int** jaggedArray = new int*[department];
    int* employee = new int[department];

    for(int i =0;i<department;i++){
        cout<<"Enter the number of employees of "<<i+1<<" Departments: "<<endl;
        cin>>employee[i];
        jaggedArray[i] = new int[employee[i]];
    }

    cout<<"Enter the salaries: "<<endl;
    for(int i =0;i<department;i++){
        for(int j=0;j<employee[i];j++){
            cin>>jaggedArray[i][j];
        }
    }

    cout<<"Departments and their employees: "<<endl;
    for(int i =0;i<department;i++){
        for(int j=0;j<employee[i];j++){
            cout<<jaggedArray[i][j]<<" ";
        }
        cout<<endl;
    }

    int highest = jaggedArray[0][0];
    for(int i =0;i<department;i++){
        for(int j=0;j<employee[i];j++){
            if(jaggedArray[i][j] > highest){
                highest = jaggedArray[i][j];
            }
        }
    }

    cout<<"The highest employee value is: "<<highest<<endl;

    return 0;
}
