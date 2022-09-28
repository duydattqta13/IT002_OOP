#include <bits/stdc++.h>
#include "Circle.h"
#include "Rectangle.h"

using namespace std;

int main()
{   
    Shape **test;
    test = new Shape * [4];
    test[0] = new Rectangle(); //default constructor (0,0) width=1, height=1
	test[1] = new Circle(); //default constructor (0,0) radius=1
	test[2] = new Rectangle(0, 2, 2, 2, 1, true); // x, y, width, height, color, filled
	test[3] = new Circle(0, 0, 2, 3, true); // x, y, radius, color, filled

	Shape::sortByPerimeter(test, 4);

	for (int i = 0; i < 4; i++) {
		cout << *test[i];
	}
}