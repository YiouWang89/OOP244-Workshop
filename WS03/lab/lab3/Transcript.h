// Name: Yiou(Anna) Wang
// Student ID:151558194
// Email: ywang811@myseneca.ca
// Data: 2020-10-06
// I have done all the coind by myself and only copied the code that my 
// professor provided to complete my workshops and assignments.
#include "Subject.h"

#ifndef SDDS_TRANSCRIPT_H_
#define SDDS_TRANSCRIPT_H_

namespace sdds {
	class Transcript {
		char* m_studentName; // pointer to hold the student name dynamically 
		Subject* m_subjects; // pointer to hold the subjects in the Transcript dynamically
		int m_noOfSubjects;  // Number of subjects or number of elements in the array of m_subjects.
		int m_subjectsAdded; // Number of subjects in the m_subjects array that are set to thie

		void setEmpty();

		bool isValid()const;

		void Title()const;

		float gpa()const;

		void footer()const;

	public:
		void init(const char* studentName, int noOfSubjects);

		bool add(const char* subject_code, int mark);

		void display()const;

		void deallocate();

	};
}

#endif // SDDS_TRANSCRIPT_H_
