// Name: Yiou(Anna) Wang
// Student ID:151558194
// Email: ywang811@myseneca.ca
// Data: 2020-10-06
// I have done all the coind by myself and only copied the code that my 
// professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <cstring>
#include "Transcript.h"
#include "Subject.h"
using namespace std;

namespace sdds {
	void Transcript::setEmpty() {
		m_studentName = nullptr;
		m_subjects = nullptr;
	}

	bool Transcript::isValid()const {
		bool ok = false;
		int i = 0;
		int count = 0;
		if (m_studentName != nullptr && m_subjects != nullptr) {
			for (i = 0; i < m_subjectsAdded; i++) {
				if (m_subjects[i].isValid())
					count++;
			}
			if (count == m_noOfSubjects) {
				ok = true;
			}
		}
		return ok;
	}

	void Transcript::Title()const {
		int i = 0;
		cout << m_studentName << endl;
		for (i = 0; i < 29; i++) {
			cout << '-';
		}
		cout << endl;
	}

	float Transcript::gpa()const {
		int i = 0;
		float gpa = 0;
		for (i = 0; i < m_noOfSubjects; i++) {
			gpa += m_subjects[i].scale4();
		}
		gpa = gpa / m_noOfSubjects;
		return gpa;
	}

	void Transcript::footer()const {
		int i = 0;
		for (i = 0; i < 29; i++) {
			cout << '-';
		}
		cout << endl;
		cout.width(26);
		cout.setf(ios::fixed);
		cout.precision(1);
		cout << "GPA: " << gpa() << endl;
	}

	void Transcript::init(const char* studentName, int noOfSubjects) {
		if (studentName == nullptr || noOfSubjects < 1) {
			setEmpty();
		}
			
		else {
			m_noOfSubjects = noOfSubjects;
			m_subjectsAdded = 0;
			m_studentName = new char[strlen(studentName) + 1];
			strcpy(m_studentName, studentName);
			m_subjects = new Subject[m_noOfSubjects];
		}
	}

	bool Transcript::add(const char* subject_code, int mark) {
		bool ok = false;
		if (m_subjectsAdded < m_noOfSubjects) {
			m_subjects[m_subjectsAdded].set(subject_code, mark);
			m_subjectsAdded++;
			ok = true;
		}
		return ok;
	}

	void Transcript::display()const {
		int i = 0;
		if (isValid()) {
			Title();
			for (i = 0; i < m_noOfSubjects; i++) {
				m_subjects[i].display();
			}
			footer();
		}
		else
			cout << "Invalid Transcript!" << endl;
	}

	void Transcript::deallocate() {
		delete[] m_studentName;
		delete[] m_subjects;
		setEmpty();
	}

}