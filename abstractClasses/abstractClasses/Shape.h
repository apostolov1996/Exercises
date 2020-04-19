#ifndef SHAPE_H
#define SHAPE_H
#include "Point.h"
#include <iostream>
class Shape 
{
public:
	virtual std::ostream& print(std::ostream& out) const = 0;

	friend std::ostream& operator<<(std::ostream& out, const Shape& p)
	{
		return p.print(out);
	}

	virtual ~Shape() {};
};

class Triangle : public Shape
{
private:
	Point m_p1;
	Point m_p2;
	Point m_p3;
public:
	Triangle(const Point& p1, const Point& p2, const Point& p3) :m_p1(p1), m_p2(p2), m_p3(p3) {}

	virtual std::ostream& print(std::ostream& out) const override
	{
		out << "Triangle(" << m_p1 << ", " << m_p2 << ", " << m_p3 << ")";
		return out;
	}
};

class Circle : public Shape
{
private:
	Point m_center;
	int m_radius;
public:
	Circle(const Point& center, int radius) :m_center(center), m_radius(radius) {}
	virtual std::ostream& print(std::ostream& out) const override
	{
		std::cout << "Circle(" << m_center << ", radius: " << m_radius;
		return out;
	}
	const int& getRadius() { return m_radius; }
};

#endif
