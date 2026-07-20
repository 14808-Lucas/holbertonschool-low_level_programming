#include "main.h"

/**
 * free_grid - frees a partially or fully allocated grid
 * @grid: the array of row pointers
 * @allocated_rows: the number of rows that were successfully allocated
 *
 * Return: void
 */
void free_grid(int **grid, int allocated_rows)
{
	int h;

	h = 0;

	while (h < allocated_rows)
	{
		free(grid[h]);
		h++;
	}

	free(grid);
}

/**
 * alloc_grid - returns a pointer to a 2D array of integers, initialized to 0
 * @width: the width of the grid
 * @height: the height of the grid
 *
 * Return: a pointer to the newly allocated grid, or NULL on failure
 */
int **alloc_grid(int width, int height)
{
	int **grid;
	int h;
	int w;

	if (width <= 0 || height <= 0)
		return (NULL);

	grid = malloc(sizeof(int *) * height);

	if (grid == NULL)
		return (NULL);

	h = 0;

	while (h < height)
	{
		grid[h] = malloc(sizeof(int) * width);

		if (grid[h] == NULL)
		{
			free_grid(grid, h);
			return (NULL);
		}

		w = 0;

		while (w < width)
		{
			grid[h][w] = 0;
			w++;
		}

		h++;
	}

	return (grid);
}
