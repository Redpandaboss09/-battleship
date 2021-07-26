#pragma once

#include <iostream>
#include <array>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

using namespace std;
using namespace sf;

//Class that acts as the game engine.

//Global variables
const unsigned int rowLogicSize = 10;
const unsigned int colLogicSize = 10;

class Game {
	private:
		//Window
		RenderWindow* window;
		VideoMode videoMode;
		Event event;
	
		//Color
		Color allColor;

		//Game logic
		bool endGame;

		//Logic grid variables
		unsigned char playerBoard[rowLogicSize][colLogicSize];
		static char lastPlayerBoard[rowLogicSize][colLogicSize];
		unsigned char AIBoard[rowLogicSize][colLogicSize];
		static char lastAIBoard[rowLogicSize][colLogicSize];

		//Visual grid variables
		VertexArray gridLines;
		float cellSize;
		float baseX, baseY;
		float endX, endY;
		int numHLines;
		int numVLines;
	
		//Private functions
		void initVariables();
		void initWindow();
		void initVisualGrid();
		void initLogicGrid();

		//Grid status 
		enum GridStatus {
			nothing, filled, wrong, hurt
		};

	public:
		//Constructors / Destructors
		Game();
		virtual ~Game();

		//Accessors
		const bool running() const;
		const bool getEndGame() const;

		void pollEvents();
		void update();

		void render();
};
