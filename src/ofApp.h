#pragma once

#include "ofMain.h"
#include "point.h"
#include "cell.h"
#include "cellsManager.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);

	Cell tempi {Cell::state::alive, {0, 0, 10}};

	std::vector<std::vector<Cell>> cells {{tempi}};

	CellsManager CM{cells};
		
	void initialize()
	{
		cells.clear();

		std::cout << cells.size();
		for(auto row {0}; row < 4; ++row)
		{
			std::vector<Cell> tempVect;
			for(auto col {0}; col < 6; ++col)
			{
				Point temp {row * 4, col * 6, 10};

				tempVect.emplace_back(Cell::state::alive, temp);
			}
			cells.emplace_back(tempVect);
		}

		CM = CellsManager{cells};
	}
};
