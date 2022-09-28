# pragma once 

#include <iostream>
#include "Point.h"
#include "Shape.h"

class Rectangle::public Shape
{
private:
    template <typename T>
    Point topLeftCorner;
    T width, length;
public:
    Rectangle();
    Rectangle(T, bool, Point, T, T);
};

