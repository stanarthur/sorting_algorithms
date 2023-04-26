#ifndef SORT_H
#define SORT_H

#include <stdlib.h>
#include <stdlib.h>


/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
    const int n;
    struct listint_s *prev;
    struct listint_s *next;
} listint_t;

void print_array(const int *array, size_t size);
void bubble_sort(int *array, size_t size);
void print_list(const listint_t *list);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void _qsort(int *a, int low, int high, int size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void ascend_sort(listint_t **ptr, listint_t **limit, listint_t **list);
void descend_sort(listint_t **ptr, listint_t **limit, listint_t **list);
void turn_list(listint_t **ptr1, listint_t **ptr2, int n);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void swap(int *a, int *b);
void _heap(int *array, size_t size, size_t root);
void radix_sort(int *array, size_t size);
void bitonic_merge(int *array, size_t size, size_t start, size_t seq,
                   char flow);
void bitonic_seq(int *array, size_t size, size_t start, size_t seq, char flow);
void bitonic_sort(int *array, size_t size);

#endif
