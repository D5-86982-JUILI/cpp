#include <iostream>
using namespace std;


int factorial(int n) {
    if (n < 0) 
        throw 2;
    if (n == 0 || n == 1) 
        return 1;
    return n * factorial(n - 1);
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    try {
        int result = factorial(n);
        cout << "Factorial is = " << result << endl;
    }
    catch (int error) {
        cout << "Factorial is not defined for negative numbers"<<endl;
    }
    
    return 0;
}
