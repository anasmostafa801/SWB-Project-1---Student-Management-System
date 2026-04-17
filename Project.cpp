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
vector <Student> students;

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

// Functions Implementations

//1 - addStudent function : 
void addStudent (){
      if (!students.empty()){
        cout << "Note : There are " << students.size() << " students already in the DataBase..." << endl;
      } else {
        cout << "Note : There are no Students in the DataBase !" << endl;
      }
      cout << "Please provide the following Student's Data....." << endl;
      Student dummyStudent;
jump: cout << "Enter Student's ID : ";
      cin >> dummyStudent.ID;  // Getting Student ID
      cin.ignore();  // So Getline would not get the endl as the Student name (associated to the Bluffer)
 // Searching if Student already exists through ID Searching
      for (int i = 0; i < students.size(); i++){
        if (dummyStudent.ID == students[i].ID){
            cout << "ID Already Exists ! " << endl;
            cout << "To go back to the Menu press -1, To Enter a new ID press any number : ";
            int choice0 ; cin >> choice0;
            if (choice0 == -1) return;
            else goto jump;
        }
    }
    // Student Has Been Found since we are still within the Function
    cout << "Enter student's Name : " << endl; // Entering Student Name
    getline(cin, dummyStudent.Name);
    // Providing Student Grader For Each Subject
    for (int i = 0; i < subjectNumber; i++){
gradeIn: cout << "Enter Grades for Subject (" << i+1 << ") : ";
         cin  >> dummyStudent.Grades[i];
         if ((dummyStudent.Grades[i] < 0) || (dummyStudent.Grades[i] > maxGrade)){
            cout << "Invalid Grade, Please Supply a Valid Grade : ";
            goto gradeIn;
        }
        cout << endl;
    }
    // Pushing Pack the Student into The Vector of Students
    students.push_back(dummyStudent);
    return;
}


//2- Display all Students function :
void displayStudents (){
 if (students.empty()){
    cout << "There are no Students in the DataBase!" << endl;
    return;
 } else {
    cout << "Displaying All Student :" << endl;
    cout << "ID           |  Name               \t        |     Subject1  |   Subject2    |  Subject3     |   Subject4    |    Subject5   |" << endl;
    cout << "==============================================================================================================================" << endl;
    for (int i = 0; i < students.size(); i++){
        cout << students[i].ID << "          |  " << students[i].Name << "               \t|\t";
        for (int j = 0; j < subjectNumber; j++){
            cout << students[i].Grades[j] << "\t|\t";
        }
        cout << endl;
  }
  return;
 }
}


//3 - Searching student by ID or Name
void searchStudent (){
    // IF there are no Students Don't Search !
    if (students.empty()){
        cout << "DataBase is Empty, No Students to Search !" << endl;
        return;
    }
    // IF we still in the function that mean there are Students in the DataBase, Continue Searching
    int choice;
jump13: cout << "To search by Name press 0 , by ID press 1 : ";
        cin >> choice;
    // Searching By Name , Every name has to Unique and not Duplicated (i.e Family Name to be provided) 
    if (!choice) {
        cout << "Searching by Name Started...." << endl;
jump0:  cout << "Please enter the Student's Name : ";
        string Name;
        cin.ignore();
        getline(cin, Name); // Getting the Full Name
        for (int i = 0; i < students.size(); i++){
            if (Name == students[i].Name){
                cout << "Student Found !" << endl;
                cout << "ID           |  Name               \t        |     Subject1  |   Subject2    |  Subject3     |   Subject4    |    Subject5   |" << endl;
                cout << "==============================================================================================================================" << endl;
                cout << students[i].ID << "          |  " << students[i].Name << "               \t|\t";
                for (int j = 0; j < subjectNumber; j++){
                cout << students[i].Grades[j] << "\t|\t";
               }
                 cout << endl << "To go back to the Menu press -1, to keep searching press any number : ";
                 int choice12; cin >> choice12;
                 if (choice12 == -1) return;
                 else goto jump13;
   
            } 
         }
        // IF we Stille withing the Function and Not returned , that means that the loop Ended 
        // withoud finding the Desired Name 
        cout << "Student's Name NOT Found !" << endl;
        cout << "To go back to the Menu press -1, To Supply another name press any number : ";
        int choice2; cin >> choice2;
        if (choice2 == -1) return;
        else goto jump0;
     }
     // Searching By ID, ID's has to Unique and not Duplicated
    if (choice) {
        cout << "Searching by ID Started...." << endl;
 jump1: cout << "Please Enter the Student's ID : ";
        string ID;
        cin >> ID;
        for (int i = 0; i < students.size(); i++){
            if (ID == students[i].ID){
                cout << "Student Found !" << endl;
                 cout << "ID           |  Name               \t        |     Subject1  |   Subject2    |  Subject3     |   Subject4    |    Subject5   |" << endl;
                 cout << "==============================================================================================================================" << endl;
                cout << students[i].ID << "          |  " << students[i].Name << "               \t|\t";
                for (int j = 0; j < subjectNumber; j++){
                cout << students[i].Grades[j] << "\t|\t";
               }
               cout << endl <<"To go back to the Menu press -1, to keep searching press any number : ";
                 int choice13; cin >> choice13;
                 if (choice13 == -1) return;
                 else goto jump13;
            } 
        }
        // IF we Still withing the Function and Not returned , that means that the loop Ended 
        // withoud finding the Desired ID
        cout << "Student's ID NOT Found !" << endl;
        cout << "To go back to the Menu press -1, To Supply another name press any number : ";
        int choice3; cin >> choice3;
        if (choice3 == -1) return;
        else goto jump1;
    }
    return;
}


//4 - Update Student Information
void updateStudent (){
    // IF there are no Students Exit the function!
    if (students.empty()){
        cout << "DataBase is Empty, No Students to Update!" << endl;
        return;
    }
    // IF there are Students Start Implementing the Function :
    int choice;
    // We will Either Search the Student to update his/her information, either by name or ID
    // IF searching by Name we will be able to update ID or Grades (Convention) 
    // IF searching by ID We will be able to update the name or Grades (Convention)
    cout << "To search by Name press 0 , by ID press 1 : ";
    cin >> choice;
    // First Searching by Name :
    if (!choice) {
        cout << "Searching by Name Started...." << endl;
jump4:  cout << "Please enter the Student's Name to update his/her Data : ";
        string Name;
        cin.ignore();
        getline(cin, Name); // Using Getline to get the full string
        // Searching for Student inside the Vector of Students
        for (int i = 0; i < students.size(); i++){
            if (Name == students[i].Name){ // Found the Name [Student Name has to match Exactly]
                // Operation on Student's ID : 
                string dummy1;
                cout << "Enter the new ID to update it, or Press -1 to Keep the old one : ";
                cin >> dummy1;
                if (dummy1 != "-1"){ // Changing Student's ID
                    students[i].ID = dummy1;
                }
                // Operation on Student's Grades :
                int dummy2;
                cout << "To Supply the new Grades for Each Subject press any number, or press -1 to keep the old ones : ";
                cin >> dummy2;
                if (dummy2 != -1){ // Changing Student's Grades :
                  for (int j = 0; j < subjectNumber; j++){
      gradeIn0:    cout << "Update Subject number (" << j+1 << ") : ";
                    cin >> students[i].Grades[j];
                    if ((students[i].Grades[j] < 0) || (students[i].Grades[j] > maxGrade)){
                        cout << "Invalid Grade, Please Supply a Valid Grade : ";
                        goto gradeIn0;
                    }
                    cout << endl;
                  }
                }
                cout << "To go back to menu press -1, To keep updating Data press any Number : ";
                int choice3; cin >> choice3;
                if (choice3 == -1) return;
                else goto jump4;
            } 
        }
        cout << "Student's Name Not Found !" << endl;
        cout << "To go back to menu press -1, To keep Supply a valid Name press any Number : ";
                int choice4; cin >> choice4;
                if (choice4 == -1) return;
                else goto jump4;
    }

    //Searching by ID : 
    if (choice) {
        cout << "Searching by ID Started...." << endl;
jump5:  cout << "Please enter the Student's ID to update his/her Data : ";
        string ID;
        cin >> ID;
        for (int i = 0; i < students.size(); i++){
            if (ID == students[i].ID){ // The first Mathcing ID [ID's Has to be Unique]
                // Operation on Student's Name :
                string dummy1;
                cout << "Enter a new Name to update Student's name, or Press -1 to Keep the old ID : ";
                cin.ignore();
                getline(cin, dummy1); // To Either get the Full Name or get -1 to Keep the old one :
                if (dummy1 != "-1"){
                    students[i].Name = dummy1;
                }
                // Operation on Student's Grades :
                int dummy2;
                cout << "To Supply the new Grades for Each Subject press any number, or press -1 to keep the old Grades : ";
                cin >> dummy2;
                if (dummy2 != -1){
                  for (int j = 0; j < subjectNumber; j++){
     gradeIn1:      cout << "Update Subject number (" << j+1 << ") : ";
                    cin >> students[i].Grades[j];
                    if ((students[i].Grades[j] < 0) || (students[i].Grades[j] > maxGrade)){
                        cout << "Invalid Grade, Please Supply a Valid Grade : ";
                        goto gradeIn1;
                    }
                    cout << endl;
                  }
                }
                cout << "To go back to menu press -1, To keep updating Data press any Number : ";
                int choice5; cin >> choice5;
                if (choice5 == -1) return;
                else goto jump5;
            } 
        }
        // IF we Still within the function that menas we did not find a matching ID :
        cout << "Student's ID Not Found !" << endl;
        cout << "To go back to menu press -1, To keep Supply a valid Name press any Number : ";
                int choice6; cin >> choice6;
                if (choice6 == -1) return;
                else goto jump5;
    }
    return;
}

// 5 - Delete Student
void deleteStudent (){
    // IF there are no Students Exit the function!
    if (students.empty()){
        cout << "DataBase is Empty, No Students to Delete!" << endl;
        return;
    }
jump6:  cout << "To search by Name press 0 , by ID press 1 : ";
    int choice; cin >> choice;
    // Searching By Name :
    if (!choice){
    string dummyName; 
    cout << "Please enter a Student's Name to delete record : ";
    cin.ignore();
    getline(cin, dummyName);
    for (int i = 0; i < students.size(); i++){
        if (dummyName == students[i].Name){
            for (int j = i; j < (students.size()-1); j++){
                students[j] = students[j+1];    // Shifting all Students to Replace the Deleted Student
            }
            students.pop_back(); // The last Element is Duplicated, Deleting it from the Vector
            cout << "To go back to menu press -1, To keep Deleting Records press any Number : " << endl;
                int choice7; cin >> choice7;
                if (choice7 == -1) return;
                else goto jump6;
            }
         }  
    // IF we Still within the function that menas we did not find a matching ID :
        cout << endl <<"Student's Name Not Found !" << endl;
        cout << "To go back to menu press -1, To Supply a valid Name or ID press any Number : ";
                int choice8; cin >> choice8;
                if (choice8 == -1) return;
                else goto jump6;
    }

    // Searching by ID :
    if (choice){
    string dummyID; 
    cout << "Please enter a Student's ID to delete : ";
    cin >> dummyID;
    for (int i = 0; i < students.size(); i++){
        if (dummyID == students[i].ID){
            for (int j = i; j < (students.size()-1); j++){
                students[j] = students[j+1];  // Shifting all Students to Replace the Deleted Student
            }
            students.pop_back(); // Deleting the Last Replicated Student
            cout << "To go back to menu press -1, To keep Deleting Records press any Number : ";
                int choice9; cin >> choice9;
                if (choice9 == -1) return;
                else goto jump6;
        }
    } 
    // IF we Still within the function that menas we did not find a matching ID :
        cout << "Student's ID Not Found !" << endl;
        cout << "To go back to menu press -1, To Supply a valid ID or Name press any Number : ";
                int choice10; cin >> choice10;
                if (choice10 == -1) return;
                else goto jump6;
     }
 return;
}


// 6 - Show top performaing Students
void topPerforming (){
    if (students.empty()){
        cout << "No Students Found, DataBase is Empty ! " << endl;
        return;
    }
    // Copying the students Vector to Manipulate
    vector <Student> dummyStudents = students;
    sort(dummyStudents.begin(), dummyStudents.end(), [](const Student& a, const Student& b) { // Sorting the Vector of Students using
    return a.getAverage() > b.getAverage();                                                     // Lampda Functions (Becaus of Vector of Structs)
    });                                                                                         // Descending Order [According to Grades]
    // IF the No. of Students is Less than Ten , Show All Students who have passed 50
    if (students.size() <= 10){
        int cnt = 9;
        cout << "The top Performing Students are : " << endl;
        cout << "ID           |  Name               \t        |     Subject1  |   Subject2    |  Subject3     |   Subject4    |    Subject5   |" << endl;
        cout << "==============================================================================================================================" << endl;
        for (int i = 0; i < students.size(); i++){
             if (dummyStudents[i].getAverage() <= 50) continue;                              //Show top Performing 
                cout << dummyStudents[i].ID << "          |  " << dummyStudents[i].Name << "               \t|\t";      // Studentss' Data
                for (int j = 0; j < subjectNumber; j++){
                cout << dummyStudents[i].Grades[j] << "\t|\t";
               }
               cout << endl; 
               cnt--;                                                                                     
            }
            cout << endl;
            if (cnt == 9) cout << "There are not any Top Performing Students !" << endl; // IF Counter hasn't been decremented at all, There are no tops        
      } 
       // IF the No. of Students is Higher than 10, Display the Top 10 Performing
      else {  
        int cnt = 9, i = 0;   // The cnt is to make sure the we count on 10 Students, and the (i) is to loop through the Vector Independtly
        cout << "The top Performing Students : " << endl;
        cout << "ID           |  Name               \t|     Subject1  |   Subject2    |  Subject3     |   Subject4    |    Subject5   |" << endl;
        cout << "======================================================================================================================" << endl;
        while (cnt > 0){
             if (dummyStudents[i].getAverage() <= 50) {
                i++;
                continue;
             }
                cout << dummyStudents[i].ID << "          |  " << dummyStudents[i].Name << "               \t|\t";
                for (int j = 0; j < subjectNumber; j++){
                cout << dummyStudents[i].Grades[j] << "\t|\t";
               }
               cout << endl;
               i++;
               cnt--;
          }
        if (cnt == 9) cout << "There are not any Top Performing Students !" << endl; // IF Counter hasn't been decremented at all, There are no tops
      }
      return;
   }

// 7 - Sorting by Grades
void gradeSort (){
    if (students.empty()){
        cout << "No Students Found, DataBase is Empty ! " << endl;
        return;
    }
    // Copying the students Vector to Manipulate
    vector <Student> dummy0Students = students;
    sort(dummy0Students.begin(), dummy0Students.end(), [](const Student& a, const Student& b) { // Sorting the Vector of Students using
    return a.getAverage() > b.getAverage();                                                     // Lampda Functions (Becaus of Vector of Structs)
    });                                                                                         // Descending Order [According to Grades]
    // IF the No. of Students is Less than Ten , Show All Students who have passed 50
        cout << "Student Sorted by Grades : " << endl;
        cout << "ID           |  Name               \t        |     Subject1  |   Subject2    |  Subject3     |   Subject4    |    Subject5   |" << endl;
        cout << "==============================================================================================================================" << endl;
        for (int i = 0; i < students.size(); i++){
             if (dummy0Students[i].getAverage() <= 50) continue;                              //Show top Performing 
                cout << dummy0Students[i].ID << "          |  " << dummy0Students[i].Name << "               \t|\t";      // Studentss' Data
                for (int j = 0; j < subjectNumber; j++){
                cout << dummy0Students[i].Grades[j] << "\t|\t";
               }
               cout << endl;                                                                                      
            }
            cout << endl;        
      } 

  // 8 - calculating Average Grade
  void aveGrade (){
  if (students.empty()){
    cout << "There are no Students in the DataBase!" << endl;
    return;
  } else {
    cout << "Displaying All Student :" << endl;
    cout << "ID           |  Name               \t        | Average Grade |" << endl;
    cout << "==============================================================================================================================" << endl;
    for (int i = 0; i < students.size(); i++){
        cout << students[i].ID << "          |  " << students[i].Name << "               \t|\t";
        cout << students[i].getAverage() << "\t|\t";
        cout << endl;
  }
  return;
  }
}    


// 9 - Save Data to a file
void saveData() {
    ofstream file("Data.txt");

    if (!file.is_open()) {
        cout << "Error creating/opening file!\n";
        return;
    }

    for (int i = 0; i < students.size(); i++) {
        file << students[i].ID <<endl;
        file << students[i].Name <<endl;

        for (int j = 0; j < subjectNumber; j++) {
            file << students[i].Grades[j] << " ";
        }
        file << endl;
    }

    file.close();
    cout << "Data saved successfully.\n";
}


// 10 - Read Data from a file
void loadData() {
    ifstream input("Data.txt");
    students.clear();
    if (!input.is_open()) {
        cout << "File not found. Starting with empty database.\n";
        return;
    }

    Student s;
    bool hasData = false;

    while (input >> s.ID) {
        input.ignore();
        getline(input, s.Name);
        for (int i = 0; i < subjectNumber; i++) {
            input >> s.Grades[i];
        }
        students.push_back(s);
        hasData = true;
    }

    if (!hasData) {
        cout << "File exists but is empty.\n";
    } else {
        cout << "Data loaded successfully.\n";
    }

    input.close();
}
// End of the File