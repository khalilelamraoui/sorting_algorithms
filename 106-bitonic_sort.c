#include "sort.h"

/**
* bitonic_sort - function that sorts an array of integers in ascending order
* @array: array
* @size: array lenght
*/
void bitonic_sort(int *array, size_t size)
{
	int order = 1;

	if (!array || size < 2)
		return;
	bitonicsort(array, 0, size, order, size);
}

/**
* bitonicsort - function that sorts an array of integers in ascending order
* @arr: array
* @low: first element
* @nbrelmt: number of elements
* @order: 1: ascending order, 0 descending order
* @size: array lenght
*/
void bitonicsort(int arr[], int low, int nbrelmt, int order, int size)
{
	int mid;

	if (nbrelmt > 1)
	{
		if (order >= 1)
		{
			printf("Merging [%i/%i] (UP):\n", nbrelmt, size);
			print_array(&arr[low], nbrelmt);
		}
		else
		{
			printf("Merging [%i/%i] (DOWN):\n", nbrelmt, size);
			print_array(&arr[low], nbrelmt);
		}
		mid = nbrelmt / 2;
		bitonicsort(arr, low, mid, 1, size);
		bitonicsort(arr, low + mid, mid, 0, size);
		merge_bitonic(arr, low, nbrelmt, order);
		if (order <= 0)
		{
			printf("Result [%i/%i] (DOWN):\n", nbrelmt, size);
			print_array(&arr[low], nbrelmt);
		}
		if (order >= 1)
		{
			printf("Result [%i/%i] (UP):\n", nbrelmt, size);
			print_array(&arr[low], nbrelmt);
		}
	}
}

/**
* swap - function that swaps two elements in an array
* @arr: array
* @item1: item one
* @item2: item two
* @order: 1: ascending order, 0 descending order
*/
void swap(int arr[], int item1, int item2, int order)
{
	int temp;

	if (order == (arr[item1] > arr[item2]))
	{
		temp = arr[item1];
		arr[item1] = arr[item2];
		arr[item2] = temp;
	}
}

/**
* merge_bitonic - function that merges two subarrays of arr[]
* @arr: array
* @low: first element
* @nbrelmt: elements number
* @order: 1: ascending order, 0 descending order
*/
void merge_bitonic(int arr[], int low, int nbrelmt, int order)
{
	int i, mid;

	if (nbrelmt > 1)
	{
		mid = nbrelmt / 2;
		for (i = low; i < low + mid; i++)
			swap(arr, i, i + mid, order);
		merge_bitonic(arr, low, mid, order);
		merge_bitonic(arr, low + mid, mid, order);
	}
}
