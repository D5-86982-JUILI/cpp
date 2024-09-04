#include<iostream>
using namespace std;
class product{
    protected:
    int id;
    string title;
    int price;

    public:
    virtual void accept()=0;
    virtual void display()=0;
    virtual float discount()=0;
    virtual void acceptbook(){};
    virtual void acceptTape(){};
    static void calculatebill(product* products[],int size){
    float total=0.0;
    for (int i=0;i<3;i++){
        total += products[i]->discount();
        
    }
     cout<<"final bill = "<< total<<"Rs"<<endl;
}
    
    

    

};
class book:virtual public product{
    protected:
    string author;

    public:
    book(){}
    book(int id,string title,string author,double price){
        this->id=id;
        this->title=title;
        this->author=author;
        this->price=price;
    }

    float discount(){
        return price*0.90;
    }

    void accept(){
         cout<<"enter id "<<endl;
            cin>>id;
            cout<<"enter title"<<endl;
            cin>>title;
            cout<<"enter price"<<endl;
            cin>>price;
    }

    void acceptbook(){
        cout<<"enter author"<<endl;
        cin>>author;
    }

    void display(){
        cout<<" id = "<<id<<endl;
        cout<<" book title = "<<title<<endl;
        cout<<"author = "<<author<<endl;
        cout<<"price = "<<price<<"Rs"<<endl;
        cout<<"discounted price="<<discount()<<"Rs"<<endl;
    }
//     void calculatebill(){
//         book *arr[3];
//     float total=0.0;
//     for (int i=0;i<3;i++){
//         total=total + arr[i]->discount();
//          cout<<"final bill = "<< total<<endl;
//     }
// }
};



class tape:virtual public product{
    string artist;

    public:
    tape(){
    }

    tape(int tapeid,string title,string artist,double price){
        this->id=tapeid;
        this->title=title;
        this->artist=artist;
        this->price=price;
    }

    float discount(){
        return price * 0.95;

    }
    void accept(){
         cout<<"enter id "<<endl;
            cin>>id;
            cout<<"enter title"<<endl;
            cin>>title;
            cout<<"enter price"<<endl;
            cin>>price;

    }
    void acceptTape(){
        cout<<"enter artist"<<endl;
        cin>>artist;
    }

    void display(){
        cout<<"tapeid="<<id<<endl;
        cout<<"title="<<title<<endl;
        cout<<"artist="<<artist<<endl;
        cout<<"price="<<price<<endl;
        cout<<"discounted price = "<<discount()<<endl;
    }
    
};
// void calculatebill(){
//     tape *arr[3];
//     float total=0.0;
//     for (int i=0;i<3;i++){
//         total=total + arr[i]->discount();
//          cout<<"final bill = "<< total<<endl;
//     }
   
    
// }

int menu(){
    int choice;
    cout<<"0.exit"<<endl;
    cout<<"1. looking for book "<<endl;
    cout<<"2. looking for tape"<<endl;
    cout<<"3. calculate bill"<<endl;
    cout<<"enter your choice"<<endl;
    cin>>choice;
    return choice;
}

int main() {
    product* products[3];
    int productCount = 0;
    int choice;

    while ((choice=menu())!=0) {

        switch (choice) {


            case 1:
                cout<<"in case 1"<<endl;
                if (productCount < 3) {
                    for(int i=0;i<3;i++){
                    products[productCount] = new book();
                    products[productCount]->accept();
                    products[productCount]->acceptbook();
                     products[productCount]->display();

                    ++productCount;
                    }
                } else {
                    cout << "Product array is full." << endl;
                }
                break;

            case 2:{
                if (productCount < 3) {
                    for(int i=0;i<3;i++){
                    products[productCount] = new tape();
                    products[productCount]->accept();
                    products[productCount]->acceptTape();
                    products[productCount]->display();
                    ++productCount;}
                } else {
                    cout << "Product array is full." << endl;
                }}
                break;

            case 3:{
                product::calculatebill(products, productCount);}
                break;

             case 0:{
                cout << "Exiting... Thank you!!" << endl;
                // Cleanup
                for (int i = 0; i < productCount; ++i) {
                    delete products[i];
                }
                return 0;}
                break;

            default:
                cout << "Wrong choice. Please try again." << endl;
                break;
        }
    }

    return 0;
}