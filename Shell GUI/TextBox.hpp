#pragma once
#include "pch.hpp"

class TextBox {
private:
	int w, h, x, y;
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Color backgroundColor;
	SDL_Color fontColor;
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