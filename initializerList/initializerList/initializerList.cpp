#include <iostream>
#include <cassert>
#include <initializer_list>

class IntArray {

private:

	int m_length{};
	int* m_data{};

public:

	IntArray()
	{
		std::cout << "Default Constructor has been used.\n";
	}
	IntArray(int length) : m_length{ length }
	{
		assert(length >= 0);
		m_data = new int[m_length];
		std::cout << "Non default constructor has been used.\n";

	}
	IntArray(std::initializer_list<int> list) : m_length(static_cast<int>(list.size())), m_data( new int[static_cast<int>(list.size())] )
	{
		int count{ 0 };
		for (int element : list)
		{
			m_data[count] = element;
			++count;
		}
		std::cout << "Initializer list constructor has been used.\n";
	}
	int& operator[](int index)
	{
		assert(index >= 0 && index < m_length);
		return m_data[index];
	}
	~IntArray()
	{
		delete[] m_data;
		std::cout << "Destructor has been used.\n";
	}

	const int getLength() {
		return m_length;
	}

	IntArray& operator=(std::initializer_list<int> list)
	{
		delete[] m_data;
		m_length = static_cast<int>(list.size());
		m_data = new int[m_length];
		int count{ 0 };
		for (auto element : list)
		{
			m_data[count] = element;
			++count;
		}
		return *this;
		std::cout << "Overloaded = operator has been used.\n";
	}

};


int main() {
	IntArray array{ 2, 4, 5, 6 };
	for (int i{0}; i<array.getLength(); ++i)
	{
		std::cout << array[i] << " ";
	}
	std::cout << "\n";
	array = { 2, 4 };
	for (int i{ 0 }; i < array.getLength(); ++i)
	{
		std::cout << array[i] << " ";
	}
	std::cout << '\n';	
	return 0;
}