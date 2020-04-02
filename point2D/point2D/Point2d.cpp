#include "point2d.h"
#include <iostream>
#include <cmath>

// Constructor:
Point2d::Point2d(double x, double y) : m_x{ x }, m_y{ y } {};
// Print:
void Point2d::print() {
	std::cout << "Point: x= " << m_x << " y= " << m_y << '\n';
}
// Distance to Function:
/* example of function call: first.distanceTo(second)
   first: - Point2d
   second - Point2d
   This one returns the distance between the two points.
*/
double Point2d::distanceTo(Point2d& second) {
    return std::sqrt(std::pow((m_x - second.m_x), 2) + (std::pow((m_y - second.m_y), 2)));
}

// Distance from point to point function implementation:
/*
  Inputs:
  - first point - Point2d
  - second point - Point2d
  Outpu:
  Distance between the two points.
*/
double distanceFrom(Point2d& first, Point2d& second) {
    return std::sqrt(std::pow((first.m_x - second.m_x), 2) + std::pow((first.m_y - second.m_y), 2));
}






