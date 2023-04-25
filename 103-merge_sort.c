#include "sort.h"
#include <stdio.h>

/**
 * merge - merges subarrays of integers to create an array
 *
 * @array: pointer to the first element of the array to be sorted
 * @tmp:   temporary array used during the merging process.
 * @left_size:  first index of the left subarray during a merge operation
 * @right_size: last index of the left subarray and starting index of the right
 * subarray during a merge operation
 * @size: Size of the array
 *
 *Return: no value
 **/
void merge(int *array, int *left, int *right, size_t size)
{
    int i, j, k;
    int left_size = size / 2;
    int right_size = size - left_size;

    printf("Merging...\n[left]: ");
    print_array(left, left_size);
    printf("[right]: ");
    print_array(right, right_size);

    for (i = 0, j = 0, k = 0; i < left_size && j < right_size; k++)
    {
        if (left[i] < right[j])
        {
            array[k] = left[i];
            i++;
        }
        else
        {
            array[k] = right[j];
            j++;
        }
    }

    while (i < left_size)
    {
        array[k] = left[i];
        i++;
        k++;
    }

    while (j < right_size)
    {
        array[k] = right[j];
        j++;
        k++;
    }

    printf("[Done]: ");
    print_array(array, size);
}

/**
 * merge_sort - Merge sort algorithm
 * @array: Array to be sorted
 * @size: Size of the array
 **/
void merge_sort(int *array, size_t size)
{
    int *left, *right;
    size_t middle = size / 2;

    if (size < 2 || array == NULL)
        return;

    left = array;
    right = array + middle;

    merge_sort(left, middle);
    merge_sort(right, size - middle);
    merge(array, left, right, size);
}
