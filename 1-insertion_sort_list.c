#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @list: Double pointer to the head of the list
 * @n1: The first node (will move right)
 * @n2: The second node (will move left)
 */
void swap_nodes(listint_t **list, listint_t *n1, listint_t *n2)
{
	if (n1->prev)
		n1->prev->next = n2;
	else
		*list = n2;

	if (n2->next)
		n2->next->prev = n1;

	n2->prev = n1->prev;
	n1->next = n2->next;
	n2->next = n1;
	n1->prev = n2;
}
/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * using the Insertion sort algorithm.
 * @list: Double pointer to the head of the list.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	curr = (*list)->next;
	while (curr != NULL)
	{
		tmp = curr;
		curr = curr->next;
		/* Move tmp backwards until it's in the correct spot */
		while (tmp->prev != NULL && tmp->n < tmp->prev->n)
		{
			swap_nodes(list, tmp->prev, tmp);
			print_list(*list);
		}
	}
}
