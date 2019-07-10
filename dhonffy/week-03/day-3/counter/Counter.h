//
// Created by Dani on 2019.07.10..
//

#ifndef COUNTER_COUNTER_H
#define COUNTER_COUNTER_H


class Counter
{
public:
    Counter(int number);
    Counter();
    void add();
    void add(int number);
    int get();
    void reset();
private:
    int _number = 0;
};


#endif //COUNTER_COUNTER_H
