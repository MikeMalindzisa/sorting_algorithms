#include <stdio.h>
#include "sort.h"

/**
* quick_sort - Sorts an array of integers in ascending order using Quick Sort
* @array: The array to be sorted
* @size: The size of the array
*/
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quicksort_recursive(array, 0, size - 1, size);
}

/**
* quicksort_recursive - Recursive function for Quick Sort
* @array: The array to be sorted
* @low: The starting index of the partition
* @high: The ending index of the partition
* @size: The size of the array
*/
void quicksort_recursive(int *array, int low, int high, size_t size)
{
	int partition;

	if (low < high)
	{
		partition = lomuto_partition(array, low, high, size);
		quicksort_recursive(array, low, partition - 1, size);
		quicksort_recursive(array, partition + 1, high, size);
	}
}

/**
* lomuto_partition - Lomuto partition scheme for Quick Sort
* @array: The array to be partitioned
* @low: The starting index of the partition
* @high: The ending index of the partition
* @size: The size of the array
*
* Return: The index of the pivot element
*/
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot, i, j;

	pivot = array[high];
	i = low - 1;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}

	if (i + 1 != high)
	{
		swap(&array[i + 1], &array[high]);
		print_array(array, size);
	}

	return (i + 1);
}

/**
* swap - Swaps two elements in an array
* @a: Pointer to the first element
* @b: Pointer to the second element
*/
void swap(int *a, int *b)
{
	int temp = *a;

	*a = *b;
	*b = temp;
}

