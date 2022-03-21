#include "game.h"
#include <iostream>
#include "SDL.h"

Game::Game(std::size_t grid_width, std::size_t grid_height)
    : 
      engine(dev()),
      random_w(0, static_cast<int>(grid_width - 1)),
      random_h(0, static_cast<int>(grid_height - 1)) {
  //snake = Snake(grid_width, grid_height);
  PlaceFood();
}

void Game::runThread(){

  threads.emplace_back(std::thread(&Game::Update,this));

}

void Game::Run(Controller &controller, Renderer &renderer,
               std::size_t target_frame_duration) {
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;
  // bool running = true;

  desired_frame_duration = target_frame_duration;

  running = true;

  // Run thread for input control
  controller.runThread();
  
  // Run thread to update game engine
  runThread(); 
  //std::cout << "hi";

  while (getRunning()) {

    // std::cout << "hi";
    frame_start = SDL_GetTicks();

    // Input, Update, Render - the main game loop.
    // controller.HandleInput();
    // Update();
    renderer.Render(snake, food, redFood, renderRed);

    frame_end = SDL_GetTicks();

    // Keep track of how long each loop through the input/update/render cycle
    // takes.
    frame_count++;
    frame_duration = frame_end - frame_start;

    // After every second, update the window title.
    if (frame_end - title_timestamp >= 1000) {
      renderer.UpdateWindowTitle(score, frame_count);
      frame_count = 0;
      title_timestamp = frame_end;
    }

    // If the time for this frame is too small (i.e. frame_duration is
    // smaller than the target ms_per_frame), delay the loop to
    // achieve the correct frame rate.
    if (frame_duration < target_frame_duration) {
      SDL_Delay(target_frame_duration - frame_duration);
    }
  }
}

void Game::PlaceFood() {
  int x, y;
  while (true) {
    x = random_w(engine);
    y = random_h(engine);
    // Check that the location is not occupied by a snake item AND red food before placing
    // food.
    if (!snake.SnakeCell(x, y) && !containsRedFood(x,y)) {
      food.x = x;
      food.y = y;
      return;
    }
  }
}

void Game::PlaceRedFood(){
  int x, y;
  while(true){
    x = random_w(engine);
    y = random_h(engine);
    // Check that the location is not occupied by a snake item AND normal food before placing
    // food.
    if (!snake.SnakeCell(x, y) && !containsFood(x,y)) {
      redFood.x = x;
      redFood.y = y;
      return;
    }

  }

}

bool Game::containsFood(int x, int y){
  if(x == food.x && y == food.y){
    return true;
  }else{
    return false;
  }

}

bool Game::containsRedFood(int x, int y){
  if(x == redFood.x && y == redFood.y){
    return true;
  }else{
    return false;
  }

}

void Game::Update() {

  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;

  while(getRunning()){

    // Reduce CPU usage by sleeping for 1 millisecond every iteration
    std::this_thread::sleep_for(std::chrono::milliseconds(1));

    frame_start = SDL_GetTicks();

    std::unique_lock<std::mutex> lckSnake(_mtxSnake); // Lock the snake resource before using it [CC]
  
    if (!snake.getAlive()) return;

    snake.Update();

    int new_x = static_cast<int>(snake.getHead_x());
    int new_y = static_cast<int>(snake.getHead_y());

    // Lock the food resources before using them [CC]
    // std::unique_lock<std::mutex> lckFood(_mtxFood);  
    // std::unique_lock<std::mutex> lckRedFood(_mtxRedFood);
    // std::unique_lock<std::mutex> lckRenderRed(_mtxRenderRed);

    if(containsFood(new_x, new_y)){
        score++;
        snake.GrowBody();
        snake.increaseSpeed(0.02);
        PlaceFood();

        //If score is a multiple of 5, add a red food
        if(score > 0 && score%5==0){
          PlaceRedFood(); 
          renderRed = true;
        }
        
        
    }else if(containsRedFood(new_x, new_y)){
      score++;
      snake.GrowBody();
      snake.decreaseSpeed(0.02); // If consumed a red food then slow down
      renderRed = false;

      // Place red food out of frame/grid
      redFood.x =34;
      redFood.y =34;
    }
    
    // Unlock resources after done using them
    // lckRenderRed.unlock();
    // lckFood.unlock();
    // lckRedFood.unlock();
    lckSnake.unlock();

    frame_end = SDL_GetTicks();
    frame_duration = frame_end - frame_start;

    // Delay loop to achieve desired frame duration
    if(frame_duration < desired_frame_duration){
      SDL_Delay(desired_frame_duration - frame_duration);
    }
    
  }
}

int Game::GetScore() const { return score; }
int Game::GetSize() const { return snake.getSize(); }