#include <iostream>
#include <string>
#include <stack>

bool isValid(const std::string& str)
{
	if (str == "")
	{
		return true;
	}
	std::stack<char> input;
	input.push(str[0]);
	for (int i{ 1 }; i < str.length(); ++i)
	{
		if (str[i] == '}' && input.top() == '{')
		{
			input.pop();
		}
		else if (str[i] == ']' && input.top() == '[')
		{
			input.pop();
		}
		else if (str[i] == ')' && input.top() == '(')
		{
			input.pop();
		}
		else
		{
			input.push(str[i]);
		}
	}
	return input.empty();
}

void printResult(bool valid)
{
	if (valid)
	{
		std::cout << "The result is true.\n";
	}
	else
	{
		std::cout << "The result is not true.\n";
	}
}

int main()
{
	std::string test1{ "()" };
	std::string test2{ "()[]{}" };
	std::string test3{ "(}" };
	std::string test4{ "([)]" };
	std::string test5{ "{[]}" };
	std::string test6{ "" };
	printResult(isValid(test1));
	printResult(isValid(test2));
	printResult(isValid(test3));
	printResult(isValid(test4));
	printResult(isValid(test5));
	printResult(isValid(test6));
	return 0;

}
