#define SDL_MAIN_HANDLED

#include "../include/window.hpp"
#include "../include/input.hpp"

#include <iostream>

bool events(SDL_Event &event, Input &input);

int main(void) {

  Window window = Window("Jogo Da Velha", 600, 600);
  Input input;

  SDL_Event event;

  while (true) {
  
    if (!events(event, input)) return false; 

    if (input.getKeyPressed(SDL_SCANCODE_ESCAPE) == true) return true;
    if (input.getMouseHeld(SDL_BUTTON_LEFT) == true)
    std::cout << input.mouse.x << ", " << input.mouse.y << "\n";

    window.clear();
    SDL_SetRenderDrawColor(window.get_renderer(), 100, 100, 100, 255);
    window.flip();
  }

  return 0;
}

bool events(SDL_Event &event, Input &input) {
  input.new_frame();

  if (SDL_PollEvent(&event)) {
    switch (event.type) {
    case SDL_QUIT:
      return false;
      break;

    case SDL_KEYDOWN:
      if (event.key.repeat == 0) input.key_down_event(&event);
      break;

    case SDL_KEYUP:
      input.key_up_event(&event);
      break;
    
    case SDL_MOUSEBUTTONUP:
      input.mouse_key_up_event(&event);
      break;

    case SDL_MOUSEBUTTONDOWN:
      input.mouse_key_down_event(&event);
      break;

    default:
      input.mouse = event.button;
      break;
    }
  }

  return true;
}