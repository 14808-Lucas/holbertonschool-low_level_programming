#include "main.h"

/**
 * sqrt_helper - searches for the natural square root of n, recursively
 * @n: the number to check
 * @guess: the current guess being tested as the square root
 *
 * Return: guess if it is the square root of n, or -1 if none exists
 */
int sqrt_helper(int n, int guess)
{
	if (guess * guess == n)
		return (guess);
	if (guess * guess > n)
		return (-1);
	return (sqrt_helper(n, guess + 1));
}

/**
 * _sqrt_recursion - returns the natural square root of a number
 * @n: the number
 *
 * Return: the natural square root of n, or -1 if it has none
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);
	return (sqrt_helper(n, 1));
}
