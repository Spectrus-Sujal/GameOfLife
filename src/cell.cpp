#include "cell.h"

// Create the Cell Object
Cell::Cell(state s, Point i) : current{ s }, info{i} {}

void Cell::updateState(int neighbours)
{
	// Change state based on neighbours
	switch(neighbours)
	{
		case 2:
		case 3:
			// Check if the Cell is coming alive
			if(neighbours == 3 && current == Cell::state::dead)
			{
				current = Cell::state::alive;
			}
			break;
		default:
			// Make the cell Die
			current = Cell::state::dead;
			break;
	}
}

void Cell::drawCell() const
{
	// Change color based on current state
	if(current == Cell::state::alive) ofSetColor(0);
	else ofSetColor(255);
	ofDrawRectangle(info.x, info.y, info.size, info.size);
}

bool Cell::isAlive() const
{
	return current == state::alive;
}

