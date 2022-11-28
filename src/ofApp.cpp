#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	initialize();
}

//--------------------------------------------------------------
void ofApp::update(){

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

	std::cout << cells.size();
	for (auto row{ 0 }; row < 10; ++row)
	{
		std::vector<Cell> tempVect;
		for (auto col{ 0 }; col < 10; ++col)
		{
			Point temp{ row * 10, col * 10, 10 };

			tempVect.emplace_back(Cell::state::alive, temp);
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

