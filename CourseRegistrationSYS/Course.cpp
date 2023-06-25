#include "Course.h"

//implementing the constructor that declared in this class header file by adding the body {}
Course::Course(const std::string& name, double cost, const std::string& professor, int credits)
    : courseName(name), courseCost(cost), courseProfessor(professor), courseCredits(credits)
{
}

//impleting the member func from private data that declared in the header file by adding in a body{} and pass in a return 
std::string Course::getCourseName() const {
    return courseName;
}

double Course::getCourseCost() const {
    return courseCost;
}

std::string Course::getCourseProfessor() const {
    return courseProfessor;
}

int Course::getCourseCredits() const {
    return courseCredits;
}

void Course::setCourseName(const std::string& name) {
    courseName = name;
}

void Course::setCourseCost(double cost) {
    courseCost = cost;
}

void Course::setCourseProfessor(const std::string& professor) {
    courseProfessor = professor;
}

void Course::setCourseCredits(int credits) {
    courseCredits = credits;
}

