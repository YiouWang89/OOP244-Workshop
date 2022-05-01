// Name: Yiou(Anna) Wang
// Student ID:151558194
// Email: ywang811@myseneca.ca
// Data: 2020-11-23
// I have done all the coind by myself and only copied the code that my 
// professor provided to complete my workshops and assignments.
#include <iostream>
#include "ReadWrite.h"
using namespace std;
namespace sdds {
   ostream& operator<<(ostream& os, const ReadWrite& c) {
      return c.display(os);
   }

   istream& operator >> (istream& is, ReadWrite& c) {
      return c.read(is);
   }
}