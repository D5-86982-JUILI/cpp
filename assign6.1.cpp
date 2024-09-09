#include <iostream>
#include <vector>
using namespace std;

class Employee
{
protected:
    int id;
    double salary;

public:
    Employee() : id(0), salary(0) {}
    Employee(int id, double salary) : id(id), salary(salary) {}

    virtual void accept()
    {
        cout << "Enter Employee ID: ";
        cin >> id;
        cout << "Enter Employee Salary : ";
        cin >> salary;
    }

    virtual void display()
    {
        cout << "Employee ID : " << id << ", Salary : " << salary << endl;
    }

    virtual ~Employee() {}
};

class Manager : virtual public Employee
{
protected:
    double bonus;

public:
    Manager() : Employee(), bonus(0) {}
    Manager(int id, double salary, double bonus) : Employee(id, salary), bonus(bonus) {}

    void accept()
    {
        Employee::accept();
        cout << "Enter Manager Bonus : ";
        cin >> bonus;
    }

    void display()
    {
        Employee::display();
        cout << "Manager Bonus : " << bonus << endl;
    }
};

class Salesman : virtual public Employee
{
protected:
    double commission;

public:
    Salesman() : Employee(), commission(0) {}
    Salesman(int id, double salary, double commission) : Employee(id, salary), commission(commission) {}

    void accept()
    {
        Employee::accept();
        cout << "Enter Salesman Commission : ";
        cin >> commission;
    }

    void display()
    {
        Employee::display();
        cout << "Salesman Commission : " << commission << endl;
    }
};

class SalesManager : public Manager, public Salesman
{
public:
    SalesManager() : Employee(), Manager(), Salesman() {}
    SalesManager(int id, double salary, double bonus, double commission)
    {
        this->id = id;
        this->salary = salary;
        this->bonus = bonus;
        this->commission = commission;
    }

    void accept()
    {
        Employee::accept();
        cout << "Enter SalesManager Bonus : ";
        cin >> bonus;
        cout << "Enter SalesManager Commission : ";
        cin >> commission;
    }

    void display()
    {
        Employee::display();
        cout << "SalesManager Bonus : " << bonus << endl;
        cout << "SalesManager Commission : " << commission << endl;
    }
};

void displayMenu()
{
    cout << "\nMenu: " << endl;
    cout << "1. Accept Employee" << endl;
    cout << "  a. Accept Manager" << endl;
    cout << "  b. Accept Salesman" << endl;
    cout << "  c. Accept SalesManager" << endl;
    cout << "2. Display count of employees by designation" << endl;
    cout << "3. Display All Managers" << endl;
    cout << "4. Display All Salesmen" << endl;
    cout << "5. Display All SalesManagers" << endl;
    cout << "6. EXIT" << endl;
}

int main()
{
    vector<Employee *> employees;
    int choice;
    int managerCount = 0, salesmanCount = 0, salesManagerCount = 0;

    do
    {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter designation type (1: Manager, 2: Salesman, 3: SalesManager): ";
            int type;
            cin >> type;
            if (type == 1)
            {
                Manager *mgr = new Manager();
                mgr->accept();
                employees.push_back(mgr);
                managerCount++;
            }
            else if (type == 2)
            {
                Salesman *slmn = new Salesman();
                slmn->accept();
                employees.push_back(slmn);
                salesmanCount++;
            }
            else if (type == 3)
            {
                SalesManager *smgr = new SalesManager();
                smgr->accept();
                employees.push_back(smgr);
                salesManagerCount++;
            }
            break;

        case 2:
            cout << "Total Managers: " << managerCount << endl;
            cout << "Total Salesmen: " << salesmanCount << endl;
            cout << "Total SalesManagers: " << salesManagerCount << endl;
            break;

        case 3:
            cout << "\nAll Managers:\n";
            for (auto emp : employees)
            {
                if (dynamic_cast<Manager *>(emp) && !dynamic_cast<SalesManager *>(emp)) // Check if it's a Manager, not a SalesManager
                {
                    emp->display();
                }
            }
            break;

        case 4:
            cout << "\nAll Salesmen:\n";
            for (auto emp : employees)
            {
                if (dynamic_cast<Salesman *>(emp) && !dynamic_cast<SalesManager *>(emp)) // Check if it's a Salesman, not a SalesManager
                {
                    emp->display();
                }
            }
            break;

        case 5:
            cout << "\nAll SalesManagers:\n";
            for (auto emp : employees)
            {
                if (dynamic_cast<SalesManager *>(emp)) // Check if it's a SalesManager
                {
                    emp->display();
                }
            }
            break;

        case 6:
            cout << "Exiting..." << endl;
            break;

        default:
            cout << "Invalid choice! Please try again." << endl;
        }

    } while (choice != 6);

    // deleting dynamically allocated memory
    for (int i = 0; i < employees.size(); i++)
    {
        delete employees[i];
    }

    return 0;
}