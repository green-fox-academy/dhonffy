#include <iostream>
#include "Copier.h"

Copier::Copier(int sizeX, int sizeY, int speed) : Printer2D(sizeX, sizeY), Scanner(speed)
{}

void Copier::copy()
{
    scan();
    print();
}

void Copier::print()
{
    std::cout << " and printing  something that's " << getSize() << " cm" << std::endl;
}
void Copier::scan()
{
    std::cout << "I'm scanning a document " << _speed << " ppm,";
}
