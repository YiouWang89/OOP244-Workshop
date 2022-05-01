// Name: Yiou(Anna) Wang
// Student ID:151558194
// Email: ywang811@myseneca.ca
// Data: 2020-11-16
// I have done all the coind by myself and only copied the code that my 
// professor provided to complete my workshops and assignments.
#ifndef SDDS_RECTANGLE_H
#define SDDS_RECTANGLE_H
#include "LblShape.h"
namespace sdds {
   class Rectangle: public LblShape {
	   int m_width;
	   int m_height;
   public:
	   Rectangle();
	   Rectangle(const char* label, int width, int height);
	   void getSpecs(std::istream& istr);
	   void draw(std::ostream& ostr)const;
	  
   };
}
#endif