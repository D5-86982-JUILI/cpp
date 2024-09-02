 /*Create a class Date with data memebrs day,month and year. 
Cretae a class Person with data members name,address and birthdate. The birthdate shoud be of 
type Date. 
Implement above classes. Test all functionalities in main().\*/

#include<iostream>
using namespace std;

class date{
    private:
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

    void setday(int day){
        this->day=day;
    }

    int getday(){
        return day;
    }

    void setmonth(int month){
        this->month=month;
    }

    int getmonth(){
        return month;
    }

    void setyear(int year){
        this->year=year;
    }
    int getyear(){
        return year;
    }

    int accept(){
         cout<<"enter your date of birth"<<endl;
        cout<<"enter day = "<<endl;
        cin>>day;
        cout<<"enter month = "<<endl;
        cin>>month;
        cout<<"enter year = "<<endl;
        cin>>year;
    }
    void display(){
        cout<<""<<day<<"/"<<month<<"/"<<year<<endl;
    }
};
class person{
    private:
    string name;
    string address;
    date d1;

    public:
    string acceptperson(){
        cout<<"enter your name"<<endl;
        cin>>name;
        cout<<"enter address"<<endl;
        cin>>address;
        d1.accept();
    }
    void display(){
        cout<<"name= "<<name<<endl<<"adress= "<<address<<endl;
        d1.display();
    }
};
int main(){
    person p1;
    p1.acceptperson();
    p1.display();
    date d1;
    d1.setday(1);
    d1.getday();
    d1.setmonth(12);
    d1.getmonth();
    d1.setyear(2024);
    d1.getyear();
    return 0;
}