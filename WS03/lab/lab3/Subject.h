// Name: Yiou(Anna) Wang
// Student ID:151558194
// Email: ywang811@myseneca.ca
// Data: 2020-10-06
// I have done all the coind by myself and only copied the code that my 
// professor provided to complete my workshops and assignments.

#ifndef SDDS_SUBJECT_H_
#define SDDS_SUBJECT_H_
namespace sdds {
	class Subject {
		
		char m_code[7];
		int m_mark;

		char grade()const ;

	public:
		void setEmpty();

		void set(const char* code, int mark);

		float scale4()const;

		bool isValid()const;

		void display()const;
	};
}


#endif // SDDS_SUBJECT_H_