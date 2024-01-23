#include "sort.h"

/**
* quick_sort_hoare - sorts an array of integers in ascending order
* using the Quick sort algorithm
* @array: array to sort
* @size: size of the array
* Return: void
*/
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quick_sort_hoare_recursion(array, 0, size - 1, size);
}

/**
* quick_sort_hoare_recursion - sorts an array of integers in ascending order
* using the Quick sort algorithm
* @array: array to sort
* @size: size of the array
* @start: start index
* @end: end index
* Return: void
*/
void quick_sort_hoare_recursion(int *array, int start, int end, size_t size)
{
	int pivot;

	if (start < end)
	{
		pivot = partition_hoare(array, start, end, size);
		quick_sort_hoare_recursion(array, start, pivot - 1, size);
		quick_sort_hoare_recursion(array, pivot, end, size);
	}
}

/**
* partition_hoare - Lomuto partition scheme
* @array: array to sort
* @size: size of the array
* @start: start index
* @end: end index
* Return: void
*/
int partition_hoare(int *array, int start, int end, size_t size)
{
	int pivot = array[end];

	int i = start - 1;

	int j = end + 1;

	while (1)
	{
		do
			i++;
		while (array[i] < pivot);

		do
			j--;
		while (array[j] > pivot);

		if (i >= j)
			return (i);
		swap_hoare(&array[i], &array[j]);
		print_array(array, size);
	}
}

/**
* swap_hoare - swap two integers
* @a: first integer
* @b: second integer
* Return: void
*/
void swap_hoare(int *a, int *b)
{
	int tmp = *a;

	*a = *b;
	*b = tmp;
}
