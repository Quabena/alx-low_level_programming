#include "main.h"
#include <stdlib.h>

/**
* free_grid - A function that frees a 2 dimensional grid previously
* created by alloc_grid.
* @grid: pointer to the 2D array to free
* @height: height of the grid
* Return: void
*/

void free_grid(int **grid, int height)
{
int i;

if (grid == NULL || height <= 0)
return;

for (i = 0; i < height; i++)
{
free(grid[i]);
}
free(grid);
}
