#include "Game.h"

//Private functions
void Game::initVariables()
{
	this->window = nullptr;

	//Color
	this->allColor = Color::Color(65, 255, 0);

	//Game logic
	this->endGame = false;
}

void Game::initWindow() {
	this->videoMode.height = 1080;
	this->videoMode.width = 1920;

	this->window = new RenderWindow(this->videoMode, "Battleship", Style::Fullscreen);

	this->window->setFramerateLimit(60);
}

void Game::initVisualGrid() {
	gridLines = VertexArray(Lines, 44);

	//Amount of lines
	numHLines = 11;
	numVLines = 11;

	cellSize = 10.0f;

	//Coords
	baseX = 0;
	baseY = 0;
	endX = 0;
	endY = 0;

	//Constants for horizontal lines
	baseX = 80.0f;
	endX = 180.0f;

	//Changed variables in horizontal loop
	baseY = 80.0f;
	endY = 80.0f;

	//Horizontal lines
	for (int i = 0; i < 11; i++) {
		gridLines[i].position = Vector2f(baseX, baseY);
		gridLines[i + 1].position = Vector2f(endX, endY);

		baseY += cellSize;
		endY += cellSize;
	} 
}

void Game::initLogicGrid() {
	//Enum declares grid status
	GridStatus empty = GridStatus::empty;
	GridStatus ship = GridStatus::ship;
	GridStatus miss = GridStatus::miss;
	GridStatus hit = GridStatus::hit;

	for (int i = 0; i < rowLogicSize; i++) {
		for (int j = 0; j < colLogicSize; j++) {
			this->playerBoard[i][j] = empty;
			this->lastPlayerBoard[i][j] = empty;
			this->AIBoard[i][j] = empty;
			this->lastAIBoard[i][j] = empty;
		}
	}
}

//Constructors / Destructors
Game::Game() {
	this->initVariables();
	this->initWindow();
	this->initLogicGrid();
	this->initVisualGrid();
}

Game::~Game() {
	delete this->window;
}

//Accessors
const bool Game::running() const
{
	return this->window->isOpen();
}

const bool Game::getEndGame() const
{
	return this->endGame;
}

//Functions
void Game::pollEvents()
{
	//Event polling
	while (this->window->pollEvent(this->event))
	{
		switch (this->event.type)
		{
		case Event::Closed:
			this->window->close();
			break;
		case Event::KeyPressed:
			if (this->event.key.code == Keyboard::Escape)
				this->window->close();
			break;
		}
	}
}

void Game::update()
{
	this->pollEvents();

	if (this->endGame == false)
	{
		
	}

	//End game condition
	
}

void Game::render()
{
	/**
		@return void
		- clear old frame
		- render objects
		- display frame in window
		Renders the game objects.
	*/

	this->window->clear();

	//Draw game objects
	this->window->draw(gridLines);

	this->window->display();
}

