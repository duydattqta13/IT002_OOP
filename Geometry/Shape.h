# pragma once
#include <iostream>
using namespace std;

class Shape
{
private:
    template <typename T>
    T color;
    bool filled;
public:
{
    Shape();
    Shape(T, bool);
    virtual double getArea();
    virtual double getPerimeter();
    friend bool operator < (Shape a, Shape b);
    friend bool operator > (Shape a, Shape b);
    friend bool operator = (Shape a, Shape b);
    friend bool operator <= (Shape a, Shape b);
    friend bool operator >= (Shape a, Shape b);
    friend ostream& operator << (ostream &os, Shape a);
    static void sortByArea(Shape** arr, int count)
    {
        for (int i = 0; i < count - 1; i++)
            for (int j = i + 1; j < count; j++)
                if (*arr[i] > *arr[j])
                    *tmp = *arr[i];
                    *arr[i] = *arr[j];
                    *arr[j] = *tmp;
    }
    static void sortByPerimeter(Shape** arr, int count)
    {
        for (int i = 0; i < count - 1; i++)
            for (int j = i + 1; j < count; j++)
                if (*arr[i] > *arr[j])
                    *tmp = *arr[i];
                    *arr[i] = *arr[j];
                    *arr[j] = *tmp;
    }
    virtual double operator + ();
    static Shape ** categorizeShape(Shape[])
    {
        
    }
};