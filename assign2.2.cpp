#include <iostream>
using namespace std;

class Tollbooth {
private:
    unsigned int TC;  
    double TM;       
    static unsigned int generateTC;  
    static double generateTM;        

public:
    Tollbooth() : TC(0), TM(0.0) {} 

    void payingCar() {
        TC++;
        TM += 0.50;
        generateTC++;
        generateTM = TM;
    }

    void noPayCar() {
        TC++;
        generateTC++;
    }

    void display() const {
        cout << "Total cars: " << TC << endl;
        cout << "Total money: " << TM << endl;
    }

    static unsigned int getGenerateTC() {
        return generateTC;
    }

    static double getGenerateTM() {
        return generateTM;
    }
};


unsigned int Tollbooth::generateTC = 0;
double Tollbooth::generateTM = 0;

int menu() {
    int choice;
    cout << "0. Exit" << endl;
    cout << "1. Add paying car" << endl;
    cout << "2. Add non-paying car" << endl;
    cout << "Your choice: ";
    cin >> choice;
    return choice;
}

int main() {
    int choice;
    Tollbooth t;  // Single instance of Tollbooth

    while ((choice = menu()) != 0) {
        switch (choice) {
            case 1:
                t.payingCar();
                t.display();
                break;
            case 2:
                t.noPayCar();
                t.display();
                break;
            default:
                cout << "Wrong choice" << endl;
                break;
        }
    }

    return 0;
}
