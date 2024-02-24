#include "sort.h"

/**
 * swap_nodes - swaps two nodes in a doubly linked list
 * @a: first node to swap
 * @b: second node to swap
 * @head: head of the linked list
 */
static void swap_nodes(listint_t *a, listint_t *b, listint_t **head)
{
	listint_t *temp;

	if (a == NULL || b == NULL)
		return;

	if (a->prev)
		a->prev->next = b;
	if (b->next)
		b->next->prev = a;

	temp = a->next;
	a->next = b->next;
	b->next = temp;

	temp = a->prev;
	a->prev = b->prev;
	b->prev = temp;

	if (a->prev == NULL)
		*head = a;
}

/**
 * insertion_sort_list - sorts a doubly linked
 * list in ascending order using
 * the insertion sort algorithm
 * @list: doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *prev;
	int value;

	if (list == NULL || *list == NULL)
		return;

	current = *list;

	while (current)
	{
		prev = current->prev;
		value = current->n;

		while (prev && prev->n > value)
		{
			swap_nodes(prev, current, list);
			print_list(*list);
			prev = current->prev;
		}

		current = current->next;
	}
}

