#include "Point3d.h"
#include "Vector3d.h"
#include <iostream>



int main() {
	Point3d point;
	Vector3d vector{ 1.0, 2.0, 3.0 };
	std::cout << "Before moveByVector\n";
	point.print();
	vector.print();
	std::cout << "After moveByVector\n";
	point.moveByVector(vector);
	point.print();
	return 0;
}


