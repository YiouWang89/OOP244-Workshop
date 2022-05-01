// Name: Yiou(Anna) Wang
// Student ID:151558194
// Email: ywang811@myseneca.ca
// Data: 2020-11-16
// I have done all the coind by myself and only copied the code that my 
// professor provided to complete my workshops and assignments.
#include "Shape.h"
namespace sdds {
	std::ostream& operator<<(std::ostream& ostr, Shape& shape)
	{
		shape.draw(ostr);
		return ostr;
	}
	std::istream& operator>>(std::istream& istr, Shape& shape)
	{
		shape.getSpecs(istr);
		return istr;
	}
}