#include <iostream>
#include "Point.h"
#include "Shape.h"
#include <vector>

void printVector(const std::vector<Shape*> &v)
{
	for (auto* element : v)
	{
		std::cout << *element << '\n';
	}
}

int getLargestRadius(const std::vector<Shape*>& v)
{
	int largestRadius{ 0 };
	for (auto element : v)
	{
		Circle* c = dynamic_cast<Circle*>(element);
		if (c) {
			if (c->getRadius() > largestRadius)
			{
				largestRadius = c->getRadius();
			}
		}
	}
	return largestRadius;
}


int main()
{
	std::vector<Shape*> v;
	v.push_back(new Circle(Point(1, 2, 3), 7));
	v.push_back(new Triangle(Point(1, 2, 3), Point(4, 5, 6), Point(7, 8, 9)));
	v.push_back(new Circle(Point(4, 5, 6), 3));
	printVector(v);
	std::cout << "The largest radius is: " << getLargestRadius(v) << '\n';
	for (auto element : v)
	{
		delete element;
	}

	return 0;
}