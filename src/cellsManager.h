#pragma once

#include "cell.h"

/**
 * \brief A class used to contain and manage all the cells in the game
 */
namespace CellsManager
{
	/**
	 * \brief Check how many cells are alive around a particular cell
	 * \param cells 2D vector containing all cells to check
	 * \param row The Row of the cell to check
	 * \param col The Column of the cell to check 
	 * \return 
	 */
	int checkConditions(const std::vector<std::vector<Cell>>& cells, int row, int col);
	

	/**
	 * \brief Update all cells in the game and check their neighbors
	 */
	std::vector<std::vector<Cell>> updateCells(std::vector<std::vector<Cell>> &cells);

	/**
	 * \brief Draw all cells to canvas
	 */
	void drawCells(std::vector<std::vector<Cell>>& cells);
	
};
