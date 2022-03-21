#include "controller.h"
#include <iostream>
#include "SDL.h"
#include "snake.h"

void Controller::ChangeDirection(Snake::Direction input,
                                 Snake::Direction opposite) const {
                                   
  std::unique_lock<std::mutex> lckSnake(_mtxSnake); // Lock snake resource before using it
  if (snake.getDirection() != opposite || snake.getSize() == 1) snake.setDirection(input);
  lckSnake.unlock();
  return;
}

void Controller::HandleInput() const {
  SDL_Event e;
  while (SDL_PollEvent(&e)) {
    if (e.type == SDL_QUIT) {

      std::unique_lock<std::mutex> lckRunning(_mtxRunning); // Lock running flag resource before changing
      running = false;
      lckRunning.unlock();

    } else if (e.type == SDL_KEYDOWN) {
      switch (e.key.keysym.sym) {
        case SDLK_UP:
          ChangeDirection(Snake::Direction::kUp,
                          Snake::Direction::kDown);
          break;

        case SDLK_DOWN:
          ChangeDirection(Snake::Direction::kDown,
                          Snake::Direction::kUp);
          break;

        case SDLK_LEFT:
          ChangeDirection(Snake::Direction::kLeft,
                          Snake::Direction::kRight);
          break;

        case SDLK_RIGHT:
          ChangeDirection(Snake::Direction::kRight,
                          Snake::Direction::kLeft);
          break;
      }
    }
  }
}

void Controller::updateController(){
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;

  while (getRunning()){

    std::this_thread::sleep_for(std::chrono::milliseconds(1)); // Reduce CPU usage by sleeping for 1 millisecond every iteration

    frame_start = SDL_GetTicks();
    Controller::HandleInput();
    frame_end = SDL_GetTicks();

    frame_duration = frame_end - frame_start;

    if(frame_duration < desired_frame_duration){
      SDL_Delay(desired_frame_duration - frame_duration);
    }

  }

}

void Controller::runThread(){

  threads.emplace_back(std::thread(&Controller::updateController,this));
  
}