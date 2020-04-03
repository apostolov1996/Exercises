#include <iostream>

class Point3d {
private:
	double m_x;
	double m_y;
	double m_z;

public:

	// 1.1 Constructor implementation:
	Point3d(double x=0.0, double y=0.0, double z=0.0) :
		m_x(x), m_y(y), m_z(z) {
		std::cout << "Point was created.\n";
	}
	// 1.2 Getter:
	double getX() { return m_x; }
	double getY() { return m_y; }
	double getZ() { return m_z; }
	// 1.3 Overload printer
	friend std::ostream& operator<<(std::ostream& out, const Point3d& point);
	// 1.4 Convert the point into negative:
	Point3d operator-() const;
	// 1.5 Returns true if the point is set at the origin of the reference system.
	bool operator!() const;
	// 1.7 Convert the point into positive:
	Point3d operator+() const;
	
};
// 1.3 Overload printer implementation:
std::ostream& operator<<(std::ostream& out, const Point3d& point)
{
	out << "Point(" << point.m_x << ", " << point.m_y << ", " << point.m_z << ")\n";
	return out;
}
// 1.4 Overload convert the point implementation:
Point3d Point3d::operator-() const
{
	return Point3d(-m_x, -m_y, -m_z);
}
// 1.5 Overload the bool ! operator implementation:
bool Point3d::operator!() const
{
	return (m_x == 0 && m_y == 0 && m_z == 0);
}
// 1.6.1 Point + Point
Point3d operator+(Point3d& first, Point3d& second) 
{
	return Point3d(first.getX() + second.getX(), first.getY() + second.getY(), first.getZ() + second.getZ());
}
// 1.7 Convert the point into positive implementation:
Point3d Point3d::operator+() const
{
	return Point3d(-m_x, -m_y, -m_z);
}

int main() {

	Point3d first(1.0, 1.0, 1.0);
	Point3d second(1.0, 1.0, 1.0);
	first = first + second;
	std::cout << "Final result: " << first << '\n';
	first = -first;
	std::cout << "Changed value: " << first << '\n';
	first = +first;
	std::cout << "Changed value: " << first << '\n';
	return 0;
}