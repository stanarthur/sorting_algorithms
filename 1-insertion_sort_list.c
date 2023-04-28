#include "sort.h"
#include <stdio.h>

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending
 * order using the insertion sort algorithm
 *
 * @list: double linked list
 * Return: no return
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *current, *next, *tmp;

    if (!list || !(*list) || !((*list)->next))
        return;

    current = (*list)->next;
    while (current)
    {
        next = current->next;
        while (current->prev && current->n < current->prev->n)
        {
            tmp = current->prev;
            tmp->next = current->next;
            if (current->next)
                current->next->prev = tmp;
            current->prev = tmp->prev;
            if (tmp->prev)
                tmp->prev->next = current;
            else
                (*list) = current;
            tmp->prev = current;
            current->next = tmp;
            print_list(*list);
        }
        current = next;
    }
}

