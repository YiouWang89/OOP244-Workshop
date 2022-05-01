// Name: Yiou(Anna) Wang
// Student ID:151558194
// Email: ywang811@myseneca.ca
// Data: 2020-11-16
// I have done all the coind by myself and only copied the code that my 
// professor provided to complete my workshops and assignments.
#ifndef SDDS_LBLSHAPE_H
#define SDDS_LBLSHAPE_H
#include "Shape.h"
namespace sdds {
   class LblShape: public Shape {
	   char* m_label;
   protected:
	   const char* label() const;
   public:
	   LblShape();
	   LblShape(const char* label);
	   LblShape(const LblShape& Lbl) = delete;
	   LblShape& operator=(const LblShape&) = delete;
	   ~LblShape();
	   virtual void draw(std::ostream& ostr)const = 0;
	   void getSpecs(std::istream& istr);

   };
}
#endif // !SDDS_LBLSHAPE_H


