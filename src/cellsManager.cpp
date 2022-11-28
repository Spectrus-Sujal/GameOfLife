#include "cellsManager.h"

CellsManager::CellsManager(std::vector<std::vector<Cell>> &c) : cells{c}{}

void CellsManager::updateCells()
{
	
}

void CellsManager::drawCells() const
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
