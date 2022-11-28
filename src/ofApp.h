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
		
	void initialize();
	
};
