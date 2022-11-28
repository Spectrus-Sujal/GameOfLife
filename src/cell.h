#pragma once

#include "point.h"
#include "ofGraphics.h"

/**
 * \brief A class used to dictate the behaviour of a cell based on the things around it
 */
class Cell
{
public:

	enum class state {alive, dead};

private:
	/**
	 * \brief The two states the cell can be
	 */
	

	/**
	 * \brief The current state of the cell
	 */
	state current;

	Point info;

public:

	Cell(state s, Point i);

	/**
	 * \brief Change the state of the cell based number of surrounding cells
	 * \param neighbours Number of cells around this cell
	 */
	void updateState(int neighbours);

	/**
	 * \brief Draw the cell to canvas
	 */
	void drawCell() const;

	bool isAlive() const;

};
