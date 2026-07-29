#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * is_digit_string - checks whether a string contains only digit
 * characters
 * @s: the string to check
 *
 * Return: 1 if s is non-empty and contains only digits, 0 otherwise
 */
int is_digit_string(char *s)
{
	int i;

	if (s == NULL || s[0] == '\0')
		return (0);

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
	}

	return (1);
}

/**
 * main - adds positive numbers passed as arguments
 * @argc: the number of arguments passed to the program
 * @argv: the array of argument strings
 *
 * Return: 0 on success, 1 if any argument is not a valid number
 */
int main(int argc, char *argv[])
{
	int i, sum;

	sum = 0;

	for (i = 1; i < argc; i++)
	{
		if (!is_digit_string(argv[i]))
		{
			printf("Error\n");
			return (1);
		}

		sum += atoi(argv[i]);
	}

	printf("%d\n", sum);

	return (0);
}
