#include<iostream>
#include <cassert>


class Fraction{

private:
	int m_num{0};
	int m_den{1};
public:
	// 1.1 Default constructor:
	Fraction() {};
	// 1.2 Non-default constructor, with input data:
	Fraction(int num, int den) : m_num{ num }, m_den{ den }{};
	// 1.3 Print function:
	void print() {
		std::cout << m_num << "/" << m_den << '\n';
	}
	// 1.4 Operator overloadings declaration:
	friend Fraction operator*(const Fraction& f1, const Fraction& f2);
	friend Fraction operator*(const Fraction& f, int num);
	friend Fraction operator*(int num, const Fraction& f);
	// 1.5 Reduce function:
	int gcd(int a, int b) 
	{
		return (b == 0) ? (a > 0 ? a : -a) : gcd(b, a % b);
	}
	void reduce() 
	{
		m_num /= gcd(m_num, m_den);
		m_den /= gcd(m_num, m_den);
	}
};

// 1.4 Operator overloadings implementation:
Fraction operator*(const Fraction& f1, const Fraction& f2) 
{
	return Fraction{ f1.m_num * f2.m_num, f1.m_den * f2.m_den };
}

Fraction operator*(const Fraction& f, int num)
{
	return Fraction{ f.m_num * num, f.m_den };
}

Fraction operator*(int num, const Fraction &f)
{
	return Fraction{ f.m_num * num, f.m_den };
}

int main()
{
    Fraction f1(10, 5);
	f1.reduce();
    f1.print();

    Fraction f2(3, 8);
	f2.reduce();
    f2.print();

    Fraction f3 = f1 * f2;
	f3.reduce();
    f3.print();

    Fraction f4 = f1 * 2;
	f4.reduce();
    f4.print();

    Fraction f5 = 2 * f2;
	f5.reduce();
    f5.print();
	
	Fraction f6 = Fraction(1, 2) * Fraction(2, 3) * Fraction(3, 4);
	f6.reduce();
    f6.print();
	
    return 0;
}