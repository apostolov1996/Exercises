#include <iostream>
#include <cassert>


class Average {
	// m_sum ---- It is the sum of all the numbers we pushed.
	// m_numbers -How many numbers we used to sum.
private:
	std::int_least32_t m_sum{ 0 };
	std::int_least8_t m_numbers{ 0 };
public:
	// 1.1 Default constructor:
	Average() {};

	// 1.2 Overloading ostream operator:
	friend std::ostream& operator<<(std::ostream& out, const Average& average)
	{
		assert(average.m_numbers != 0 && "Invalid data, denominator is equal to 0");
		out << static_cast<double>(average.m_sum) / average.m_numbers;
		return out;
	}

	// 1.3 Overloading operator+:
	Average& operator+=(int number)
	{
		m_sum += number;
		++m_numbers;
		return *this;
	}
};

int main() {
	Average avg;
	avg += 4;
	std::cout << "Average: " << avg << '\n';
	return 0;
}