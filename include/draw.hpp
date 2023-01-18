#pragma once

#include <SDL2/SDL.h>

#include "./vector2.hpp"
#include "./vector4.hpp"

class Draw {
private:
  Vector4 color = Vector4(0.0f, 0.0f, 0.0f, 0.0f);
public:

  void line(SDL_Renderer* renderer, Vector2 p1, Vector2 p2, Vector4 _color);

};