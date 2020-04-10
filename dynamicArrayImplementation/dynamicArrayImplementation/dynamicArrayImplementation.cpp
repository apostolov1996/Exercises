#include <iostream>
#include <cassert>

class DynamicArray
{
private:
	int* m_data{ nullptr };
	int m_length{ 0 };

public:
	// 1.0 Default constructor:
	DynamicArray(int size)
	{
		// Creating the new dynamic array:
		assert(size > 0 && "Array size can't be a negative number.");
		m_data = new int[size];
		m_length = size;
		for (int i{ 0 }; i < m_length; ++i)
		{
			m_data[i] = 0;
		}
		std::cout << "Default constructor has been used.\n";
	}
	// 1.1 Destructor:
	~DynamicArray() {
		delete[] m_data;
		std::cout << "Destructor has been used.\n";
	}
	// 1.2 Print array function:
	void print() {
		for (int i{ 0 }; i < m_length; ++i)
		{
			std::cout << m_data[i] << " ";
		}
		std::cout << '\n';
	}
	// 1.3 Print array adress:
	void printAdress() {
		std::cout << "The adress of the dynamicArray is: " << &m_data << '\n';
	}
	// 1.4 Overloading [] operator:
	int& operator[](const int index)
	{
		assert(index >= 0 && "Index must be a positive number");
		assert(index < m_length && "Index can't be larger than m_length");
		return m_data[index];
	}
	// 1.5 Overloading = operator declaration:
	DynamicArray& operator=(const DynamicArray& source)
	{
		if (this == &source) {
			return *this;
		}
		delete[] m_data;
		m_length = source.m_length;
		m_data = new int[m_length];
		for (int i{ 0 }; i < m_length; ++i)
		{
			m_data[i] = source.m_data[i];
		}
		return *this;
	}
	// 1.6 Copy constructor that does a deep copy:
	DynamicArray(const DynamicArray& source)
	{
		m_length = source.m_length;
		m_data = new int[m_length];
		for (int i{ 0 }; i < m_length; ++i)
		{
			m_data[i] = source.m_data[i];
		}
	}
	// 1.7 Get arrayLength:
	int getLength() {
		return m_length;
	}
};




int main() {

	DynamicArray array{ 5 };
	array[0] = 5;
	array.print();
	array.printAdress();
	DynamicArray arrayTwo{ array };
	arrayTwo.print();
	arrayTwo.printAdress();
	return 0;
}