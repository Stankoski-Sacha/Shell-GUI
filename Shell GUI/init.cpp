#include "pch.hpp"
#include "init.hpp"

void init() {
	if (!SDL_Init(SDL_INIT_EVERYTHING)) {
		std::cerr << "Error SDLINIT : " << SDL_GetError() << std::endl;
		SDL_Quit();
		exit(1);
	}

	if (TTF_Init() == -1) {
		std::cerr << "Error TTFINIT : " << TTF_GetError() << std::endl;
		SDL_Quit();
		TTF_Quit();
		exit(1);
	}

	if (!IMG_Init(IMG_INIT_PNG)) {
		std::cerr << "Error loading IMGPNG : " << IMG_GetError() << std::endl;
		SDL_Quit();
		TTF_Quit();
		IMG_Quit();
		exit(1);
	}
}

SDL_Window* createWindow(std::string title, int w, int h) {
	return SDL_CreateWindow(
		title.c_str(), 
		SDL_WINDOWPOS_CENTERED, 
		SDL_WINDOWPOS_CENTERED, 
		w, h, 
		SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE
	);
}

SDL_Renderer* createRenderer(SDL_Window* win) {
	return SDL_CreateRenderer(
		win, -1, 
		SDL_RENDERER_ACCELERATED
	);
}

TTF_Font* openFont(std::string font, int size) {
    TTF_Font* fontPtr = TTF_OpenFont(font.c_str(), size);
    if (fontPtr == nullptr) {
        std::cerr << "Error opening font: " << TTF_GetError() << std::endl;
    }

    return fontPtr;
}