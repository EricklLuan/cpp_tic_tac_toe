#pragma once

#include <SDL2/SDL.h>
#include "./vector2.hpp"

class Entity {
private:
  SDL_Texture* texture;
  SDL_Rect currentFrame;
  Vector2 size = Vector2(0.0f, 0.0f);
public:
  Vector2 scale = Vector2(1.0f, 1.0f);
  Vector2 position = Vector2(0.0f, 0.0f);

  Entity(SDL_Renderer* renderer, Vector2 _size, Vector2 _position, const char* path);

  inline SDL_Texture* getTexture() { return texture; };
  inline SDL_Rect getCurrentFrame() { return currentFrame; };
  inline Vector2 getSize() { return size; };

};