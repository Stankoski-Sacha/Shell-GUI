#include "pch.hpp"
#include "init.hpp"

int main(int argc, char** argv) {

	SDL_Window* win = createWindow("Shell", 400, 400);
	SDL_Renderer* renderer = createRenderer(win);
	SDL_Event e;
	bool running = true;

	while (running) {
		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT) {
				running = false;
			}

			SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
			SDL_RenderClear(renderer);

			SDL_RenderPresent(renderer);
		}
	}

	SDL_DestroyWindow(win);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	TTF_Quit();
	IMG_Quit();

	return 0;
}