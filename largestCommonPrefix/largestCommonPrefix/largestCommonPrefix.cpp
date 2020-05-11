#include <iostream>
#include <string>
#include <vector>


int minLength(std::vector<std::string>& strs)
{
	int result = static_cast<int>(strs[0].length());
	for (int i{ 0 }; i < static_cast<int>(strs.size()); ++i)
	{
		if (strs[i].length() < result)
		{
			result = strs[i].length();
		}
	}
	return result;
}

std::string longestCommonPrefix(std::vector<std::string>& strs)
{
	int index{ 0 };
	int j;
	int i;
	bool broken{ false };
	for (j=0; j < minLength(strs); ++j)
	{
		for (i = 1; i < static_cast<int>(strs.size()); ++i)
		{
			if (strs[0].at(j) != strs[i].at(j))
			{
				broken = true;
				break;
			}
		}
		if (broken)
		{
			break;
		}
		++index;
	}
	if (index != 0)
	{
		return strs[0].substr(0,index);
	}
	else
	{
		return "";
	}
}
		

int main()
{
	std::vector<std::string> tester1 = { "car", "racecar", "car" };
	std::vector<std::string> tester2 = { "flower", "flow", "flight" };
	std::cout << longestCommonPrefix(tester1) << '\n';
	std::cout << longestCommonPrefix(tester2) << '\n';
	return 0;
}

