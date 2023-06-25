#pragma once


#include "ParentCourse.h"

//class name and         inherits publicly from the parent class including its data members
class TechnologyCourse : public ParentCourse {
public:
    //create a cocnstructor for this class and take in paras
    TechnologyCourse(const std::string& name, double cost, const std::string& professor, int credits);

    // member func method prototype and will be use to override the same signature func in the base class
    void displayCourseDetails() const override;

    void registerCourse(const std::string& userName) override;

    //std::string getCategory() const override;
    int getCategory() const override;

    std::string getTitle() const override;

};



