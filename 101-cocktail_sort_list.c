#include "sort.h"

/**
 * turn_list - This function takes two pointers to nodes in the linked list
 * and a variable n that is used to determine the direction of the swap
 *
 * @temp: temporary pointer used to hold a reference to a node in the list
 * @tmp:  temporary pointer used to store the second element while swapping
 * nodes
 *
 * @ptr1: first pointer
 * @ptr2: second pointer
 * @n: n is 0 for increase, n is 1 for decrease
 *
 * Return: no return
 */
void turn_list(listint_t **ptr1, listint_t **ptr2, int n)
{
	listint_t *temp, *tmp;

	temp = *ptr1;
	tmp = *ptr2;

	temp->next = tmp->next;
	tmp->prev = temp->prev;

	if (tmp->next)
		tmp->next->prev = temp;

	if (temp->prev)
		temp->prev->next = tmp;

	temp->prev = tmp;
	tmp->next = temp;

	if (n == 0)
		*ptr1 = tmp;
	else
		*ptr2 = temp;
}

/**
 * ascend_sort - function tahes the larger numbers to the end of the list
 *
 * @ptr: pointer to the bigger number
 * @limit: limit of the list
 * @list: list of integers
 *
 * Return: no return
 */
void ascend_sort(listint_t **ptr, listint_t **limit, listint_t **list)
{
	listint_t *temp;

	temp = *ptr;

	while (temp != *limit && temp->next != *limit)
	{
		if (temp->n > temp->next->n)
		{
			turn_list(&temp, &(temp->next), 0);
			if (temp->prev == NULL)
				*list = temp;
			print_list(*list);
		}
		temp = temp->next;
	}

	*limit = temp;
	*ptr = temp;
}

/**
 * descend_sort - function takes the lesser numbers to the beginnig of the
 * list
 *
 * @ptr: pointer to the smaller number
 * @limit: limit of the list
 * @list: list of integers
 *
 * Return: no return
 */
void descend_sort(listint_t **ptr, listint_t **limit, listint_t **list)
{
	listint_t *temp;

	temp = *ptr;

	while (temp != *limit && temp->prev != *limit)
	{
		if (temp->n < temp->prev->n)
		{
			turn_list(&(temp->prev), &temp, 1);
			if (temp->prev->prev == NULL)
				*list = temp->prev;
			print_list(*list);
		}
		temp = temp->prev;
	}

	*limit = temp;
	*ptr = temp;
}

/**
 * cocktail_sort_list - function that sorts the double linked list by calling ascending
 * and descending_sort until they complete themselves
 *
 * @list: head of the linked list
 * Return: no return
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *limit1, *limit2, *ptr;

	if (list == NULL)
		return;

	if (*list == NULL)
		return;

	limit1 = limit2 = NULL;
	ptr = *list;

	do {
		ascend_sort(&ptr, &limit1, list);
		descend_sort(&ptr, &limit2, list);
	} while (limit1 != limit2);
}
