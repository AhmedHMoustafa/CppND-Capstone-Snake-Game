#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include "SDL.h"

class Snake {
 public:
  enum class Direction { kUp, kDown, kLeft, kRight };

  Snake(int grid_width, int grid_height)
      : grid_width(grid_width),
        grid_height(grid_height),
        head_x(grid_width / 2),
        head_y(grid_height / 2) {}

  // Update snake position
  void Update();
  
  // Grow snake's body size
  void GrowBody();

  // Check if snake contains given coordinates
  bool SnakeCell(int const &x, int const &y);

  /*Getters and Setters [OOP]*/ 
  
  Direction getDirection() const;
  void setDirection(Direction k);

  float getSpeed() const;
  void increaseSpeed(float s);
  void decreaseSpeed(float s);

  int getSize() const;
  void setSize(int s);

  bool getAlive() const;
  void setAlive(bool b);

  float getHead_x() const;
  float getHead_y() const;

  std::vector<SDL_Point> getBody() const;
  

 private:
  void UpdateHead();
  void UpdateBody(SDL_Point &current_cell, SDL_Point &prev_cell);

  bool growing{false};
  int grid_width;
  int grid_height;


  Direction direction = Direction::kUp;

  float speed{0.1f};
  int size{1};
  bool alive{true};
  float head_x;
  float head_y;
  std::vector<SDL_Point> body;
};

#endif