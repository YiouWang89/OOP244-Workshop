// Name: Yiou(Anna) Wang
// Student ID:151558194
// Email: ywang811@myseneca.ca
// Data: 2020-11-16
// I have done all the coind by myself and only copied the code that my 
// professor provided to complete my workshops and assignments.
#include <cstring>
#include <iomanip>
#include "Rectangle.h"
using namespace std;
namespace sdds {
	Rectangle::Rectangle(): LblShape()
	{
		m_width = 0;
		m_height = 0;
	}
	Rectangle::Rectangle(const char* label, int width, int height): LblShape(label)
	{
		m_width = width;
		m_height = height;
		int num = strlen(LblShape::label()) + 2;
		if (m_height < 3 || m_width < num) {
			m_width = 0;
			m_height = 0;
		}

	}
	void Rectangle::getSpecs(std::istream& istr)
	{
		LblShape::getSpecs(istr);
		istr >> m_width;
		istr.ignore(100, ',');
		istr >> m_height;
		istr.ignore(200, '\n');
	}
	void Rectangle::draw(std::ostream& ostr)const
	{
		if (m_width > 0 && m_height > 0) {
			ostr << "+";
			for (int i = 0; i < (m_width - 2); i++) {
				ostr << "-";
			}
			ostr << "+" << endl << "|";
			ostr << setw(m_width - 2) << left << LblShape::label() << "|" << endl;
			for (int i = 0; i < (m_height - 3); i++) {
				ostr << "|";
				for (int j = 0; j < (m_width - 2); j++) {
					ostr << " ";
				}
				ostr << "|" << endl;
			}
			ostr << "+";
			for (int i = 0; i < (m_width - 2); i++) {
				ostr << "-";
			}
			ostr << "+";
		}
	}
}