/*
Rachael Savage
CSC275-C++ 2
Professor Tony Hinton
6/21/23
*/

#include "TechnologyCourse.h"//child class header file
#include "GeneralStudyCourse.h"//child class header file
#include "ElectiveCourse.h" //child class header file
#include <iostream> //input/output
#include <vector> //library is used to create and manage a dynamic collection of Course objects
#include <limits>//use to specify the maximum value when calling std::cin.ignore() function
//provides functions and manipulators for formatting input and output
#include <iomanip>//use to set the precision

void intro(); //func prototype with no body{}
void instruction();

int main() {
    std::cout << "\n\n\n\n" << std::endl;
    for (int i = 0; i < 2; ++i) {
        std::cout << "*****************************************************************************************************" << std::endl;
    }
    std::cout << "" << std::endl;
    std::cout << "\n          WELCOME TO UNIVERSITY COURSE REGISTRATION SYSTEM\n" << std::endl;
    
    for (int i = 0; i < 2; ++i) {
        std::cout << "******************************************************************************************************" << std::endl;
    }
    std::cout << "\n\n" << std::endl;
    //call the intro and instruction funcs. NOTE that no return func type, just the name
    intro();

    std::string userName; //create var for user input
    //ask user name
    std::cout << "Please enter your full name to continue:  " << std::endl;
    //capture user name using getline func to capture along string text
    std::getline(std::cin, userName);
    //display user name
    std::cout << "Welcome to course registration program,"<< userName <<"!" << std::endl;
    std::cout << "Please read and follow instructions below to register courses" << std::endl;



    std::cout << "\n           HOW TO USE IT?\n" << std::endl;
    instruction();
    

    //creates a vector courses to store pointers to Course objects. 
    //This vector will be used to store instances of different course types.
    std::vector<Course*> courses;
    //Course objects are dynamically allocated using the new operator and added to the courses vector
    courses.push_back(new TechnologyCourse("C++ Programming", 1500.0, "Matthew Davis", 4));
    courses.push_back(new TechnologyCourse("Web Development", 1250.0, "Emily Brown", 3));
    courses.push_back(new TechnologyCourse("Data Structures", 1600.0, "Michael Davis", 3));
    courses.push_back(new GeneralStudyCourse("Introduction to Biology", 1300.0, "Mia Taylor", 4));
    courses.push_back(new GeneralStudyCourse("World History", 1100.0, "Jessica Wilson", 3));
    courses.push_back(new GeneralStudyCourse("College Algebra", 1400.0, "Daniel Thompson", 3));
    courses.push_back(new ElectiveCourse("English", 1000.0, "David Johnson", 3));
    courses.push_back(new ElectiveCourse("Art Appreciation", 900.0, "Sophia Anderson", 3));
    courses.push_back(new ElectiveCourse("Introduction to Psychology", 1100.0, "Oliver Martin", 4));

    std::cout << "\n    COURSE CATEGORIES : \n" << std::endl;
    std::cout << "1. Technology Courses" << std::endl;
    std::cout << "2. General Study Courses" << std::endl;
    std::cout << "3. Elective Courses" << std::endl;
    std::cout << "4. Exit" << std::endl;

    std::vector<Course*> selectedCourses;
    double totalCost = 0.0;

    while (true) {
        std::cout << "\nPlease enter the category number of the course you want to register (1-3) or 4 to exit: ";
        int category;
        std::cin >> category;
        //clear the input buffer after reading input from the user using std::cin.
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (category == 4) {//out of the range
            break;
        }
        else if (category < 1 || category > 3) {
            std::cout << "Invalid category. Please enter a number between 1 and 4." << std::endl;
            continue;
        }

        std::cout << "Available courses in the selected category:" << std::endl;
        bool coursesFound = false;
        int courseIndex = 1;
        for (const auto& course : courses) {
            if (course->getCategory() == (category)) {
                std::cout << courseIndex << ". " << course->getCourseName() << std::endl;
                ++courseIndex;
                coursesFound = true;
            }
        }

        if (!coursesFound) {
            std::cout << "No courses available in the selected category." << std::endl;
            continue;
        }


        std::cout << "Please enter the index of the course you want to register: ";
        int courseChoice;
        std::cin >> courseChoice;
        //clear the input buffer after reading input from the user using std::cin.
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (courseChoice < 1 || courseChoice > courseIndex - 1) {
            std::cout << "Invalid course index. Please enter a valid index." << std::endl;
            continue;
        }

        Course* selectedCourse = nullptr;//declares pointer var selectedCourse and initializes it to nullptr which is not point to any valid object or memory address.
        courseIndex = 1;//keep track of the position of the courses within the desired category.
        for (const auto& course : courses) {//a range-based for loop that iterates over each course in the courses collection
            if (course->getCategory() == (category)) {//checks if the category of the current course matches 
                if (courseIndex == courseChoice) {//checks course's index matches the user's choice 
                    selectedCourse = course;// assigns the address of the current course to the selectedCourse pointer.
                    break;
                }
                ++courseIndex;//increments the courseIndex after each iteration
            }
        }
        //checks if the selectedCourse pointer is not nullptr = evaluates to true
        if (selectedCourse != nullptr) {
            //adds the selectedCourse pointer to the selectedCourses vector container 
            selectedCourses.push_back(selectedCourse);
            totalCost += selectedCourse->getCourseCost();//increments the totalCost variable by the cost of the selected course
            std::cout << "\nCourse \"" << selectedCourse->getCourseName() << "\" has been registered." << std::endl;
        }
        else {
            std::cout << "Invalid course selection. Please try again." << std::endl;
        }
    }

    std::cout << "\n==================================" << std::endl;
    std::cout << "   SUMMARY OF SELECTED COURSES" << std::endl;
    std::cout << "==================================" << std::endl;

    /*
    * const auto& specifie that course is a constant to each element
    it allows us to access its data members from the classes without modifying them.
    */
    for (const auto& course : selectedCourses) {
        std::cout << "Category: " << course->getCategory() << std::endl;
        std::cout << "Course: " << course->getCourseName() << std::endl;
        std::cout << "Professor: " << course->getCourseProfessor() << std::endl;
        std::cout << "Credits: " << course->getCourseCredits() << std::endl;
        std::cout << "Cost: $" << course->getCourseCost() << std::fixed << std::setprecision(2) << std::endl;
        std::cout << "------------------------------" << std::endl;
    }

    std::cout << "Total Cost: $" << totalCost << std::fixed << std::setprecision(2) << std::endl;



    
    // cleans up/deallocates the dynamically allocated memory by deleting each course object from the courses vector using delete.
    for (auto& course : courses) {
        delete course;
    }

    return 0;
}//end main


//implementing the intro func by adding a body {} and data in it
void intro() {
    std::cout << "University Course Registration System is a program designed to assist students in selecting and managing their university courses" << std::endl;
    std::cout << "It allows you to view course details, including the course name, cost, professor, and credits" << std::endl;
    std::cout << "You can select courses from categories such as Technology, General Study, and Elective." << std::endl;
    std::cout << "The  the program will also provide a summary of your selected courses and the total cost." << std::endl;
    std::cout << "" << std::endl;
    
}

void instruction() {
    std::cout << "You will see a list of course categories:" << std::endl;
    std::cout << "Technology Course, General Study Course, and Elective Course" << std::endl;
    std::cout << "Enter the number corresponding to the category you wish to explore and press Enter." << std::endl;
    std::cout << "The program will display the available courses in the selected category, along with their details." << std::endl;
    std::cout << "After you exit the course selection by entering 4, you will see a summary of the courses you selected and the total cost" << std::endl;
    std::cout << "NOTE: make sure you enter the correct number when choosing options." << std::endl;
}