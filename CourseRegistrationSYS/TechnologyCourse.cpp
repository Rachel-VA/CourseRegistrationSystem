#include "TechnologyCourse.h"
#include<iostream>


/*
this is the body of this class to implement member func that declared in the header file
*/

//class name        constructor      and paras
TechnologyCourse::TechnologyCourse(const std::string& name, double cost, const std::string& professor, int credits)
    : ParentCourse(name, cost, professor, credits)
{
    // Set values for additional data members
    courseType = "Technology Course";
    courseLevel = "Intermediate";
}

//impleting member func with a body {} and data inside it
void TechnologyCourse::displayCourseDetails() const {
    std::cout << "Technology Course Details" << std::endl;
    ParentCourse::displayCourseDetails(); //call the func inside the parent class
}

void TechnologyCourse::registerCourse(const std::string& userName)
{
    std::cout << "Registered " << getCourseName() << " for " << userName << std::endl;
}

int TechnologyCourse::getCategory() const {
    return 1;
}
     

//std::string TechnologyCourse::getCategory() const {
    //return "Technology";
//}

std::string TechnologyCourse::getTitle() const {
    return getCourseName();
}