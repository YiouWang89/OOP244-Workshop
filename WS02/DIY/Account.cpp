#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "File.h"
#include "Account.h"

using namespace std;
// use overloading reference dynamic
//
namespace sdds 
{
    int noOfAccount;
    Report* reports;

    void sort() {
        int i, j;
        Report temp;
        for (i = noOfAccount - 1; i > 0; i--) {
            for (j = 0; j < i; j++) {
                if (reports[j].balance > reports[j+1].balance)
                {
                    temp = reports[j];
                    reports[j] = reports[j + 1];
                    reports[j + 1] = temp;
                }
            }
        }
    }

    bool load(Report& rep)
    {
        bool ok = false;
        int rep_acc = 0;
        double rep_bal = 0;
        if (read(rep_acc) && read(rep_bal))
        {
            rep.account = rep_acc;
            rep.balance = rep_bal;
            ok = true;
        }
        return ok;
    }

    bool load(const char* file )
    {
        bool ok = false;
        int i = 0;
        int count_rep = 0;
        
        if (openFile(file))
        {
            noOfAccount = noOfRecords();

            reports = new Report[noOfAccount];

            for (i = 0; i < noOfAccount; i++)
            {
                load(reports[i]);
                count_rep++;
            }

            if (noOfAccount != count_rep)
            {
                cout << "Error: incorrect number of records read; the data is possibly corrupted" << endl;
            }
            else {
                ok = true;
            }
            closeFile();
        }
        else {
            cout << "Could not open data file: " << file << endl;
        }
        return ok;
    }

    void display(const Report& rep)
    {
        cout << rep.account << "  " << rep.balance << endl;
    }

    void display()
    {
        int i;
        sort();
        cout << "Account#: Balance" << endl;
        for (i = 0; i < noOfAccount; i++)
        {
            
            display(reports[i]);
        }
    }

    void deallocateMemory()
    {
        delete[] reports;
    }
}
