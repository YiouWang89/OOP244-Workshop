// Name: Yiou(Anna) Wang
// Student ID:151558194
// Email: ywang811@myseneca.ca
// Data: 2020-10-24
// I have done all the coind by myself and only copied the code that my 
// professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include "Mark.h"

namespace sdds {

	Mark::Mark() {
		m_mark = 0;
	}

	Mark::Mark(int mark) {
		m_mark = mark;
		if (!isValid())
			m_mark = -1;
	}

	bool Mark::isValid()
	{
		return (m_mark >= 0 && m_mark <= 100);
	}

	Mark::operator int()
	{
		int mark = 0;
		if (isValid())
			mark = m_mark;
		return mark;
	}

	int& Mark::operator+=(int mark)
	{
		if (m_mark < 0)
			m_mark = 0;
		else
			m_mark += mark;
		if (m_mark > 100)
			m_mark = 0;
		return m_mark;
	}

	int& Mark::operator=(int mark)
	{
		if (mark > 0 && mark <= 100)
			m_mark = mark;
		else
			m_mark = 0;
		return m_mark;
	}

	Mark::operator double()
	{
		double GPA = 0.0;
		if (m_mark >= 50 && m_mark < 60)
			GPA = 1.0;
		if (m_mark >= 60 && m_mark < 70)
			GPA = 2.0;
		if (m_mark >= 70 && m_mark < 80)
			GPA = 3.0;
		if (m_mark >= 80 && m_mark <= 100)
			GPA = 4.0;
		return GPA;
	}

	Mark::operator char()
	{
		char Grade = ' ';
		if (m_mark > 0 && m_mark < 50)
			Grade = 'F';
		else if (m_mark >= 50 && m_mark < 60)
			Grade = 'D';
		else if (m_mark >= 60 && m_mark < 70)
			Grade = 'C';
		else if (m_mark >= 70 && m_mark < 80)
			Grade = 'B';
		else if (m_mark >= 80 && m_mark <= 100)
			Grade = 'A';
		else
			Grade = 'X';
		return Grade;
	}

	int operator +=( int& number, Mark& x) {
		if (int(x) != 0)
			number += int(x);
		return number;
	}

}