#include <iostream>
#include "Station.h"
#include <vector>
void generations(std::vector<Car>&);
void refillAll(Station&, std::vector<Car>&);
void refill();
int main()
{
    Station BP(1000);
    std::vector<Car> cars;
    generations(cars);
    refillAll(BP, cars);
    return 0;
}

void generations(std::vector<Car>& cars)
{
    cars.push_back(Car(48, 50));
    cars.push_back(Car(22, 50));
    cars.push_back(Car(45, 100));
    cars.push_back(Car(8, 26));
    cars.push_back(Car(23, 35));
}

void refillAll(Station& petrolStation, std::vector<Car>& cars)
{
    for (int i = 0; i < cars.size(); ++i) {
        while (cars[i].isFull() == 0){
            petrolStation.fill(cars[i]);
        }
        petrolStation.remain();
    }
}