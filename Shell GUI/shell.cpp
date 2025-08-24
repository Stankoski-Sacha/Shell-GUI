#include "pch.hpp"
#include "HandleInput.hpp"
#include "TextBox.hpp"
#include "init.hpp"

// For GUI (not now)
void shell(SDL_Window* window, SDL_Renderer* renderer) {
	SDL_Event e;
	bool running = true;

	while (running) {
		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT) {
				running = false;
			}
		}

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
		SDL_RenderClear(renderer);

		getWinSize(window);

		SDL_RenderPresent(renderer);

		// ~60fps limit
		SDL_Delay(16);
	}
}