/* Write a menu driven program for Student management. 
Create a class student with data members name, gender, rollNumber(Auto generated) and array to 
keep marks of three subjects.  
Accept every thing from user and Print name, rollNumber, gender and percentage. 
Provide global functions void sortRecords() and int searchRecords() for sorting and searching array. 
In main(), create Student* arr[5] and provide facility for accept, print, search and sort. 
Search function returns index of found Student, otherwise returns -1. 
sortRecord sorts the students array based on roll no in descending order. */



#include<iostream>
using namespace std;

class student {
    
    string name;
    string gender;
    static int generateroll;
    int roll;
    double marks[3];
    double sum;

public:
    student() : roll(++generateroll), sum(0) {
        this->name = "abc";
        this->gender = "f";
    }

    void accept() {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter your gender: ";
        cin >> gender;
        sum = 0; 
        for (int i = 0; i < 3; i++) {
            cout << "Enter marks for subject " << (i + 1) << ": ";
            cin >> marks[i];
            sum += marks[i];
        }
        sum = (sum / 300) * 100; 
    }

    void display() const {
        cout << "Name: " << name << endl;
        cout << "Gender: " << gender << endl;
        cout << "Roll No: " << roll << endl;
        for (int i = 0; i < 3; i++) {
            cout << "Marks in subject " << (i + 1) << ": " << marks[i] << endl;
        }
        cout << "Percentage: " << sum << "%" << endl;
    }
    void setroll(int roll){
        this->roll=roll;
    }

    int getroll(){
        return roll;
    }
};

int student::generateroll = 100;

void sortRecords(student *arr[],int size){
    for (int i=0;i<size-1;i++){
        for (int j=i+1;j<size;j++){
            if(arr[i]->getroll()<arr[j]->getroll()){
                student *temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }

}

int searchRecords(student*arr[],int size,int rollnumber){
    for(int i=0;i<size;i++){
        if(arr[i]->getroll()==rollnumber){
            return i;
        }

    }
    return -1;
}


int main() {
    student* arr[5];
    for (int i = 0; i < 5; i++) {
        arr[i]=new student();}

        int choice;
        do {
            int choice;
        cout<<"0. exit"<<endl;
        cout<<"1. Accept student details" << endl;
        cout <<"2. Print student details" << endl;
        cout <<"3. Search for a student by roll number" << endl;
        cout <<"4. Sort student records by roll number" << endl;
        cout<<"enter your choice"<<endl;
        cin>>choice;
            switch (choice)
            {
            case 0:
                for(int i=0;i<5;i++){
                    delete arr[i];
                    arr[i]=NULL;
                    exit(0);
                }
                break;

            case 1:
            for (int i=0;i<5;i++){
                arr[i]->accept();
            }
            break;

            case 2:
            for (int i=0;i<5;i++){
                arr[i]->display();
            }
            break;

            case 3:
            int roll;
            cout<<"enter rollno";
            cin>>roll;
            for(int i=0;i<1;i++){
              int index = searchRecords(arr,5,roll);
                if(index !=-1){
                    cout<<"student found at index = "<<index<<endl;
                    arr[index]->display();
                }
                else
                cout<<"student not found"<<endl;
            }
            break;

            case 4:
             sortRecords(arr,5);
                cout<<"record sorted"<<endl;
            break;

            default:
            cout<<"wrong choice :("<<endl;
                break;
            }
        }
        while (choice != 4);
    
    return 0;
}
