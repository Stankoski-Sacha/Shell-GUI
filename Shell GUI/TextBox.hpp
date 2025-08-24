#pragma once
#include "pch.hpp"

class TextBox {
private:
	// Size and position
	int w, h, x, y;

	// How to place on screen
	SDL_Window* window;
	SDL_Renderer* renderer;

	// Style on screen
	SDL_Color backgroundColor;
	SDL_Color fontColor;

	// Text for the box
	std::string Text;

public:
	TextBox(int w, int h, int x, int y, 
		SDL_Window* window, SDL_Renderer* renderer, 
		SDL_Color background, SDL_Color font, 
		std::string text
	);

	void placeOnScreen();

	void handleEverything();

	std::string getText();
};