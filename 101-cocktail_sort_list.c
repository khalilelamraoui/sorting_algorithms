#include "sort.h"

/**
* cocktail_sort_list - Sorts a doubly linked list of integers
* in ascending order using the Cocktail shaker sort algorithm
* @list: Doubly linked list
*/
void cocktail_sort_list(listint_t **list)
{
    listint_t *current;
    int swapped = 1;

    if (list == NULL || *list == NULL)
        return;

    current = *list;
    while (swapped)
    {
        swapped = 0;
        while (current->next != NULL)
        {
            if (current->n > current->next->n)
            {
                swap_nodes(current, current->next, list);
                swapped = 1;
                print_list(*list);
            }
            else
                current = current->next;
        }
        if (swapped == 0)
            break;
        swapped = 0;
        while (current->prev != NULL)
        {
            if (current->n < current->prev->n)
            {
                swap_nodes(current->prev, current, list);
                swapped = 1;
                print_list(*list);
            }
            else
                current = current->prev;
        }
    }
}
