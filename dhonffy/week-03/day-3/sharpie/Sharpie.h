
#ifndef SHARPIE_SHARPIE_H
#define SHARPIE_SHARPIE_H

#include <string>

class Sharpie
{
public:
    Sharpie(std::string color, float width);
    void use();
private:
    std::string _color;
    float _width;
    float _inkAmount = 100.0;
};


#endif //SHARPIE_SHARPIE_H
