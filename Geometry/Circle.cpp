#include <iostream>
#include "Point.h"
#include "Shape.h"

using namespace std;


Circle::Circle()
{
    color = 0;
    filled = false;
    ..
    radius = 0;
};

Circle:Circle(T color, bool filled, T x, T y, T radius)
{
    this->color = color;
    this->filled = filled;
    this->x = x;
    this->y = y;
    this->radius = radius;
}

double Circle::getArea()
{
    return pi*radius**2;
}

double Circle::getPerimeter()
{
    return 2*pi*radius;
}

bool operator <= (Circle a, Circle b)
{
    return ((a.getArea() < b.getArea()) || (a.getArea() == b.getArea());
}

bool operator > (Circle a, Circle b)
{
    return a.getArea() > b.getArea();
}

Circle& Circle::operator ++ ()
{
    radius++;
}

double Circle::operator + (Circle a, Circle b)
{
    return a.getArea() + b.getArea();
}

ostream& operator << (ostream &os, Circle a)
{
    os <<"Circle---"<<a.filled;
    os <<"CenterPoint:("<<a.x<<","<<a.y<<")";
    os <<"radius = "<<a.radius;
    return os;
}