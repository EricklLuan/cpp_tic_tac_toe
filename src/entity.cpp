#include "../include/entity.hpp"

#include <SDL2/SDL_image.h>
#include <iostream>

Entity::Entity(SDL_Renderer* renderer, Vector2 _size, Vector2 _position, const char* path = NULL)
: size(_size), position(_position)
{
  currentFrame.x = 0;
  currentFrame.y = 0;
  currentFrame.w = size.x;
  currentFrame.h = size.y;

  if (path != NULL) {
    texture = IMG_LoadTexture(renderer, path);

    if (texture == NULL) {
      std::cout << "SDL::CREATE::TEXTURE::ERROR: " << SDL_GetError() << "\n";
    }
  }
}