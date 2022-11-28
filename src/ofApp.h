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
		void mousePressed(int x, int y, int button);

	int boardSize{100};

	bool isPaused{ true };
	bool gameStarted{ false };

	std::vector<std::vector<Cell>> cells {};
		
	void initialize();
	void initializeRandom();
	
};
