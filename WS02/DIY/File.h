#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_
namespace sdds {
   bool openFile(const char filename[]);
   void closeFile();
   int noOfRecords();
   bool read(int& account);
   bool read(double& balance);
}
#endif // !SDDS_FILE_H_
