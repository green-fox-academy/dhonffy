//
// Created by Dani on 2019.07.10..
//

#include "Counter.h"

Counter::Counter(int number): _number(number){}
Counter::Counter(): _number(0){}

void Counter::add()
{
    ++_number;
}
void Counter::add(int number)
{
    _number += number;
}
int Counter::get()
{
    return _number;
}
void Counter::reset()
{
    _number = 0;
}