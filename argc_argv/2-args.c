#include "main.h"
#include <stdio.h>

/**
 * main - prints all arguments passed to the program, one per line
 * @argc: the number of arguments passed to the program
 * @argv: the array of argument strings
 *
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	int i;

	for (i = 0; i < argc; i++)
		printf("%s\n", argv[i]);

	return (0);
}
