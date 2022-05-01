// Name: Yiou(Anna) Wang
// Student ID:151558194
// Email: ywang811@myseneca.ca
// Data: 2020-10-24
// I have done all the coind by myself and only copied the code that my 
// professor provided to complete my workshops and assignments.

#ifndef SDDS_ACCOUNT_H_
#define SDDS_ACCOUNT_H_
#include <iostream>

namespace sdds {
   class Account {
      int m_number;
      double m_balance; 
      void setEmpty();
      bool isNew()const;
      bool isValid()const;

   public:
      Account();
      Account(int number, double balance);
      std::ostream& display()const;
      operator bool()const;
      operator int()const;
      operator double()const;
      bool operator~()const;
      Account& operator =(int number);
      Account& operator =( Account& rightAcc);
      Account& operator +=(double rightBal);
      Account& operator -=(double rightBal);
      //friend double operator +(const Account& leftAcc, const Account& rightAcc);
      //friend double operator +=(double& left, const Account& rightAcc);
   };

   double operator +(const Account& leftAcc, const Account& rightAcc);
   double operator +=(double& left, const Account& rightAcc);


}
#endif // SDDS_ACCOUNT_H_