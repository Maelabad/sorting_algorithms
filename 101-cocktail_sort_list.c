#include "sort.h"
#include <stdio.h>

/**
 * cocktail_sort_list - Sorts a 2 *linked list of integers in ascending order
 *                      using Cocktail shaker sort algorithm
 * @list: Pointer to a pointer to the head of the list
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped;
	listint_t *start = NULL;
	listint_t *end = NULL, *ptr;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	do {
		swapped = 0;
		ptr = *list;
		while (ptr->next != end)
		{
			if (ptr->n > ptr->next->n)
			{
				swap_nodes(&ptr, &(ptr->next), list);
				swapped = 1;
				print_list(*list);
			}
			else
				ptr = ptr->next;
		}
		end = ptr;
		if (!swapped)
			break;
		swapped = 0;
		while (ptr->prev != start)
		{
			if (ptr->n < ptr->prev->n)
			{
				swap_nodes(&(ptr->prev), &ptr, list);
				swapped = 1;
				print_list(*list);
			}
			else
				ptr = ptr->prev;
		}
		start = ptr;
	} while (swapped == 0);
}


/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @node1: Pointer to the first node
 * @node2: Pointer to the second node
 * @list: Pointer to a pointer to the head of the list
 */
void swap_nodes(listint_t **node1, listint_t **node2, listint_t **list)
{
	listint_t *temp = *node1;

	if ((*node1)->prev != NULL)
		(*node1)->prev->next = *node2;
	else
		*list = *node2;
	if ((*node2)->next != NULL)
		(*node2)->next->prev = *node1;

	(*node1)->next = (*node2)->next;
	(*node2)->prev = (*node1)->prev;
	(*node1)->prev = *node2;
	(*node2)->next = *node1;

	*node1 = *node2;
	*node2 = temp;
}
