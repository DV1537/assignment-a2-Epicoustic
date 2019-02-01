#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "vector2.h"
#include "shape.h"
#include "line.h"

class Triangle : public Shape
{
public:
    Triangle(const Vector2* sentCoord,const int size);
    const char* getType();
    float area();
    float circumference();
    Vector2 position();
    bool isConvex();
private:
    Vector2 tempVector[3];
    int arrSize;
};

#endif