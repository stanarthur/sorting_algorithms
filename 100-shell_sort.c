#include "sort.h"

/**
 * shell_sort - function that sorts an array of integers in ascending order
 * using the Shell sort algorithm
 * space - The gap is the interval between the elements to be compared during
 * each iteration of the algorithm
 *
 * @array: input arrray
 * @size: size of the array
 * Return: no return
 */
void shell_sort(int *array, size_t size)
{
size_t i, j, space, int tmp;

if (!array || size < 2)
return;

space = 1;
while (space < size / 3)
space = space * 3 + 1;

while (space > 0)
{
for (i = space; i < size; i++)
{
tmp = array[i];
j = i;

while (j >= space && array[j - space] > tmp)
{
array[j] = array[j - space];
j -= space;
}

array[j] = tmp;
}

space = (space - 1) / 3;
print_array(array, size);
}
}
