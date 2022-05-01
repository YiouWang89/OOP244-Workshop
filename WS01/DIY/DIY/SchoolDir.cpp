#include <iostream>
#include "School.h"
using namespace std;
using namespace sdds;

void flushkeys();
bool yes();

// flushes the keyboard
void flushkeys() {
    while (cin.get() != '\n');
}

// returns true if user enter y or Y
bool yes() {
    char ch = cin.get();
    flushkeys();
    return ch == 'y' || ch == 'Y';
}

int main() {
    bool done = false;
    char name[5];
    loadSchools();
    cout << " Seneca School Extension search. " << endl << endl;
    while (!done) {
        cout << "Enter the School code: ";
        cin >> name;
        flushkeys();
        displaySchoolWithExtention(name);
        cout << "Do another search? (Y)es: ";
        done = !yes();
        cout << endl;
    }
    cout << "Goodbye!" << endl;
    return 0;
}