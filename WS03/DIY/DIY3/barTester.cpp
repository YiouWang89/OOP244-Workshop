// Name: Yiou(Anna) Wang
// Student ID:151558194
// Email: ywang811@myseneca.ca
// Data: 2020-10-06
// I have done all the coind by myself and only copied the code that my 
// professor provided to complete my workshops and assignments.
// Workshop 3:
// Version: 0.9
// Date: 10/02/2020
// Author: Fardad Soleimanloo
// Description:
// This file tests the Bar section of your DIY workshop
/////////////////////////////////////////////
#include "Bar.h"

using namespace sdds;
int main() {
   Bar b;
   for (int i = 1; i <= 5; i++) {
      b.set("the bar", '=', i*20);
      b.draw();
   }
   b.set("Bad Bar", '=', -200);
   b.draw();
   b.set("Bad Bar", '=', 200);
   b.draw();
   return 0;
}