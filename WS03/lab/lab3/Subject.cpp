// Name: Yiou(Anna) Wang
// Student ID:151558194
// Email: ywang811@myseneca.ca
// Data: 2020-10-06
// I have done all the coind by myself and only copied the code that my 
// professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <cstring>
#include "Subject.h"

using namespace std;
namespace sdds {
	char Subject::grade()const {
		char mark_lev;
		if (0 <= m_mark && m_mark < 50)
			mark_lev = 'F';
		else if (50 <= m_mark && m_mark < 60)
			mark_lev = 'D';
		else if (60 <= m_mark && m_mark < 70)
			mark_lev = 'C';
		else if (70 <= m_mark && m_mark < 80)
			mark_lev = 'B';
		else if (80 <= m_mark && m_mark <= 100)
			mark_lev = 'A';
		return mark_lev;
	}

	void Subject::setEmpty() {
		m_code[0] = '\0';
		m_mark = -1;
	}

	void Subject::set(const char* code, int mark)
	{
		
		if (mark < 0 || mark > 100)
			setEmpty();
		else {
			strcpy(m_code, code);
			m_mark = mark;
		}
	}

	float Subject::scale4()const {
		float scal;
		if (0 <= m_mark && m_mark < 50)
			scal = 0.0;
		else if (50 <= m_mark && m_mark < 60)
			scal = 1.0;
		else if (60 <= m_mark && m_mark < 70)
			scal = 2.0;
		else if (70 <= m_mark && m_mark < 80)
			scal = 3.0;
		else if (80 <= m_mark && m_mark <= 100)
			scal = 4.0;
		return scal;
	}

	bool Subject::isValid()const {
		bool ok = false;
		if (m_mark >= 0)
			ok = true;
		return ok;
	}

	void Subject::display()const {
		if (isValid()) {
			cout.width(15);
			cout << left << m_code;
			cout.width(3);
			cout << right << m_mark;
			cout.width(10);
			cout << right << grade() << endl;
		}
	}
}