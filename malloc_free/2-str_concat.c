#include "main.h"

/**
 * _strlen_safe - returns the length of a string, or 0 if NULL
 * @s: the string to measure
 *
 * Return: the length of the string, or 0 if s is NULL
 */
int _strlen_safe(char *s)
{
	int len;

	if (s == NULL)
		return (0);

	len = 0;

	while (s[len] != '\0')
		len++;

	return (len);
}

/**
 * str_concat - concatenates two strings into newly allocated memory
 * @s1: the first string (NULL treated as empty)
 * @s2: the second string (NULL treated as empty)
 *
 * Return: a pointer to the newly allocated concatenated string,
 *         or NULL on failure
 */
char *str_concat(char *s1, char *s2)
{
	char *result;
	int len1, len2, i, j;

	len1 = _strlen_safe(s1);
	len2 = _strlen_safe(s2);

	result = malloc(sizeof(char) * (len1 + len2 + 1));

	if (result == NULL)
		return (NULL);

	i = 0;

	while (i < len1)
	{
		result[i] = s1[i];
		i++;
	}

	j = 0;

	while (j < len2)
	{
		result[i] = s2[j];
		i++;
		j++;
	}

	result[i] = '\0';

	return (result);
}
