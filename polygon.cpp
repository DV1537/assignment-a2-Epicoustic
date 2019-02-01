#include "shape.h"
#include "polygon.h"
#include <iostream>
#include "math.h"
#include "vector2.h"

Polygon::Polygon(Vector2* sentCoord,const int size){
    arrSize = size;
    tempVector = sentCoord;
    convex = Polygon::isConvex();
}
 
const char* Polygon::getType(){
    return "Polygon";
}

// Calculate value using shoelace formula 

float Polygon::area(){
    float area = 0;
    if(convex){
    int j = arrSize - 1; 
    for (int i = 0; i < arrSize; i++) 
    { 
        area += (tempVector[j].x + tempVector[i].x) * (tempVector[j].y - tempVector[i].y); 
        j = i;
    } 

    area = abs(area / 2.0); 
    }
    else{
        area = -1;
    }
    return area;
}

//Calculates perimeter with distance formula

float Polygon::circumference(){
    float circum = 0;
    int j = 1;
    for(int i = 0; i < arrSize - 1; i++){
        circum += sqrt(pow(tempVector[j].x - tempVector[i].x,2.0)
        + (pow(tempVector[j].y - tempVector[i].y,2.0)));
        j++;
    }
    j--;
    circum += sqrt(pow(tempVector[j-1].x - tempVector[0].x,2.0)
        + (pow(tempVector[j].y - tempVector[0].y,2.0)));
    return fabs(circum);
}

//Returns center of boundingbox

Vector2 Polygon::boundingBoxCenter(){
    Vector2 center;
    float minX;
    float minY;
    float maxX;
    float maxY;
    initializeMinMax(minX,minY,maxX,maxY);

    for(int i = 0; i < arrSize;i++){
        if(tempVector[i].x < minX){
            minX = tempVector[i].x;
        }
        if(tempVector[i].y < minY){
            minY = tempVector[i].y;
        }
        if(tempVector[i].x > maxX){
            maxX = tempVector[i].x;
        }
        if(tempVector[i].y > maxY){
            maxY = tempVector[i].y;
        }
    }

    center.x = fabs(maxX - minX)/2;
    center.y = fabs(maxY - minY)/2;
    return center;
}

void Polygon::initializeMinMax(float& miX,float& miY,float& maX,float& maY){
    miX = tempVector[1].x;
    miY = tempVector[1].y;
    maX = tempVector[1].x;
    maY = tempVector[1].y;

    for(int i = 0; i < arrSize;i++){
        if(tempVector[i].x < miX){
            miX = tempVector[i].x;
        }
        else if (tempVector[i].x > maX){
            maX = tempVector[i].x;
        }
        else if (tempVector[i].y < miY){
            miY = tempVector[i].y;
        }
        else if (tempVector[i].y > maY){
            maY = tempVector[i].y;
        }
    }
}

Vector2 Polygon::position(){

    Vector2 centroid = {0, 0};

    if(convex){
        float centerX;
        float centerY;
        for(int i= 0; i < arrSize;i++){
            centerX += tempVector[i].x;
            centerY += tempVector[i].y;
        }
        centroid.x = centerX/arrSize;
        centroid.y = centerY/arrSize;    
    }

    //Center of bounding box

    else{
        centroid = boundingBoxCenter();
    }

    return centroid;
}

//if crossproduct is + or - the whole way the shape is convex

bool Polygon::isConvex(){
    bool convex = true;
    bool initialSignOf = signbit(crossProduct(0));
    for(int i = 0; i < arrSize;i++){
        bool signOf = signbit(crossProduct(i));
        if(signOf != initialSignOf){
            convex = false;
        }
            i++;
    } 
    return convex;
}

int Polygon::crossProduct(int index){
    int product = (tempVector[index+1].y - tempVector[index].y) *
        (tempVector[index+2].x - tempVector[index+1].x) -
        (tempVector[index+1].x - tempVector[index].x) *
        (tempVector[index+2].y - tempVector[index+1].y);
    return product;
}

float Polygon::distance(Shape &s){
    Vector2 firstShape = this->position();
    Vector2 secondShape = s.position();

    float distance = sqrt(pow(secondShape.x - firstShape.x,2.0)
        + (pow(secondShape.y - firstShape.y,2.0)));

    return distance;
}


