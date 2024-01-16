#include "sort.h"
/**
* insertion_sort_list - sorts a doubly linked list of integers in ascending
* order using the Insertion sort algorithm
* @list: doubly linked list
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *current_node, *previous_node, *head_node;

	if (!list || !(*list) || !(*list)->next)
		return;

	head_node = *list;

	while (head_node)
	{
		current_node = head_node;
		while (current_node && current_node->prev)
		{
			previous_node = current_node->prev;
			if (previous_node->n > current_node->n)
			{
				if (previous_node->prev)
					(previous_node->prev)->next = current_node;
				current_node->prev = previous_node->prev;
				previous_node->next = current_node->next;
				previous_node->prev = current_node;
				current_node->next = previous_node;
				if (previous_node->next)
					(previous_node->next)->prev = previous_node;
				if (!current_node->prev)
					*list = current_node;
				print_list(*list);
			}
			else
				current_node = current_node->next;
		}
		head_node = head_node->next;
	}
}
