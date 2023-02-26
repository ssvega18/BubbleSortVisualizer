#pragma once

#include <iostream>
#include <vector>
#include <cmath>
#include <string>

#define NOMINMAX
#include <Windows.h>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class Visualizer 
{

	public:
		// Variables
		sf::RenderWindow* window;
		sf::VideoMode videoMode;
		sf::Event ev;

		sf::Font font;
		sf::Text text;
		sf::Text text2;

		std::vector<int> array;
		std::vector<int> copyArr;

		int currIndex = 0;
		int comparisonCount = 0;
		int currAccess = 0;

		// Constructor
		Visualizer();
		virtual ~Visualizer();

		// Getters
		const bool running() const;

		// general functions
		void pollEvents();

		//void updateDT();
		void update();
		void render();
	

	private:
		// Utility functions 
		void initVariables();
		void initWindow();
		void initEntities();
		void sortArray();
		void initText();
		void reset();
		void updateText(unsigned int number, sf::Text* text);






};
