#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include "SDL.h"
#include "snake.h"
#include <memory>
#include "food.h"

class Renderer {
 public:
  Renderer(const std::size_t screen_width, const std::size_t screen_height,
           const std::size_t grid_width, const std::size_t grid_height);
   // Rule of Three:
  Renderer(const Renderer &source);
  Renderer &operator=(const Renderer &source);
  ~Renderer();

  // Rule of Five:
  Renderer(Renderer &&source) noexcept;
  Renderer &operator=(Renderer &&source) noexcept;

  //void Render(Snake const snake, SDL_Point const &food);
  void Render(Snake const snake, std::unique_ptr<Food> const &food);
  void UpdateWindowTitle(int score, int fps);

 private:
  SDL_Window *sdl_window;
  SDL_Renderer *sdl_renderer;

  const std::size_t screen_width;
  const std::size_t screen_height;
  const std::size_t grid_width;
  const std::size_t grid_height;
};

#endif