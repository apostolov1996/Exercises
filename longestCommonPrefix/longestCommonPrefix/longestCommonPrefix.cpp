#include <iostream>
#include <vector>
#include <string>



int findMinLength(std::vector<std::string> &arr) {
	int min{ static_cast<int>(arr[0].length())};
	for (int i{ 0 }; i < arr.size(); i++) {
		if (min > arr[i].length()) {
			min = arr[i].length();
		}
	}
	return min;
}

std::string commonPrefix(std::vector<std::string> &arr) {
	int minLength{ findMinLength(arr) };
	std::string result{ "" };
	char currentChar{};
	for (int i{ 0 }; i < minLength; i++) {
		currentChar = arr[0][i];
		for (int j{ 0 }; j < arr.size(); j++) {
			if (arr[j][i] != currentChar) {
				return result;
			}
		}
		result.push_back(currentChar);
	}
}


int main() {
	std::vector<std::string> arr{ "flower", "flow", "flight" };
	std::string common{ commonPrefix(arr) };
	std::cout << "Result: " << common;
	return 0;
}