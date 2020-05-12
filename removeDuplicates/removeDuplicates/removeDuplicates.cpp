#include <iostream>
#include <vector>
#include <algorithm>



int removeDuplicates(std::vector<int>& nums)
{
	std::sort(nums.begin(), nums.end());
	nums.erase(std::unique(nums.begin(), nums.end()), nums.end());
	return nums.size();
}

void printVector(const std::vector<int>& nums)
{
	for (auto iterator = nums.begin(); iterator != nums.end(); ++iterator)
	{
		std::cout << *iterator << "\t";
	}
	std::cout << '\n';
}


int main()
{
	std::vector<int> testVector;
	testVector.push_back(5);
	testVector.push_back(5);
	testVector.push_back(7);
	testVector.push_back(8);
	testVector.push_back(7);
	testVector.push_back(4);
	int length = static_cast<int>(testVector.size());
	std::cout << "Before removeDuplicates: " << length << '\n';
	length = removeDuplicates(testVector);
	std::cout << "After removeDuplicates: " << length << '\n';
	printVector(testVector);
	return 0;
}