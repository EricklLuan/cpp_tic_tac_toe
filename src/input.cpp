#include "../include/input.hpp"

void Input::new_frame() {
  _pressed.clear();
  _relesead.clear();
}

void Input::key_up_event(SDL_Event *event) {
  _relesead[event->key.keysym.scancode] = true;
  _held[event->key.keysym.scancode] = false;
}

void Input::key_down_event(SDL_Event* event) {
  _pressed[event->key.keysym.scancode] = true;
  _held[event->key.keysym.scancode] = true;
}

bool Input::getKeyRelesead(SDL_Scancode key) {
  return _relesead[key];
}


bool Input::getKeyPressed(SDL_Scancode key) {
  return _pressed[key];
}


bool Input::getKeyHeld(SDL_Scancode key) {
  return _held[key];
}