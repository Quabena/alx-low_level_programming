#!/usr/bin/python3

def island_perimeter(grid):
    """
    Function to calculate the perimeter of the island described in the grid.
    
    Parameters:
    grid (list of list of integers): A rectangular grid representing the map where
                                      1 is land and 0 is water.
    
    Returns:
    int: The perimeter of the island.
    
    The function iterates through each land cell and checks its neighbors to calculate
    the perimeter of the island.
    """
    
    perimeter = 0
    
    # Iterate through each cell in the grid
    for i in range(len(grid)):
        for j in range(len(grid[i])):
            # If the cell is land
            if grid[i][j] == 1:
                # Check four directions (left, right, up, down) to calculate perimeter
                if i == 0 or grid[i - 1][j] == 0:  # check above
                    perimeter += 1
                if i == len(grid) - 1 or grid[i + 1][j] == 0:  # check below
                    perimeter += 1
                if j == 0 or grid[i][j - 1] == 0:  # check left
                    perimeter += 1
                if j == len(grid[i]) - 1 or grid[i][j + 1] == 0:  # check right
                    perimeter += 1
    
    return perimeter
