#include "main.h"

/**
 * times_table - Prints the 9 times table
 */
void times_table(void)
{
	int row;
	int column;
	int result;

	for (row = 0; row <= 9; row++)
	{
		for (column = 0; column <= 9; column++)
		{
			result = row * column;

			if (result > 9)
			{
				_putchar(',');
				_putchar(' ');
				_putchar((result / 10) + '0');
				_putchar((result % 10) + '0');
			}
			else
			{
				if (column != 0)
				{
					_putchar(',');
					_putchar(' ');
					_putchar(' ');
				}

				_putchar(result + '0');
			}
		}

		_putchar('\n');
	}
}
