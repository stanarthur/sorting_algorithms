#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * counting_sort - sorts an array of integers in ascending order
 * using the Counting sort algorithm
 *
 * @car: an array that will be used to keep track of the counted array
 * sar: an array that will hold the sorted array
 * mval: integer that holds the maximum value in the input array
 * @array: array of integers to be sorted
 * @size: size of the array
 *
 * Return: no return
 */

void counting_sort(int *array, size_t size)
{
int i, j, mval;
int *car = NULL, *sar = NULL;

if (!array || size < 2)
return;

mval = array[0];
for (i = 1; i < (int)size; i++)
{
if (array[i] > mval)
mval = array[i];
}

car = malloc(sizeof(int) * (mval + 1));
sar = malloc(sizeof(int) * size);
if (!car || !sar)
return;

for (i = 0; i < (mval + 1); i++)
car[i] = 0;

for (i = 0; i < (int)size; i++)
car[array[i]]++;

for (i = 1; i < (m_val + 1); i++)
car[i] += car[i - 1];

for (i = (int)(size - 1); i >= 0; i--)
{
sar[car[array[i]] - 1] = array[i];
car[array[i]]--;
}

for (i = 0; i < (int)size; i++)
array[i] = sar[i];

printf("Counting array:\n");
for (j = 0; j < (mval + 1); j++)
printf("%d, ", car[j]);
printf("\n");

free(car);
free(sar);
}
