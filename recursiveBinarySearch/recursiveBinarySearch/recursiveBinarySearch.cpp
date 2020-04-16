
#include <cassert>

// array is the array to search over.
// target is the value we're trying to determine exists or not.
// min is the index of the lower bounds of the array we're searching.
// max is the index of the upper bounds of the array we're searching.
// binarySearch() should return the index of the target element if the target is found, -1 otherwise
int binarySearch(const int *array, int target, int min, int max)
{
	assert(array); // make sure array exists

// implement this recursively

	if (min > max)
		return -1;

	int midpoint{ min + ((max - min) / 2) }; // this way of calculating midpoint avoids overflow

	if (array[midpoint] > target)
	{
		return binarySearch(array, target, min, midpoint - 1);
	}
	else if (array[midpoint] < target)
	{
		return binarySearch(array, target, midpoint + 1, max);
	}
	else
		return midpoint;
}