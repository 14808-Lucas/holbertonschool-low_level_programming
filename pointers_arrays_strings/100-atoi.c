#include "main.h"

/**
 * _atoi - converts a string to an integer
 * @s: the string to convert
 *
 * Return: the converted integer, or 0 if no digits are found
 */
int _atoi(char *s)
{
	int i, sign, num, digit_found;

	i = 0;
	sign = 1;
	num = 0;
	digit_found = 0;

	while (s[i] != '\0' && (s[i] < '0' || s[i] > '9'))
	{
		if (s[i] == '-')
			sign *= -1;
		i++;
	}

	while (s[i] >= '0' && s[i] <= '9')
	{
		digit_found = 1;
		num = num * 10 + (s[i] - '0');
		i++;
	}

	if (digit_found == 0)
		return (0);

	return (num * sign);
}
