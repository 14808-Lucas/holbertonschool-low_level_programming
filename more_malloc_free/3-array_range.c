#include "main.h"

/**
 * array_range - creates an array of integers from min to max, inclusive
 * @min: the starting value
 * @max: the ending value
 *
 * Return: a pointer to the newly created array, or NULL on failure
 */
int *array_range(int min, int max)
{
	int *array;
	int size;
	int i;

	if (min > max)
		return (NULL);

	size = max - min + 1;
	array = malloc(sizeof(int) * size);

	if (array == NULL)
		return (NULL);

	i = 0;
	while (i < size)
	{
		array[i] = min + i;
		i++;
	}

	return (array);
}
