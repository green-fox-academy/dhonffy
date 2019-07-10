//
// Created by Dani on 2019.07.10..
//

#include "Animal.h"

Animal::Animal(int hunger, int thirst): _hunger(hunger), _thirst(thirst){}

void Animal::eat()
{
    --_hunger;
}
void Animal::drink()
{
    --_thirst;
}
void Animal::play()
{
    ++_thirst;
    ++_hunger;
}