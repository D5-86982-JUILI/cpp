#include<iostream>
using namespace std;
class time{
    private:
    int h;
    int m;
    int s;

public:
time(){
    this->h=0;
    this->m=0;
    this->s=0;
}

time(int h,int m,int s){
    this->h=h;
    this->m=m;
    this->s=s;
}
void seth(int h){
    this->h=h;
}

int geth(){
    return h;
}
void setm(int m){
    this->m=m;
}
int getm(){
    return m;
}
void sets(int s){
    this->s=s;
}
int gets(){
    return s;
}
void accept(){
    cout<<"enter hours="<<endl;
    cin>>h;
    cout<<"enter mins="<<endl;
    cin>>m;
    cout<<"enter seconds="<<endl;
    cin>>s;
}
void print(){
    cout<<" time= "<<h<<":"<<m<<":"<<s<<endl;
}
};
int main(){
    time *arr[3];
    arr[0] = new time();
    arr[0]->accept();
    arr[0]->print();
    arr[1]= new time(8,5,56);
    arr[0]->seth(3);
    cout<<arr[0]->geth()<<endl;
    arr[0]->setm(5);
    cout<<arr[0]->getm()<<endl;
    arr[0]->sets(10);
    cout<<arr[0]->gets()<<endl;
    arr[1]->print();
    delete arr[0];
    delete arr[1];
    arr[0]=NULL;
    arr[1]= NULL;
    return 0;
}