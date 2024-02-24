#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in
 * ascending order using the bubble sort algorithm
 * @array: the array to be sorted
 * @size: the size of the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t j, i;
	int n;

	/* Check if the array has 2 or more elements */
	if (size < 2)
		return;

	/* Iterate through the array */
	for (i = 0; i < size - 1; i++)
	{
		/* Iterate through the unsorted part of the array */
		for (j = 0; j < size - i - 1; j++)
		{
			/* If the current element is greater than the next element, swap them */
			if (array[j] > array[j + 1])
			{
				n = array[j];
				array[j] = array[j + 1];
				array[j + 1] = n;

				/* Print the current state of the array after the swap */
				print_array(array, size);
			}
		}
	}
}

