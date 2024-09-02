#include<iostream>
using namespace std;
class volume{
    int length;
    int width;
    int height;
public:

    volume(){
        length=1;
        width=2;
        height=3;
        cout<<"volume of default input is "<<length*width*height<<endl;
        
    }
    volume(int x,int y,int z){
        length =x;
        width = y;
        height=z;
    }
    volume(int val){
        length=val;
        width=val;
        height=val;
    
    }

    void display(){
                cout<<"volume of given input is "<<length*width*height<<endl;

    }

};
int menu(){
    int choice;
    cout<<endl<<"0. exit"<<endl;
    cout<<"1. calculate volume with default values"<<endl;
    cout<<"2.calculate volume with same L,W,H"<<endl;
    cout<<"3. calculate volume with different L,B,W"<<endl;
    cout<<"Enter your choice"<<endl;
    cin>>choice;
    return choice;
}


int main(){
    int choice;
    volume v1;
    volume v2(5);
    volume v3(6,4,8);
    while((choice=menu())!=0)
    {
        switch (choice){
            case 1:
             v1.display();
             break;

            case 2:
             v2.display();
             break;
            case 3:
            v3.display();
            break;
            default :
            cout<<"wrong choice"<<endl;
        }
    }

    return 0;
}