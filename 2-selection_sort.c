#include "sort.h"
/**
* selection_sort - sorts an array of integers in ascending order
* using the Selection sort algorithm
* @array: array to sort
* @size: size of the array
*/
void selection_sort(int *array, size_t size)
{
	size_t i, j = 0, min = 0, tmp = 0;

	for (i = 0; i < size - 1; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
				min = j;
		}
		if (min != i)
		{
			tmp = array[i];
			array[i] = array[min];
			array[min] = tmp;
			print_array(array, size);
		}
	}
}
