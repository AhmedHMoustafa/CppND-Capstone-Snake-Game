#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include "SDL.h"
#include "snake.h"
#include "ThreadObject.h"
#include <memory>


class Renderer {
 public:
  Renderer(const std::size_t screen_width, const std::size_t screen_height,
           const std::size_t grid_width, const std::size_t grid_height);

  ~Renderer();

  // Renders snake and food
  void Render(Snake const snake, SDL_Point const &food, SDL_Point const &redFood, bool &renderRed);

  // Updates score and FPS in window title 
  void UpdateWindowTitle(int score, int fps);

 private:

  // Shared pointers instead of raw pointers (functionality in .cpp file changed accordingly) [MM]
  std::shared_ptr<SDL_Window> sdl_window;
  std::shared_ptr<SDL_Renderer> sdl_renderer;

  const std::size_t screen_width;
  const std::size_t screen_height;
  const std::size_t grid_width;
  const std::size_t grid_height;
};

#endif