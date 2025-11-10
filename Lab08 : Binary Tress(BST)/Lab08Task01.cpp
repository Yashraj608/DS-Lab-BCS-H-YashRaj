#include<iostream>
using namespace std;
class Node{
public:
string name;
Node*mother,*father;
Node(string name){
    this->name = name;
    mother = father = nullptr;
}
};

void DisplayLevels(Node*root, int level = 1){
    if(!root){
        return;
    }
    cout<<root->name<<" is at level "<<level<<endl;
    DisplayLevels(root->mother,level+1);
    DisplayLevels(root->father, level+1);
}


void DisplayRoot(Node*root){
     if(!root){
        cout<<"There is no hirearchy"<<endl;
    }
  else{
      cout<<"Youngest Root is: "<<root->name<<" ";
  }
    
}


void DisplayInorder(Node*root){
    if(!root){
        return;
    }
    DisplayInorder(root->mother);
    cout<<root->name<<endl;
    DisplayInorder(root->father);
}


void DisplayLeaves(Node*root){
    if(!root){
        return;
    }
    if(!root->mother && !root->father){
        cout<<root->name<<" is a leaf Node"<<endl;
    }
    DisplayLeaves(root->mother);
    DisplayLeaves(root->father);
}


int Height(Node*root){
    if(root==nullptr){
        return 0;
    }
    int LeftHeight = Height(root->mother);
    int RightHeight = Height(root->father);
    return max(LeftHeight,RightHeight)+1;
}

int main(){
Node*child = new Node("child");
child->father = new Node("Child's Father");
child->mother = new Node("Child's Mother");

child->mother->mother = new Node("Child's Maternal GrandMother");
child->mother->father = new Node("Child's Maternal GrandFather ");

child->father->mother = new Node("Child GrandMother");
child->father->father = new Node("Child's GrandFather");


DisplayRoot(child);
cout<<endl;
DisplayLeaves(child);
cout<<endl;
DisplayInorder(child);

cout<<"Height is :"<<Height(child)<<endl;
    return 0;
}