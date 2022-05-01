// Name: Yiou(Anna) Wang
// Student ID:151558194
// Email: ywang811@myseneca.ca
// Data: 2020-11-16
// I have done all the coind by myself and only copied the code that my 
// professor provided to complete my workshops and assignments.
#ifndef SDDS_SHAPE_H
#define SDDS_SHAPE_H
#include <iostream>
namespace sdds {
   class Shape {
   public:
	   virtual void draw(std::ostream& ostr)const = 0;
	   virtual void getSpecs(std::istream& istr) = 0;
	   virtual ~Shape() {};
   };
   std::ostream& operator<<(std::ostream& ostr, Shape& shape);
   std::istream& operator>>(std::istream& istr, Shape& shape);
}

#endif // !SDDS_SHAPE_H

