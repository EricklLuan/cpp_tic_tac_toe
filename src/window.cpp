#include "../include/window.hpp"
#include "../include/entity.hpp"

#include <SDL2/SDL_image.h>
#include <iostream>

Window::Window(const char* title, int width, int height) {

  if (SDL_Init(SDL_INIT_VIDEO) != 0) { 
    std::cout << "SDL::INIT::ERROR: " << SDL_GetError() << "\n";
  }

  if (!IMG_Init(IMG_INIT_PNG) ) {
    std::cout << "SDL::IMG::INIT::ERROR: " << IMG_GetError() << "\n";
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
  IMG_Quit();
  SDL_DestroyWindow(_window);
  SDL_Quit();
}

void Window::render(Entity *entity) {
  SDL_Rect source;
  source.x = entity->getCurrentFrame().x;
  source.y = entity->getCurrentFrame().y;
  source.w = entity->getCurrentFrame().w;
  source.h = entity->getCurrentFrame().h;

  SDL_Rect destination;
  destination.x = entity->position.x;
  destination.y = entity->position.y;
  destination.w = entity->getSize().x * entity->scale.x;
  destination.h = entity->getSize().y * entity->scale.y;

  SDL_RenderCopy(_renderer, entity->getTexture(), &source, &destination);
}