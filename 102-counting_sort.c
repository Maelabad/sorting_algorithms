#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * counting_sort - Sorts an array of integers in ascending order
 *                 using Counting sort algorithm
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void counting_sort(int *array, size_t size)
{
	int *count, i, max, index;
	size_t j;

	if (array == NULL || size < 2)
		return;

	max = array[0];
	for (j = 1; j < size; j++)
	{
		if (array[j] > max)
			max = array[j];
	}
	count = malloc((max + 1) * sizeof(int));
	if (count == NULL)
		return;

	for (i = 0; i <= max; i++)
		count[i] = 0;
	for (j = 0; j < size; j++)
		count[array[j]]++;

	for (i = 0; i <= max; i++)
	{
		printf("%d", count[i]);
		if (i != max)
			printf(" ,");
	}
	print("/n");
	index = 0;
	for (i = 0; i <= max; i++)
	{
		while (count[i] > 0)
		{
			array[index++] = i;
			count[i]--;
		}
	}
	free(count);
}
