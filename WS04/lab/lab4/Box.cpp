// Name: Yiou(Anna) Wang
// Student ID:151558194
// Email: ywang811@myseneca.ca
// Data: 2020-10-12
// I have done all the coind by myself and only copied the code that my 
// professor provided to complete my workshops and assignments.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
#include "Box.h"

using namespace sdds;
using namespace std;

Box::Box() {
	m_width = 12;
	m_height = 12;
	m_length = 12;
	m_contentName = nullptr;
	m_contentVolume = 0;
}

Box::Box(int sideLength, const char* contentName) {
	m_contentName = nullptr;
	if (sideLength >= 5 && sideLength <= 36) {
		m_width = sideLength;
		m_height = sideLength;
		m_length = sideLength;
		m_contentVolume = 0;
		setName(contentName);
	}
	else
		setUnusable();

}

Box::Box(int width, int height, int length, const char* contentName) {
	m_contentName = nullptr;
	if (width >= 5 && width <= 36 && height >= 5 && height <= 36 && length >= 5 && length <= 36) {
		m_width = width;
		m_height = height;
		m_length = length;
		m_contentVolume = 0;
		setName(contentName);
	}
	else
		setUnusable();
}

void sdds::Box::setName(const char* Cstr)
{
	if (Cstr) {
		m_contentName = nullptr;
		m_contentName = new char[strlen(Cstr) + 1];
		strcpy(m_contentName, Cstr);
	}
}

void sdds::Box::setUnusable()
{
	m_contentName = nullptr;
	m_width = -1;
	m_height = -1;
	m_length = -1;
	m_contentVolume = -1;
}

bool sdds::Box::isUnusable() const
{
	bool ok = false;
	if (m_width == -1 && m_height == -1 && m_length == -1 && m_contentVolume == -1)
		ok = true;
	return ok;
}

bool sdds::Box::hasContent() const
{
	bool ok = false;
	if (m_contentVolume > 0 && quantity() > 0) {
		ok = true;
	}
	return ok;
}

Box::~Box() {
	delete[] m_contentName;
}

int sdds::Box::capacity() const
{
	int volume = m_width * m_height * m_length;
	return volume;
}

int sdds::Box::quantity() const
{
	return m_contentVolume;
}

Box& sdds::Box::setContent(const char* contentName)
{
	if (hasContent() && m_contentName) {
		setUnusable();
	}
	else
		setName(contentName);
	
	return *this;
}

std::ostream& sdds::Box::display() const
{
	if (isUnusable()) {
		cout << "Unusable box, discard the content, and recycle.";
	}
	else if (m_contentName == nullptr) {
		cout << setw(30) << left << setfill('.') << "Empty box" << ' ' << ' ' << setfill('0') << setw(2) << right << m_width << "x" << setfill('0') << setw(2) << right << m_height << "x" << setfill('0') << setw(2) << right << m_length << ' ' << setw(7) << right << setfill(' ') << quantity() << '/' << capacity() << " C.I.";
	 }
	else {
		cout << setw(30) << left << setfill('.') << m_contentName << ' ' << ' ' << setfill('0') << setw(2) << right << m_width << "x" << setfill('0') << setw(2) << right << m_height << "x" << setfill('0') << setw(2) << right << m_length << ' ' << setw(7) << right << setfill(' ') << quantity() << '/' << capacity() << " C.I.";
	}
	return cout;
}

Box& sdds::Box::add(int quantity)
{
	if (quantity > 0 && quantity < capacity()-m_contentVolume)
		m_contentVolume += quantity;
	else
		setUnusable();
	return *this;
}

Box& sdds::Box::add(Box& B)
{
	if (m_contentName == nullptr || quantity() == 0) {
		setContent(B.m_contentName);
	}   
	if (strcmp(m_contentName, B.m_contentName) == 0) {
		if (quantity() + B.quantity() <= capacity()) {
			add(B.quantity());        
			B.m_contentVolume = 0;
		}
		else {
			B.m_contentVolume -= (capacity() - quantity());        
			m_contentVolume = capacity();
		}
	}
	else {
		if (quantity() + B.quantity() <= capacity()) {
			B.m_contentVolume = 0;
		}
		else {
			B.m_contentVolume -= (capacity() - quantity());
		}      
		setUnusable();
	}   return *this;

}


