#include <iostream>
#include <string>

int strStr(const std::string& haystack, const std::string& needle)
{
	bool controller = false;
	if (needle.size() > haystack.size())
	{
		return -1;
	}
	else if (needle.size() == 0)
	{
		return 0;
	}
	else
	{
		for (int startIndex{ 0 }; startIndex <= haystack.size() - needle.size(); ++startIndex)
		{
			for (int needleIndex{ 0 }; needleIndex < needle.size(); ++needleIndex)
			{
				if (haystack.at(startIndex + needleIndex) == needle.at(needleIndex))
				{
					controller = true;
				}
				else
				{
					controller = false;
					break;
				}
			}
			if (controller)
			{
				return startIndex;
			}
		}
		return -1;
	}
}

int main()
{
	std::string haystack = "mississippi";
	std::string needle = "missip";
	int index = strStr(haystack, needle);
	std::cout << "The first index is: " << index << '\n';
	return 0;
}
