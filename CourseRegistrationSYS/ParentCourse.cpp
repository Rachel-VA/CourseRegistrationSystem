#include "ParentCourse.h"//header file
#include <iostream> //input/output

/*
* the implementations of the member functions for the "ParentCourse" class.
* The constructor initializes the member variables, including those inherited from the base class

*/


//class name    constructor and paras
ParentCourse::ParentCourse(const std::string& name, double cost, const std::string& professor, int credits)
    : Course(name, cost, professor, credits)
{
    // Initialize additional data members
    courseType = "";
    courseLevel = "";
}
//declares a member func and overrides the same function declared as a pure virtual function in the base class "Course".
void ParentCourse::displayCourseDetails() const {
    std::cout << "Course Name: " << getCourseName() << std::endl;
    std::cout << "Course Cost: $" << getCourseCost() << std::endl;
    std::cout << "Course Professor: " << getCourseProfessor() << std::endl;
    std::cout << "Course Credits: " << getCourseCredits() << std::endl;
    std::cout << "Course Type: " << courseType << std::endl;
    std::cout << "Course Level: " << courseLevel << std::endl;
}

void ParentCourse::setTitle(const std::string& title)
{
}

void ParentCourse::setCategory(const std::string& category)
{
}

