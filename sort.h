#ifndef SORT_H
#define SORT_H

#include <stdlib.h>
#include <stdio.h>

/**
* struct listint_s - Doubly linked list node
*
* @n: Integer stored in the node
* @prev: Pointer to the previous element of the list
* @next: Pointer to the next element of the list
*/
typedef struct listint_s
{
	const int n;

	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/* Print Functions */
void print_array(const int *array, size_t size);

void print_list(const listint_t *list);

/* Sorting Algorithms */
/**
* bubble_sort - Sorts an array of integers in ascending order
* @array: Non-sorted array
* @size: Number of elements in @array
*/
void bubble_sort(int *array, size_t size);

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * in ascending order
 * @list: Doubly linked list
 */
void insertion_sort_list(listint_t **list);

/**
 * selection_sort - Sorts an array of integers in ascending order
 * using the Selection sort algorithm
 * @array: Non-sorted array
 * @size: Number of elements in @array
 */
void selection_sort(int *array, size_t size);

/**
 * quick_sort - Sorts an array of integers in ascending order
 * using the Quick sort algorithm
 * @array: Non-sorted array
 * @size: Number of elements in @array
 */
void quick_sort(int *array, size_t size);

/**
 * quick_sort_recursive - Sorts an array of integers in ascending order
 * using the Quick sort algorithm
 * @array: Non-sorted array
 * @lo: Lowest index of @array
 * @hi: Highest index of @array
 * @size: Number of elements in @array
 */
void quick_sort_recursive(int *array, int lo, int hi, size_t size);

/**
 * partition - Sorts an array of integers in ascending order
 * using the Quick sort algorithm
 * @array: Non-sorted array
 * @lo: Lowest index of @array
 * @hi: Highest index of @array
 * @size: Number of elements in @array
 *
 * Return: Index of the pivot
 */
int partition(int *array, int lo, int hi, size_t size);

/**
* cocktail_sort_list - Sorts a doubly linked list of integers
* in ascending order using the Cocktail shaker sort algorithm
* @list: Doubly linked list
*/
void cocktail_sort_list(listint_t **list);

/**
* swap_nodes - Swaps two nodes of a doubly linked list
* @node1: First node
* @node2: Second node
* @list: Doubly linked list
*/
void swap_nodes(listint_t *node1, listint_t *node2, listint_t **list);

/**
* shell_sort - Sorts an array of integers in ascending order
* using the Shell sort algorithm
* @array: Non-sorted array
* @size: Number of elements in @array
*/
void shell_sort(int *array, size_t size);

/**
* counting_sort - Sorts an array of integers in ascending order
* using the Counting sort algorithm
* @array: Non-sorted array
* @size: Number of elements in @array
*/
void counting_sort(int *array, size_t size);

/**
* merge_sort - Sorts an array of integers in ascending order
* using the Merge sort algorithm
* @array: Non-sorted array
* @size: Number of elements in @array
*/
void merge_sort(int *array, size_t size);

/**
* merge_sort_recursive - Sorts an array of integers in ascending order
* using the Merge sort algorithm
* @array: Non-sorted array
* @tmp: Temporary array
* @lo: Lowest index of @array
* @hi: Highest index of @array
*/
void merge_sort_recursive(int *array, int *tmp, int lo, int hi);


/**
* merge - Sorts an array of integers in ascending order
* using the Merge sort algorithm
* @array: Non-sorted array
* @tmp: Temporary array
* @lo: Lowest index of @array
* @mid: Middle index of @array
* @hi: Highest index of @array
*/
void merge(int *array, int *tmp, int lo, int mid, int hi);

/**
* heap_sort - Sorts an array of integers in ascending order
* using the Heap sort algorithm
* @array: Non-sorted array
* @size: Number of elements in @array
*/
void heap_sort(int *array, size_t size);

/**
* heapify - Heapifies a subtree
* @array: Non-sorted array
* @size: Number of elements in @array
* @i: Index of the subtree root
* @size_orig: Original size of the array
*/
void heapify(int *array, int size, int i, int size_orig);

/**
* counting_radix - Sorts an array of integers in ascending order
* using the Counting sort algorithm
* @array: Non-sorted array
* @size: Number of elements in @array
* @exp: Exponent
* @tmp: Temporary array
*/
void counting_radix(int *array, size_t size, int exp, int *tmp);

/**
* radix_sort - Sorts an array of integers in ascending order
* using the Radix sort algorithm
* @array: Non-sorted array
* @size: Number of elements in @array
*/
void radix_sort(int *array, size_t size);

/**
* bitonic_sort - function that sorts an array of integers in ascending order
* @array: array
* @size: array lenght
*/
void bitonic_sort(int *array, size_t size);

/**
* bitonicsort - function that sorts an array of integers in ascending order
* @arr: array
* @low: first element
* @nbrelmt: number of elements
* @order: 1: ascending order, 0 descending order
* @size: array lenght
*/
void bitonicsort(int arr[], int low, int nbrelmt, int order, int size);

/**
* swap - function that swaps two elements in an array
* @arr: array
* @item1: item one
* @item2: item two
* @order: 1: ascending order, 0 descending order
*/
void swap(int arr[], int item1, int item2, int order);

/**
* merge_bitonic - function that merges two subarrays of arr[]
* @arr: array
* @low: first element
* @nbrelmt: elements number
* @order: 1: ascending order, 0 descending order
*/
void merge_bitonic(int arr[], int low, int nbrelmt, int order);

/**
* quick_sort_hoare - sorts an array of integers in ascending order
* using the Quick sort algorithm
* @array: array to sort
* @size: size of the array
* Return: void
*/
void quick_sort_hoare(int *array, size_t size);

/**
* quick_sort_hoare_recursion - sorts an array of integers in ascending order
* using the Quick sort algorithm
* @array: array to sort
* @size: size of the array
* @start: start index
* @end: end index
* Return: void
*/
void quick_sort_hoare_recursion(int *array, int start, int end, size_t size);

/**
* partition_hoare - Lomuto partition scheme
* @array: array to sort
* @size: size of the array
* @start: start index
* @end: end index
* Return: void
*/
int partition_hoare(int *array, int start, int end, size_t size);

/**
* swap_hoare - swap two integers
* @a: first integer
* @b: second integer
* Return: void
*/
void swap_hoare(int *a, int *b);

#endif /* SORT_H */
