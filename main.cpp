#define SDL_MAIN_HANDLED

#include "../include/window.hpp"
#include "../include/input.hpp"
#include "../include/entity.hpp"
#include "../include/draw.hpp"

#include <iostream>

bool events(SDL_Event &event, Input &input);

int main(void) {

  Window window = Window("Jogo Da Velha", 600, 600);
  Input input;
  Draw draw;

  std::vector<Entity> entities = {
    Entity(window.get_renderer(), Vector2(200.0f, 200.0f), Vector2(0.0f, 0.0f), Vector4(255.0f, 255.0f, 255.0f, 255.0f), ""),
    Entity(window.get_renderer(), Vector2(200.0f, 200.0f), Vector2(200.0f, 0.0f), Vector4(255.0f, 255.0f, 255.0f, 255.0f), ""),
    Entity(window.get_renderer(), Vector2(200.0f, 200.0f), Vector2(400.0f, 0.0f), Vector4(255.0f, 255.0f, 255.0f, 255.0f), ""),
    Entity(window.get_renderer(), Vector2(200.0f, 200.0f), Vector2(0.0f, 200.0f), Vector4(255.0f, 255.0f, 255.0f, 255.0f), ""),
    Entity(window.get_renderer(), Vector2(200.0f, 200.0f), Vector2(200.0f, 200.0f), Vector4(255.0f, 255.0f, 255.0f, 255.0f), ""),
    Entity(window.get_renderer(), Vector2(200.0f, 200.0f), Vector2(400.0f, 200.0f), Vector4(255.0f, 255.0f, 255.0f, 255.0f), ""),
    Entity(window.get_renderer(), Vector2(200.0f, 200.0f), Vector2(0.0f, 400.0f), Vector4(255.0f, 255.0f, 255.0f, 255.0f), ""),
    Entity(window.get_renderer(), Vector2(200.0f, 200.0f), Vector2(200.0f, 400.0f), Vector4(255.0f, 255.0f, 255.0f, 255.0f), ""),
    Entity(window.get_renderer(), Vector2(200.0f, 200.0f), Vector2(400.0f, 400.0f), Vector4(255.0f, 255.0f, 255.0f, 255.0f), ""),
  };

  SDL_Event event;

  int player = 0;

  while (true) {
  
    if (!events(event, input)) return false; 
    if (input.getKeyPressed(SDL_SCANCODE_ESCAPE) == true) return true;

    for (int i = 0; i < entities.size(); i++) {
      if(entities[i].checkIfCollideWith(input.getMouseCollision())) {
        if (input.getMousePressed(SDL_BUTTON_LEFT)) {
          if (player == 0) {
            entities[i].setTexture(window.get_renderer(), "assets/o.png");
            player = 1;
          } else if (player == 1) {
            entities[i].setTexture(window.get_renderer(), "assets/x.png");
            player = 0;
          }
        }
      }
    }
    
    window.clear();
    
    SDL_SetRenderDrawColor(window.get_renderer(), 255, 255, 255, 255);

    window.render(&entities);

    draw.line(window.get_renderer(), Vector2(200, 0), Vector2(200, 600), Vector4(0, 0, 0, 255));
    draw.line(window.get_renderer(), Vector2(400, 0), Vector2(400, 600), Vector4(0, 0, 0, 255));
    draw.line(window.get_renderer(), Vector2(0, 200), Vector2(600, 200), Vector4(0, 0, 0, 255));
    draw.line(window.get_renderer(), Vector2(0, 400), Vector2(600, 400), Vector4(0, 0, 0, 255));

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