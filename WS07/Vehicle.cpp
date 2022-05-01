// Name: Yiou(Anna) Wang
// Student ID:151558194
// Email: ywang811@myseneca.ca
// Data: 2020-11-10
// I have done all the coind by myself and only copied the code that my 
// professor provided to complete my workshops and assignments.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
#include "Vehicle.h"
using namespace std;
namespace sdds {
	Vehicle::Vehicle(const char* licencePlateNum, int buildYear)
	{
		strcpy(m_licencePlateNum, licencePlateNum);
		m_buildYear = buildYear;
		strcpy(m_address, "Factory");
	}
	void Vehicle::moveTo(const char* address)
	{
		cout << "|" << setw(8) << setfill(' ') << right << m_licencePlateNum << "| ";
		cout << "|" << setw(20) << setfill(' ') << right << m_address << " ---> ";
		cout << setw(20) << setfill(' ') << left << address;
		cout << "|" << right << endl;
		strcpy(m_address, address);
	}
	ostream& Vehicle::write(ostream& os)const
	{
		os << "| " << m_buildYear << " | " << m_licencePlateNum << " | " << m_address;
		return os;
	}

	istream& Vehicle::read(istream& in)
	{
		cout << "Built year: ";
		in >> m_buildYear;
		in.ignore(2000, '\n');
		cout << "License Plate: ";
		in.get(m_licencePlateNum,8);
		in.ignore(2000, '\n');
		cout << "Current location: ";
		in.get(m_address, 63);
		in.ignore(2000, '\n');
		return in;
	}


	std::ostream& operator<<(std::ostream& ostr, const Vehicle& veh)
	{
		return veh.write(ostr);
	}

	std::istream& operator>>(std::istream& istr, Vehicle& veh)
	{
		return veh.read(istr);
	}

}
