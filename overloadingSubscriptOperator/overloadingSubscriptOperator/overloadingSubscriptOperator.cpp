#include <iostream>

class IntList {
private:
	int m_list[10]{};
public:
	int& operator[](int index);
};

int& IntList::operator[](int index) {
	return m_list[index];
}


int main() {
	IntList list{};
	list[0] = 3;
	std::cout << "The inserted value is: " << list[0];
	return 0;
}