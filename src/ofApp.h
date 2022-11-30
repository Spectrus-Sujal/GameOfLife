#pragma once

#include "ofMain.h"
#include "point.h"
#include "cell.h"
#include "cellsManager.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		
		void mousePressed(int x, int y, int button);

		// Start the game off with all cells as dead
		void initialize();
		// Start the game with a random number of cells alive
		void initializeRandom();

		// Pause the game
		void changeIsPaused();

		ofxPanel gui;
		ofxSlider<int> boardSize;
		ofxButton resetGameEmpty;
		ofxButton resetGameRandom;
		ofxSlider<double> chanceToBeAlive;
		ofxSlider<int> genSpeed;
		ofxToggle isPaused;
		ofxButton nextGeneration;

	// Size of the game area
	int size{ (ofGetHeight() / boardSize) };

	// The current generation number
	int generationNumber{ 1 };

	// 2D Vector if all cells in the game
	std::vector<std::vector<Cell>> cells {};

	

	// Update components of the game
	void updateGame();
	//Draw components of game to canvas
	void drawGame();
	
};
