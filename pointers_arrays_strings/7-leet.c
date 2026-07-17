#include "main.h"

/**
 * leet - encodes a string into 1337
 * @str: the string to encode
 *
 * Return: a pointer to the encoded string
 */
char *leet(char *str)
{
	char lower[] = "aeotl";
	char upper[] = "AEOTL";
	char digit[] = "43071";
	int i;
	int j;

	i = 0;

	while (str[i] != '\0')
	{
		j = 0;

		while (j < 5)
		{
			if (str[i] == lower[j] || str[i] == upper[j])
				str[i] = digit[j];

			j++;
		}

		i++;
	}

	return (str);
}
