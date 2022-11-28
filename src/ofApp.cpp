#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	initialize();
	ofSetFrameRate(1);
}

//--------------------------------------------------------------
void ofApp::update()
{
	cells = CellsManager::updateCells(cells);
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
			int sizer{ (ofGetWidth() / boardSize) };
			Point temp{ row * sizer, col * sizer, sizer };

			if(ofRandom(10) < 2) 	tempVect.emplace_back(Cell::state::alive, temp);
			else tempVect.emplace_back(Cell::state::dead, temp);
		}
		cells.emplace_back(tempVect);
	}
}



//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

