#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * swap_ints - Swaps two integers in an array
 * @a: Pointer to the first integer
 * @b: Pointer to the second integer
 * Return: no return
 */
void swap_ints(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

/**
 * hoare_partition - Partitions an array using the Hoare scheme
 *
 * @array: Pointer to the array to partition
 * @size: Size of the array
 * @low: Lower bound of the partition to sort
 * @high: Upper bound of the partition to sort
 *
 * Return: Index of the partition pivot
 */
size_t hoare_partition(int *array, size_t size, size_t low, size_t high)
{
    int pivot = array[high];
    size_t i = low - 1, j = high + 1;

    while (1)
    {
        do {
            i++;
        } while (array[i] < pivot);

        do {
            j--;
        } while (array[j] > pivot);

        if (i >= j)
            return j;

        swap_ints(&array[i], &array[j]);
        print_array(array, size);
    }
}

/**
 * quicksort - Sorts a partition of an array using the Hoare scheme
 *
 * @array: Pointer to the array to sort
 * @size: Size of the array
 * @low: Lower bound of the partition to sort
 * @high: Upper bound of the partition to sort
 *
 * Return: no return
 */
void quicksort(int *array, size_t size, size_t low, size_t high)
{
    if (low < high)
    {
        size_t p = hoare_partition(array, size, low, high);

        quicksort(array, size, low, p);
        quicksort(array, size, p + 1, high);
    }
}

/**
 * quick_sort_hoare - Sorts an array of integers using the Quick sort algorithm
 *
 * @array: Pointer to the array to sort
 * @size: Size of the array
 *
 * Return: no return
 */
void quick_sort_hoare(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    quicksort(array, size, 0, size - 1);
}
