// Name: Yiou(Anna) Wang
// Student ID:151558194
// Email: ywang811@myseneca.ca
// Data: 2020-11-10
// I have done all the coind by myself and only copied the code that my 
// professor provided to complete my workshops and assignments.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Truck.h"
using namespace std;
namespace sdds {
	Truck::Truck(const char* plateNumber, int buildYear, double capacity, const char* address) : Vehicle(plateNumber, buildYear)
	{
		m_capacity = capacity;
		m_cargo = 0;
		Vehicle::moveTo(address);
	}

	bool Truck::addCargo(double cargo)
	{
		bool ok = false;
		double value = m_cargo + cargo;
		if (m_cargo != m_capacity) {
			if (value < m_capacity) {
				m_cargo = value;
				ok = true;
			}
			if (value > m_capacity) {
				m_cargo = m_capacity;
				ok = true;
			}
		}	
		return ok;
	}

	bool Truck::unloadCargo()
	{
		bool ok = false;
		if (m_cargo > 0) {
			m_cargo = 0;
			ok = true;
		}
		return ok;
	}

	ostream& Truck::write(ostream& os) const
	{
		Vehicle::write(os);
		os << " | " << m_cargo << "/" << m_capacity;
		return os;
	}

	istream& sdds::Truck::read(istream& in)
	{
		Vehicle::read(in);
		cout << "Capacity: ";
		in >> m_capacity;
		in.ignore(2000, '\n');
		cout << "Cargo: ";
		in >> m_cargo;
		in.ignore(2000, '\n');
		return in;
	}

	std::ostream& operator<<(std::ostream& ostr, const Truck& truck)
	{
		return truck.write(ostr);
	}

	std::istream& operator>>(std::istream& istr, Truck& truck)
	{
		return truck.read(istr);
	}

}
