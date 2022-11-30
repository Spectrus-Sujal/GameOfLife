#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	// Setup the GUI
	gui.setup();
	// Add the Board Size
	gui.add(boardSize.setup("Board Size", 40, 10, 80));
	// Add the Empty board
	gui.add(resetGameEmpty.setup("Restart Game (Empty)"));
	// Add the Random board
	gui.add(resetGameRandom.setup("Restart Game (Random)"));
	// Add the chances of a cell to be alive in random board
	gui.add(chanceToBeAlive.setup("Alive Chances", 1, 0.1, 10));
	// Speed the generations change
	gui.add(genSpeed.setup("Generation Speed", 3, 1, 5));

	// Create the game board
	resetGameEmpty.addListener(this, &ofApp::initialize);
	resetGameRandom.addListener(this, &ofApp::initializeRandom);
	
	// Make the game 60fps
	ofSetFrameRate(60);
}

//--------------------------------------------------------------
void ofApp::update()
{
	// Update every second based on genSpeed
	if (ofGetFrameNum() % (60 / genSpeed) == 0 && !isPaused) updateGame();

	gui.setPosition(800, 0);
}

//--------------------------------------------------------------
void ofApp::draw()
{
	drawGame();
	gui.draw();
}

void ofApp::updateGame()
{
	// Start the new generation
	cells = CellsManager::updateCells(cells);
	generationNumber++;
}


void ofApp::drawGame()
{
	// Erase the last generation
	ofBackground(50);

	// Draw the new generation
	CellsManager::drawCells(cells);

	// SHow generation number
	ofSetColor(255);
	ofDrawBitmapString("Generation Number: " + std::to_string(generationNumber), 800, 200);
	ofDrawBitmapString("Black Pixels: Dead", 800, 250);
	ofDrawBitmapString("White Pixels: Alive", 800, 270);
}

void ofApp::initialize()
{
	// Remove the last game board
	cells.clear();

	size = ofGetHeight() / boardSize;
	isPaused = true;

	// Go through every cell
	for (auto row{ 0 }; row < boardSize; ++row)
	{
		// Create a new Cell vector
		std::vector<Cell> tempVect;
		for (auto col{ 0 }; col < boardSize; ++col)
		{
			// Assign the cells to the temp vectordd
			const Point temp{ row * size, col * size, size };
			
			tempVect.emplace_back(Cell::state::dead, temp);
		}
		// Add the temp vector to cells
		cells.emplace_back(tempVect);
	}

	// Reset the generation number
	generationNumber = 1;
}


void ofApp::initializeRandom()
{
	cells.clear();

	size = ofGetHeight() / boardSize;
	isPaused = true;
	
	for (auto row{ 0 }; row < boardSize; ++row)
	{
		std::vector<Cell> tempVect;
		for (auto col{ 0 }; col < boardSize; ++col)
		{
			const Point temp{ row * size, col * size, size };

			// Check if the cell is alive or dead, based on chance to be alive
			if(ofRandom(10) < chanceToBeAlive) 	
			{	 tempVect.emplace_back(Cell::state::alive, temp);		}
			else tempVect.emplace_back(Cell::state::dead, temp);
		}
		cells.emplace_back(tempVect);
	}

	generationNumber = 1;
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

	// Check for space bar  // Invert isPaused 
	if(key == ' ') isPaused = !isPaused;


	if(isPaused && (key == 'n' || key == 'N')) updateGame();
	
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

void ofApp::mousePressed(int x, int y, int button)
{
	// Check if the game is paused
	// if so then check where the mouse was pressed
	for (auto row{ 0 }; isPaused && row < boardSize; ++row)
	{
		// Bool to break out of the loop
		bool breaker{ false };

		for (auto col{ 0 }; col < boardSize; ++col)
		{
			// Get the size and position of current cell
			const Point temp{ row * size, col * size, size };

			// Check if mouse is at current cell
			if (x < (row * size) + size && y < (col * size) + size)
			{
				// toggle cell state
				if ( cells[row][col].isAlive())
				{	 cells[row][col] = Cell{ Cell::state::dead, temp };	}
				else cells[row][col] = Cell{ Cell::state::alive, temp };

				// Stop the loop
				breaker = true;
				break;
			}
		}
		// Break out of outer loop
		if (breaker) break;
	}
}
