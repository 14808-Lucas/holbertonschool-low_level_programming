#include "main.h"

/**
 * str_length - returns the length of a string
 * @s: the string to measure
 *
 * Return: the length of the string
 */
unsigned int str_length(char *s)
{
	unsigned int len;

	len = 0;

	while (s[len] != '\0')
		len++;

	return (len);
}

/**
 * string_nconcat - concatenates s1 with up to n bytes of s2
 * @s1: the first string (NULL treated as empty)
 * @s2: the second string (NULL treated as empty)
 * @n: the maximum number of bytes to use from s2
 *
 * Return: a pointer to the newly allocated concatenated string,
 *         or NULL on failure
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *result;
	unsigned int len1;
	unsigned int len2;
	unsigned int i;
	unsigned int j;

	if (s1 == NULL)
		s1 = "";

	if (s2 == NULL)
		s2 = "";

	len1 = str_length(s1);
	len2 = str_length(s2);

	if (n > len2)
		n = len2;

	result = malloc(sizeof(char) * (len1 + n + 1));

	if (result == NULL)
		return (NULL);

	i = 0;
	while (i < len1)
	{
		result[i] = s1[i];
		i++;
	}

	j = 0;
	while (j < n)
	{
		result[i] = s2[j];
		i++;
		j++;
	}

	result[i] = '\0';

	return (result);
}
