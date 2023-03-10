#pragma once

#include <SDL2/SDL.h>
#include <vector>

struct Entity;

class Window {
private:
  SDL_Window* _window;
  SDL_Renderer* _renderer;
public:
  Window(const char* title, int width, int height);
  ~Window();
  
  inline void clear() { SDL_RenderClear(_renderer); };
  inline void flip() { SDL_RenderPresent(_renderer); };

  void render(std::vector<Entity> *entities);

  inline SDL_Window* get_window() { return this->_window; }
  inline SDL_Renderer* get_renderer() { return this->_renderer; }
};
