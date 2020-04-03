#include <iostream>


class Digit {
private:
	int m_digit;
public:
	// Constructor implementation:
	Digit(int digit = 0) :
		m_digit{ digit }
	{
		std::cout << "A digit has been made.\n";
	}
	// Getter implementation, used to print the digit value:
	int get() { return m_digit; }
	// 1.1.1 PREFIX INCREMENT DECLARATION:
	Digit& operator++();
	// 1.1.2 POSTFIX INCREMENT DECLARATION:
	// Here we need to implement a temporary variable, that holds the initial value, this is less eff. if compared to the prefix increment.
	Digit& operator++(int);
	// 1.2.1 PREFIX DECREMENT DECLARATION:
	Digit& operator--();
	// 1.2.2 POSTFIX DECREMENT DECLARATION:
	Digit& operator--(int);
};

// 1.1.1 PREFIX INCREMENT IMPLEMENTATION:
Digit& Digit::operator++()
{
	++m_digit;
	return *this;
}
// 1.1.2 POSTFIX INCREMENT IMPLEMENTATION:
Digit& Digit::operator++(int)
{
	Digit temp(m_digit);
	// Here I have to use the prefix increment function. This shows me that in general the prefix incrementation is more eff.
	++(*this);
	return temp;
}
// 1.2.1 PREFIX DECREMENT IMPLEMENTATON:
Digit& Digit::operator--()
{
	--m_digit;
	return *this;
}
// 1.2.2 POSTFIX DECREMENT IMPLEMENTATION:
Digit& Digit::operator--(int)
{
	Digit temp(m_digit);
	--(*this);
	return temp;
}
// Conclusion: with the postfix increment implementation, I create one more Digit class. It's less efficient, becouse I use temp variables.
// These temp variables go out of scope in the end of the implementation code.
// USE PREFIX INCREMENT OR DECREMENT FUNCTIONS !!!

int main() {

	Digit first;
	std::cout << "Before increment: " << first.get() << '\n';
	first++;
	std::cout << "After increment: " << first.get() << '\n';
	first--;
	std::cout << "After decrement: " << first.get() << '\n';
	std::cout << "End\n";
	return 0;
}