#include "Cohort.h"
#include <iostream>

Cohort::Cohort(const std::string &name) : _name(name)
{}


void Cohort::addStudent(Student *student)
{
    students.push_back(student);
}

void Cohort::addMentor(Mentor *mentor)
{
    mentors.push_back(mentor);
}

void Cohort::info()
{
    std::cout << "The " << _name << " has " << students.size() << " students and "
              << mentors.size() << " mentors." << std::endl;
}


