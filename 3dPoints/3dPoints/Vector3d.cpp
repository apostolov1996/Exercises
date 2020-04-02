#include "Vector3d.h"
#include <iostream>

// Constructor:
Vector3d::Vector3d(double x, double y, double z) :
	m_x{ x }, m_y{ y }, m_z{ z } 
{};

// Printer:
void Vector3d::print() {
	std::cout << "Vector: ";
	std::cout << m_x << "/ " << m_y << "/ " << m_z << '\n';
}

// Setters:
void Vector3d::setX(double x) {
	m_x = x;
}
void Vector3d::setY(double y) {
	m_y = y;
}
void Vector3d::setZ(double z) {
	m_z = z;
}
void Vector3d::set(double x, double y, double z) {
	m_x = x;
	m_y = y;
	m_z = z;
}

// Getters:
double Vector3d::getX() {
	return m_x;
}
double Vector3d::getY() {
	return m_y;
}
double Vector3d::getZ() {
	return m_z;
}
