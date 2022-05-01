#ifndef _SDDS_FILE_H_ // replace with relevant names
#define _SDDE_FILE_H_

namespace sdds
{

	bool openFile(const char filename[]);
	void closeFile();
	bool readSchoolName(char name[]);
	bool readSchoolExtention(int* number);
}
#endif