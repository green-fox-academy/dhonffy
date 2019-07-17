#include "Pirate.h"
#include <iostream>
Pirate::Pirate()
{
    _drankRum = 0;
    _died = 0;
}

void Pirate::drinkSomeRum()
{
    ++_drankRum;
}

void Pirate::howsItGoingMate()
{
    if (_died){
        std::cout << "He's dead." << std::endl;
    } else if(_drankRum <= 4){
        std::cout << "Pour me anudder!" << std::endl;
    } else{
        std::cout << "Arghh, I'ma Pirate. How d'ya d'ink its goin?" << std::endl;
    }
}
