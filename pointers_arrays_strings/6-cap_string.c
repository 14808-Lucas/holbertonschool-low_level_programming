#include "main.h"

/**
 * cap_string - capitalizes all words of a string
 * @str: the string to modify
 *
 * Return: a pointer to the modified string
 */
char *cap_string(char *str)
{
	int i;
	int start_of_word;
	char separators[] = " \t\n,;.!?\"()}{";
	int j;

	i = 0;
	start_of_word = 1;

	while (str[i] != '\0')
	{
		if (start_of_word && str[i] >= 'a' && str[i] <= 'z')
			str[i] = str[i] - 'a' + 'A';

		start_of_word = 0;
		j = 0;

		while (separators[j] != '\0')
		{
			if (str[i] == separators[j])
				start_of_word = 1;
			j++;
		}

		i++;
	}

	return (str);
}
