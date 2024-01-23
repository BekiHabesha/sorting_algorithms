/*
*
*  📝🔡File_name🔠📒: 1-insertion_sort_list.c
*    📑🔢Task_no🔢📜: 1
* 📖🔤Task_Title🔤📃: Insertion sort
*
*  📔📚Functions📓🗳: void insertion_sort_list, void swap_nodes
* 🗓⌚️Created On🕰📅: january 22, 2024
*
*     🧧🔠Project Title🔤🧰: 0x1B. C - Sorting algorithms & Big O
* 🗃📀GitHub repository📀💽: sorting_algorithms
*  💾🗂GitHub Directory📁🗃: sorting_algorithms
*
*  💻🖍️Author🖊️🪪: Bereket Dereje Mekkonen
*  🌍🔢Cohort🔢🌍: 19
* 🪙📱Program📲🎖: Full Stack
*
*/

#include "sort.h"

/**
 * swap_nodes - It Swap two nodes in a listint_t
 *              doubly-linked list.
 *
 * Author: Bereket Dereje Mekkonen.
 *
 * @h: A pointer to the head of the doubly-linked list.
 *
 * @n1: A pointer to the first node to swap.
 *
 * @n2: The second node to swap.
 */

void swap_nodes(listint_t **h, listint_t **n1, listint_t *n2)
{
	(*n1)->next = n2->next;
	if (n2->next != NULL)
		n2->next->prev = *n1;
	n2->prev = (*n1)->prev;
	n2->next = *n1;
	if ((*n1)->prev != NULL)
		(*n1)->prev->next = n2;
	else
		*h = n2;
	(*n1)->prev = n2;
	*n1 = n2->prev;
}


/**
 * insertion_sort_list - Sorts a doubly linked list
 *                       of integers using the
 *                       insertion sort algorithm.
 *
 * Author: Bereket Dereje Mekkonen.
 *
 * @list: A pointer to the head of a doubly-linked
 *        list of integers.
 *
 * Description: Prints the list after each swap.
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *iter, *insert, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (iter = (*list)->next; iter != NULL; iter = tmp)
	{
		tmp = iter->next;
		insert = iter->prev;
		while (insert != NULL && iter->n < insert->n)
		{
			swap_nodes(list, &insert, iter);
			print_list((const listint_t *)*list);
		}
	}
}
