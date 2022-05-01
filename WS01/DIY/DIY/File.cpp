#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "File.h"

FILE* fptr;

namespace sdds {

    // opens the data file and returns true is successful
    bool openFile(const char filename[])
    {
        fptr = fopen(filename, "r");
        return fptr != NULL;
    }

    //close the data file
    void closeFile()
    {
        if (fptr) fclose(fptr);
    }

    //reads the schools' name
    bool readSchoolName(char name[])
    {
        return fscanf(fptr, "%s", name) == 1;
    }

    bool readSchoolExtention(int* number)
    {
        return fscanf(fptr, "%d", number) == 1;
    }

}

