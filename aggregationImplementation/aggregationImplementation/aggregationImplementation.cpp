#include <iostream>
#include <string>
#include <vector>
#include <functional>


class Teacher {
private:

	std::string m_name{};
public:

	// 1.1 Constructor definition:
	Teacher(const std::string& name) : m_name{ name }
	{
		std::cout << "Teacher constructor has been used.\n";
	}

	// 1.2 Getter:
	const std::string& getName() const
	{
		return m_name;
	}
};

class Department {
private:

	std::vector<std::reference_wrapper<const Teacher>> m_teachers{};
public:
	// 1.3 Default constructor implementation:
	Department() 
	{
		std::cout << "Default department constructor has been used.\n";
	}
	// 1.4 addFunction
	void add(const Teacher& source)
	{
		m_teachers.push_back(source);
	}
	friend std::ostream& operator<<(std::ostream& out, const Department& department)
	{
		out << "Department: ";
		for (auto teacher : department.m_teachers)
		{
			out << teacher.get().getName() << ' ';
		}
		out << '\n';
		return out;
	}
};




int main() {
	Teacher t1{ "Bob" };
	Teacher t2{ "Frank" };
	Teacher t3{ "Beth" };
	{
		Department department;
		department.add(t1);
		department.add(t2);
		department.add(t3);
		std::cout << department;
		std::cout << "Department goes out of scope here.\n";
	}
	std::cout << t1.getName() << " still exists.\n";
	std::cout << t2.getName() << " still exists.\n";
	std::cout << t3.getName() << " still exists.\n";
	
	return 0;
}