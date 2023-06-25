#include "ElectiveCourse.h"
#include<iostream>
#include<string>

/*
implementations of the member functions for this class. 
The constructor initializes the member variables, including those inherited from the base class,
and the displayCourseDetails() function
*/


//class name      constructor and body {} and paras
ElectiveCourse::ElectiveCourse(const std::string& name, double cost, const std::string& professor, int credits)
    : ParentCourse(name, cost, professor, credits)
{
    // Set values for additional data members
    courseType = "Elective Course";
    courseLevel = "Advanced";
}

//implementing of the member func by adding a body {} and data in it

void ElectiveCourse::displayCourseDetails() const {
    std::cout << "Elective Course Details" << std::endl;
    ParentCourse::displayCourseDetails();//call the member func from the parent class
}


void ElectiveCourse::registerCourse(const std::string& userName)
{
    std::cout << "Registered " << getCourseName() << " for " << userName << std::endl;
}

int ElectiveCourse::getCategory() const {
    return 3;
}
//std::string ElectiveCourse::getCategory() const {
    //return "Elective";
//}

std::string ElectiveCourse::getTitle() const {
    return getCourseName();
}