#include "sort.h"
#include <stdio.h>

/**
 * bubble_sort - function that sorts an array
 *
 * The first loop should iterate through all the elements in the array
 * The second loop will compare elements next to each other and switch orderly
 *
 * @tmp: temporary variable used to store sorted elements
 * @array: input arrray
 * @size: size of the array
 * Return: no return
 */

void bubble_sort(int *array, size_t size)
{
        int tmp;
        size_t i, j;
        
        for (i = 0; i < size - 1; i++)
        {
                for (j = 0; j < size - 1 - i; j++)
                {
                        if (array[j] > array[j + 1])
                        {
                                tmp = array[j];
                                array[j] = array[j + 1];
                                array[j + 1] = tmp;
                                print_array(array, size);
                        }
                }
        }
}
