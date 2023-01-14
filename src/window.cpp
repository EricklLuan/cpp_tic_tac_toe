#include "../include/window.hpp"

#include <iostream>

Window::Window(const char* title, int width, int height) {

  if (SDL_Init(SDL_INIT_VIDEO) != 0) { 
    std::cout << "SDL::INIT::ERROR: " << SDL_GetError() << "\n";
  }

  _window = SDL_CreateWindow(
    title, 
    SDL_WINDOWPOS_CENTERED, 
    SDL_WINDOWPOS_CENTERED, 
    width, 
    height, 
    SDL_WINDOW_OPENGL
  );

  if (_window == NULL) {
    std::cout << "SDL::CREATE::WINDOW::ERROR: " << SDL_GetError() << "\n";
  }

  _renderer = SDL_CreateRenderer(
    _window,
    -1,
    SDL_RENDERER_PRESENTVSYNC
  );

  if (_renderer == NULL) {
    std::cout << "SDL::CREATE::RENDERER::ERROR: " << SDL_GetError() << "\n";
  }
}

Window::~Window() {
  SDL_DestroyWindow(_window);
  SDL_Quit();
}