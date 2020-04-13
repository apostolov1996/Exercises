#include <iostream>
#include <string>

class Person
{
private:
	std::string m_name;
	int m_age;

public:
	Person():m_name{""}, m_age{0}
	{
		std::cout << "Person: Default constructor has been used.\n";
	}
	Person(const std::string& name, int age) : m_name(name), m_age(age)
	{
		std::cout << "Person: Non default constructor has been used.\n";
	}
	const int& getAge() { return m_age; }
	const std::string& getName() { return m_name; }

};

class Employee
{
private:
	std::string m_employer;
	double m_wage;

public:
	Employee() : m_employer{ "" }, m_wage{ 0.0 }
	{
		std::cout << "Employee: Default constructor has been used.\n";
	}
	Employee(const std::string& employer, double wage) : m_employer{ employer }, m_wage{ wage }
	{
		std::cout << "Employee: Non default constructor has been used.\n";
	}
	const std::string& getEmployer() { return m_employer; }
	const double& getWage() { return m_wage; }
};

class Teacher : public Employee, public Person
{
private:
	int m_teachesGrade;
public:
	Teacher(const std::string &name, int age, const std::string &employer, double wage, int teachesGrade)
		:Person(name, age), Employee(employer, wage), m_teachesGrade{ teachesGrade }
	{
		std::cout << "Teacher: Non default constructor has been used.\n";
	}
	const int &getTeachesGrade() { return m_teachesGrade; }
};

int main() {
	Teacher nikolay{ "Nikolay", 24, "Politecnico di Milano", 2400.50, 5 };
	std::cout << nikolay.getName() << " " << nikolay.getAge() << " " << nikolay.getEmployer() << " " << nikolay.getWage() << " " << nikolay.getTeachesGrade() << "\n";
	
	return 0;
}




