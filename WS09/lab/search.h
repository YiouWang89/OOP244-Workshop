// Name: Yiou(Anna) Wang
// Student ID:151558194
// Email: ywang811@myseneca.ca
// Data: 2020-11-23
// I have done all the coind by myself and only copied the code that my 
// professor provided to complete my workshops and assignments.
#ifndef SDDS_SEARCH_H_
#define SDDS_SEARCH_H_
#include "Collection.h"
#include "Car.h"
namespace sdds {
	template <typename S>
	bool search(S s[], int numberElem, const char* key, Collection<S>& collection);

	template<typename S>
	bool search(S s[], int numberElem, const char* key, Collection<S>& collection)
	{
		bool ok = false;
		for (int i = 0; i < numberElem; i++) {
			if (s[i] == key) {
				ok = true;
				collection.add(s[i]);
			}
		}


		return ok;
	}
}

#endif