#define SDL_MAIN_HANDLED

#include "../include/window.hpp"
#include "../include/input.hpp"
#include "../include/entity.hpp"

#include <iostream>

bool events(SDL_Event &event, Input &input);

int main(void) {

  Window window = Window("Jogo Da Velha", 600, 600);
  Input input;

  SDL_Event event;

  Entity image = Entity(window.get_renderer(), Vector2(2000.0f, 2634.0f), Vector2(0.0f, 0.0f), "assets/mario.png");
  image.scale = Vector2(0.1f, 0.1f);

  SDL_SetRenderDrawColor(window.get_renderer(), 50, 50, 50, 255);
  while (true) {
  
    if (!events(event, input)) return false; 
    if (input.getKeyPressed(SDL_SCANCODE_ESCAPE) == true) return true;

    window.clear();
    window.render(&image);
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