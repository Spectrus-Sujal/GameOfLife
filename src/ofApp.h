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

		void keyPressed(int key);
		void keyReleased(int key);
		void mousePressed(int x, int y, int button);

		ofxPanel gui;
		ofxButton resetGameEmpty;
		ofxButton resetGameRandom;
		ofxSlider<int> genSpeed;

	// Size of the game area
	int boardSize{80};
	const int size{ (ofGetHeight() / boardSize) };

	// Game is not updating
	bool isPaused{ true };

	// The current generation number
	int generationNumber{ 1 };

	// 2D Vector if all cells in the game
	std::vector<std::vector<Cell>> cells {};

	// Start the game off with all cells as dead
	void initialize();
	// Start the game with a random number of cells alive
	void initializeRandom();

	// Update components of the game
	void updateGame();
	//Draw components of game to canvas
	void drawGame();
	
};
