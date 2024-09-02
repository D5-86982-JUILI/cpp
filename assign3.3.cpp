#include<iostream>
using namespace std;
class stack{
    int *arr;
    int top;
    int capacity;

    public:
    stack(int size=5){
        arr=new int[size];
        capacity=size;
        top=-1;
    }

    bool isfull(){
        return top==capacity-1;
    }

    bool isempty(){
        return top==-1;
    }

    int push(int x){
        if(isfull()){
            cout<<"stack is full cannot push any value"<<x<<endl;
            return 0;
        }
        else{
            arr[++top]=x;
        }
    }

    ~stack(){
        delete []arr;
    }

    int  pop(){
        if(isempty()){
            cout<<"stack is empty cannot pop any value"<<endl;
            return -1;
        }

        return arr[top--];
    }

    int peek(){
        if(isempty()){
            cout<<"stack is empty"<<endl;
            return -1;
        }

        return arr[top];
    }

    void print(){
        if(isempty()){
            cout<<"stack is empty"<<endl;
            return;
        }

        for(int i=0;i<=top;i++){
            cout<<arr[i]<<""<<endl;
        }
        cout<<endl;
    }


};

int menu(){
    int choice;
    cout<<endl<<"0. exit"<<endl;
    cout<<"1. check is stack is empty"<<endl;
    cout<<"2.check is stack is full"<<endl;
    cout<<"3.push a value"<<endl;
    cout<<"4. pop the value"<<endl;
    cout<<"5.peek the value"<<endl;
    cout<<"6.print the stack"<<endl;
    cin>>choice;
    return choice;
}

int main(){
    int choice;
    stack s;
    while((choice=menu())!=0){
        int value;
        switch (choice)
        {
        case 1:
           if (s.isempty()){
            cout<<"stack is empty"<<endl;
           }
           else
           cout<<"stack is full"<<endl;
            break;

        case 2:
            if(s.isfull()){
                cout<<"stack is full"<<endl;
            }
            else
            cout<<"stack is empty"<<endl;
            break;

        case 3:
             if(s.isfull()){
                cout<<"stack is full cannot push any value"<<endl;
             }
             else 
             cout<<"enter value"<<endl;
             cin>>value;
             s.push(value);
             break;

        case 4:
        cout<<"popped element is ="<<s.pop()<<endl;
        break;

        case 5:
        if(s.isempty()){
            cout<<"stack is empty cannot peek any value"<<endl;
        }
        else
        s.peek();
        cout<<"element on top="<<s.peek()<<endl;
        break;

        case 6:
        if(s.isempty()){
            cout<<"stack is empty"<<endl;
        }
        cout<<"stack elements="<<endl;
        s.print();
        break;

        
        default:
        cout<<"wrong choice entered :("<<endl;
         break;
        }
    }
    return 0;
}