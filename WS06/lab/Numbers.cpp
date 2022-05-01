#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <fstream>
#include "Numbers.h"
using namespace std;
namespace sdds {

  
   Numbers::Numbers() { 
      setEmpty();
      m_isOriginal = false;
   }

   Numbers::Numbers(const char* filename) { 
      setEmpty();
      m_isOriginal = true;
      setFilename(filename);
      m_numCount = numberCount(filename);
      if (m_numCount == 0 || !load()) {
         delete[] m_numbers;
         delete[] m_filename;
         setEmpty();
         m_isOriginal = false; 
      }
      else {
          sort();
      }
   }
   Numbers::Numbers(const Numbers& Num)
   {
       setEmpty();
       m_isOriginal = false;
       operator=(Num);
   }
   Numbers& Numbers::operator=(const Numbers& Num)
   {
       delete[] m_numbers;
       m_numbers = new double[Num.m_numCount];
       m_numCount = Num.m_numCount;
       for (int i = 0; i < Num.m_numCount; i++) {
           m_numbers[i] = Num.m_numbers[i];
       }
       return *this;
   }
   Numbers::~Numbers() {
      save();
      delete[] m_numbers;
      delete[] m_filename;
   }
   
   bool Numbers::isEmpty() const { 
      return m_numbers == nullptr;
   }

   void Numbers::setEmpty() { 
      m_numbers = nullptr;
      m_filename = nullptr;
      m_numCount = 0;
   }
   void Numbers::setFilename(const char* filename) { 
      delete[] m_filename;
      m_filename = new char[strlen(filename) + 1];
      strcpy(m_filename, filename);
   }
   void Numbers::sort() {
      int i, j;
      double temp;
      for (i = m_numCount - 1; i > 0; i--) {
         for (j = 0; j < i; j++) {
            if (m_numbers[j] > m_numbers[j + 1]) {
               temp = m_numbers[j];
               m_numbers[j] = m_numbers[j + 1];
               m_numbers[j + 1] = temp;
            }
         }
      }
   }

   double Numbers::average() const {
      double aver = 0.0;
      if (!isEmpty()) {
         for (int i = 0; i < m_numCount; i++)
            aver += m_numbers[i];
         aver = aver / m_numCount;
      }
      return aver;
   }
   double Numbers::min() const {
      double minVal = 0.0;
      if (!isEmpty()) {
         minVal = m_numbers[0];
         for (int i = 1; i < m_numCount; i++)
            if (minVal > m_numbers[i]) minVal = m_numbers[i];
      }
      return minVal;
   }
   int Numbers::numberCount(const char* filename)
   {
       char Char = ' ';
       int count = 0;
       ifstream filein(filename);
       if (filein) {
           while (filein.get(Char)) {
               if (Char == '\n')
                   count++;
           }
       }
       return count;
   }
   bool Numbers::load()
   {
       bool ok = false;
       double value;
       int fileCount = 0;
       if (m_numCount > 0)
           m_numbers = new double[m_numCount + 1];
       ifstream filein("numbers.txt");
       if (filein) {
           for (int i = 0; i < numberCount("numbers.txt"); i++) {
               filein >> value;
               if (!filein.fail()) {
                   m_numbers[i] = value;
                       fileCount++;
               }
            }
       }
       if (m_numCount == fileCount)
           ok = true;
       return ok;
   }
   void Numbers::save()
   {
      // m_isOriginal == true &&
       if (!isEmpty()) {
           ofstream fileout("numbers.txt");
           for (int i = 0; i < m_numCount; i++) {
               fileout << m_numbers[i] << endl;
           }
       }
   }
   Numbers& Numbers::operator+=(double value)
   {
       double* temp = new double[m_numCount + 1];
       if (!isEmpty()) {
           for (int i = 0; i < m_numCount; i++) {
               temp[i] = m_numbers[i];
           }
           m_numCount++;
           temp[m_numCount - 1] = value;
           delete[] m_numbers;
           m_numbers = temp;
           sort();
       }
      
       return *this;
   }

   ostream& Numbers::display(ostream& ostr) const {

       if (isEmpty())
           ostr << "Empty list";
       else {
           ostr << "=========================" << endl;
           if (m_isOriginal)
               ostr << m_filename << endl;
           else
               ostr << "*** COPY ***" << endl;
           for (int i = 0; i < m_numCount; i++) {
               if (i == m_numCount - 1)
                   ostr << m_numbers[i] << endl;
               else
                   ostr << m_numbers[i] << ", ";
           }
           ostr << "-------------------------" << endl;
           ostr << "Total of " << m_numCount << " number(s)" << endl;
           ostr << "Largest number:  " << max() << endl;
           ostr << "Smallest number: " << min() << endl;
           ostr << "Average :        " << average() << endl;
           ostr << "=========================";
       }

       return ostr;
   }
   

   double Numbers::max() const {
      double maxVal = 0.0;
      if (!isEmpty()) {
         maxVal = m_numbers[0];
         for (int i = 1; i < m_numCount; i++)
            if (maxVal < m_numbers[i]) maxVal = m_numbers[i];
      }
      return maxVal;
   }


   std::ostream& operator<<(ostream& os, const Numbers& N)
   {
       return N.display(os);
   }

   std::istream& operator>>(istream& istr, Numbers& N)
   {
       double value;
       istr >> value;
       N += value;
       return istr;
   }

}
