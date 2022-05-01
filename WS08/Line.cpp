// Name: Yiou(Anna) Wang
// Student ID:151558194
// Email: ywang811@myseneca.ca
// Data: 2020-11-16
// I have done all the coind by myself and only copied the code that my 
// professor provided to complete my workshops and assignments.
#include "Line.h"
using namespace std;
namespace sdds {
	Line::Line () : LblShape()
	{
		m_length = 0;
	}
	Line::Line(const char* label, int length): LblShape (label)
	{
		m_length = length;
	}
	void Line::getSpecs(std::istream& istr)
	{
		LblShape::getSpecs(istr);
		istr >> m_length;
		istr.ignore(200, '\n');
	}
	void Line::draw(std::ostream& ostr)const
	{
		if (m_length > 0 && LblShape::label())
			ostr << LblShape::label() << endl;
		for (int i = 0; i < m_length; i++) {
			ostr << "=";
		}
	}
}
