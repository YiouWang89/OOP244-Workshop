// Name: Yiou(Anna) Wang
// Student ID:151558194
// Email: ywang811@myseneca.ca
// Data: 2020-10-06
// I have done all the coind by myself and only copied the code that my 
// professor provided to complete my workshops and assignments.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
#include "NameTag.h"

using namespace std;
using namespace sdds;

void sdds::NameTag::setName(const char name[])
{
	const char* temp=&name[0];
	if (name) {
		m_name = nullptr;
		m_name = new char[strlen(name) + 1];
		strcpy(m_name, temp);
		if (strlen(name) > 40) {
			m_name[40] = '\0';
		}
	}
	else
		m_name = nullptr;
}

void sdds::NameTag::setExtention(int extention)
{
	m_extention = extention;
}

bool sdds::NameTag::extentionValid(const int extention)
{
	bool ok = false;
	if (extention > 10000 && extention < 99999)
		ok = true;
	if (extention < 0)
		ok = true;
	return ok;
}

sdds::NameTag::NameTag()
{
	m_name = nullptr;
	m_extention = -1;
}

sdds::NameTag::NameTag(const char name[])
{
	setName(name);
	m_extention = -1;
}

sdds::NameTag::NameTag(const char name[], int extention)
{
	setName(name);
	setExtention(extention);
}

std::ostream& sdds::NameTag::print()
{
	if (m_name != nullptr && extentionValid(m_extention)) {
		if (strlen(m_name) <= 20) {
			for (int i = 0; i < 24; i++)
				cout << '*';
			cout << endl;
			cout << '*' << setw(23) << right << setfill(' ') << '*' << endl;
			cout << '*' << ' ' << m_name << setw(22 - strlen(m_name)) << right << setfill(' ') << '*' << endl;
			cout << '*' << setw(23) << right << setfill(' ') << '*' << endl;
			if (m_extention > 10000 && m_extention < 99999) {
				cout << '*' << ' ' << "Extension: " << m_extention << setw(6) << right << setfill(' ') << '*' << endl;
			}
			else {
				cout << '*' << ' ' << "Extension: N/A" << setw(8) << right << setfill(' ') << '*' << endl;
			}
			cout << '*' << setw(23) << right << setfill(' ') << '*' << endl;
			for (int i = 0; i < 24; i++)
				cout << '*';
			cout << endl;
		}
		if (strlen(m_name) ==40) {
			for (int i = 0; i < 44; i++)
				cout << '*';
			cout << endl;
			cout << '*' << setw(43) << right << setfill(' ') << '*' << endl;
			cout << '*' << ' ' << m_name << ' ' << '*' << endl;
			cout << '*' << setw(43) << right << setfill(' ') << '*' << endl;
			if (m_extention > 10000 && m_extention < 99999) {
				cout << '*' << ' ' << "Extension: " << m_extention << setw(26) << right << setfill(' ') << '*' << endl;
			}
			else {
				cout << '*' << ' ' << "Extension: N/A" << setw(28) << right << setfill(' ') << '*' << endl;
			}
			cout << '*' << setw(43) << right << setfill(' ') << '*' << endl;
			for (int i = 0; i < 44; i++)
				cout << '*';
			cout << endl;
		}
	}
	else
		cout << "EMPTY NAMETAG!" << endl;

	return cout;
}

NameTag& sdds::NameTag::read()
{
	char temp_name[41] = { 0 };
	char y_n = 'n';
	cout << "Please enter the name:";
	cin.get(temp_name, 41);
	cin.ignore(2000,'\n');
	setName(temp_name);
	cout << "Would you like to enter an extension? (Y)es/(N)o: ";
	y_n = cin.get();
	cin.ignore(2000, '\n');
	if (y_n == 'y' || y_n=='Y')
	{
		cout << "Please enter a 5 digit phone extension: ";
		cin >> m_extention;
		cin.ignore(2000, '\n');
		while (m_extention > 99999 || m_extention < 10000) {
			cout << "Invalid value [10000<=value<=99999]:";
			cin >> m_extention;
			cin.ignore(2000, '\n');
		}
		
	}
	if (y_n == 'n' || y_n == 'N') {
		m_extention = -1;
	}
	return *this;
}

sdds::NameTag::~NameTag()
{
	delete[] m_name;
}


