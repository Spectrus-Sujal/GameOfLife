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

		for(auto row {0}; row < 1; ++row)
		{
			for(auto col {0}; col < 1; ++col)
			{
				Point temp {0, 0, 10};
				std::cout << "Hey";
				cells[0].emplace_back(Cell::state::alive, temp);
				std::cout << "TF?!?!?!";
			}
		}

		CM = CellsManager{cells};
	}
};
