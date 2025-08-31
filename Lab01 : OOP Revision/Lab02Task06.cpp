#include<iostream>
using namespace std;
class safePointer{
private:
int*data;
public:
safePointer(){
    data = new int;
}
void setvalue(int value){
    *data = value;
}
int getvalue(){
    return *data;
}

void release(){
    delete data;
    data = nullptr;
}


};
int main(){
    safePointer students[5];
    for(int i =0;i<5;i++){
        int marks;
        cout<<"Enter the students marks"<<endl;
        cin>>marks;
        students[i].setvalue(marks);
        students[i].getvalue();
        students[i].release();
    }
    return 0;
}
