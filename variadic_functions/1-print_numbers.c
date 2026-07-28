#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include "variadic_functions.h"

/**
 * print_numbers - prints numbers, separated by a separator, followed
 * by a new line
 * @separator: the string to print between numbers, or NULL to skip it
 * @n: the number of integers passed
 * @...: the list of integers to print
 *
 * Return: Nothing.
 */
void print_numbers(const char *separator, const unsigned int n, ...)
{
	va_list args;
	unsigned int i;

	va_start(args, n);

	for (i = 0; i < n; i++)
	{
		printf("%d", va_arg(args, int));

		if (separator != NULL && i != n - 1)
			printf("%s", separator);
	}

	printf("\n");

	va_end(args);
}
