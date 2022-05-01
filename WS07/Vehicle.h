// Name: Yiou(Anna) Wang
// Student ID:151558194
// Email: ywang811@myseneca.ca
// Data: 2020-11-10
// I have done all the coind by myself and only copied the code that my 
// professor provided to complete my workshops and assignments.
#ifndef SDDS_VEHICLE_H_
#define SDDS_VEHICLE_H_
#include <iostream>
namespace sdds {
	class Vehicle
	{
		char m_licencePlateNum[9];
		char m_address[64];
		int m_buildYear;
	public:
		Vehicle(const char* licencePlateNum, int buildYear);
		void moveTo(const char* address);
		std::ostream& write(std::ostream& os)const;
		std::istream& read(std::istream& in);
	};
	std::ostream& operator <<(std::ostream& ostr, const Vehicle& veh);
	std::istream& operator >>(std::istream& istr, Vehicle& veh);
}
#endif // !SDDS_VEHICLE_H_

