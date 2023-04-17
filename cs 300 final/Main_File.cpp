//Author :Jeury Santos
//Major: Computer Science
//Class: CS 300
//School : SHNU
//Description : Thsi program allow user to look up the desired calss and obtains its disprectiion and pre-cal
//Date : Sun 6 Apr 2023


#include <iostream> 
#include <map>
#include <string>
#include <vector>
#include<fstream>
#include<sstream>

using namespace std;

void readFile(std::vector<std::string>& data, const std::string& filename) {
    std::ifstream infile(filename);
    if (!infile) {
        std::cerr << "Unable to open file: " << filename << std::endl;
        return;
    }
    std::string line;
    while (std::getline(infile, line)) {
        data.push_back(line);
    }
}

// Struct  to hold information about the  course

struct Course{
    string name;
    vector<string> prerequisites;
};


//Map to hold the information of the course
map<string, Course> courses;

//Function Desfinition

//function to load the data structures
void loadDataStructures() {
    Course c;

    c.name = "Discrete Mathematics";
    courses["MATH201"] = c; 

    c.name = "Introduction to Computer Science";
    courses["CSCI100"] = c;

    c.name = "Introduction to Programming in C++";
    c.prerequisites.push_back("CSCI100");
    courses["CSCI101"] = c;

    c.name = "Data Structures";
    c.prerequisites.push_back("CSCI101");
    courses["CSCI200"] = c;
 

    c.name = "Advanced Programming in C++";
    courses["CSCI301"] = c;

    c.name = "Introduction to Algorithms";
    c.prerequisites.push_back("CSCI200");
    c.prerequisites.push_back("MATH201");
    courses["CSCI300"] = c;

    c.name = "Operating Systems";
    c.prerequisites.push_back("CSCI300");
    courses["CSCI350"] = c;

    c.name = "Large Software Development";
    c.prerequisites.push_back("CSCI301");
    c.prerequisites.push_back("CSCI350");
    courses["CSCI400"] = c;



}


// function to print the list of all courses, To increase readability of the courses code has added Bold UI
void printCourseList() {
    for (auto const& courses : courses) {
        cout << "\033[1m" << courses.first << "\033[0m" << ", " << courses.second.name << endl;
        cout << endl; // Add empty line for readability
    }
}
// function to print the details of a specific course
void printCourse(string courseCode) {

    // conver input to lowercase 
    
    if (courses.find(courseCode) == courses.end()) {
        cout << "Course not found." << endl;
        return;
    }

    Course c = courses[courseCode];
    cout << "-------------------------- "<< endl; // Adding devider to increase readability
    cout <<  "\033[1m" << courseCode + " "+ c.name  << "\033[0m" << endl; // bold string added fro better UI
    cout << "-------------------------- "<< endl; // Adding devider to increase readability
    
    
    if (!c.prerequisites.empty()) {
        cout << "Prerequisites: ";
        for (auto const& prereq : c.prerequisites) {
            cout << prereq << ", ";
        }
        cout << endl;
        cout << "-------------------------- "<< endl; // Adding devider to increase readability
        
    }
    else  {
        cout << " Not Prerequisites required" << endl;
        cout << "-------------------------- "<< endl; // Adding devider to increase readability
    }
}

int main() {

    int choice = 0;
    while (choice != 9) {
        cout << "-------------------------- "<< endl;
        cout <<  "\033[1m" << "Menu" << "\033[0m" <<endl; //
        cout << "1. Load Data Structure." << endl;
        cout << "2. Print Course List." << endl;
        cout << "3. Print Course." << endl;
        cout << "9. Exit" << endl;
        cout << "-------------------------- "<< endl;
        cout <<  "\033[1m" << "What would you like to do? " << "\033[0m";
        cin >> choice;

        switch (choice) {
            case 1:
                loadDataStructures();
                cout<< " "<<endl; // empty sapce for better readability.
                cout<<  "\033[1m" << "***The Data has been loaded successfully**"<< "\033[0m" <<endl;
                cout << " Please select a value between 2 and 3 or (9 for exit)." <<endl;
                 cout<< " "<<endl; // empty sapce for better readability.
                break;
            case 2:
                printCourseList();
                break;
            case 3: {
                string courseCode;
                cout<< " "<<endl; // empty sapce for better readability.
                cout << "What course do you want to know about?\t ";
                cout<< " "<<endl; // empty sapce for better readability.
                cin >> courseCode;
                transform(courseCode.begin(), courseCode.end(), courseCode.begin(), ::toupper);
                printCourse(courseCode);
                break;
            }
            case 9:
                cout << "Thank you for using the course planner.\t" << endl;
                break;
            default:
                cout << choice << " is Invalid input. Please enter a numeric value between 1 and 3.\t" << endl;
                break;
        }
    }

    return 0;

}
