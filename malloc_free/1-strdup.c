#include "main.h"

/**
 * _strdup - returns a pointer to a newly allocated copy of a string
 * @str: the string to duplicate
 *
 * Return: a pointer to the duplicated string, or NULL if str is NULL
 *         or if memory allocation fails
 */
char *_strdup(char *str)
{
	char *copy;
	unsigned int len;
	unsigned int i;

	if (str == NULL)
		return (NULL);

	len = 0;

	while (str[len] != '\0')
		len++;

	copy = malloc(sizeof(char) * (len + 1));

	if (copy == NULL)
		return (NULL);

	i = 0;

	while (i < len)
	{
		copy[i] = str[i];
		i++;
	}

	copy[len] = '\0';

	return (copy);
}
