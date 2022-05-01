// Name: Yiou(Anna) Wang
// Student ID:151558194
// Email: ywang811@myseneca.ca
// Data: 2020-10-24
// I have done all the coind by myself and only copied the code that my 
// professor provided to complete my workshops and assignments.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Account.h"

using namespace std;
namespace sdds {
    void Account::setEmpty() {
        m_number = -1;
        m_balance = 0.0;
    }
    bool Account::isNew()const
    {
        return m_number == 0;
    }
    bool Account::isValid()const
    {
        bool ok = false;
        if ((m_number >= 10000 && m_number <= 99999
            && m_balance >= 0 )|| m_number == 0)
            ok = true;
        return ok;
    }
    // New account
    Account::Account() {
        m_number = 0;
        m_balance = 0.0;
    }
    Account::Account(int number, double balance) {
        setEmpty();
        if (number >= 10000 && number <= 99999
            && balance > 0) {
            m_number = number;
            m_balance = balance;
        }
    }
    std::ostream& Account::display() const {
        if (*this) {
            cout << "Acc#: ";
            if (~(*this))
                cout << "Not Set";
            else
                cout << " " << m_number << " ";
            cout << ", Balance: ";
            cout.width(12);
            cout.precision(2);
            cout.setf(ios::right);
            cout.setf(ios::fixed);
            cout << m_balance;
            cout.unsetf(ios::right);
            // I (Fardad) removed the "return cout", this was a mistake
            // (copied and pasted by mistake)
            // and had no effect to the execution of the program.
            // As mentioned before we should have only
            // one return statement in a function.
        }
        else {
            cout << "Invalid Account";
        }
        return cout;
    }

    Account::operator bool() const
    {
        bool ok = false;
        if (isValid())
            ok = true;
        return ok;
    }

    Account::operator int() const
    {
        return m_number;
    }

    Account::operator double() const
    {
        return m_balance;
    }

    bool Account::operator ~()const
    {
   
        return isNew();
    }

    Account& Account::operator =(int number)
    {
        if (number >= 10000 && number <= 99999)
            m_number = number;
        else
            setEmpty();
        return *this;
    }

    Account& Account::operator =(Account& rightAcc)
    {
        if (isValid()) {
            if (rightAcc.m_balance >= 0 && ((rightAcc.m_number > 10000 && rightAcc.m_number < 99999 )|| m_number == 0)) {
                m_balance = rightAcc.m_balance;
                rightAcc.m_balance = 0;
            }
        }
        return *this;
    }

    Account& sdds::Account::operator+=(double rightBal)
    {
        if (isValid() && rightBal >= 0)
            m_balance += rightBal;
        return *this;
    }

    Account& Account::operator-=(double rightBal)
    {
        if (isValid() && rightBal >= 0 && m_balance >= rightBal)
            m_balance -= rightBal;
        return *this;
    }
   double operator+(const Account& leftAcc, const Account& rightAcc)
    {
        double sum = 0;
        if (leftAcc.operator double() >= 0 && rightAcc.operator double() >= 0)
            sum = leftAcc.operator double() + rightAcc.operator double();
        else
            sum = 0;
        return sum;
    }
   double operator+=(double& left, const Account& rightAcc)
   {
       if (rightAcc.operator double() >= 0) {
           left += rightAcc.operator double();
       }
       return left;
   }
}
