#ifndef ZOO_ANIMAL_H
#define ZOO_ANIMAL_H

#include <string>

class Animal
{
public:
    Animal(const std::string &name);
    virtual std::string getName() = 0;
    virtual std::string breed() = 0;
protected:
    std::string _name;
    int _age;
};


#endif //ZOO_ANIMAL_H
