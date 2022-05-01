// Name: Yiou(Anna) Wang
// Student ID:151558194
// Email: ywang811@myseneca.ca
// Data: 2020-11-16
// I have done all the coind by myself and only copied the code that my 
// professor provided to complete my workshops and assignments.
#ifndef SDDS_LINE_H
#define SDDS_LINE_H
#include "LblShape.h"
namespace sdds {
   class Line: public LblShape{
	   int m_length;
   public:
	   Line();
	   Line(const char* label, int length);
	   void getSpecs(std::istream& istr);
	   void draw(std::ostream& ostr)const;
   };
}
#endif // !SDDS_LINE_H

