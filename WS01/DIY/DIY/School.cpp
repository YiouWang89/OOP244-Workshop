#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "School.h"
#include "File.h"
using namespace std;

School schools[24];

namespace sdds
{
bool loadSchools()
{
	School sch;
	int snum = 0;
	bool ok = true;
	if (openFile("schools.dat"))
	{
		while (ok && snum < 24)
		{
			ok = readSchoolName(sch.school_name) && readSchoolExtention(&sch.extention);
			if (ok)
				schools[snum++] = sch;
		}
		closeFile();
	}
	return snum == 24;
}

bool hasSchool(const School* sch, const char name[])
{
	bool flag = false;
	bool found = false;
	while (!found && sch->school_name && !flag) 
	{
		if (strstr(sch->school_name, name))
			found = true;
		else
			flag = true;
	}
	return found;
}

void displaySchool(const School* sch) 
{
	cout << "416 491 5050 x " << sch->extention << endl;
}

void displaySchoolWithExtention(const char name[]) 
{
	int i, j;
	for (i = 0, j = 1; i < 24; i++)
	{
		if (sdds::hasSchool(&schools[i], name))
		{
			sdds::displaySchool(&schools[i]);
			j++;
		}
	}
	if (j == 1) 
	{
		cout << name << " School code not found! " << endl;
	}
}
}
