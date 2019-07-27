#ifndef DEVICES_COPIER_H
#define DEVICES_COPIER_H

#include "Printer2D.h"
#include "Scanner.h"

class Copier : Printer2D, Scanner
{
public:
    Copier(int sizeX, int sizeY, int speed);
    void copy();

private:
    void print() override;

    void scan() override;
};


#endif //DEVICES_COPIER_H
