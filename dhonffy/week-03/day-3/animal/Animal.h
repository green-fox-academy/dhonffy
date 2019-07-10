//
// Created by Dani on 2019.07.10..
//

#ifndef ANIMAL_ANIMAL_H
#define ANIMAL_ANIMAL_H


class Animal
{
public:
    Animal(int hunger, int thirst);
    void eat();
    void drink();
    void play();
private:
    int _hunger = 50;
    int _thirst = 50;
};


#endif //ANIMAL_ANIMAL_H
