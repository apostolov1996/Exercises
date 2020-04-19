#include <iostream>
#include <map>
#include <iostream>
#include <cctype>

std::string duplicate_encoder(const std::string& word) 
{
	std::map<char, int> table;
	for (auto ch : word)
	{
		table[std::tolower(ch)]++;
	}
	std::string result;
	for (auto ch : word)
	{
		if (table[std::tolower(ch)] == 1)
		{
			result += '(';
		}
		else
		{
			result += ')';
		}
	}
	return result;
}


int main()
{
	std::string test{ "Success" };
	std::cout << "Before duplicate test: " << test << '\n';
	std::cout << "After duplicate: " << duplicate_encoder(test) << '\n';
	return 0;
}

