#include "GeneralStudyCourse.h"
#include<iostream>

/*
implementing the class constructor and its data members
*/

//class name          constructor        paras
GeneralStudyCourse::GeneralStudyCourse(const std::string& name, double cost, const std::string& professor, int credits)
    : ParentCourse(name, cost, professor, credits)
{
    // Set values for additional data members
    courseType = "General Study Course";
    courseLevel = "Beginner";
}

//implementing the member fun by adding a body {} and data
void GeneralStudyCourse::displayCourseDetails() const {
    std::cout << "General Study Course Details" << std::endl;
    //call the member function of the base class "ParentCourse
    //This will allows the base class implementation of displayCourseDetails() to be executed
    ParentCourse::displayCourseDetails();
}


void GeneralStudyCourse::registerCourse(const std::string& userName)
{
    std::cout << "Registered " << getCourseName() << " for " << userName << std::endl;
}


int GeneralStudyCourse::getCategory() const {
    return 2;
}
//std::string GeneralStudyCourse::getCategory() const {
    //return "General Study";
//}

std::string GeneralStudyCourse::getTitle() const {
    return getCourseName();
}