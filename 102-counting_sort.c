#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * counting_sort - sorts an array of integers in ascending order
 * using the Counting sort algorithm
 *
 * @count_arr: an array that will be used to keep track of the count of each
 * element in the input array
 * sorted_arr: an array that will hold the sorted output
 * ma_val: integer that holds the maximum value in the input array
 * @array: array of integers to be sorted
 * @size: size of the array
 *
 * Return: no return
 */

void counting_sort(int *array, size_t size)
{
int i, j, max_val;
int *count_arr = NULL, *sorted_arr = NULL;

if (!array || size < 2)
return;

max_val = array[0];
for (i = 1; i < (int)size; i++)
{
if (array[i] > max_val)
max_val = array[i];
}

count_arr = malloc(sizeof(int) * (max_val + 1));
sorted_arr = malloc(sizeof(int) * size);
if (!count_arr || !sorted_arr)
return;

for (i = 0; i < (max_val + 1); i++)
count_arr[i] = 0;

for (i = 0; i < (int)size; i++)
count_arr[array[i]]++;

for (i = 1; i < (max_val + 1); i++)
count_arr[i] += count_arr[i - 1];

for (i = (int)(size - 1); i >= 0; i--)
{
sorted_arr[count_arr[array[i]] - 1] = array[i];
count_arr[array[i]]--;
}

for (i = 0; i < (int)size; i++)
array[i] = sorted_arr[i];

printf("Counting array:\n");
for (j = 0; j < (max_val + 1); j++)
printf("%d, ", count_arr[j]);
printf("\n");

free(count_arr);
free(sorted_arr);
}
