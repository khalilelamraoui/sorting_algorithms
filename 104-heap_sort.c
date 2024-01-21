#include "sort.h"

/**
* heap_sort - Sorts an array of integers in ascending order
* using the Heap sort algorithm
* @array: Non-sorted array
* @size: Number of elements in @array
*/
void heap_sort(int *array, size_t size)
{
	int i, tmp;

	if (!array || size < 2)
		return;

	for (i = size / 2 - 1; i >= 0; i--)
		heapify(array, size, i, size);

	for (i = size - 1; i >= 0; i--)
	{
		tmp = array[0];
		array[0] = array[i];
		array[i] = tmp;

		if (i != 0)
			print_array(array, size);

		heapify(array, i, 0, size);
	}
}

/**
* heapify - Heapifies a subtree
* @array: Non-sorted array
* @size: Number of elements in @array
* @i: Index of the subtree root
* @size_orig: Original size of the array
*/
void heapify(int *array, int size, int i, int size_orig)
{
	int largest = i, left = 2 * i + 1, right = 2 * i + 2, tmp;

	if (left < size && array[left] > array[largest])
		largest = left;

	if (right < size && array[right] > array[largest])
		largest = right;

	if (largest != i)
	{
		tmp = array[i];
		array[i] = array[largest];
		array[largest] = tmp;
		print_array(array, size_orig);
		heapify(array, size, largest, size_orig);
	}
}
