#ifndef SHARPIESET_SHARPIESET_H
#define SHARPIESET_SHARPIESET_H
#include <vector>
#include "Sharpie.h"
class SharpieSet
{
public:
    bool countUsable();
    void removeTrash();
private:
    std::vector<Sharpie> _SharpieSet;
};

#endif //SHARPIESET_SHARPIESET_H
