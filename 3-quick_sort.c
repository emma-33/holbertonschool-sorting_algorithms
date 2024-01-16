#include "sort.h"
/**
* partition - partitions the array and swaps if needed
* @array: array to sort
* @start: beginning of the array
* @end: end of the array
* @size: size of the array
* Return: partitioned index
*/
int partition(int *array, int start, int end, size_t size)
{
	int pivot, i, j, tmp;

	pivot = array[end];
	i = start - 1;

	for (j = start; j < end; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
				print_array(array, size);

			}
		}
	}
	if (pivot < array[i + 1])
	{
		tmp = array[i + 1];
		array[i + 1] = array[end];
		array[end] = tmp;
		print_array(array, size);
	}
	return (i + 1);
}

/**
* sorting - sorts the array
* @array: array to sort
* @start: beginning of the array
* @end: end of the array
* @size: size of the array
*/
void sorting(int *array, int start, int end, size_t size)
{
	int p = 0;

	if (start >= end || start < 0)
		return;

	p = partition(array, start, end, size);

	sorting(array, start, p - 1, size);
	sorting(array, p + 1, end, size);
}
/**
* quick_sort - sorts an array of integers in ascending
* order using the Quick sort algorithm with Lomuto aprtition scheme
* @array: array to sort
* @size: size of the array
*/
void quick_sort(int *array, size_t size)
{
	int start, end;

	start = 0;
	end = size - 1;
	sorting(array, start, end, size);
}
