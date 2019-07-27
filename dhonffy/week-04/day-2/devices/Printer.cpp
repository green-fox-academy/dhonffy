#include "Printer.h"
#include <iostream>
Printer::Printer()
{}

void Printer::print()
{
    std::cout << "I'm printing something that's " << getSize() << " cm." << std::endl;
}
