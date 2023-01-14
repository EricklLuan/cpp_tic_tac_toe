#define SDL_MAIN_HANDLED

#include <iostream>
#include <SDL2/SDL.h>

int main(void) {

  if (SDL_Init(SDL_INIT_VIDEO) != 0) { 
    std::cout << "SDL::INIT::ERROR: " << SDL_GetError() << "\n";
    return 1;
  }

  SDL_Window* window = SDL_CreateWindow(
    "Jogo da Velha", 
    SDL_WINDOWPOS_CENTERED, 
    SDL_WINDOWPOS_CENTERED, 
    600, 
    600, 
    SDL_WINDOW_OPENGL
  );

  if (window == NULL) {
    std::cout << "SDL::CREATE::WINDOW::ERROR: " << SDL_GetError() << "\n";
    return 1;
  }

  SDL_Renderer* renderer = SDL_CreateRenderer(
    window,
    -1,
    SDL_RENDERER_PRESENTVSYNC
  );

  if (renderer == NULL) {
    std::cout << "SDL::CREATE::RENDERER::ERROR: " << SDL_GetError() << "\n";
    return 1;
  }

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

    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 100, 100, 100, 255);
    SDL_RenderPresent(renderer);
  }

  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(renderer);
  SDL_Quit();
  return 0;
}