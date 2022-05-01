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
// This file tests the BarChart section of your DIY workshop
/////////////////////////////////////////////

#include <iostream>


using namespace std;
int main() {
    int a[13] = { 1,3,0,4,5,0,8,76,9,0,4,0,0 };
    int i;
    int X = 0;
    for (i = 0; i < 13; i++)
        X += !!a[i];
    cout << X;
   return 0;
}
