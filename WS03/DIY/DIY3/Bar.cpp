// Name: Yiou(Anna) Wang
// Student ID:151558194
// Email: ywang811@myseneca.ca
// Data: 2020-10-06
// I have done all the coind by myself and only copied the code that my 
// professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Bar.h"
using namespace std;
using namespace sdds;
	void Bar::setEmpty() {
		m_title[0] = '\0';
		m_sampleValue = -1;
		m_fillcha = '\0';
	}

	void Bar::set(const char* title, char cha, int value) {
		if (value < 0 || value > 100)
			setEmpty();
		else {
			strcpy(m_title, title);
			m_sampleValue = value;
			m_fillcha = cha;
		}
	}

	bool Bar::isValid()const {
		bool ok = false;
		if (m_title != nullptr && m_sampleValue >= 0)
			ok = true;
		return ok;
	}

	void Bar::draw()const {
		int i = 0;
		if (isValid()) {
			cout.fill('.');
			cout.width(20);
			cout << left << m_title << "|";
			for (i = 0; i < m_sampleValue / 2; i++) {
				cout << m_fillcha;
		}
			cout << endl;
		}
	}

