#include "vector2.h"
#include "shape.h"
#include "point.h"
#include "line.h"
#include "triangle.h"
#include "polygon.h"
#include <fstream>
#include <iostream>
#include <cmath>

float roundedArea(float n);

int main(int argc, const char *argv[]){
	int arraySize = 5;
    std::ifstream myReadFile;
	myReadFile.open(argv[1]);
	Vector2* vertices = new Vector2[arraySize];
	int iteration = 0;

	while (!(myReadFile.eof())){
		if(iteration == arraySize){
		 	vertices->expandVectorArray(vertices,arraySize);
		}
		//checks if input is valid
		if(!(myReadFile >> vertices[iteration].x)){
			return 1;
		}
		if(!(myReadFile >> vertices[iteration].y)){
			return 1;
		}
		iteration++;

	}

	arraySize = iteration;
	
	if(arraySize == 1){
		Point pointObj(vertices[0].x,vertices[0].y);
		Shape& point = pointObj;
		std::cout << point.area() << std::endl;
	}

	if(arraySize == 2){
		Line lineObj(vertices,arraySize);
		Shape& line = lineObj;
		std::cout << line.area() << std::endl;
	}

	if(arraySize == 3){
		Triangle triObj(vertices,arraySize);
		Shape& tri = triObj;
		std::cout << roundedArea(tri.area()) << std::endl;
	}

	if(arraySize >= 4){
		
		Polygon polyObj(vertices,arraySize);
		Shape& poly = polyObj;
		std::cout << roundedArea(poly.area()) << std::endl;
	}	

	myReadFile.close();
	delete [] vertices;
	vertices = nullptr;
}

float roundedArea(float n){
		float roundedArea = roundf(n * 1000) / 1000;
		return roundedArea;
}

