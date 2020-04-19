#ifndef POINT_H
#define POINT_H

class Point
{
private:
	double m_x; 
	double m_y;
	double m_z;
public:
	Point(int x = 0, int y = 0, int z=0) :m_x(x), m_y(y), m_z(z) {}
	friend std::ostream& operator<<(std::ostream& out, const Point& p)
	{
		out << "Point(" << p.m_x << ", " << p.m_y << ", " << p.m_z << ")";
		return out;
	}
};
#endif