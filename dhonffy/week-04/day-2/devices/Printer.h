#ifndef DEVICES_PRINTER_H
#define DEVICES_PRINTER_H
#include <string>

class Printer
{
public:
    Printer();
    virtual std::string getSize() = 0;

    virtual void print();

private:
};


#endif //DEVICES_PRINTER_H
