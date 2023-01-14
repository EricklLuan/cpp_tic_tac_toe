#define SDL_MAIN_HANDLED

#include "../include/window.hpp"

int main(void) {

  Window window = Window("Jogo Da Velha", 600, 600);

  SDL_Event event;

  while (true) {
    if (SDL_PollEvent(&event)) {
      switch (event.type) {
      case SDL_QUIT:
        return false;
        break;

      case SDL_KEYDOWN:
        if (event.key.keysym.scancode == SDL_SCANCODE_ESCAPE) return false;
        break;

      default:
        break;
      }
    }

    window.clear();

    SDL_SetRenderDrawColor(window.get_renderer(), 100, 100, 100, 255);

    window.flip();
  }

  return 0;
}