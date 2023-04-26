#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * radix_sort - sorts an array of integers in ascending order using the
 * LSD radix sort algorithm
 *
 * @out: an array used to store the sorted elements
 * @mdigit: maximum digit in the array, which determines the number 
 * of significant digits 
 * @array: the array to sort
 * @size: the size of the array to sort
 *
 * Return: no return
 */
void radix_sort(int *array, size_t size)
{
    int *count = NULL, *out = NULL, mdigit = 0, divisor = 1;
    size_t i, j;

    if (!array || size < 2)
        return;

    count = malloc(sizeof(int) * 10);
    out = malloc(sizeof(int) * size);

    if (!count || !out)
    {
        free(count);
        free(out);
        return;
    }

    for (i = 0; i < size; i++)
        mdigit = array[i] > mdigit ? array[i] : mdigit;

    while (mdigit / divisor > 0)
    {
        for (i = 0; i < 10; i++)
            count[i] = 0;

        for (i = 0; i < size; i++)
            count[(array[i] / divisor) % 10]++;

        for (i = 1; i < 10; i++)
            count[i] += count[i - 1];

        for (i = size - 1; (int)i >= 0; i--)
        {
            j = (array[i] / divisor) % 10;
            out[count[j] - 1] = array[i];
            count[j]--;
        }

        for (i = 0; i < size; i++)
            array[i] = out[i];

        print_array(array, size);
        divisor *= 10;
    }

    free(count);
    free(out);
}
