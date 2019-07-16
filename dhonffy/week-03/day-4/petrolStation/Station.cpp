#include "Station.h"

Station::Station(int gasAmount) : _gasAmount(1000)
{

}

void Station::fill(Car& car)
{
    --_gasAmount;
    car.fill();
    std::cout << "Filling car!" << std::endl;
}

void Station::remain()
{
    std::cout << "Remaining gas amount is " << _gasAmount << std::endl;
}


