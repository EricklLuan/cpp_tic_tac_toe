#define SDL_MAIN_HANDLED

#include "../include/window.hpp"
#include "../include/input.hpp"
#include "../include/entity.hpp"

#include <iostream>

bool events(SDL_Event &event, Input &input);

int main(void) {

  Window window = Window("Jogo Da Velha", 600, 600);
  Input input;

  Entity rect = Entity(
    window.get_renderer(), 
    Vector2(64.0f, 64.0f), 
    Vector2(0.0f, 0.0f), 
    Vector3(125.0f, 125.0f, 125.0f), 
    ""
  );

  SDL_Event event;

  while (true) {
  
    if (!events(event, input)) return false; 
    if (input.getKeyPressed(SDL_SCANCODE_ESCAPE) == true) return true;

    if (rect.checkIfCollideWith(input.getMouseCollision())) {
      if (input.getMousePressed(SDL_BUTTON_LEFT)) {
        std::cout << "Collide" << "\n";
      }
    }

    window.clear();
    window.render(&rect);
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
      input.getMouseCollision()->x = input.mouse.x;
      input.getMouseCollision()->y = input.mouse.y;
      break;
    }
  }

  return true;
}