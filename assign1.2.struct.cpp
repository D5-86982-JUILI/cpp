#include<iostream>
using namespace std;
struct date
{
    int day;
    int month;
    int year;

    void initdate(){
    day = 1;
    month = 01;
    year = 2001;
    cout<<"default date is "<<day<<"-"<<month<<"-"<<year<<endl;
}
void AcceptDate (){
    cout<<"Enter Day:"<<endl;
    cin>>day;
    cout<<"Enter month:"<<endl;
    cin>>month;
    cout<<"Enter year:"<<endl;
    cin>>year;
}

void printdate(){
    cout<<"date: "<<day<<"-"<<month<<"-"<<year<<endl;
}

bool leapyear(){
    bool b1;

    if (year%400==0 || year%4 ==0 && year%100 !=0){
       cout<<b1<<endl;
        
    }
    else{
        cout<<b1<<endl;
    }
}
};
int menu(){
    int choice;
    cout<<"0. exit"<<endl;
     cout<<"1. default date: "<<endl;
    cout<<"2. accept date"<<endl;
    cout<<"3. print date"<<endl;
    cout<<"4. look for leap year"<<endl;
    cout<<"Enter your choice"<<endl;
    cin>>choice;
    return choice;
}

int main(){
    struct date d1;
   int choice;
   while((choice=menu())!=0){
    switch (choice)
    {
    case 1:
       d1.initdate();
        break;

    case 2:
    d1.AcceptDate();
    break;

    case 3:
    d1.printdate();
    break;

    case 4:
    d1.leapyear();
    break;
    
    default:
    cout<<"wrong choice"<<endl;
        break;
    }
   }


}
