#include <string>
#include <iostream>
#include <algorithm>

void str_toupper(std::string &s) {
	std::transform(s.begin(), s.end(), s.begin(),
		[](unsigned char c) { return std::toupper(c); }
	);
}



std::string duplicateEncoder(const std::string& word)
{
	std::string temp{ word };
	std::string newString;
	newString.resize(word.length());
	str_toupper(temp);
	for (size_t pos{ 0 }; pos < temp.length()-1; ++pos)
	{

		std::size_t found = temp.find(temp.at(pos), pos+1);
		if (found != std::string::npos)
		{
			newString.at(pos) = ')';
			newString.at(found) = ')';
		}
		else if(newString.at(pos)!=')')
		{
			newString.at(pos) = '(';
		}

	}
	if (newString.at(newString.length() - 1) != ')')
	{
		newString.at(newString.length() - 1) = '(';
	}
	return newString;
}

int main() {
	std::string firstOne{ "(( @" };
	std::cout << "Before Duplicate: " << firstOne << '\n';
	std::string duplicate{ duplicateEncoder(firstOne) };
	
	std::cout << "After duplicate: " << duplicate << '\n';
	return 0;
}