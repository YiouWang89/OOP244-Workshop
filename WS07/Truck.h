// Name: Yiou(Anna) Wang
// Student ID:151558194
// Email: ywang811@myseneca.ca
// Data: 2020-11-10
// I have done all the coind by myself and only copied the code that my 
// professor provided to complete my workshops and assignments.
#pragma once
#ifndef SDDS_TRUCK_H_
#define SDDS_TRUCK_H_
#include <iostream>
#include "Vehicle.h"
namespace sdds {
	class Truck: public Vehicle
	{
		double m_capacity;
		double m_cargo;
	public:
		Truck(const char* plateNumber, int buildYear, double capacity, const char* address);
		bool addCargo(double cargo);
		bool unloadCargo();
		std::ostream& write(std::ostream& os)const;
		std::istream& read(std::istream& in);
	};
	std::ostream& operator <<(std::ostream& ostr, const Truck& truck);
	std::istream& operator >>(std::istream& istr, Truck& truck);
}
#endif

