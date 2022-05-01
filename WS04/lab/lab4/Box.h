// Name: Yiou(Anna) Wang
// Student ID:151558194
// Email: ywang811@myseneca.ca
// Data: 2020-10-12
// I have done all the coind by myself and only copied the code that my 
// professor provided to complete my workshops and assignments.

#ifndef SDDS_BOX_H_
#define SDDS_BOX_H_
#include <iostream>

namespace sdds {
	class Box {
		char* m_contentName;
		int m_width;
		int m_height;
		int m_length;
		int m_contentVolume;

		void setName(const char* Cstr);
		void setUnusable();
		bool isUnusable()const;
		bool hasContent()const;

	public:
		Box();
		Box(int sideLength, const char* contentName = nullptr);
		Box(int width, int height, int length, const char* contentName = nullptr);
		int capacity()const;
		int quantity()const;
		Box& setContent(const char* contentName);
		std::ostream& display()const;
		Box& add(int quantity);
		Box& add(Box& B);
		~Box();
	};
}

#endif
