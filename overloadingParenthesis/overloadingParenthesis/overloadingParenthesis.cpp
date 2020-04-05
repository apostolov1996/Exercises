#include <iostream>
#include <cassert>

class Matrix {
	// Data definition:
private:
	double data[4][4]{};
public:
	// Overloading parenthesis definiton:
	double& operator()(int row, int col);
	const double& operator()(int row, int col) const;


};

// Ovedloarind parenthesis implementation:
double& Matrix::operator()(int row, int col) 
{
	assert(col >= 0 && col < 4);
	assert(row >= 0 && row < 4);
	return data[row][col];
}
const double& Matrix::operator()(int row, int col) const
{
	assert(col >= 0 && col < 4);
	assert(row >= 0 && row < 4);
	return data[row][col];
}

int main() {


	Matrix matrix{};
	matrix(0, 0) = 0.5;
	std::cout << "Value at matrix(0, 0): " << matrix(0, 0) << '\n';

	return 0;
}