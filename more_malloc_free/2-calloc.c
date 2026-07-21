#include "main.h"

/**
 * _calloc - allocates and zero-fills memory for an array
 * @nmemb: the number of elements
 * @size: the size of each element, in bytes
 *
 * Return: a pointer to the allocated memory, or NULL on failure
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *ptr;
	unsigned int total;
	unsigned int i;

	if (nmemb == 0 || size == 0)
		return (NULL);

	total = nmemb * size;
	ptr = malloc(total);

	if (ptr == NULL)
		return (NULL);

	i = 0;
	while (i < total)
	{
		ptr[i] = 0;
		i++;
	}

	return (ptr);
}
