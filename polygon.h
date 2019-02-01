#ifndef POLYGON_H
#define POLYGON_H
#include "shape.h"
#include "vector2.h"


class Polygon : public Shape
{
    public:
        Polygon(Vector2* sentCoord,const int size);
        const char* getType();
        float area();
        float circumference();
        bool isConvex();
        Vector2 position();
        float distance(Shape &s);
    private:
        void initializeMinMax(float& miX,float& miY,float& maX,float& maY);
        Vector2* tempVector;
        int arrSize;
        int crossProduct(int index);
        Vector2 boundingBoxCenter();
        bool convex;
};

#endif