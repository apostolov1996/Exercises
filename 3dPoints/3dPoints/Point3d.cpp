// Here i will define all the functions that the class Point3d can use.
#include <iostream>
#include "Point3d.h"
#include "Vector3d.h"

// Constructor
Point3d::Point3d(double x, double y, double z) :
	m_x{ x }, m_y{ y }, m_z{ z }
{}

// Printer
void Point3d::print() {
	std::cout << "Point: ";
	std::cout << m_x << "/ " << m_y << "/ " << m_z << "\n";
}

// Setters:
void Point3d::setX(double x) {
	m_x = x;
}
void Point3d::setY(double y) {
	m_y = y;
}
void Point3d::setZ(double z) {
	m_z = z;
}

// Getters:
double Point3d::getX() {
	return m_x;
}
double Point3d::getY() {
	return m_y;
}
double Point3d::getZ() {
	return m_z;
}

void Point3d::moveByVector(Vector3d &vector) {
	m_x += vector.m_x;
	m_y += vector.m_y;
	m_z += vector.m_z;
}
