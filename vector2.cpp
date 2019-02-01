#include "vector2.h"
#include <string>

void Vector2::expandVectorArray(Vector2* sentCoord,int& arrSize){
    arrSize *= 2;
    Vector2 *tempArray = new Vector2[arrSize];
    memcpy(tempArray, sentCoord, sizeof(Vector2) * arrSize);
    delete [] sentCoord;
    sentCoord = tempArray; 
}