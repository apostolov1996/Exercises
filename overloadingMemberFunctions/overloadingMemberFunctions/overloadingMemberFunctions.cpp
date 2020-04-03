#include <iostream>

class Cents {
private:
	int m_cents{};
public:
	Cents() {};
	Cents(int cents) :m_cents{ cents } {};
	int getCents() {
		return m_cents;
	}

	// Overloading Cents
	Cents operator+(int number);
};

Cents Cents::operator+(int number) {
	return Cents{ number + m_cents };
}

int main() {

	Cents cent{ 2 };
	Cents sum = cent + 2;
	std::cout << sum.getCents();

	return 0;
}