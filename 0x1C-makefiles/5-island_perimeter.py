#!/usr/bin/python3
"""Module that calculates the perimeter of an island in a grid."""

def num_water_neighbors(grid, i, j):
    """
    Helper function that calculates the number of water neighbors 
    (or exposed sides) for a land cell in the grid.
    """
    
    num = 0

    # Check the cell above
    if i <= 0 or not grid[i - 1][j]:
        num += 1  # Increment if the cell is out of bounds or is water

    # Check the cell to the left
    if j <= 0 or not grid[i][j - 1]:
        num += 1  # Increment if the cell is out of bounds or is water

    # Check the cell to the right
    if j >= len(grid[i]) - 1 or not grid[i][j + 1]:
        num += 1  # Increment if the cell is out of bounds or is water

    # Check the cell below
    if i >= len(grid) - 1 or not grid[i + 1][j]:
        num += 1  # Increment if the cell is out of bounds or is water

    return num

def island_perimeter(grid):
    """
    Function to calculate the perimeter of the island described in the grid.
    
    The perimeter is calculated by summing the number of exposed water sides 
    for each land cell in the grid. A land cell is considered to have an exposed 
    side if it is adjacent to water or is on the grid boundary
    """
    
    perimeter = 0

    # Iterate through each cell in the grid
    for i in range(len(grid)):
        for j in range(len(grid[i])):
            if grid[i][j]:
                perimeter += num_water_neighbors(grid, i, j)

    return perimeter
