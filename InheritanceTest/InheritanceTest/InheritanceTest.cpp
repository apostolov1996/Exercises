#include <iostream>
#include <string>


class Person 
{
private:

	std::string m_name{};
	int m_age{};

public:
	Person(std::string name = "", int age = 0) :m_name(name), m_age(age)
	{
		std::cout << "A person has been defined.\n";
	}
	const std::string& getName() const
	{
		return m_name;
	}
	const int& getAge() const
	{
		return m_age;
	}
	void setAge(int age)
	{
		m_age = age;
	}
	void setName(const std::string& name)
	{
		m_name = name;
	}
};

class BaseballPlayer : public Person
{
private:

	double m_battingAverage;
	int m_homeRuns;

public:

	BaseballPlayer(double battingAverage=0.0, int homeRuns=0) : m_battingAverage(battingAverage), m_homeRuns(homeRuns)
	{
		std::cout << "Baseball player has been created.\n";
	}
};

int main()
{
	BaseballPlayer firstPlayer;
	firstPlayer.setName("Nikolay");
	std::cout << "First player name is: " << firstPlayer.getName() << '\n';
	return 0;
}