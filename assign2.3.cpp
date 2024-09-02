#include<iostream>
using namespace std;
class address{
    string b;
    string street;
    string city;
    int pin;
public:

    address(){
        b="kaveri";
        street="laxmi";
        city="pune";
        pin=411033;
    }
    void setb(string b){
        this->b= b;
    }
    void setstreet(string street){
        this->street=street;
    }
    void setcity(string city){
        this->city=city;
    }
    void setpin(int pin){
        this->pin=pin;
    }
    string getb(){
        return b;
    }

    void accept(){
        cout<<"enter building"<<endl;
        cin>>b;
        cout<<"enter street"<<endl;
        cin>>street;
        cout<<"enter city"<<endl;
        cin>>city;
        cout<<"enter pin"<<endl;
        cin>>pin;

    }
    void display(){
        cout<<" building ="<<b<<endl;
        cout<<" street ="<<street<<endl;
        cout<<" city = "<<city<<endl;
        cout<<" pin ="<<pin<<endl;

    }


};


int main(){
address a1;
//a1.setb("venna");
cout<<a1.getb()<<endl;
a1.accept();
a1.display();
}
