#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

class Car {
private:
	std::string m_make;
	std::string m_model;

public:
	// 1.1 Constructor implementation:
	Car(std::string make, std::string model) :
		m_make{ make }, m_model{ model }
	{
		std::cout << "A car has been set.\n";
	}
	// 1.2 Print function implementation:
	void print() 
	{
		std::cout << "Make: " << m_make << "\tModel: " << m_model << '\n';
	}
	friend bool operator==(const Car & c1, const Car & c2);
	friend bool operator!=(const Car& c1, const Car& c2);
	friend bool operator<(const Car& c1, const Car& c2);
};

bool operator==(const Car& c1, const Car& c2) 
{
	return(c1.m_make == c2.m_make && c1.m_model == c2.m_model);
}
bool operator!=(const Car& c1, const Car& c2) 
{
	return !(c1 == c2);
}
bool operator<(const Car& c1, const Car& c2)
{
	if (c1.m_make == c2.m_make) 
	{
		return (c1.m_model < c2.m_model);
	}
	else 
	{
		return (c1.m_make < c2.m_make);
	}
}

int main() {
	std::vector<Car> v{
		{"Toyota", "Corolla"},
		{"Honda", "Accord"},
		{"Toyota", "Camry"},
		{"Honda", "Civic"},
	};
	std::sort(v.begin(), v.end());
	for (int i{ 0 }; i < v.size(); i++) {
		v[i].print();
	}
	return 0;
}