#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

class Employee {
protected:
    int Eno, d, o, j, exp;
    string name;
    int salary;

public:
    Employee() {
        cout << "Enter Employee's Name: ";
        cin >> name;
        cout << "Enter Employee's Number: ";
        cin >> Eno;
    };

    Employee(int no, string ame) {
        Eno = no;
        name = ame;
    }

    void get() {
        cout << "Enter Employee's date of joining (Date Month Year): ";
        cin >> d >> o >> j;
        cout << "Enter Employee's salary: ";
        cin >> salary;
        cout << "Enter Employee's experience: ";
        cin >> exp;
    }

    void show() {
        cout << "Employee Name is " << setw(15) << left << name << endl;
        cout << "Employee Number is " << setw(15) << left << Eno << endl;
        cout << "Employee Date of Joining is " << setw(2) << d << " " << setw(2) << o << " " << setw(4) << j << endl;
        cout << "Employee Experience is " << setw(15) << left << exp << endl;
        cout << "Employee Salary is " << salary << endl;
    }

    void nsalary() {
        float intSalary = salary;
        cout << "Employee's salary is " << intSalary << endl;
    }

    ~Employee() {
        cout << "Thank You";
    };

    static void comp() {
        const string comp = "ABC";
        cout << "Company :  " << comp << endl;
    };

    static void count() {
        static int count = 0;
        count++;
        cout << "Employee " << count << endl;
    };

    friend void clientFunction(Employee& emp);

    void saveToFile() {
        ofstream outFile("employees.txt", ios::app);
        if (outFile.is_open()) {
            outFile << name << " " << Eno << " " << d << " " << o << " " << j << " " << exp << " " << salary << "\n";
            outFile.close();
        }
    }

    bool operator==(const Employee& other) const {
        return Eno == other.Eno;
    }

    friend ostream& operator<<(ostream& os, const Employee& emp) {
        os << "Employee Name is " << setw(15) << left << emp.name << endl;
        os << "Employee Number is " << setw(15) << left << emp.Eno << endl;
        os << "Employee Date of Joining is " << setw(2) << emp.d << " " << setw(2) << emp.o << " " << setw(4) << emp.j << endl;
        os << "Employee Experience is " << setw(15) << left << emp.exp << endl;
        os << "Employee Salary is " << emp.salary << endl;
        return os;
    }
};

inline void message() {
    cout << "Welcome to the Employee Management System!" << endl;
};
class Manager:public Employee{
    private:char title[80];
            double Pay;
    public:Manager(){
        Employee::get();
        cout<<"Enter Title: ";
        cin>>title;
        cout<<"Payment: ";
        cin>>Pay;
    }
    void virtual showdata(){
        Employee::show();
        cout<<"Title is"<<this->title<<"Payment"<<this->Pay;
    }
};
class Scientist:public Employee{
    private: string publication;
    public: Scientist(){
        Employee::get();
        cout<<"Number of Publications";
        cin>>publication;
    }
    void virtual showdata(){
        Employee::get();
        cout<<"Total Publications: "<<this->publication;
    }
};
class client {
    string cname;
public:
    void gech() {
        cout << "Name of Client Organisation: ";
        cin >> cname;
        Employee emp;
        clientFunction(emp);
    }
};
void clientFunction(Employee& emp) {
    cout << "Client can access Employee's private Info:" << endl;
    cout << "Employee Name is " << emp.name << endl;
    cout << "Employee Number is " << emp.Eno << endl;
    cout << "Employee Date of Joining is " << emp.d << " " << emp.o << " " << emp.j << endl;
    cout << "Employee Experience is " << emp.exp << endl;
}

int main() {
    int i=0,n;
    Employee::comp();
    message();
    cout<<"Enter Number of employees: ";
    cin>>n;
    Employee *e = new Employee[n];
    for(int i=0; i<n; i++){
    e[i].get();
    e[i].show();
    e[i].nsalary();
}
    Employee k(8,"Mahesh");
    Employee::count();
    k.get();
    k.show();
    k.nsalary();
    
    Scientist s1;
    cout<<"Enter data for Scientist";
    s1.showdata();
    
    Manager m1;
    m1.showdata();
    Employee emp1;
    Employee emp2;
    if (emp1 == emp2) {
    cout << "Employees are the same" << endl;
    } else {
    cout << "Employees are different" << endl;
    }
    cout << emp1; 
    cout << emp2;
    
    delete[] e;
    
    return 0;
}
