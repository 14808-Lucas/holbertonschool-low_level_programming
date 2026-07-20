#include "main.h"

/**
 * free_grid - frees a 2D grid previously created by alloc_grid
 * @grid: the array of row pointers
 * @height: the number of rows in the grid
 *
 * Return: void
 */
void free_grid(int **grid, int height)
{
	int h;

	h = 0;

	while (h < height)
	{
		free(grid[h]);
		h++;
	}

	free(grid);
}
