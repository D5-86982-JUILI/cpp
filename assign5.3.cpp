/* Implement following classes. Test all functionalities in main() of each created class. Note that 
employee is inherited into manager and salesman.*/
#include<iostream>
#include<typeinfo>
using namespace std;

class employee{
    protected:
    int id;
    double salary;
    public:
    employee(){

    }

    employee(int id,double salary){
        this->id=id;
        this->salary=salary;
    }

    void setid(int id){
        this->id=id;
    }

    int getid(){
        return id;
    }

    void setsalary(double salary){
        this->salary=salary;
    }

    double getsalary(){
        return salary;
    }

    virtual void accept(){
        cout<<"Enter ID - "<<endl;
        cin>>id;
        cout<<"Enter salary - "<<endl;
        cin>>salary;
    }

   virtual void display(){
        cout<<"ID ="<<id<<endl;
        cout<<"Salary ="<<salary<<endl;
    }
};

class manager:virtual public employee{
    protected:
    double bonus;

    protected:
    void acceptmanager(){
        cout<<"enter bonus = "<<endl;
        cin>>bonus;
    }

    void displaymananger(){
        cout<<"bonus = "<<bonus<<endl;
    }

    public:
    manager(){}
    manager(int id,double salary,double bonus){
        this->id=id;
        this->salary=salary;
        this->bonus=bonus;
    }

    void setbonus(double bonus){
        this->bonus=bonus;
    }

    double getbonus(){
        return bonus;
    }

    void accept(){
        employee::accept();
        acceptmanager();
    }

    void display(){
        employee::display();
        displaymananger();
    }

    
};

class salesman: virtual public employee{
    protected :
    double commission;

    protected:
    void acceptsalesman(){
        cout<<"enter commission - "<<endl;
        cin>>commission;
    }

    void displaysalesman(){
        cout<<"commission = "<<commission<<endl;
    }

    public:
    salesman(){}
    salesman(int id,double salary,double commission){
        this->id=id;
        this->salary=salary;
        this->commission=commission;
    }

    void setcommission(double commission){
        this->commission=commission;
    }
    double getcommission(){
        return commission;
    }

    void accept(){
        employee::accept();
        acceptsalesman();
    }

    void display(){
        employee::display();
        displaysalesman();
    
    
}};

class salesmanager:public manager , public salesman{
    public:
    salesmanager(){}
    salesmanager(int id,double salary,double bonus,double commission){
        this->id=id;
        this->salary=salary;
        this->bonus=bonus;
        this->commission=commission;
    }
    void accept(){
        employee::accept();
        acceptmanager();
        acceptsalesman();
    }

    void display(){
        employee::display();
        displaymananger();
        displaysalesman();
    }
};



 

int main(){
   employee* eptr = new salesman();
    eptr->accept();
    eptr->display();
    delete eptr; 
    eptr=NULL;
    employee* e1ptr = new manager();
    e1ptr->accept();
    e1ptr->display();
    delete e1ptr; 
    e1ptr=NULL;
    salesman* s1= new salesmanager();
    s1->accept();
    s1->display();
    s1->setid(5);
    s1->getid();     

}
