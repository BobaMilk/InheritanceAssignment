#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Appointment {
protected:
    string desc;
    int month;
    int day;
    int year;
    double cost;
public:
    Appointment() {
        desc = "";
        month = 0;
        day = 0;
        year = 0;
        cost = 0;
    }
    void setDecs(string d) {
        desc = d;
    }
    void setMonth(int m) {
        month = m;
    }
    void setDay(int d) {
        day = d;
    }
    void setYear(int y) {
        year = y;
    }
    void setCost(double x) {
        cost = x;
    }
    string getDecs() {
        return desc;
    }
    int getMonth() {
        return month;
    }
    int getDay() {
        return day;
    }
    int getYear() {
        return year;
    }
    double getCost() {
        return cost;
    }
    virtual void printReceipt() {
        cout << "Appointment\nTotal cost: " << getCost() << "\n\n";
    }
};

class Doctor : public Appointment {
private:
    bool urgentCare = false;
    bool checkUp = false;
    bool surgery = false;
public:
    void choice(char x) {
        if (x == 'u') {
            urgentCare = true;
        }
        else if (x == 'c') {
            checkUp = true;
        }
        else if (x == 's') {
            surgery = true;
        }
    }
    void printReceipt() {
        cout << "Thank you for visiting the Doctor\nTotal cost: " << getCost() << "\n\n";
    }
};

class Dentist : public Appointment {
private:
    bool cleanUp = false;
    bool toothRemoval = false;
    bool braces = false;
public:
    void choice(char x) {
        if (x == 'c') {
            cleanUp = true;
        }
        else if (x == 't') {
            toothRemoval = true;
        }
        else if (x == 'b') {
            braces = true;
        }
    }
    void printReceipt() {
        cout << "Thank you for visiting the Dentist\nTotal cost: " << getCost() << "\n\n";
    }
};

class Therapy : public Appointment {
private:
    bool behavioral = false;
    bool anxiety = false;
    bool depression = false;
public:
    void choice(char x) {
        if (x == 'b') {
            behavioral = true;
        }
        else if (x == 'a') {
            anxiety = true;
        }
        else if (x == 'd') {
            depression = true;
        }
    }
    void printReceipt() {
        cout << "Thank you for visiting the Therapy\nTotal cost: " << getCost() << "\n\n";
    }
};

class HairSalon : public Appointment {
private:
    bool hairDye = false;
    bool hairCut = false;
    bool perm = false;
public:
    void choice(char x) {
        if (x == 'd') {
            hairDye = true;
        }
        else if (x == 'c') {
            hairCut = true;
        }
        else if (x == 'p') {
            perm = true;
        }
    }
    void printReceipt() {
        cout << "Thank you for visiting the HairSalon\nTotal cost: " << getCost() << "\n\n";
    }
};

int main()
{
    int month, day, year, j = 1;
    vector<Appointment*> Appointments;

    HairSalon* app1 = new HairSalon;
    app1->setDecs("Hair Salon appointment.\n");
    app1->choice('p');
    app1->setMonth(3);
    app1->setDay(1);
    app1->setYear(2022);
    app1->setCost(60.2);
    Appointments.push_back(app1);
    app1->printReceipt();

    Doctor* app2 = new Doctor;
    app2->setDecs("Doctor appointment.\n");
    app2->choice('s');
    app2->setMonth(3);
    app2->setDay(1);
    app2->setYear(2022);
    app2->setCost(120.59);
    Appointments.push_back(app2);
    app2->printReceipt();

    Dentist* app3 = new Dentist;
    app3->setDecs("Dentist appointment.\n");
    app3->choice('b');
    app3->setMonth(2);
    app3->setDay(2);
    app3->setYear(2022);
    app3->setCost(86.34);
    Appointments.push_back(app3);
    app3->printReceipt();

    Therapy* app4 = new Therapy;
    app4->setDecs("Therapy appointment.\n");
    app4->choice('d');
    app4->setMonth(2);
    app4->setDay(2);
    app4->setYear(2022);
    app4->setCost(101.20);
    Appointments.push_back(app4);
    app4->printReceipt();

    cout << "Please enter a month. EX: 2\n";
    cin >> month;
    cout << "Please enter a day. EX: 17\n";
    cin >> day;
    cout << "Please enter a year. EX: 2003\n";
    cin >> year;
    cout << "\nPrinting out all the appointments on that date...\n\n";

    for (int i = 0; i < Appointments.size(); i++) {
        if (Appointments.at(i)->getMonth() == month) {
            if (Appointments.at(i)->getDay() == day) {
                if (Appointments.at(i)->getYear() == year) {
                    cout << "Appointment #" << j << "\n" << Appointments.at(i)->getDecs();
                    cout << Appointments.at(i)->getMonth() << "/" << Appointments.at(i)->getDay() << "/" << Appointments.at(i)->getYear() << endl;
                    Appointments.at(i)->printReceipt();
                    j++;
                }
            }
        }
    }
}
