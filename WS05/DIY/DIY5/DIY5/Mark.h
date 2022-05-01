#pragma once
// Name: Yiou(Anna) Wang
// Student ID:151558194
// Email: ywang811@myseneca.ca
// Data: 2020-10-24
// I have done all the coind by myself and only copied the code that my 
// professor provided to complete my workshops and assignments.

#ifndef SDDS_MARK_H_
#define SDDS_MARK_H_
namespace sdds {
	class Mark {
		int m_mark;
		bool isValid();
	public:
		Mark();
		Mark(int mark);
		operator int();
		int& operator +=(int mark);
		int& operator =(int mark);
		operator double();
		operator char();
	};
	int operator +=(int& number, Mark& x);
	
}
#endif // !SDDS_MARK_H_
