#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	initialize();
	ofSetFrameRate(1);
}

//--------------------------------------------------------------
void ofApp::update()
{
	if(!isPaused) cells = CellsManager::updateCells(cells);
}

//--------------------------------------------------------------
void ofApp::draw()
{
	ofBackground(255);
	CellsManager::drawCells(cells);
}

void ofApp::initialize()
{
	cells.clear();

	for (auto row{ 0 }; row < boardSize; ++row)
	{
		std::vector<Cell> tempVect;
		for (auto col{ 0 }; col < boardSize; ++col)
		{
			const int sizer{ (ofGetWidth() / boardSize) };
			const Point temp{ row * sizer, col * sizer, sizer };
			
			tempVect.emplace_back(Cell::state::dead, temp);
		}

		cells.emplace_back(tempVect);
	}
}


void ofApp::initializeRandom()
{
	cells.clear();
	
	for (auto row{ 0 }; row < boardSize; ++row)
	{
		std::vector<Cell> tempVect;
		for (auto col{ 0 }; col < boardSize; ++col)
		{
			const int sizer{ (ofGetWidth() / boardSize) };
			const Point temp{ row * sizer, col * sizer, sizer };

			if(ofRandom(10) < 2) 	tempVect.emplace_back(Cell::state::alive, temp);
			else tempVect.emplace_back(Cell::state::dead, temp);
		}
		cells.emplace_back(tempVect);
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

	if(key == ' ')
	{
		isPaused = !isPaused;
		gameStarted = !gameStarted;
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

void ofApp::mousePressed(int x, int y, int button)
{
	bool breaker{ false };
	if (!gameStarted)
	{
		for (auto row{ 0 }; row < boardSize; ++row)
		{
			for (auto col{ 0 }; col < boardSize; ++col)
			{
				if (breaker) break;
				const int sizer{ (ofGetWidth() / boardSize) };
				const Point temp{ row * sizer, col * sizer, sizer };

				if (x < (row * sizer) + sizer && y < (col * sizer) + sizer)
				{
					if(cells[row][col].isAlive()) cells[row][col] = Cell{ Cell::state::dead, temp };
					else cells[row][col] = Cell{ Cell::state::alive, temp };
					
					breaker = true;
				}
			}
			if (breaker) break;
		}
	}
}
