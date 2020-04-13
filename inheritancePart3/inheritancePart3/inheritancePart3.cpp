#include <iostream>
#include <string>

class Fruit {
private:

	std::string m_name;
	std::string m_color;

public:
	// 1.1 Default Constructor:
	Fruit() : m_name{""}, m_color{""}
	{
		std::cout << "Default fruit constructor has been used.\n";
	}
	// 1.2 Non Default Constructor:
	Fruit(const std::string &name, const std::string &color) : m_name{ name }, m_color(color)
	{
		std::cout << "Non default fruit constructor has been used.\n";
	}
};

class Banana : public Fruit {
private:

	double m_fiber{};

public:
	// 2.1 Default Constructor:
	Banana()
	{
		std::cout << "Default banana constructor has been used.\n";
	}
	// 2.2 Non Default Constructor:
	Banana(double fiber, const std::string& name, const std::string& color) : Fruit(name, color), m_fiber(fiber)
	{
		std::cout << "Non default banana constructor has been used.\n";
	}

};

int main()
{
	Banana banana1;
	Banana banana2(20.4, "Banana", "Yellow");
	return 0;
}

