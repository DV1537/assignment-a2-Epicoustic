#ifndef LINE_H
#define LINE_H

#include "vector2.h"
#include "shape.h"

class Line : public Shape
{
    public:
        Line(const Vector2* sentCoord,int size);
        const char* getType();
        float area();
        float circumference();
        bool isConvex();
        Vector2 position();
    private:
        Vector2 tempVector[2];
};

#endif