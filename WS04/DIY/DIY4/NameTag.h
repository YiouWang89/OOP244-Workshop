// Name: Yiou(Anna) Wang
// Student ID:151558194
// Email: ywang811@myseneca.ca
// Data: 2020-10-06
// I have done all the coind by myself and only copied the code that my 
// professor provided to complete my workshops and assignments.

#ifndef SDDS_NAMETAGE_H_
#define SDDS_NAMETAGE_H_
#include <iostream>
namespace sdds {
	class NameTag {
		char* m_name;
		int m_extention;

		void setName(const char name[]);
		void setExtention(int extention);
		bool extentionValid(const int extention);

	public:
		NameTag();
		NameTag(const char name[]);
		NameTag(const char name[], int extention);
		std::ostream& print();
		NameTag& read();

		~NameTag();
	};
}

#endif // !SDDS_NAMETAGE_H_

