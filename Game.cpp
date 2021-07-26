#include "Game.h"

char Game::lastPlayerBoard[rowLogicSize][colLogicSize];
char Game::lastAIBoard[rowLogicSize][colLogicSize];

//Private functions
void Game::initVariables()
{
	this->window = nullptr;

	//Color
	this->allColor = Color::Color(65, 255, 0);

	//Game logic
	this->endGame = false;

	//Init static arrays
	for (int i = 0; i < rowLogicSize; i++) {
		for (int j = 0; j < colLogicSize; j++) {
			lastPlayerBoard[i][j] = 0;
			lastAIBoard[i][j] = 0;
		}
	}
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
	endX = 710.0f;

	//Changed variables in horizontal loop
	baseY = 80.0f;
	endY = 80.0f;

	//Horizontal lines
	for (int i = 0; i < 11; i++) {
		gridLines[i].position = Vector2f(baseX, baseY);
		gridLines[i + 1].position = Vector2f(endX, endY);

		baseY += 10.0f;
		endY += 10.0f;
	} 

	//Constants for vertical lines
	baseY = 80.0f;
	endY = 710.0f;

	//Changed variables in vertical loop
	baseX = 80.0f;
	endX = 80.0f;

	//Vertical lines
	for (int i = 12; i < 22; i++) {
		gridLines[i].position = Vector2f(baseX, baseY);
		gridLines[i + 1].position = Vector2f(endX, endY);

		baseX += 10;
		endX += 10;
	}
}

void Game::initLogicGrid() {
	//Enum declares grid status
	GridStatus empty = GridStatus::nothing;
	GridStatus ship = GridStatus::filled;
	GridStatus miss = GridStatus::wrong;
	GridStatus hit = GridStatus::hurt;


	for (int i = 0; i < rowLogicSize; i++) {
		for (int j = 0; j < colLogicSize; j++) {
			this->playerBoard[i][j] = empty;
			lastPlayerBoard[i][j] = empty;
			this->AIBoard[i][j] = empty;
			lastAIBoard[i][j] = empty;
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
