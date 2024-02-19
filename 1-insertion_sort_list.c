#include "sort.h"


/**
 * insertion_sort_list - function that sorts a doubly linked list of integers
 *                      in ascending order using the Insertion sort algorithm
 * @list: Pointer to a pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *actual, *next, *prev;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	actual = (*list)->next;

	while (actual != NULL)
	{
		next = actual->next;

		while (actual->prev != NULL && actual->n < actual->prev->n)
		{
			prev = actual->prev;
			if (actual->next != NULL)
				actual->next->prev = prev;
			prev->next = actual->next;
			actual->next = prev;
			actual->prev = prev->prev;
			prev->prev = actual;
			if (actual->prev != NULL)
				actual->prev->next = actual;
			else
				*list = actual;
			print_list(*list);
		}
		actual = next;
	}
}
