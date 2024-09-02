#include<iostream>
using namespace std;

class cylinder{
    private:
    double radius;
    double height;
    static int pi;

public:
    cylinder():radius(1),height(1){

    }
    
    cylinder(double radius,double height){
        this->radius=radius;
        this->height=height;
        this->pi=pi;
    }

    cylinder(double val):cylinder(val,val){
    }

    void setradius(int radius){
        this->radius=radius;
   }
   int getradius(){
    return radius;
   }
   void setheight(int height){
    this->height=height;
   }
   int getheight(){
    return height;
   }
   void calculatevolume(){
    cout<<"enter radius"<<endl;
    cin>>radius;
    cout<<"enter height"<<endl;
    cin>>height;
    cout<<"volume is = "<<3.14*radius*radius*height<<endl;
   }
   void display(){
     cout<<"volume is = "<<3.14*radius*radius*height<<endl;
   }

};
int cylinder::pi=3.14;
int main(){
    cylinder c1;
    cylinder c2(4);
    cylinder c3(8,8);
    cout<<c1.getradius()<<endl;
    cout<<c1.getheight()<<endl;
    c1.calculatevolume();
    c2.display();
    c3.display();
    

}