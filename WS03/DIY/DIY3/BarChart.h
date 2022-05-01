// Name: Yiou(Anna) Wang
// Student ID:151558194
// Email: ywang811@myseneca.ca
// Data: 2020-10-06
// I have done all the coind by myself and only copied the code that my 
// professor provided to complete my workshops and assignments.
#include "Bar.h"
#ifndef SDDS_BARCHART_H_
#define SDDS_BARCHART_H_

namespace sdds {
	struct BarChart {
		char* bc_charttitle;
		Bar* bc_bars;
		char bc_fillcha;
		int bc_size;
		int bc_added;
		bool isValid()const;
		void init(const char* title, int noOfSampels, char fill);
		void add(const char* bar_title, int value);
		void draw()const;
		void deallocate();
	};
}

#endif
