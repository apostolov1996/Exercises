#include <iostream>
#include <exception>

class Fraction
{
private:
	int m_num;
	int m_den;
public:
	Fraction(int num = 0, int den = 1) :m_num(num), m_den(den)
	{
		if (den == 0)
		{
			throw std::runtime_error("Invalid denominator.\n");
		} 
		std::cout << "Fraction has been created.\n";
	}
	friend std::ostream& operator<<(std::ostream& out, const Fraction& f);
};

std::ostream& operator<<(std::ostream& out, const Fraction& f)
{
	out << f.m_num << "/" << f.m_den;
	return out;
}

int main()
{
	std::cout << "Insert a numerator: ";
	int numerator;
	std::cin >> numerator;
	std::cout << "Insert a denominator: ";
	int denominator;
	std::cin >> denominator;
	try
	{
		Fraction f(numerator, denominator);
		std::cout << "Your fraction is: " << f << '\n';
	}
	catch (std::exception& exception)
	{
		std::cout << exception.what() << '\n';
	}
	return 0;
}