#include "point2d.h"
#include <iostream>

int main() {
	Point2d first{};
	Point2d second{ 3.0, 4.0 };
	first.print();
	second.print();
	std::cout << "Distance between the two points: " << first.distanceTo(second) << '\n';
	std::cout << "Distance between the two points: " << distanceFrom(first, second) << '\n';
	return 0;
}