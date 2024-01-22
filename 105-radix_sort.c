#include "sort.h"

/**
* radix_sort - Sorts an array of integers in ascending order
* using the Radix sort algorithm
* @array: Non-sorted array
* @size: Number of elements in @array
*/
void radix_sort(int *array, size_t size)
{
	int *tmp, max, exp;

	if (!array || size < 2)
		return;
	tmp = malloc(sizeof(int) * size);
	if (!tmp)
		return;
	max = array[0];
	for (exp = 0; exp < (int)size; exp++)
	{
		if (array[exp] > max)
			max = array[exp];
	}
	for (exp = 1; max / exp > 0; exp *= 10)
	{
		counting_radix(array, size, exp, tmp);
		print_array(array, size);
	}

	free(tmp);
}

/**
* counting_radix - Sorts an array of integers in ascending order
* using the Counting sort algorithm
* @array: Non-sorted array
* @size: Number of elements in @array
* @exp: Exponent
* @tmp: Temporary array
*/
void counting_radix(int *array, size_t size, int exp, int *tmp)
{
	int i, count[10] = {0};

	for (i = 0; i < (int)size; i++)
		count[(array[i] / exp) % 10]++;
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];
	for (i = size - 1; i >= 0; i--)
	{
		tmp[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10]--;
	}
	for (i = 0; i < (int)size; i++)
		array[i] = tmp[i];
}
