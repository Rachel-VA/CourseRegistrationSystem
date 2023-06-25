#pragma once


#include "ParentCourse.h"


// create a child course and inherits member data publicly from the parent class
//adds its own constructor and overrides
class ElectiveCourse : public ParentCourse {
public:
    //constructor and paras
    ElectiveCourse(const std::string& name, double cost, const std::string& professor, int credits);

    // create member method prototype and it'll verride a virtual function with the same signature in the base class "ParentCourse"
    void displayCourseDetails() const override;

    void registerCourse(const std::string& userName) override;

    //std::string getCategory() const override;
    int getCategory() const override;
    std::string getTitle() const override;
};




