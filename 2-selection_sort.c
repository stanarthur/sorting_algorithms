#include "sort.h"
#include <stdio.h>


/**
 * selection_sort - Sorts an array of integers in ascending order using the
 * Selection sort algorithm
 *
 * @tmp: temporary variable used to store sorted elements
 * @m_val: variable use to track the min value in the unsorted part of the
 * array
 * @array: Pointer to the first element of the array to be sorted
 * @size: Size of the array to be sorted
 * Return: no return
 */
void selection_sort(int *array, size_t size)
{
    size_t i, j, m_val;
    int tmp;

    for (i = 0; i < size - 1; i++)
    {
        m_val = i;
        for (j = i + 1; j < size; j++)
        {
            if (array[j] < array[m_val])
                m_val = j;
        }
        if (m_val != i)
        {
            tmp = array[i];
            array[i] = array[m_val];
            array[m_val] = tmp;
            print_array(array, size);
        }
    }
}
