/*
compiler-specific directive used to ensure that the header file is included only once during compilation, 
regardless of how many times it is included in different source files. It helps prevent multiple inclusion errors.
*/
#pragma once


/*
Declares a class and adds its own constructor and overrides the displayCourseDetails() function inherited from the base class.
*/
#include "ParentCourse.h"
//class name     and      inherits publicly from the parent class
class GeneralStudyCourse : public ParentCourse {
public:
    //constructor prototype and paras
    GeneralStudyCourse(const std::string& name, double cost, const std::string& professor, int credits);

    // create member func method prototype. 
    //const is specifier for not modify the object on which it is called.
    //it'll override a virtual function with the same signature in the base class "ParentCourse"
    void displayCourseDetails() const override;

    void registerCourse(const std::string& userName) override;

   // std::string getCategory() const override;
    int getCategory() const override;
    std::string getTitle() const override;
};



