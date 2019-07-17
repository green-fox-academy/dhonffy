#ifndef PIRATES_PIRATE_H
#define PIRATES_PIRATE_H


class Pirate
{
public:
    Pirate();

    void drinkSomeRum();
    void howsItGoingMate();

protected:
    unsigned int _drankRum;
    bool _died;
};


#endif //PIRATES_PIRATE_H
