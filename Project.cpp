#include "project.h"

/*Vector of Students*/
vector <Student> students;

/*-------------------------------------------------------Main Function-------------------------------------------------------------------*/
int main(){
   int choose;
   do {
   cout << "==========================================================================================================" << endl;
   cout << "=======================================[Program Interface]================================================" << endl;
   cout << "Loading Data....." << endl;
   loadData();
   cout << "==========================================================================================================" << endl;
   cout << "================================( Please Pick from the program list : )===================================" << endl;
   cout << "Press [1] to add a new Student." << endl;
   cout << "Press [2] to display all Students." << endl;
   cout << "Press [3] to Search for a Student." << endl;
   cout << "Press [4] to Update Student Data." << endl;
   cout << "Press [5] to Delete Student Recored." << endl;
   cout << "Press [6] to Show Top performing Students." << endl;
   cout << "Press [7] to Show Student Sorted by Grades." << endl;
   cout << "Press [8] to Show Studentss' Averages :" << endl;
   cout << "Press [9] to Save the new Data." << endl;
   cout << "Press [10] to Load the Data from the Data file" << endl;
   cout << "Press [0] to Exit the Program." << endl;
   cin >> choose;
   switch (choose){
   case(1): 
    cout << "======================================( Adding a new Student )===========================================" << endl;
    cout << "Pleas Follw The Instructions to Add a new Student : " << endl;
    addStudent();
    cout << "========================================( Excecution Ended )=============================================" << endl;
    break;
   case(2):
   cout << "====================================( Displaying All Students )===========================================" << endl;
    displayStudents(); 
    cout << "=======================================( Excecution Ended )==============================================" << endl;
    break;
   case(3):
    cout << "======================================( Searching a Student )===========================================" << endl;
    cout << "Pleas Follw The Instructions to Search a Student : " << endl;
    searchStudent();
    cout << "=======================================( Excecution Ended )==============================================" << endl;
    break;
   case(4):
    cout << "======================================( Updating a Student Record )===========================================" << endl;
    cout << "Pleas Follw The Instructions to Update Student Record : " << endl;
    updateStudent();
    cout << "==========================================( Excecution Ended )==============================================" << endl;
    break;
   case(5):
    cout << "======================================( Deleting a Student Record )===========================================" << endl;
    cout << "Pleas Follw The Instructions to Delete Student Record : " << endl;
    deleteStudent();
    cout << "========================================( Excecution Ended )==============================================" << endl;
    break;
   case(6):
    cout << "======================================( Displaying Top Performing )===========================================" << endl;
    topPerforming();
    cout << "==========================================( Excecution Ended )==============================================" << endl;
    break;
   case(7):
    cout << "======================================( Displaying Sorted Students )===========================================" << endl;
    gradeSort();
    cout << "==========================================( Excecution Ended )==============================================" << endl;
    break;
    case(8):
    cout << "======================================( Displaying Average for each Student )===========================================" << endl;
    aveGrade();
    cout << "=============================================( Excecution Ended )==============================================" << endl;
    case(9):
    cout << "======================================( Saving Data to Data File )===========================================" << endl;
    saveData();
    cout << "==========================================( Excecution Ended )==============================================" << endl;
    break;
   case(10):
    cout << "======================================( Reading Data from Data File )===========================================" << endl;
    loadData();
    cout << "==========================================( Excecution Ended )==============================================" << endl;
    break;   
   case(0):
    cout << "Exiting the Program...." << endl;
    break;
    default:
    cout << "Invalid input !, Please Enter a choose from Program List." << endl; 
  }
 } while (choose != 0);
 cout << "==========================================================================================================" << endl;
 cout << "=======================================(Program Excecution Ended)=========================================" << endl;
 cout << "==========================================================================================================" << endl;
    return 0;
}
// End of the File