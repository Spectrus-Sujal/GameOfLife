#pragma once

#include "cell.h"

/**
 * \brief A class used to contain and manage all the cells in the game
 */
class CellsManager
{
private:
	/**
	 * \brief Vector containing all cells
	 */
	std::vector<std::vector<Cell>> cells;
	

public:
	/**
	 * \brief Constructor for CellsManager
	 * \param c Vector of cells
	 */
	CellsManager(std::vector<std::vector<Cell>> &c);

	/**
	 * \brief Update all cells in the game and check their neighbors
	 */
	void updateCells();

	/**
	 * \brief Draw all cells to canvas
	 */
	void drawCells() const;
	
};
