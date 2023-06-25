#pragma once//preprocessor directive that ensures that this header file containing this code is included only once during compilation.


#include "Course.h" //include header file
//parent class and inherits publicly all member vars from the base class Course
class ParentCourse : public Course {
public:
    // declares a public constructor & paras
    ParentCourse(const std::string& name, double cost, const std::string& professor, int credits);

    // declares a member function prototype and it will override a function with the same signature in the base class
    void displayCourseDetails() const override;

    void registerCourse(const std::string& userName) = 0;

    int getCategory() const = 0;
    void setCategory(const std::string& category);

    void setTitle(const std::string& title);

protected://accessible within the class and its child classes but not from outside the class hierarchy
    // Additional data members
    std::string courseType;
    std::string courseLevel;
};



