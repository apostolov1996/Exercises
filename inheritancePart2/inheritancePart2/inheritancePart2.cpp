#include <iostream>

class Base 
{
private:
	int m_id{};

public:

	Base() 
	{
		std::cout << "Default base constructor has been used.\n";
	}

	Base(int id) : m_id(id)
	{
		std::cout << "Base has been created.\n";
	}

	const int& getId() const { return m_id; }
};

class Derived :public Base 
{
private:
	double m_cost;
public:

	Derived(double cost = 0.0) : m_cost(cost)
	{
		std::cout << "Default derived constructor has been used.\n";
	}
	Derived(double cost, int id) : m_cost(cost), Base(id)
	{
		std::cout << "Derived has been created.\n";
	}

};

int main() {
	Derived derived1(12.5, 4);
	Derived derived2(12.5);
	return 0;
}