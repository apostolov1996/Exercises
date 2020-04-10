#include <iostream>
#include <cassert>
class FixedPoint2 {
private:
	std::int_least16_t m_base{};
	std::int_least8_t m_decimal{};
public:

	// 1.1 Default constructor implementation:
	FixedPoint2() : m_base{ 0 }, m_decimal{ 0 }
	{
		std::cout << "Default constructor has been used.\n";
	}

	// 1.2.1 Non-Default constructor implementation:
	FixedPoint2(int_least16_t base, int_least8_t decimal)
	{
		assert(decimal > -100 && decimal < 100);
		m_base = base;
		m_decimal = decimal;
		if (base < 0 || decimal < 0)
		{
			if (base > 0)
			{
				m_base = -base;
			}
			if (decimal > 0)
			{
				m_decimal = -decimal;
			}
		}
		std::cout << "Normal constructor has been used.\n";
	}
	// 1.2.2 Non-Default constructor implementation:
	FixedPoint2(double number) :
		m_base{ static_cast<std::int_least16_t>(number) },
		m_decimal{ static_cast<std::int_least8_t>(round((number - m_base) * 100)) }
	{
		std::cout << "Double constructor has been used.\n";
	}

	// 1.3 Overloading double() operator.
	operator double() const
	{
		return m_base + static_cast<double>(m_decimal) / 100.0;
	}
	// 1.4 Overloading std::cout
	friend std::ostream& operator<<(std::ostream& out, FixedPoint2& point)
	{
		out << static_cast<double>(point);
		return out;
	}

	// 1.5 Overloading +operator:
	friend FixedPoint2 operator+(FixedPoint2& first, FixedPoint2& second)
	{
		return FixedPoint2 { first.m_base + second.m_base, first.m_decimal + second.m_decimal };
	}
	// Overloading -operator:
	friend FixedPoint2 operator-(FixedPoint2& first, FixedPoint2& second)
	{
		return FixedPoint2{ first.m_base - second.m_base, first.m_decimal - second.m_decimal };
	}

	// 1.7 Overloading ==operator:
	friend bool operator==(FixedPoint2& first, FixedPoint2& second)
	{
		return (first.m_base == second.m_base && first.m_decimal == second.m_decimal);
	}
};






int main() {

	FixedPoint2 first{ 10, 45};
	FixedPoint2 second{ 10, 45 };
	std::cout << "First: " << first << '\n';
	std::cout<<"Second: "<<second<<'\n';
	std::cout << std::boolalpha;
	std::cout << (first == second) << '\n';
	FixedPoint2 sum;
	sum = first - second;
	std::cout << sum << '\n';

	return 0;
}