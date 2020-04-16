#include <iostream>
#include <iterator>
#include <algorithm>

void printArray(int array[], int length) {
	for (int index{ 0 }; index < length; index++) {
		printf("%d ", array[index]);
	}
	std::cout << '\n';
}

void bubbleSort(int array[], int length) {
	while (true) {
		int changesCounter{ 0 };
		for (int index{ 0 }; index < length; index++) {
			if (index + 1 < length) {
				if (array[index] > array[index + 1]) {
					changesCounter++;
					std::swap(array[index], array[index + 1]);
				}
			}
		}
		if (changesCounter == 0) {
			break;
		}
	}
}


int main() {
	int array[]={ 10, 23, 245, 60, 10, 30, 40, 60, 70 };
	int length{ static_cast<int>(std::size(array)) };
	std::cout << "Array before bubble sort\n";
	printArray(array, length);

	std::cout << "Array after bubble sort\n";
	bubbleSort(array, length);
	printArray(array, length);
	return 0;

}