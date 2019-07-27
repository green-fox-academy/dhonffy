#ifndef DEVICES_PRINTER2D_H
#define DEVICES_PRINTER2D_H

#include <string>
#include "printer.h"

class Printer2D : public Printer
{
public:
    Printer2D(int sizeX, int sizeY);

    std::string getSize() override;

protected:
    int _sizeX;
    int _sizeY;
};


#endif //DEVICES_PRINTER2D_H
