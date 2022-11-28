#include "cellsManager.h"

std::vector<std::vector<Cell>> CellsManager::updateCells(std::vector<std::vector<Cell>> &cells)
{
	std::vector<std::vector<Cell>> newGen {cells} ;

	// Go through every cell
	for (auto row{ 0 }; row < cells.size(); row++)
	{
		for (auto col{ 0 }; col < cells[row].size(); col++)
		{
			newGen[row][col].updateState(checkConditions(cells, row, col));
		}
	}

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
	int counter{ 0 };

	if(row > 0)
	{
		if (cells[row - 1][col].isAlive()) counter++;

		if(col > 0)
		{
			if (cells[row - 1][col - 1].isAlive()) counter++;
		}

		if (col < cells[row].size() - 1)
		{
			if (cells[row - 1][col + 1].isAlive()) counter++;
		}
	}

	if (row < cells.size() - 1)
	{
		if (cells[row + 1][col].isAlive()) counter++;

		if (col > 0)
		{
			if (cells[row + 1][col - 1].isAlive()) counter++;
		}

		if (col < cells[row].size() - 1)
		{
			if (cells[row + 1][col + 1].isAlive()) counter++;
		}
	}

	if (col > 0)
	{
		if (cells[row][col - 1].isAlive()) counter++;
	}

	if (col < cells[row].size() - 1)
	{
		if (cells[row][col + 1].isAlive()) counter++;
	}

	return counter;
}
