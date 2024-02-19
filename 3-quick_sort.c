#include "sort.h"
#include <stdio.h>

/**
 * quick_sort - Sorts an array of integers in ascending order
 *              using Quick sort algorithm with Lomuto partition scheme
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	_quick_sort(array, 0, size - 1, size);
}

/**
 * _quick_sort - Recursive function to perform Quick sort
 * @array: The array to be sorted
 * @low: The index of the first element of the partition
 * @high: The index of the last element of the partition
 * @size: Number of elements in the array
 */
void _quick_sort(int *array, int low, int high, size_t size)
{
	int partition_idx;

	if (low < high)
	{
		partition_idx = _partition(array, low, high, size);
		_quick_sort(array, low, partition_idx - 1, size);
		_quick_sort(array, partition_idx + 1, high, size);
	}
}

/**
 * _partition - Lomuto partition scheme for Quick sort
 * @array: The array to be sorted
 * @low: The index of the first element of the partition
 * @high: The index of the last element of the partition
 * @size: Number of elements in the array
 *
 * Return: Index of the pivot element
 */
int _partition(int *array, int low, int high, size_t size)
{
	int pivot, temp;
	int i = low - 1;
	int j;

	pivot = array[high];

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			if (i != j)
				print_array(array, size);
		}
	}
	temp = array[i + 1];
	array[i + 1] = array[high];
	array[high] = temp;
	if (i + 1 != high)
		print_array(array, size);
	return (i + 1);
}
