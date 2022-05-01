// Name: Yiou(Anna) Wang
// Student ID:151558194
// Email: ywang811@myseneca.ca
// Data: 2020-10-06
// I have done all the coind by myself and only copied the code that my 
// professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "BarChart.h"
using namespace std;
using namespace sdds;

bool BarChart::isValid()const {
	bool ok = false;
	int i = 0;
	int count = 0;
	if (bc_charttitle != nullptr && bc_bars != nullptr) {
		for (i = 0; i < bc_added; i++) {
			if (bc_bars[i].isValid())
				count++;
		}
		if (count == bc_size)
			ok = true;
	}
	return ok;
}

void BarChart::init(const char* title, int noOfSampels, char fill) {
	bc_size = noOfSampels;
	bc_fillcha = fill;
	bc_added = 0;
	bc_charttitle = new char[strlen(title) + 1];
	strcpy(bc_charttitle, title);
	bc_bars = new Bar[bc_size];
}

void BarChart::add(const char* bar_title, int value) {
	if (bc_added < bc_size) {
		bc_bars[bc_added].set(bar_title, bc_fillcha, value);
		bc_added++;
	}
}

void BarChart::draw()const {
	if (isValid()) {
		int i = 0;
		cout << bc_charttitle << endl;
		for (i = 0; i < 71; i++) {
			cout << '-';
		}
		cout << endl;
		for (i = 0; i < bc_size; i++) {
			bc_bars[i].draw();
		}
		for (i = 0; i < 71; i++) {
			cout << '-';
		}
	}
	else
		cout << "Invalid Chart!" << endl;
}

void BarChart::deallocate() {
	delete[] bc_charttitle;
	delete[] bc_bars;
	bc_charttitle = nullptr;
	bc_bars = nullptr;
}