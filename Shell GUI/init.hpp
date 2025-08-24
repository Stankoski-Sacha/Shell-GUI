#pragma once

void init();
SDL_Window* createWindow(std::string title, int w, int h);
SDL_Renderer* createRenderer(SDL_Window* win);
TTF_Font* openFont(std::string font, int size);
