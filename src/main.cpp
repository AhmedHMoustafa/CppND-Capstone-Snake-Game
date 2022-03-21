#include <iostream>
#include "controller.h"
#include "game.h"
#include "renderer.h"
#include "ThreadObject.h"

int main() {
  constexpr std::size_t kFramesPerSecond{60};
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
  constexpr std::size_t kScreenWidth{640};
  constexpr std::size_t kScreenHeight{640};
  constexpr std::size_t kGridWidth{32};
  constexpr std::size_t kGridHeight{32};


  // Initialize Renderer, Controller & Game objects
  Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
  Controller controller;
  Game game(kGridWidth, kGridHeight);

  // Set the static parameters for game and controller
  game.setSnake(Snake(kGridWidth, kGridHeight));
  game.setDesFrame(kMsPerFrame);

  // Run game
  game.Run(controller, renderer, kMsPerFrame);

  // Print out when game ends
  std::cout << "Game has terminated successfully!\n";
  std::cout << "Score: " << game.GetScore() << "\n";
  std::cout << "Size: " << game.GetSize() << "\n";
  return 0;
}