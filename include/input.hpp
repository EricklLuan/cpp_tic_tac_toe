#pragma once

#include <SDL2/SDL.h>
#include <map>

class Input {
private:
  std::map<SDL_Scancode, bool> _pressed;
  std::map<SDL_Scancode, bool> _held;
  std::map<SDL_Scancode, bool> _relesead;

  std::map<Uint8, bool> _mousePressed;
  std::map<Uint8, bool> _mouseHeld;
  std::map<Uint8, bool> _mouseRelesead;

public:
  SDL_MouseButtonEvent mouse;

  void new_frame();

  void key_down_event(SDL_Event *event);
  void key_up_event(SDL_Event *event);

  void mouse_key_down_event(SDL_Event *event);
  void mouse_key_up_event(SDL_Event *event);

  bool getKeyRelesead(SDL_Scancode key);
  bool getKeyPressed(SDL_Scancode key);
  bool getKeyHeld(SDL_Scancode key);

  bool getMouseRelesead(Uint8 mouseButton);
  bool getMousePressed(Uint8 mouseButton);
  bool getMouseHeld(Uint8 mouseButton);

};
