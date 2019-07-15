#ifndef GREENFOXINHARITANCEEXCERCISE_COHORT_H
#define GREENFOXINHARITANCEEXCERCISE_COHORT_H
#include <string>
#include <vector>
#include "Student.h"
#include "Mentor.h"
//Cohort
//Create a Cohort class that has the following
//members:
//name: the name of the cohort
//students: a vector of Students
//mentors: a vector of Mentors
//functions:
//addStudent(Student*): adds the given Student to students vector
//addMentor(Mentor*): adds the given Mentor to mentors vector
//info(): prints out "The name cohort has students.size() students and mentors.size() mentors."
//The Cohort class has the following constructors:
//Cohort(name): beside the given parameter, it sets students and mentors as empty lists

class Cohort
{
public:
    Cohort(const std::string &name, const std::vector<Student *> &students, const std::vector<Mentor *> &mentors);

    void addStudent(Student*);
    void addMentor(Mentor*);
    void info();
private:
    std::string _name;
    std::vector<Student*> students;
    std::vector<Mentor*> mentors;
};


#endif //GREENFOXINHARITANCEEXCERCISE_COHORT_H
