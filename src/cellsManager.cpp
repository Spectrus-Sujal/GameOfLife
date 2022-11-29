#include "cellsManager.h"

std::vector<std::vector<Cell>> CellsManager::updateCells(std::vector<std::vector<Cell>> &cells)
{
	// Make a new 2D vector of cells
	// Have it be the same values as cells
	std::vector<std::vector<Cell>> newGen {cells} ;

	// Go through every cell
	for (auto row{ 0 }; row < cells.size(); row++)
	{
		for (auto col{ 0 }; col < cells[row].size(); col++)
		{
			// Update every cell in the new Generation based on the current generation
			newGen[row][col].updateState(checkConditions(cells, row, col));
		}
	}

	// Return the updated cells
	return newGen;
}

void CellsManager::drawCells(std::vector<std::vector<Cell>>& cells)
{
	// Go through every cell
	for(auto row {0}; row < cells.size(); row++)
	{
		for(auto col {0}; col < cells[row].size(); col++)
		{
			// Draw the cell
			cells[row][col].drawCell();
		}
	}
}

int CellsManager::checkConditions(const std::vector<std::vector<Cell>>& cells, int row, int col)
{
	// Make the number of neighbors 0
	int counter{ 0 };

	// Check if cell is at left edge
	if(row > 0)
	{
		// Check left cell
		if (cells[row - 1][col].isAlive()) counter++;

		// Check top left
		if(col > 0)
		{
			if (cells[row - 1][col - 1].isAlive()) counter++;
		}

		// Bottom left
		if (col < cells[row].size() - 1)
		{
			if (cells[row - 1][col + 1].isAlive()) counter++;
		}
	}

	// Check right edge
	if (row < cells.size() - 1)
	{
		// Check right
		if (cells[row + 1][col].isAlive()) counter++;

		// Top right
		if (col > 0)
		{
			if (cells[row + 1][col - 1].isAlive()) counter++;
		}

		// Bottom right
		if (col < cells[row].size() - 1)
		{
			if (cells[row + 1][col + 1].isAlive()) counter++;
		}
	}

	// Top
	if (col > 0)
	{
		if (cells[row][col - 1].isAlive()) counter++;
	}

	// Bottom
	if (col < cells[row].size() - 1)
	{
		if (cells[row][col + 1].isAlive()) counter++;
	}

	// Return the number of neighbors
	return counter;
}
