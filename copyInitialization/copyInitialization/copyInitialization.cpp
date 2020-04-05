#include <cstring>
#include <iostream>
#include <cassert>

class MyString {
private:
	char* m_data;
	int m_length;
public:
	// Constructor definition and implementation:
	MyString(const char* source = "")
	{
		// Make sure that *source is not a nullptr
		assert(source);

		// Set the length of the string:
		m_length = std::strlen(source) + 1;

		// I'm using a dynamic memory now, I have to clear after this one.
		m_data = new char[m_length];
		for (int i{ 0 }; i < m_length; ++i)
		{
			// Here I'm sure that source isn't a nullptr, so this is ok.
			m_data[i] = source[i];
		}

		// Making sure the string is over:
		m_data[m_length - 1] = '\0';
		std::cout << "String created.\n";
		std::cout << "Adress of the string: " << &m_data << '\n';
	}
	// Destructor definition and implementation:
	~MyString()
	{
		delete[]m_data;
		std::cout << "Destructor used.\n";
	}

	char* getString()
	{
		return m_data;
	}
	int getLength()
	{
		return m_length;
	}
	MyString& operator=(const char* source);
};

MyString& MyString::operator=(const char* source)
{
	assert(source);
	m_length = std::strlen(source) + 1;
	for (int i{ 0 }; i < m_length; ++i)
	{
		m_data[i] = source[i];
	}
	m_data[m_length - 1] = '\0';
	std::cout << "Operator = has been used.\n";
	return *this;
}



int main() {
	MyString firstString{ "Nikolay" };
	std::cout << "String before changes: " << firstString.getString() << '\n';
	firstString = "Stefan";
	std::cout << "String after changes: " << firstString.getString() << '\n';
    return 0;
}