#include "Vector3d.h"
#ifndef POINT_3D_H
#define POINT_3D_H
class Point3d {
private:
	double m_x{ 0 };
	double m_y{ 0 };
	double m_z{ 0 };

	// Constructor declaration.
public:
	Point3d() {};
	Point3d(double x, double y, double z);

	// Print declaration.
	void print();

	//Setter
	void setX(double x);
	void setY(double y);
	void setZ(double z);

	// Getter
	double getX();
	double getY();
	double getZ();
	// Move by vector function.
	void moveByVector(Vector3d &vector);
	
};
#endif
