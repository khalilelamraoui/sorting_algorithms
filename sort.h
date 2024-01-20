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
* shell_sort - Sorts an array of integers in ascending order
* using the Shell sort algorithm
* @array: Non-sorted array
* @size: Number of elements in @array
*/
void shell_sort(int *array, size_t size);

#endif /* SORT_H */
