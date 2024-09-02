#include<iostream>
using namespace std;
class date{
    int day;
    int month;
    int year;
    public:
date(){

}
date(int day,int month,int year){
    this->day=day;
    this->month=month;
    this->year=year;
}
virtual int accept(){
    cout<<"enter day"<<endl;
    cin>>day;
    cout<<"enter month"<<endl;
    cin>>month;
    cout<<"enter year"<<endl;
    cin>>year;
}
virtual int display(){
    cout<<day<<"/"<<month<<"/"<<year<<endl;
}
void displaydoj(){
    cout<<"date of join is = "<<day<<"/"<<month<<"/"<<year<<endl;
}
void displaydob(){
    cout<<"date of birth is = "<<day<<"/"<<month<<"/"<<year<<endl;
}
};
class person{
    protected:
    string name;
    string address;
    date dob;

    public:
    person(){

    }
    person(string name,string address,date dob){
        this->name=name;
        this->address=address;
        this->dob=dob;
    }

    int accept()
{
    cout<<"enter name->"<<endl;
    cin>>name;
    cout<<"enter address->"<<endl;
    cin>>address;
    cout<<"enter your date of birth"<<endl;
    dob.accept();
}

void display(){
    cout<<" name = "<<name<<endl;
    cout<< "address = "<<address<<endl;
    dob.display();
    dob.displaydob();

}
};
class employee: public person{
    int id;
    double salary;
    string department;
    date doj;
    public:
    employee(){

    }

    employee(int id,string name,string address,double salary,string department,date dob ,date doj ):person(name,address,dob){
        this->id=id;
        this->salary=salary;
        this->department=department;
        this->doj=doj;

    }

    int accept(){
        cout<<"enter empid"<<endl;
        cin>>id;
        cout<<"enter salary"<<endl;
        cin>>salary;
        cout<<"enter department"<<endl;
        cin>>department;
        person::accept();
        cout<<"enter your date of joining"<<endl;
        doj.accept();
    }

    void display(){
        cout<<"employee id = "<<id<<endl;
        cout<<"salary = "<<salary<<endl;
        cout<<"department = "<<department<<endl;
        person::display();
        doj.display();
        doj.displaydoj();
    }
};
int main(){
    employee e;
    e.accept();
    e.display();
    return 0;
}