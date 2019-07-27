#ifndef ZOO_BIRD_H
#define ZOO_BIRD_H
#include "animal.h"
#include "flyable.h"
class Bird : public Animal, Flyable
{
public:
    Bird(const std::string &name);

    std::string getName() override;

    std::string breed() override;

private:
    void land() override;

    void fly() override;

    void takeOff() override;
};


#endif //ZOO_BIRD_H
