#pragma once
 
#include <iostream>
#include <sstream>
#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

using namespace sf;
using namespace std;

const int columns = 10;
const int rows = 10;

//Class that acts as the game engine (Wrapper class)

class Game {
	private:
		//Window
		RenderWindow* window;
		VideoMode videoMode;
		Event event;

		//Mouse positions
		Vector2i mousePosWindow;

		//Resources
		Font font;
		Color allColor;

		//Text 
		Text uiText;

		//Game variables
		bool endGame;

		//Grid variables
		VertexArray grid;
		float rowH;
		float colW;

		//Private functions
		void initVariables();
		void initWindow();
		void initFonts();
		void initGrid();
		void initText();
	public:
		//Constructors / Destructors
		Game();
		virtual ~Game();

		//Accessors
		const bool running() const;
		const bool getEndGame() const;

		//Functions
		void spawnEnemy();
		void drawGrid(RenderTarget& target) const;

		void pollEvents();
		void updateText();
		void updateEnemies();
		void update();

		void renderText(sf::RenderTarget& target);
		void renderEnemies(sf::RenderTarget& target);
		void render();
};

