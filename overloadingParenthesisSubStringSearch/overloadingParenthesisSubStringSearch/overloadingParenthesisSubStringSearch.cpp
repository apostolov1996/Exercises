#include <iostream>
#include <string>
#include <cassert>


class MyString {
private:
	std::string m_string{};
public:
	MyString() 
	{
		std::cout << "Empty string has been made.\n";
	}
	// 1.2 Definition and implementation of the parameter constructor:
	MyString(const std::string& inputString) : m_string{ inputString }
	{
		std::cout << "String has been made.\n";
	}
	// 1.3 Overloading function:
	std::string operator()(int startIndex, int length);

};

std::string MyString::operator() (int startIndex, int length)
{
	assert(startIndex >= 0 && startIndex + length <= static_cast<int>(m_string.length()));
	std::string temp;
	for (int i{ 0 }; i <= length; i++)
	{
		temp += m_string[static_cast<std::string::size_type>(startIndex+length)];
	}
	return temp;
}


int main() {
	MyString string{ "Hello, world!" };
	std::cout << "The substring is: " << string(7, 5) << '\n';
	return 0;
}