#include<iostream>
#include<string>
using namespace std;
class Box{
public:
int*number;
Box(int number){ //constructor
    this->number = new int(number);
}

//Copy constructor to make the deep copy//
Box(Box const& other){
    number = new int(*(other.number));
}

Box& operator = (const Box& other){
  if(this != &other){
    delete number;
    number = new int(*(other.number));
  }
  return *this;
}

void display(){
    cout<<"number is: "<<*number<<endl;
}

~Box(){
    delete number;  //Here double[] brackets are not used because this is single not array or something//
}
};
int main(){
    Box b1(30);
    Box b2 = b1; //deep copy using constructor//
    b2.display();
    Box b3(40);
    b3 = b1; // deep copy using the copy assignment//
    b3.display();
    b1.display();

    return 0;
}