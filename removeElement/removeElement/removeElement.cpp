#include <iostream>
#include <vector>
#include <algorithm>



// With this function we can delete every element inside of the vector with nums[i]==val
// The return value is the new length
// And the vector is passed by reference, becouse we want to delete those elements and save the changes.

int removeElement(std::vector<int>& nums, int val) {
	int erased = 0;
	do
	{
		auto found{ std::find_if(nums.begin(), nums.end(),[val](int i)
		{
			return i == val;
		}
		) };
		if (found != nums.end())
		{
			erased = 1;
			nums.erase(found);
		}
		else
		{
			erased = 0;
		}

	} while (erased);

	return nums.size();
}


void printVector(std::vector<int> &nums)
{
	for (auto element : nums)
	{
		std::cout << element << '\t';
	}
	std::cout << "\n";
}

int main()
{
	std::vector<int> test1{ 3, 2, 2, 3 };
	std::cout << "Before removeElement(): ";
	printVector(test1);
	int length = test1.size();
	std::cout << "Vector length: " << length << '\n';
	std::cout << "After removeElement(): ";
	length=removeElement(test1, 2);
	printVector(test1);
	std::cout << "Vector length: " << length << '\n';
	return 0;

}