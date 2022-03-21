#ifndef GAME_H
#define GAME_H

#include <random>
#include "SDL.h"
#include "controller.h"
#include "renderer.h"
#include "snake.h"
#include "ThreadObject.h"

class Game : public ThreadObject {
 public:

  Game(std::size_t grid_width, std::size_t grid_height);

  void Run(Controller &controller, Renderer &renderer,
           std::size_t target_frame_duration);


  // Updates game status in a thread [CC]
  void runThread() override;

  int GetScore() const;
  int GetSize() const;

 private:
  // Snake snake;
  SDL_Point food;
  SDL_Point redFood;
  bool renderRed; // Flag to check when to render the redfood
  // bool running{true}; // Flag for game is still running
  // std::size_t desired_frame_duration;

  std::random_device dev;
  std::mt19937 engine;
  std::uniform_int_distribution<int> random_w;
  std::uniform_int_distribution<int> random_h;

  int score{0};

  void PlaceFood();
  void PlaceRedFood();
  bool containsFood(int x, int y);
  bool containsRedFood(int x, int y);
  void Update();
};

#endif