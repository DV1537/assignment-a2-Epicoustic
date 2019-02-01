#ifndef POINT_H
#define POINT_H

#include "shape.h"

class Point : public Shape
{
    public:
        Point(float x, float y);
        float area();
        const char* getType();
        float circumference();
        bool isConvex();
        Vector2 position();
    private:
        float x, y;
};

#endif