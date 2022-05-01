#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Student.h"
#include "File.h"
using namespace std;
namespace sdds {
   int noOfStudents;
   Student* students;


   void sort() {
      int i, j;
      Student temp;
      for (i = noOfStudents - 1; i > 0; i--) {
         for (j = 0; j < i; j++) {
            if (students[j].m_gpa > students[j + 1].m_gpa) {
               temp = students[j];
               students[j] = students[j + 1];
               students[j + 1] = temp;
            }
         }
      }
   }

   // TODO: Finish the implementation of the 1 arg load function which
   // reads one student record from the file and loads it into the student reference
   // argument
   bool load(Student& stu) {
      bool ok = false;
      char name[128];
      int stu_number = 0;
      double stu_gpa = 0;
      // if reading of name is successful
      if (read(name)) {
         // allocate memory to the size of the name + 1
         // and keep its address in the name of the Student Reference

          stu.m_name = new char [strlen(name) + 1];
          
         // copy the name into the newly allocated memroy
          strcpy(stu.m_name, name);

         // read student number and gpa from the file into the corresponding
         // variables in the Student Referenct
          if (read(stu_number) && read(stu_gpa) )
          {
              stu.m_studentNumber = stu_number;
              stu.m_gpa = stu_gpa;
              ok = true;
          }
         // make sure the "ok" flag is set to true, if all is good
      }
      return ok;
   }
   // TODO: Finish the implementation of the 0 arg load function 
   bool load() {
      bool ok = false;
      int i = 0;
      int count_st = 0;
      if (openFile(DATAFILE)) {
         // set the noOfStudents to the number of recoreds in the file.
          noOfStudents = noOfRecords();
         // dyanamically allocated an array of students into the global
         // Student pointer; "students" to the size of the noOfStudents.
          students = new Student[noOfStudents];
         // in a loop load the student records from the file into 
         // the dynamic array.
        
          for (i = 0; i < noOfStudents; i++)
          {
              load(students[i]);
              count_st++;
          }
         // if th number of the records does not match the number of reads
         // print an error message
         if (sdds::noOfStudents != count_st)
         {
             cout << "Error: incorrect number of records read; the data is possibly corrupted" << endl;
         }
         else {
            ok = true;
         }
         closeFile();
      }
      else {
         cout << "Could not open data file: " << DATAFILE<< endl;
      }
      return ok;
   }

   // TODO: Implementation for the display functions go here
   void display(const Student& stu)
   {
       cout << stu.m_name << ", " << stu.m_studentNumber << ": " << stu.m_gpa << endl;
   }

   void display()
   {
       int i;
       sort(); 
       for (i = 0; i < noOfStudents; i++)
       {
           cout << i + 1 << ": ";
           display(students[i]);
       }
   }

   // TODO: Implementation for the deallocateMemory function goes here
   void deallocateMemory()
   {
       int i;
       
       for (i = 0; i < noOfStudents; i++)
       {
           Student& stu = students[i];
           delete[] stu.m_name;
       }
       delete[] students;
   }
}