# pragma once 

#include <iostream>
#include "Point.h"
#include "Shape.h"

using namespace std;

static const pi = 3.14;

class Circle::public Shape
{
private:
    template <typename T>    
    T radius;
public:
    Circle();
    Circle(T, bool, T, T, T);
    double getArea();
    double getPerimeter();
    Circle operator ++ ();
};

