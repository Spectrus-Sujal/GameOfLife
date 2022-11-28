#include "cell.h"

// Create the Cell Object
Cell::Cell(state s, Point i) : current{ s }, info{i} {}

void Cell::updateState(int neighbours)
{
	switch(neighbours)
	{
		case 2:
	case 3:
			if(neighbours == 3 && current == Cell::state::dead)
			{
				current = Cell::state::alive;
			}
			break;
		default:
			if(current == Cell::state::alive)
			{
				current = Cell::state::dead;
			}
			break;
	}
}

void Cell::drawCell() const
{
	if(current == Cell::state::alive) ofSetColor(0);
	else ofSetColor(255);
	ofDrawRectangle(info.x, info.y, info.size, info.size);
}


