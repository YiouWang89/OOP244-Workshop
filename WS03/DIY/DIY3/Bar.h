// Name: Yiou(Anna) Wang
// Student ID:151558194
// Email: ywang811@myseneca.ca
// Data: 2020-10-06
// I have done all the coind by myself and only copied the code that my 
// professor provided to complete my workshops and assignments.
#ifndef SDDS_BAR_H_
#define SDDS_BAR_H_
namespace sdds {
	class Bar {
		char m_title[20];
		int m_sampleValue;
		char m_fillcha;
	public:
		void setEmpty();
		void set(const char* title, char cha, int value);
		bool isValid()const;
		void draw()const;
	};
}
#endif
