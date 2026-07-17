#include "main.h"

/**
 * _strspn - gets the length of a prefix substring
 * @s: the string to check
 * @accept: the string of bytes to match against
 *
 * Return: the number of bytes in the initial segment of s which
 *         consist only of bytes from accept
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int count;
	int i;
	int j;
	int found;

	count = 0;
	i = 0;

	while (s[i] != '\0')
	{
		found = 0;
		j = 0;

		while (accept[j] != '\0')
		{
			if (s[i] == accept[j])
				found = 1;
			j++;
		}

		if (found == 0)
			break;

		count++;
		i++;
	}

	return (count);
}
