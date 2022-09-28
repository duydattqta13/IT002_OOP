#include <iostream>
#include "Point.h"
#include "Shape.h"

using namespace std;

Rectangle::Rectangle()
{
    color = 0;
    filled = false;
    Point topLeftCorner;
    width = 0;
    length = 0;
}

Rectangle::Rectangle(T color, bool filled, Point topLeftCorner, T width, T length)
{
    this->color = color;
    this->filled = filled;
    this->x = x;
    this->y = y;
    this->width = width;
    this->length = length;
}

double Rectangle::getArea()
{
    return width*length;
}

double Rectangle::getPerimeter()
{
    return (width + length)*2;
}

bool operator <= (Rectangle a, Rectangle b)
{
    return ((a.getArea() < b.getArea()) || (a.getArea() == b.getArea());
}

bool operator > (Rectangle a, Rectangle b)
{
    return a.getArea() > b.getArea();
}

double Rectangle::operator + (Rectangle a, Rectangle b)
{
    return a.getArea() + b.getArea();
}

ostream& operator << (ostream &os, Rectangle a)
{
    os <<"Rectangle---"<<a.filled;
    os <<"UpperLeftPoint:("<<a.x<<","<<a.y<<")";
    os <<"width = "<<a.width;
    os <<"length = "<<a.length;
    return os;
}


