#include "Game.h"

void Game::initVariables() {
	this->window = nullptr;

	bool endGame = false;

	//Color for all objects
	this->allColor = Color::Color(65, 255, 0);
}

void Game::initWindow() {
	this->videoMode = VideoMode::getDesktopMode();

	this->window = new RenderWindow(this->videoMode, "Battleship", Style::Fullscreen);

	this->window->setFramerateLimit(60);
}

void Game::initFonts() {
	if (!this->font.loadFromFile("Assets/amstrad-cpc-correct.ttf"))
	{
		std::cout << "ERROR::GAME::INITFONTS::Failed to load font!" << "\n";
	}

}

void Game::initGrid() {
	//Initialize Values
	int numLines = rows + columns - 2;
	this->grid = VertexArray(Lines, 2 * (numLines));
	this->window->setView(this->window->getDefaultView());
	auto size = this->window->getView().getSize();
	this->rowH = size.y / rows;
	this->colW = size.x / columns;

	//Row separators
	for (int i = 0; i < rows - 1; i++) {
		int r = i + 1;
		float rowY = rowH * r;
		this->grid[i * 2].position = { 0, rowY };
		this->grid[i * 2 + 1].position = { size.x, rowY };
	}

	// column separators
	for (int i = rows - 1; i < numLines; i++) {
		int c = i - rows + 2;
		float colX = colW * c;
		this->grid[i * 2].position = { colX, 0 };
		this->grid[i * 2 + 1].position = { colX, size.y };
	}
}

void Game::initText() {
	this->uiText.setFont(this->font);
	this->uiText.setFillColor(allColor);
	this->uiText.setCharacterSize(65);
	this->uiText.setString("NONE");
}

Game::Game() {
	this->initVariables();
	this->initWindow();
	this->initFonts();
	this->initText();
}

Game::~Game() {
	delete this->window;
}

const bool Game::running() const {
	return this->window->isOpen();
}

const bool Game::getEndGame() const {
	return this->endGame;
}

void Game::spawnEnemy() {

}

void Game::pollEvents() {
	//Event polling
	while (this->window->pollEvent(this->event)) {
		switch (this->event.type) {
			case Event::Closed:
				this->window->close();
				break;
			case Event::KeyPressed:
				if (this->event.key.code == sf::Keyboard::Escape) {
					this->window->close();
				}
				break;
		}
	}
}

void Game::updateText() {
	/*
	stringstream ss;

	ss << "HELLO" << "\n";

	this->uiText.setString(ss.str());
	*/
}

void Game::updateEnemies() {

}

void Game::drawGrid(RenderTarget& target) const {
	target.draw(this->grid);
}

void Game::update() {
	this->pollEvents();

	if (this->endGame == false) {
		this->updateText();

		this->updateEnemies();
	}
}

void Game::renderText(RenderTarget& target) {
	target.draw(this->uiText);
}

void Game::renderEnemies(sf::RenderTarget& target) {

}

void Game::render() {
	/**
		@return void
		- clear old frame
		- render objects
		- display frame in window
		Renders the game objects.
	*/

	this->window->clear();

	//Draw game objects
	this->drawGrid(*this->window);
	//Draw UI elements
	//this->renderText(*this->window);

	this->window->display();
}


