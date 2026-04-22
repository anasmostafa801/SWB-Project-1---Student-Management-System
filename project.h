#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

//constants
const int subjectNumber = 5;
const int maxGrade = 100;

//struct
struct Student {
    public:

      string ID;
      string Name;
      double Grades  [subjectNumber];
     
      // A method to return the Average 
      double getAverage() const {
      double sum = 0;
      for (int i = 0; i < subjectNumber; i++) {
          sum += Grades[i];
      }
      return sum / subjectNumber;
   }
};

/* vector of students */
 extern vector <Student> students;

/*Functions Prototyping*/
// 1 - Add Student
void addStudent();
// 2 - Diplay all Students
void displayStudents();
// 3 - Searching a Student
void searchStudent();
// 4 - Update Student
void updateStudent();
// 5 - Delete a Student
void deleteStudent();
// 6 - Top Performing Student
void topPerforming();
// 7 - Sort By Grade
void gradeSort();
// 8 - Show Average Grade
void aveGrade();
// 9 - Save Data to the Data File
void saveData();
// 10 - Load Data from Data File
void loadData();