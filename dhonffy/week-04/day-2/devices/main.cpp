#include <iostream>
#include <vector>
#include "Printer.h"
#include "Printer2D.h"
#include "Printer3D.h"
#include "Scanner.h"
#include "Copier.h"

int main(int argc, char *args[])
{
    // Create a vector that holds Printer* objects
    // Fill the vector with 3 Printer2D, 2 Printer3D and 1 copier.
    // Iterate through the vector and invoke print function on all of them.

    // Create a vector that holds Scanner* objects
    // Fill the vector with 2 Scanner and 2 Copier objects.
    // Iterate through the vector and invoke scan function on all of them

    // Create a Copier object and invoke copy function on it.

    std::vector<Printer*> printers;
    Printer2D white2DPrinter(30, 30);
    Printer2D red2DPrinter(40, 30);
    Printer2D orange2DPrinter(40, 40);
    printers.push_back(&white2DPrinter);
    printers.push_back(&red2DPrinter);
    printers.push_back(&orange2DPrinter);
    Printer3D blue3DPrinter(30, 30, 30);
    Printer3D green3DPrinter(40, 40, 40);
    printers.push_back(&blue3DPrinter);
    printers.push_back(&green3DPrinter);
    Copier greyCopier(30, 30, 100);
    //printers.push_back(&greyCopier);
    for (int i = 0; i < printers.size(); ++i) {
        printers[i]->print();
    }

    std::vector<Scanner*> scanners;
    Scanner purpleScanner(30);
    Scanner yellowScanner(40);
    Copier roseCopier(40, 30, 200);
    scanners.push_back(&purpleScanner);
    scanners.push_back(&yellowScanner);
    //scanners.push_back(&greyCopier);
    //scanners.push_back(&roseCopier);
    for (int i = 0; i < scanners.size(); ++i) {
        scanners[i]->scan();
    }
    greyCopier.copy();
}