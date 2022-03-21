#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "snake.h"
#include "ThreadObject.h"

class Controller : public ThreadObject {
 public:
  // Handles the input from keyboard and acts accordingly
  void HandleInput() const;

  // Overrides the parent's abstract method and runs controller thread [CC]
  void runThread() override;

  // Has the main loop which thread executes during game and controls frame timing
  void updateController();

 private:

  // Method to change direction of moving snake
  void ChangeDirection(Snake::Direction input,
                       Snake::Direction opposite) const;
};

#endif