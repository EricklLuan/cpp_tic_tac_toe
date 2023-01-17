#pragma once

#include <SDL2/SDL.h>

#include "./vector2.hpp"
#include "./vector3.hpp"

class Entity {
private:
  SDL_Texture* texture = NULL;
  SDL_Rect currentFrame;
  SDL_Rect collision;
  Vector3 color = Vector3(0.0f, 0.0f, 0.0f);
  Vector2 size = Vector2(0.0f, 0.0f);
public:
  Vector2 scale = Vector2(1.0f, 1.0f);
  Vector2 position = Vector2(0.0f, 0.0f);

  Entity(SDL_Renderer* renderer, Vector2 _size, Vector2 _position, Vector3 _color, const char* path);

  bool checkIfCollideWith(SDL_Rect* collider); 

  inline SDL_Texture* getTexture() { return texture; };
  inline SDL_Rect *getCollision() { return &collision; };
  inline SDL_Rect getCurrentFrame() { return currentFrame; };
  inline Vector2 getSize() { return size; };
  inline Vector3 getColor() { return color; };

};