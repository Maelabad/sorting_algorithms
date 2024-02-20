#include "sort.h"
#include <stdio.h>

/**
 * shell_sort - Sorts an array of integers in ascending order
 *              using Shell sort algorithm with Knuth sequence
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void shell_sort(int *array, size_t size)
{
	int inter = 1, tmp, j, i;

	if (array == NULL || size < 2)
		return;

	while (inter <= (int)(size / 3))
		inter = inter * 3 + 1;

	while (inter > 0)
	{
		for (i = inter; i < (int)size; i++)
		{
			tmp = array[i];
			j = i;
			while (j >= inter && array[j - inter] > tmp)
			{
				array[j] = array[j - inter];
				j -= inter;
			}
			array[j] = tmp;
		}
		print_array(array, size);
		inter /= 3;
	}
}
