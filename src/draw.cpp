#include "../include/draw.hpp"


void Draw::line(SDL_Renderer* renderer, Vector2 p1, Vector2 p2, Vector4 _color) {
  color = _color;

  SDL_SetRenderDrawColor(renderer, color.x, color.y, color.z, color.w);
  SDL_RenderDrawLine(renderer, p1.x, p1.y, p2.x, p2.y);

  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
}