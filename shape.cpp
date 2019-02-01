#include "shape.h"
#include <cmath>
#include "vector2.h"

const char* Shape::getType(){
    return "";
}

float Shape::area(){
    return -1;
}

float Shape::circumference(){
    return 0;
}

Vector2 Shape::position(){
    Vector2 centroid = {0, 0};
    return centroid;
}

bool Shape::isConvex(){
    return false;
}

float Shape::distance(Shape &s){
    Vector2 firstShape = this->position();
    Vector2 secondShape = s.position();

    float distance = sqrt((pow((firstShape.x - secondShape.x), 2)) +
        (pow((firstShape.y - secondShape.y), 2)));
    return distance;
}

