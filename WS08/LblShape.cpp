// Name: Yiou(Anna) Wang
// Student ID:151558194
// Email: ywang811@myseneca.ca
// Data: 2020-11-16
// I have done all the coind by myself and only copied the code that my 
// professor provided to complete my workshops and assignments.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "LblShape.h"
using namespace std;
namespace sdds {
	const char* LblShape::label() const
	{
		return m_label;
	}
	LblShape::LblShape()
	{
		m_label = nullptr;
	}
	LblShape::LblShape(const char* label)
	{
		m_label = nullptr;
		m_label = new char[strlen(label) + 1];
		strcpy(m_label, label);
	}
	LblShape::~LblShape()
	{
		delete[] m_label;
	}
	void LblShape::getSpecs(std::istream& istr)
	{
		char temp[21];
		istr.get(temp, 21, ',');
		delete[] m_label;
		m_label = new char[21];
		strcpy(m_label, temp);
		istr.ignore(100, ',');
	}
}