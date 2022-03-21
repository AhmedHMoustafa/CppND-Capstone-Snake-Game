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

  // Central method that runs all the threads and renderer
  void Run(Controller &controller, Renderer &renderer,
           std::size_t target_frame_duration);


  // Overrides the parent's abstract method and runs controller thread [CC]
  void runThread() override;

  // Getters
  int GetScore() const;
  int GetSize() const;

 private:
  SDL_Point food; // Food every point
  SDL_Point redFood; // Red food every 5 points
  bool renderRed; // Flag to check when to render the redfood

  /*Random device number generator for food location*/
  std::random_device dev;
  std::mt19937 engine;
  std::uniform_int_distribution<int> random_w;
  std::uniform_int_distribution<int> random_h;

  int score{0}; // Game score

  // Places Food and/or Red food in a random location
  void PlaceFood();
  void PlaceRedFood();

  // Checks if given cell contains food or red food
  bool containsFood(int x, int y);
  bool containsRedFood(int x, int y);

  // Main loop that thread executes during game. 
  // Controls frame timing, snake physics
  void Update();
};

#endif