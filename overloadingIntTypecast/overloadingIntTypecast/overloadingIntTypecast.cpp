#include <iostream>

class Cents {
private:
	int m_cents;
public:
	// Constructor
	Cents(int cents) : m_cents{ cents } 
	{
		std::cout << "Cent has been created.\n";
	}
	// Coppy constructor implementation:
	Cents(const Cents& sourceCent) :
		m_cents(sourceCent.m_cents)
	{
		std::cout << "A coppy constructer has been used.\n";
	}
	// Overloading typecast:
	operator int() const 
	{
		return m_cents;
	}
	// Make negative function:
	Cents makeNegative(Cents input) 
	{
		return Cents(-input.m_cents);
	}
};

int main() {
	Cents cent{ 5 };
	std::cout << "Before makeNegative: " << cent << '\n';
	cent = cent.makeNegative(cent);
	std::cout << "After makeNegative: " << cent << '\n';
	return 0;
}