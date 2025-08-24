#ifndef PCH_HPP
#define PCH_HPP

//SDL Imports
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>

//Regular C++
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <functional>
#include <stdexcept>
#include <memory>

//Window size updater
extern int WINW;
extern int WINH;

inline void getWinSize(SDL_Window* window) {
	SDL_GetWindowSize(window, &WINW, &WINH);
}

#endif