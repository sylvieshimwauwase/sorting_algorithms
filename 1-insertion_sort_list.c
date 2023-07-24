#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list using insertion sort
 * @list: Pointer to a pointer to the head of the list
 *
 * Description:
 *     Prints the list after each swap
 *     Uses the insertion sort algorithm
 *     Only swaps nodes (including their pointers) and their values
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *iterator, *insert, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (iterator = (*list)->next; iterator != NULL; iterator = tmp)
	{
		tmp = iterator->next;
		insert = iterator->prev;

		while (insert != NULL && iterator->n < insert->n)
		{
			if (iterator->next != NULL)
				iterator->next->prev = insert;
			insert->next = iterator->next;

			iterator->next = insert;
			iterator->prev = insert->prev;

			if (insert->prev != NULL)
				insert->prev->next = iterator;
			else
				*list = iterator;
			insert->prev = iterator;


			insert = iterator->prev;

			print_list((const listint_t *)*list);
		}
	}
}
