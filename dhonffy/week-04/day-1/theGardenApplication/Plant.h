#ifndef THEGARDENAPPLICATION_PLANT_H
#define THEGARDENAPPLICATION_PLANT_H

enum class color
{
    YELLOW,
    BLUE,
    PURPLE,
    ORANGE
};

enum class type
{
    TREE,
    FLOWER
};

class Plant
{
public:
    Plant(color color, type type);
    virtual void watering(int amount) = 0;
    virtual bool needsWater() = 0;
protected:
    bool _needsWater;
    float _waterAmount;
    color _color;
    type _type;
};


#endif //THEGARDENAPPLICATION_PLANT_H
