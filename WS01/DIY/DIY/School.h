#ifndef _SDDS_SCHOOL_H_
#define _SDDS_SCHOOL_H_

struct School
{
	char school_name[5];
	int  extention;
};

namespace sdds
{
	bool loadSchools();
	bool hasSchool(const School* sch, const char name[]);
	void displaySchool(const School* sch);
	void displaySchoolWithExtention( const char name[]);
}
#endif