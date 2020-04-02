#ifndef POINT2D_H
#define POINT2D_H
class Point2d {
private:
	double m_x{ 0.0 };
	double m_y{ 0.0 };
public:
	// Default constructor:
	Point2d() {};
	// Constructor with input data:
	Point2d(double x, double y);
	// Printer declaration:
	void print();
	// Distance to function declaration:
	double distanceTo(Point2d& secondPoint);
	// Distance from function declaration:
	friend double distanceFrom(Point2d& first, Point2d& second);
};
#endif
