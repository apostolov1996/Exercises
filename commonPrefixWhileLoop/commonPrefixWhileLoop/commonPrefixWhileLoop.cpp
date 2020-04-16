#include<iostream>
#include <vector>
#include <string>



int getMinLength(std::vector<std::string> &strs) {
	int min{static_cast<int>(strs[0].length()) };
	for (int i{ 0 }; i < strs.size(); i++) {
		if (min > strs[i].length()) {
			min = strs[i].length();
		}
	}
	return min;
}


std::string getCommonPrefix(std::vector<std::string> &strs) {
	int minLength{ getMinLength(strs) };
	std::string result{};
	char currentChar{};
	for (int i{ 0 }; i < minLength; i++) {
		currentChar = strs[0][i];
		for (int j{ 0 }; j < strs.size(); j++) {
			if (strs[j][i]!=currentChar) {
				return result;
			}
		}
		result.push_back(currentChar);
	}
}



int main() {
	std::vector<std::string> arr{ "dog", "flow", "flight" };
	std::cout << "Min Lengths is: " << getMinLength(arr) << '\n';
	std::string result{ getCommonPrefix(arr) };
	std::cout << "Final result: " << result;
	return 0;
}