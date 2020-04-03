#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


typedef struct {
	std::string name{};
	char grade;
}StudentGrade;

class GradeMap {
private:
	std::vector<StudentGrade> m_map;
public:
	// 1.1 Overloading the subscript [] parameter definition:
	char& operator[](const std::string& studentName);
};

char& GradeMap::operator[](const std::string& studentName)
{
	auto found=std::find_if(m_map.begin(), m_map.end(), [&](const StudentGrade &student) {
		return (student.name == studentName);
	});
	if (found != m_map.end())
	{
		return found->grade;
	}
	else
	{
		// Here i create a new student:
		m_map.push_back({ studentName });
		return m_map.back().grade;
	}
}

int main()
{
	GradeMap grades{};

	grades["Joe"] = 'A';
	grades["Frank"] = 'B';

	std::cout << "Joe has a grade of " << grades["Joe"] << '\n';
	std::cout << "Frank has a grade of " << grades["Frank"] << '\n';
	std::cout << "Zack has a grade of " << grades["Zack"] << '\n';

	return 0;
}
