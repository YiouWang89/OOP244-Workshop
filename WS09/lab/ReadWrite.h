// Name: Yiou(Anna) Wang
// Student ID:151558194
// Email: ywang811@myseneca.ca
// Data: 2020-11-23
// I have done all the coind by myself and only copied the code that my 
// professor provided to complete my workshops and assignments.
#include <iostream>
#ifndef SDDS_READWRITE_H_
#define SDDS_READWRITE_H_
namespace sdds {
   class ReadWrite {
   public:
      virtual std::ostream& display(std::ostream& os)const = 0;
      virtual std::istream& read(std::istream& is) = 0;
      virtual ~ReadWrite() {
      }
   };
   std::ostream& operator<<(std::ostream& os, const ReadWrite& c);
   std::istream& operator>>(std::istream& is, ReadWrite& c);
}
#endif // !SDDS_READWRITE_H_

