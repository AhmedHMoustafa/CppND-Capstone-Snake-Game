#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "snake.h"
#include "ThreadObject.h"

class Controller : public ThreadObject {
 public:
  void HandleInput() const;

  void runThread() override;

  void updateController();

 private:
  void ChangeDirection(Snake::Direction input,
                       Snake::Direction opposite) const;
};

#endif