#include<iostream>
#include<cstring>
using namespace std;
class Exam{
    public:
    char *studentName;
    char*examDate;
    float score;
    Exam(){
    }
    Exam(const char*Name,const char*Date,float score){  //constructor
       studentName = new char[strlen(Name)+1];
       strcpy(studentName,Name);

       examDate = new char[strlen(Date)+1];
       strcpy(examDate,Date);

       this->score = score;
    }

   void setAttributes(char*name,char*date,float score){
    delete[]studentName;
    delete[]examDate;
    studentName = new char[strlen(name)+1];
    strcpy(studentName,name);

    examDate = new char[strlen(date)+1];
    strcpy(examDate,date);

    this->score = score;
   }

    ~Exam(){   //destructor//
        delete[]studentName;
        delete[]examDate;
    }

    void display(){
        cout<<"Student Name is: "<<studentName<<endl;
        cout<<"Exam date is: "<<examDate<<endl;
        cout<<"Student score is: "<<score<<endl;
    }
};
int main(){
   Exam student1("yash raj","25-09-25",99.7);
   student1.display();

   //shallow copy//
   Exam student2 = student1;
   student2.display();


   cout<<"After modification : "<<endl;
   student2.setAttributes("Saad","24-08-25",99.8);
   student2.display();

   student1.display();
   
    return 0;

}