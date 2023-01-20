#include "../include/entity.hpp"

#include <SDL2/SDL_image.h>
#include <iostream>
#include <string.h>

Entity::Entity(SDL_Renderer* renderer, Vector2 _size, Vector2 _position, Vector4 _color, const char* path = "")
: size(_size), position(_position)
{
  currentFrame.x = 0;
  currentFrame.y = 0;
  currentFrame.w = size.x;
  currentFrame.h = size.y;

  collision = {
    (int)position.x,
    (int)position.y,
    (int)size.x,
    (int)size.y,
  };

  const char* str = "";
  if (strcmp(path, str) != 0) {
    texture = IMG_LoadTexture(renderer, path);

    if (texture == NULL) {
      std::cout << "SDL::CREATE::TEXTURE::ERROR: " << SDL_GetError() << "\n";
    }
  } else {
    color = _color;
  }
}

bool Entity::checkIfCollideWith(SDL_Rect *collider) {
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    leftA = collision.x;
    rightA = collision.x + collision.w;
    topA = collision.y;
    bottomA = collision.y + collision.h;

    leftB = collider->x;
    rightB = collider->x + collider->w;
    topB = collider->y;
    bottomB = collider->y + collider->h;

    if ( bottomA <= topB ) return false;
    if( topA >= bottomB ) return false;
    if( rightA <= leftB ) return false;
    if( leftA >= rightB ) return false;

    return true;
}

void Entity::setTexture(SDL_Renderer* renderer, const char *path) {
  texture = IMG_LoadTexture(renderer, path);

  if (texture == NULL) {
    std::cout << "SDL::CREATE::TEXTURE::ERROR: " << SDL_GetError() << "\n";
  }
}

void Entity::clear() {
  texture = NULL;
  active = true;
}