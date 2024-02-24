#include "sort.h"

/**
* locate_min - Locate the minimum from the
* current index in the array
* @array: The Array to be Searched
* @index: Starting Index of The Search
* @size: The Size of The Array
* Return: (int) index of min if found or
* same given index if index is the min
*/
int locate_min(int *array, size_t index, size_t size)
{
	int min = array[index];
	int idx_min = index;

	for (size_t i = index + 1; i < size; i++)
	{
		if (array[i] < min)
		{
			min = array[i];
			idx_min = i;
		}
	}

	return (idx_min == index ? -1 : idx_min);
}

/**
* swap - Swaps two elements in an array
* @array: The Array containing elements
* @a: Index of the first element
* @b: Index of the second element
*/
void swap(int *array, size_t a, size_t b)
{
	int temp = array[a];

	array[a] = array[b];
	array[b] = temp;
}

/**
* selection_sort - Implementation of Selection Sort Algorithm
* @array: Array to sort type int *
* @size: The Size of The Given Array
*/
void selection_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	for (size_t i = 0; i < size; i++)
	{
		int min = locate_min(array, i, size);

		if (min != -1)
		{
			swap(array, i, min);
			print_array(array, size);
		}
	}
}

