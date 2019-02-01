#include "point.h"
#include <iostream>


Point::Point(float xCoord,float yCoord)
{
	this->x = xCoord;
	this->y = yCoord;
}

const char* Point::getType(){
	return "Point";
}

float Point::area(){
	return -1;
}

float Point::circumference(){
	return 0;
}

Vector2 Point::position(){
	Vector2 centroid = {0, 0};
	centroid.x = x;
	centroid.y = y;
	return centroid;
}

bool Point::isConvex(){
	return false;
}