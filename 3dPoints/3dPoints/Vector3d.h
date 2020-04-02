#ifndef VECTOR_3D_H
#define VECTOR_3D_H

class Vector3d {
private:
	double m_x{0};
	double m_y{0};
	double m_z{0};

public:
	friend class Point3d;
	// Constructor declarations:
	// Default:
	Vector3d() {};
	// Input requested:
	Vector3d(double x, double y, double z);

	// Printer declaration:
	void print();

	// Setters:
	void setX(double x);
	void setY(double y);
	void setZ(double z);
	void set(double x, double y, double z);

	// Getters:
	double getX();
	double getY();
	double getZ();
};
#endif
