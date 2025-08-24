#include "pch.hpp"
#include "TextBox.hpp"

TextBox::TextBox(int w, int h, int x, int y,
	SDL_Window* window, SDL_Renderer* renderer,
	SDL_Color background, SDL_Color font,
	std::string text) :
	w(w), h(h), x(x), y(y),
	window(window), renderer(renderer),
	backgroundColor(background), fontColor(font), Text(text) {
}

void TextBox::placeOnScreen() {

}

void TextBox::handleEverything() {

}

std::string TextBox::getText() {
	return Text;
}