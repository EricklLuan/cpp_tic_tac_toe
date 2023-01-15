#include "../include/input.hpp"

void Input::new_frame() {
  _pressed.clear();
  _relesead.clear();
  _mousePressed.clear();
  _mouseRelesead.clear();
}

void Input::key_up_event(SDL_Event *event) {
  _relesead[event->key.keysym.scancode] = true;
  _held[event->key.keysym.scancode] = false;
}

void Input::key_down_event(SDL_Event* event) {
  _pressed[event->key.keysym.scancode] = true;
  _held[event->key.keysym.scancode] = true;
}

void Input::mouse_key_up_event(SDL_Event* event) {
  _mouseRelesead[event->button.button] = true;
  _mouseHeld[event->button.button] = false;
}

void Input::mouse_key_down_event(SDL_Event* event) {
  _mousePressed[event->button.button] = true;
  _mouseHeld[event->button.button] = true;
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

bool Input::getMouseRelesead(Uint8 mouseButton) {
  return _mouseRelesead[mouseButton];
}

bool Input::getMousePressed(Uint8 mouseButton) {
  return _mousePressed[mouseButton];
}

bool Input::getMouseHeld(Uint8 mouseButton) {
  return _mouseHeld[mouseButton];
}