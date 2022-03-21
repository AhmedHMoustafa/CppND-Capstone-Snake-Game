#include "renderer.h"
#include <iostream>
#include <string>

Renderer::Renderer(const std::size_t screen_width,
                   const std::size_t screen_height,
                   const std::size_t grid_width, const std::size_t grid_height)
    : screen_width(screen_width),
      screen_height(screen_height),
      grid_width(grid_width),
      grid_height(grid_height) {
  // Initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cerr << "SDL could not initialize.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create Window
  sdl_window = std::shared_ptr<SDL_Window> (SDL_CreateWindow("Snake Game", SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED, screen_width,
                                screen_height, SDL_WINDOW_SHOWN), SDL_DestroyWindow);

  if (nullptr == sdl_window) {
    std::cerr << "Window could not be created.\n";
    std::cerr << " SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create renderer
  sdl_renderer = std::shared_ptr<SDL_Renderer> (SDL_CreateRenderer(sdl_window.get(), -1, SDL_RENDERER_ACCELERATED), SDL_DestroyRenderer);
  if (nullptr == sdl_renderer) {
    std::cerr << "Renderer could not be created.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }
}

Renderer::~Renderer() {
  SDL_DestroyWindow(sdl_window.get());
  SDL_Quit();
}

// void Renderer::runThread(){

//   threads.emplace_back(std::thread(&Renderer::UpdateRender,this));

// }

// void Renderer::UpdateRender(){

//   Uint32 frame_start;
//   Uint32 frame_end;
//   Uint32 frame_duration;
//   int frame_count = 0;

//   while(true){

//     // Reduce CPU usage by sleeping for 1 millisecond every iteration
//     std::this_thread::sleep_for(std::chrono::milliseconds(1));

//     frame_start = SDL_GetTicks();

//   }

// }

void Renderer::Render(Snake const snake, SDL_Point const &food, SDL_Point const &redFood, bool &renderRed) {
  SDL_Rect block;
  block.w = screen_width / grid_width;
  block.h = screen_height / grid_height;

  // Clear screen
  SDL_SetRenderDrawColor(sdl_renderer.get(), 0x1E, 0x1E, 0x1E, 0xFF);
  SDL_RenderClear(sdl_renderer.get());

  // Render food
  // std::unique_lock<std::mutex> lckFood(_mtxFood);
  SDL_SetRenderDrawColor(sdl_renderer.get(), 0xFF, 0xCC, 0x00, 0xFF);
  block.x = food.x * block.w;
  block.y = food.y * block.h;
  // lckFood.unlock();
  SDL_RenderFillRect(sdl_renderer.get(), &block);

  // Render Red Food [FUNC] & [CC]
  
  // std::unique_lock<std::mutex> lckRenderRed(_mtxRenderRed);
  // std::unique_lock<std::mutex> lckRedFood(_mtxRedFood);
  if(renderRed){
    SDL_SetRenderDrawColor(sdl_renderer.get(), 0xFF, 0x00, 0x00, 0xFF);
    block.x = redFood.x * block.w;
    block.y = redFood.y * block.h;
    SDL_RenderFillRect(sdl_renderer.get(), &block);
  }
  // lckRedFood.unlock();
  // lckRenderRed.unlock();


  // Render snake's body
  SDL_SetRenderDrawColor(sdl_renderer.get(), 0xFF, 0xFF, 0xFF, 0xFF);
  // std::unique_lock<std::mutex> lckSnake(_mtxSnake);
  for (SDL_Point const &point : snake.getBody()) {
    block.x = point.x * block.w;
    block.y = point.y * block.h;
    SDL_RenderFillRect(sdl_renderer.get(), &block);
  }

  // Render snake's head
  block.x = static_cast<int>(snake.getHead_x()) * block.w;
  block.y = static_cast<int>(snake.getHead_y()) * block.h;
  if (snake.getAlive()) {
    SDL_SetRenderDrawColor(sdl_renderer.get(), 0x00, 0x7A, 0xCC, 0xFF);
  } else {
    SDL_SetRenderDrawColor(sdl_renderer.get(), 0xFF, 0x00, 0x00, 0xFF);
  }
  // lckSnake.unlock();
  SDL_RenderFillRect(sdl_renderer.get(), &block);

  // Update Screen
  SDL_RenderPresent(sdl_renderer.get());
}

void Renderer::UpdateWindowTitle(int score, int fps) {
  std::string title{"Snake Score: " + std::to_string(score) + " FPS: " + std::to_string(fps)};
  SDL_SetWindowTitle(sdl_window.get(), title.c_str());
}
