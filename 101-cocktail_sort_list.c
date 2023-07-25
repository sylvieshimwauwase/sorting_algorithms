#include "sort.h"

/**
 * swap_node - swaps node of linked list
 * @list: pointer to head
 * @a: first node to swap
 * @b: second node to swap
 */
void swap_node(listint_t **list, listint_t *a, listint_t *b)
{
	listint_t *prev_a = a->prev;
	listint_t *next_a = a->next;
	listint_t *prev_b = b->prev;
	listint_t *next_b = b->prev;

	if (prev_a)
		prev_a->next = b;
	else
		*list = b;

	if (next_b)
		next_b->prev = a;
	else
		*list = a;

	a->prev = prev_b;
	a->next = next_b;
	b->prev = prev_a;
	b->next = next_a;

	if (next_a)
		next_a->prev = b;
	if (prev_b)
		prev_b->next = a;

	/* print_list((const listint_t *)*list);*/
}

/**
 * cocktail_sort_list - sorts linked lists using cocktail sorting
 * @list: pointer to linkd list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *start = NULL, *curr;
	int swapped = 0;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	do {
		swapped = 0;
		for (curr = *list; curr->next != start; curr = curr->next)
		{
			if (curr->n > curr->next->n)
			{
				swap_node(list, curr, curr->next);
				swapped = 1;
				print_list(*list);
			}
		}

		if (swapped == 0)
			break;

		start = (*list)->prev;

		swapped = 0;
		for (curr = start; curr->prev != NULL; curr = curr->prev)
		{
			if (curr->n < curr->prev->n)
			{
				swap_node(list, curr->prev, curr);
				swapped = 1;
				print_list(*list);
			}
		}
	} while (swapped);
}
