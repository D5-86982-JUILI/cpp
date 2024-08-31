#include<iostream>
using namespace std;
namespace Nstudent{
class student{
    int rollno;
    string name;
    int marks;
public:
    void initstudent(){
        rollno=1;
        name="ABC";
        marks=95;
        cout<<"rollno "<<rollno<<"name "<<name<<"marks "<<marks; 
    }
    void acceptdata(){
        cout<<"Enter roll no "<<endl;
        cin>>rollno;
        cout<<"Enter name"<<endl;
        cin>>name;
        cout<<"enter marks"<<endl;
        cin>>marks;
    }
    void printdata(){
        cout<<"rollno= "<<rollno<<" name= "<<name<<" marks= "<<marks<<endl;
    }
};
}
int menu(){
    int choice;
    cout<<"0. exit"<<endl;
    cout<<"1. accept student data"<<endl;
    cout<<"2. print student data"<<endl;
     cout<<"3. default student info: "<<endl;
    cout<<"Enter your choice"<<endl;
    cin>>choice;
    return choice;
}
int main(){
    int choice;
    Nstudent :: student s1;
    while((choice=menu())!=0){
            switch (choice)
    {
    case 1:
       s1.acceptdata();
        break;

    case 2:
        s1.printdata();
        break;
    
    case 3:
        s1.initstudent();
        break;
    
    default:
        cout<<"wrong choice"<<endl;
        break;
    }


    }


}