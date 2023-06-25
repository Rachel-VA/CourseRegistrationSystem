#pragma once //processor directive that ensure this header file only run once
/*
this is the header file for this base abstract class for other classes to be inherited
*/


#include <string>

class Course {
//declares a public constructor for this class and take in four parameters + initializing the member variables 
public:
    Course(const std::string& name, double cost, const std::string& professor, int credits);

    // declares a pure virtual method prototype  and it must be overridden in child classes later
    //(Any class that derives from this base abstract "Course" must provide its own implementation of this function.)
    virtual void displayCourseDetails() const = 0;

    virtual void registerCourse(const std::string& userName) = 0;
    virtual int getCategory() const = 0;
    // Add getCategory() and getTitle() functions
    //virtual std::string getCategory() const = 0;
    virtual std::string getTitle() const = 0;

    // Create Getter methods prototype for the member variables of the "Course" class. 
    //These methods allow access to the values of the private member variables from outside the class.
    std::string getCourseName() const;
    double getCourseCost() const;
    std::string getCourseProfessor() const;
    int getCourseCredits() const;

    // Create Setter methods prototype 
    void setCourseName(const std::string& name);
    void setCourseCost(double cost);
    void setCourseProfessor(const std::string& professor);
    void setCourseCredits(int credits);

   

    //private data member can be only accessed within the class. To use outside of the class, use getter/setter methods
private:
    std::string courseName;
    double courseCost;
    std::string courseProfessor;
    int courseCredits;
};



