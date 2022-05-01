#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "File.h"

namespace sdds {
   FILE* fptr;
   bool openFile(const char filename[]) {
      fptr = fopen(filename, "r");
      return fptr != NULL;
   }
   int noOfRecords() {
      int noOfRecs = 0;
      char ch;
      while (fscanf(fptr, "%c", &ch) == 1) {
         noOfRecs += (ch == '\n');
      }
      rewind(fptr);
      return noOfRecs;
   }
   void closeFile() {
      if (fptr) fclose(fptr);
   }
   // TODO: read functions go here    
   bool read(char name[]) { 
       return fscanf(fptr, "%[^,],", name) == 1;
   }
   bool read(int& number) {
       return fscanf(fptr, "%d,", &number) == 1;
   }
   bool read(double& GPA) {
       return fscanf(fptr, "%lf\n", &GPA) == 1;
   }
   
}