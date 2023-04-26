#include "sort.h"

/**
 * swap - function swaps two integers in an array
 *
 * @a: First integer to swap
 * @b: Second integer to swap
 *
 * Return: no return
 */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * _heap - ensures that the binary tree starting at index 'root'
 * satisfies the heap property (parent node is greater than or equal 
 * to its children).
 *
 * @array: Array containing binary tree
 * @size: Size of the array
 * @root: Index of the root node of the binary tree
 *
 * Return: no return
 */
void _heap(int *array, size_t size, size_t root)
{
    size_t largest = root;
    size_t left = 2 * root + 1;
    size_t right = 2 * root + 2;

    if (left < size && array[left] > array[largest])
        largest = left;

    if (right < size && array[right] > array[largest])
        largest = right;

    if (largest != root)
    {
        swap(&array[root], &array[largest]);
        print_array(array, size);
        _heap(array, size, largest);
    }
}

/**
 * heap_sort - Sorts an array of integers in ascending order using
 *             the sift-down heap sort algorithm.
 *
 * @array: pointer to the first element of the array to sorted
 * @size: Size of the element of the array
 *
 * Return: no return
 */
void heap_sort(int *array, size_t size)
{
    int i;

    for (i = size / 2 - 1; i >= 0; i--)
        _heap(array, size, i);

    for (i = size - 1; i >= 0; i--)
    {
        swap(&array[0], &array[i]);
        if (i != 0)
            print_array(array, size);
        _heap(array, i, 0);
    }
}
